// This is an example of a command line tool for editing colors in an SVG file.

// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non - commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain.We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors.We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// For more information, please refer to <http://unlicense.org/>

#include "../../colorm.h"
#include <iostream>
#include <fstream>
#include <streambuf>
#include <regex>
#include <set>

using Oklch = colorm::Oklch;
using Lrgb = colorm::Lrgb;
using Xyz = colorm::XyzD65;
using Rgb = colorm::Rgb;
using ColorScale = colorm::ColorScale<Lrgb>;
using ParseError = colorm::ParseError;

static const char* const USAGE =
"Discolored edits colors contained in SVG files.\n\n"
"Usage: discolored [inputfiles] [options]\n\n"
"Options:\n"
"  --help                              show this help\n"
"  -o [ --output ] path                set output file\n"
"  -O [ --output-file-suffix ] suffix  set output file suffix\n"
"  -i [ --index ]                      show the indexes of the colors\n"
"  -p [ --protect ] indexes            set the indexes of the colors that will not be edited\n"
"  -s [ --select ]  indexes            set the indexes of the colors to be edited\n"
"  -m [ --multiply ] color             set filter color\n"
"  -g [ --gradient ] color color       replace each color with the color contained in a gradient.\n"
"  -lm [ --lightness-multiply ] value  set lightness multiplier\n"
"  -cm [ --chroma-multiply ] value     set chroma multiplier\n"
"  -hm [ --hue-multiply ] value        set hue multiplier\n"
"  -l [ --lightness ] value            set lightness addend\n"
"  -c [ --chroma ] value               set chroma addend\n"
"  -h [ --hue ] value                  set hue addend\n"
"  -L [ --set-lightness ] value        set lightness\n"
"  -C [ --set-chroma ] value           set chroma\n"
"  -H [ --set-hue ] value              set hue\n"
"  -r [ --reference ] color            set reference color\n"
"  -t [ --target ] color               set target color\n"
"  -G [ --gamma ] value                set gamma\n"
"  -I [ --invert ]                     invert colors\n"
"  -f [ --flip ] value                 flip hues\n"
;

struct Option
{
	enum class Mode {
		usage, index, main
	} mode;

	std::vector<std::string> inputfiles, outputfiles;
	std::string suffix;
	std::set<int> protectedColors, selectedColors;
	Lrgb lrgbMultiplier, black, white;
	Oklch reference, target;
	bool setLightness, setChroma, setHue, hasTarget, gradient, invert, flip;
	double lightness, chroma, hue, newLightness, newChroma, newHue, flipArg;
	double lightnessMul, chromaMul, hueMul, gamma;

	Option()
		: mode{Mode::usage},
		  setLightness{}, setChroma{}, setHue{}, hasTarget{}, gradient{}, invert{}, flip{},
		  lightness{}, chroma{}, hue{}, newLightness{}, newChroma{}, newHue{}, flipArg{},
		  lightnessMul{}, chromaMul{}, hueMul{}, gamma{}
	{}

	bool parse(int argc, char *argv[])
	{
		if (argc < 2) {
			mode = Mode::usage;
			return true;
		}

		mode = Mode::main;
		suffix = "_discolored";
		lrgbMultiplier = Lrgb(1.0, 1.0, 1.0);
		black = Lrgb(0.0, 0.0, 0.0);
		white = Lrgb(1.0, 1.0, 1.0);
		reference = target = Oklch(50, 0, 0);
		setLightness = setChroma = setHue = hasTarget = gradient = invert = flip = false;
		lightness = chroma = hue = newLightness = newChroma = newHue = flipArg = 0.0;
		lightnessMul = chromaMul = hueMul = gamma = 1.0;

		int i = 1;
		const auto parseString = [argc, argv, &i]()
		{
			if (i < argc) {
				++i;
				return std::string(argv[i - 1]);
			}
			return std::string();
		};
		const auto parseNumber = [&parseString](double& d)
		{
			std::string s = parseString();
			try {
				d = std::stod(s);
			} catch (...) {
				std::cout << "\"" << s << "\" is not a number." << std::endl;
				return false;
			}
			return true;
		};
		const auto parseIndexes = [&parseString](std::set<int>& d)
		{
			std::istringstream is(parseString());
			std::string s;
			while (std::getline(is, s, ',')) {
				try {
					if (!s.empty()) d.insert(static_cast<int>(std::stoul(s)) - 1);
				} catch (...) {
					std::cout << "\"" << s << "\" is not an index." << std::endl;
					return false;
				}
			}
			return true;
		};

		try {
			while (i < argc) {
				std::string s = parseString();
				if (s == "--help") {
					mode = Mode::usage;
					return true;
				} else if (s == "-o" || s == "--output") {
					outputfiles.emplace_back(parseString());
				} else if (s == "-O" || s == "--output-file-suffix") {
					suffix = parseString();
				} else if (s == "-i" || s == "--index") {
					mode = Mode::index;
					return true;
				} else if (s == "-p" || s == "--protect") {
					if (!parseIndexes(protectedColors)) return false;
				} else if (s == "-s" || s == "--select") {
					if (!parseIndexes(selectedColors)) return false;
				} else if (s == "-m" || s == "--multiply") {
					lrgbMultiplier = Lrgb(parseString());
				} else if (s == "-g" || s == "--gradient") {
					black = Lrgb(parseString());
					white = Lrgb(parseString());
					gradient = true;
				} else if (s == "-lm" || s == "--lightness-multiply") {
					if (!parseNumber(lightnessMul)) return false;
				} else if (s == "-cm" || s == "--chroma-multiply") {
					if (!parseNumber(chromaMul)) return false;
				} else if (s == "-hm" || s == "--hue-multiply") {
					if (!parseNumber(hueMul)) return false;
				} else if (s == "-l" || s == "--lightness") {
					if (!parseNumber(lightness)) return false;
				} else if (s == "-c" || s == "--chroma") {
					if (!parseNumber(chroma)) return false;
				} else if (s == "-h" || s == "--hue") {
					if (!parseNumber(hue)) return false;
				} else if (s == "-L" || s == "--set-lightness") {
					if (!parseNumber(newLightness)) return false;
					setLightness = true;
				} else if (s == "-C" || s == "--set-chroma") {
					if (!parseNumber(newChroma)) return false;
					setChroma = true;
				} else if (s == "-H" || s == "--set-hue") {
					if (!parseNumber(newHue)) return false;
					setHue = true;
				} else if (s == "-r" || s == "--reference") {
					reference = Oklch(parseString());
				} else if (s == "-t" || s == "--target") {
					target = Oklch(parseString());
					hasTarget = true;
				} else if (s == "-G" || s == "--gamma") {
					if (!parseNumber(gamma)) return false;
				} else if (s == "-I" || s == "--invert") {
					invert = true;
				} else if (s == "-f" || s == "--flip") {
					if (!parseNumber(flipArg)) return false;
					flip = true;
				} else if (!s.empty() && s[0] != '-') {
					inputfiles.emplace_back(s);
				} else {
					std::cout << "\"" << s << "\" is an unknown option." << std::endl;
					return false;
				}
			}
		} catch (const ParseError& e) {
			std::cout << "\"" << e.what() << "\" is not a color string." << std::endl;
			return false;
		}

		if (inputfiles.empty()) {
			std::cout << "No input file specified." << std::endl;
			return false;
		}
		if (inputfiles.size() > outputfiles.size()) {
			outputfiles.clear();
			for (const auto& s : inputfiles) {
				const auto pos = s.rfind('.');
				if (pos == std::string::npos) {
					outputfiles.emplace_back(s + suffix);
				} else {
					outputfiles.emplace_back(s.substr(0U, pos) + suffix + s.substr(pos));
				}
			}
		}
		return true;
	}
};

std::string readFile(const std::string& fileName)
{
	std::ifstream f(fileName, std::ios::binary);
	if (!f) {
		std::cout << "\"" << fileName << "\" cannot be opened." << std::endl;
		return std::string();
	}
	return std::string(
		(std::istreambuf_iterator<char>(f)),
		std::istreambuf_iterator<char>());
}

bool convert(const Option& option, const size_t fileNumber)
{
	const std::string src = readFile(option.inputfiles[fileNumber]);
	if (src.empty()) return false;

	std::vector<std::string> texts, colors;
	std::vector<bool> isHexColor;

	const std::regex reg(R"((?:color|stroke|fill)\s*[:=]\s*"?((#?)\w+(?:\([^)]+\))?))");
	std::smatch m;
	auto ci = src.cbegin();
	const auto ce = src.cend();
	while (std::regex_search(ci, ce, m, reg)) {
		texts.emplace_back(ci, ci + m.position(1));
		colors.emplace_back(m.str(1));
		isHexColor.emplace_back(m.str(2) == "#");
		ci += m.position(0) + m.length(0);
	}
	texts.emplace_back(ci, ce);

	// -i
	if (option.mode == Option::Mode::index) {
		const auto size = colors.size();
		for (size_t i = 0U; i < size; ++i) {
			std::cout << i + 1 << ":\t" << colors[i] << '\t';
			try {
				Oklch c(colors[i]);
				std::cout << c.css() << std::endl;
			} catch (...) {
				std::cout << "N/A" << std::endl;
			}
		}
		return 0;
	}

	// -l -c -h
	Oklch lchAddend(option.lightness, option.chroma, option.hue);
	// -r -t
	if (option.hasTarget) {
		lchAddend += Oklch(
			option.target.lightness() - option.reference.lightness(),
			option.target.chroma() - option.reference.chroma(),
			option.target.hue() - option.reference.hue()
		);
	}
	// -lm -cm -hm
	const Oklch lchMultiplier(option.lightnessMul, option.chromaMul, option.hueMul);

	const int nColors = static_cast<int>(colors.size());
	for (int i = 0; i < nColors; ++i) {
		if (option.selectedColors.empty()) {
			// -p
			const auto& pr = option.protectedColors;
			if (pr.find(i) != pr.end()) continue;
		} else {
			// -s
			const auto& se = option.selectedColors;
			if (se.find(i) == se.end()) continue;
		}
		try {
			auto newColor = Oklch(colors[i]);
			if (option.invert) {
				// -I
				Lrgb c(newColor);
				newColor = Oklch(Lrgb(1.0 - c.red(), 1.0 - c.green(), 1.0 - c.blue(), c.alpha()));
			}
			if (option.flip) {
				// -f
				newColor = newColor.flip(option.flipArg);
			}
			newColor *= lchMultiplier;
			newColor += lchAddend;
			if (option.setHue) {
				// -H
				newColor.setHue(option.newHue);
			}
			if (option.setChroma) {
				// -C
				newColor.setChroma(option.newChroma);
			}
			if (option.setLightness) {
				// -L
				newColor.setLightness(option.newLightness);
			}

			// -m
			auto lr = (Lrgb(Lrgb(newColor) * option.lrgbMultiplier)).fit();
			if (option.gamma > 0.0 && option.gamma != 1.0) {
				// -G
				lr = Lrgb(
					std::pow(lr.red(), option.gamma),
					std::pow(lr.green(), option.gamma),
					std::pow(lr.blue(), option.gamma),
					lr.alpha()
				);
			}
			if (option.gradient) {
				// -g
				const ColorScale cs({option.black, option.white});
				lr = cs(lr.calculateLuminance());
			}

			if (isHexColor[i]) {
				colors[i] = lr.hex();
			} else {
				colors[i] = Rgb(lr).css();
			}
		} catch (...) {
		}
	}

	std::ofstream dst(option.outputfiles[fileNumber], std::ios::binary);
	if (!dst) {
		std::cout << "\"" << option.outputfiles[fileNumber] << "\" cannot be opened." << std::endl;
		return false;
	}

	const auto nTexts = texts.size();
	for (size_t i = 0U; i < nTexts - 1U; ++i) {
		dst.write(texts[i].c_str(), static_cast<std::streamsize>(texts[i].size()));
		dst.write(colors[i].c_str(), static_cast<std::streamsize>(colors[i].size()));
	}
	dst.write(texts.back().c_str(), static_cast<std::streamsize>(texts.back().size()));
	return true;
}

int main(int argc, char *argv[])
{
	Option option;
	if (!option.parse(argc, argv)) return -1;

	// --help
	if (option.mode == Option::Mode::usage) {
		std::cout << USAGE << std::endl;
		return 0;
	}

	int exitStatus = 0;
	const size_t nFiles = option.inputfiles.size();
	for (size_t i = 0U; i < nFiles; ++i) {
		if (!convert(option, i)) {
			--exitStatus;
		}
	}
	return exitStatus;
}
