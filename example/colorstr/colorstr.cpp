// This is an example of reading and writing color strings.

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
#include <algorithm>
#include <sstream>
#include <map>
#include <regex>

static const char* const USAGE =
"Enter color strings, \"-\", an output mode or \"quit\".\n"
"\n"
"Output mode:\n"
"  hex\n"
"  rgb\n"
"  hsl\n"
"  hwb\n"
"  srgb-linear\n"
"  xyz-d50\n"
"  lab\n"
"  lch\n"
"  xyz\n"
"  oklab\n"
"  oklch\n"
"  srgb\n"
"  display-p3\n"
"  a98-rgb\n"
"  prophoto-rgb\n"
"  rec2020\n"
"\n"
"Example:\n"
"  oklch\n"
"  > \n"
"  hsl(20, 100%, 29%) - - green\n"
"  > oklch(45.487% 0.14169 40.374) oklch(47.65% 0.15341 74.414) oklch(49.812% 0.16513 108.455) oklch(51.975% 0.17686 142.495\n"
"  hex\n"
"  > #943100 #7e5300 #696700 #008000\n"
;

enum class Mode : int
{
	HEX,
	RGB,
	HSL,
	HWB,
	LRGB,
	XYZD50,
	LAB,
	LCH,
	XYZD65,
	OKLAB,
	OKLCH,
	SRGB,
	DISPLAY_P3,
	A98_RGB,
	PROPHOTO_RGB,
	REC2020
};

static std::map<std::string, Mode> StringToMode = {
	{"hex",          Mode::HEX},
	{"rgb",          Mode::RGB},
	{"hsl",          Mode::HSL},
	{"hwb",          Mode::HWB},
	{"srgb-linear",  Mode::LRGB},
	{"xyz-d50",      Mode::XYZD50},
	{"lab",          Mode::LAB},
	{"lch",          Mode::LCH},
	{"xyz",          Mode::XYZD65},
	{"xyz-D65",      Mode::XYZD65},
	{"oklab",        Mode::OKLAB},
	{"oklch",        Mode::OKLCH},
	{"srgb",         Mode::SRGB},
	{"display-p3",   Mode::DISPLAY_P3},
	{"a98-rgb",      Mode::A98_RGB},
	{"prophoto-rgb", Mode::PROPHOTO_RGB},
	{"rec2020",      Mode::REC2020}
};

struct Color
{
	colorm::Oklab oklab;
	int count;
};

static void ReadColors(std::vector<Color>& colorList, const std::string& line)
{
	colorList.clear();
	int count = 0;
	static const std::regex re(R"(\-|(#?)\w+(?:\([^)]+\))?)");
	std::sregex_iterator begin(line.begin(), line.end(), re), end;

	for (std::sregex_iterator it = begin; it != end; ++it) {
		auto word = it->str();
		if (word == "-") {
			++count;
		} else {
			colorm::Oklab oklab;
			try {
				oklab = colorm::Oklab(word);
				if (count > 0 && !colorList.empty()) {
					colorList.push_back({oklab, count});
				} else {
					colorList.push_back({oklab, 0});
				}
				count = 0;
			} catch (const colorm::ParseError& e) {
				std::cout << '"' << e.what() << '"' << " is not a color string." << std::endl;
				continue;
			}
		}
	}
}

template <typename T> static void PrintColors(std::vector<Color>& colorList, bool hex = false)
{
	std::cout << "> ";

	const size_t size = colorList.size();
	std::vector<Color> colorList2;

	for (size_t i = 0U; i < size; ++i) {
		if (i == 0U || colorList[i].count == 0) {
			colorList2.push_back(colorList[i]);
			if (i > 0U) {
				std::cout << ' ';
			}
			if (hex) {
				std::cout << colorList[i].oklab.hex();
			} else {
				std::cout << T(colorList[i].oklab).css();
			}
		} else {
			colorm::ColorScale<T> cs({T(colorList[i - 1U].oklab), T(colorList[i].oklab)});
			auto v = cs.colors(colorList[i].count + 2);
			bool first = true;
			for (const auto& c : v) {
				if (first) {
					first = false;
					continue;
				}
				colorList2.push_back({colorm::Oklab(c), 0});
				std::cout << ' ';
				if (hex) {
					std::cout << c.hex();
				} else {
					std::cout << c.css();
				}
			}
		}
	}
	std::cout << std::endl;

	colorList = colorList2;
}

static void ToLower(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(), tolower);
}

int main()
{
	std::cout << USAGE << std::endl;

	Mode mode = Mode::HEX;
	std::vector<Color> colorList;
	std::string line, word;

	while (std::getline(std::cin, line)) {
		if (line.empty()) return 0;

		std::istringstream(line) >> word;
		ToLower(word);
		if (word.empty() || word == "quit") return 0;

		auto it = StringToMode.find(word);
		if (it != StringToMode.end()) {
			mode = it->second;
		} else {
			ReadColors(colorList, line);
		}

		switch (mode) {
		case Mode::HEX:
			PrintColors<colorm::Rgb>(colorList, true);
			break;
		case Mode::RGB:
			PrintColors<colorm::Rgb>(colorList);
			break;
		case Mode::HSL:
			PrintColors<colorm::Hsl>(colorList);
			break;
		case Mode::HWB:
			PrintColors<colorm::Hwb>(colorList);
			break;
		case Mode::LRGB:
			PrintColors<colorm::Lrgb>(colorList);
			break;
		case Mode::XYZD50:
			PrintColors<colorm::XyzD50>(colorList);
			break;
		case Mode::LAB:
			PrintColors<colorm::Lab>(colorList);
			break;
		case Mode::LCH:
			PrintColors<colorm::Lch>(colorList);
			break;
		case Mode::XYZD65:
			PrintColors<colorm::XyzD65>(colorList);
			break;
		case Mode::OKLAB:
			PrintColors<colorm::Oklab>(colorList);
			break;
		case Mode::OKLCH:
			PrintColors<colorm::Oklch>(colorList);
			break;
		case Mode::SRGB:
			PrintColors<colorm::Srgb>(colorList);
			break;
		case Mode::DISPLAY_P3:
			PrintColors<colorm::DisplayP3>(colorList);
			break;
		case Mode::A98_RGB:
			PrintColors<colorm::A98Rgb>(colorList);
			break;
		case Mode::PROPHOTO_RGB:
			PrintColors<colorm::ProphotoRgb>(colorList);
			break;
		case Mode::REC2020:
			PrintColors<colorm::Rec2020>(colorList);
			break;
		}
	}
}
