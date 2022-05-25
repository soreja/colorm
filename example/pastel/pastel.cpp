// This is an example of editing colors in an HTML / CSS file.

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
#include <fstream>
#include <streambuf>
#include <regex>

std::string readFile(const char* const filename)
{
	std::ifstream f(filename);
	if (!f) return std::string();
	return std::string(
		(std::istreambuf_iterator<char>(f)),
		std::istreambuf_iterator<char>());
}

std::string toPastelColor(const std::string& color)
{
	try {
		colorm::Oklch c(color);
		if (c.chroma() > 0.06) {
			c.setChroma(0.12).setLightness(0.8);
		} else {
			c.setChroma(0.0);
		}
		return colorm::Hsl(c).css();
	} catch (const colorm::ParseError& e) {
		return std::string(e.what());
	}
}

void convertAndWriteColor(std::ofstream& o, const std::string& str)
{
	static const std::regex reg(R"(#?[%\-/0-9A-Za-z]+(?:\([^)]*\))?)");
	std::smatch m;
	auto ci = str.cbegin();
	const auto ce = str.cend();
	while (std::regex_search(ci, ce, m, reg)) {
		o << std::string(ci, ci + m.position(0));
		o << toPastelColor(m.str(0));
		ci += m.position(0) + m.length(0);
	}
	o << std::string(ci, ce);
}

int main()
{
	const std::string str = readFile("A.html");
	std::ofstream o("B.html");
	const std::regex reg(R"((?:background|border|color)\s*:\s*([^:;<=>\{\}]+))", std::regex_constants::icase);
	std::smatch m;
	auto ci = str.cbegin();
	const auto ce = str.cend();
	while (std::regex_search(ci, ce, m, reg)) {
		o << std::string(ci, ci + m.position(1));
		convertAndWriteColor(o, m.str(1));
		ci += m.position(0) + m.length(0);
	}
	o << std::string(ci, ce);
}
