#include "pch.h"

#include <boost/test/unit_test.hpp>


using namespace colorm;

BOOST_AUTO_TEST_CASE(HEX)
{
	BOOST_CHECK_EQUAL(Rgb("BlaCk").hex(),   "#000000");
	BOOST_CHECK_EQUAL(Rgb("#FfffFF").hex(), "#ffffff");

	BOOST_CHECK_EQUAL(Rgb(0x12, 0x34, 0x56).hex(),                   "#123456");
	BOOST_CHECK_EQUAL(Rgb(0x12, 0x34, 0x56, 1.1).hex(),              "#123456");
	BOOST_CHECK_EQUAL(Rgb(0x12, 0x34, 0x56, -1.1).hex(),             "#12345600");
	BOOST_CHECK_EQUAL(Rgb(0x12 + 0.4, 0x34 + 0.4, 0x56 + 0.4).hex(), "#123456");
	BOOST_CHECK_EQUAL(Rgb(0x12 - 0.4, 0x34 - 0.4, 0x56 - 0.4).hex(), "#123456");

	BOOST_CHECK_EQUAL(Rgb("#123").hex(),        "#112233");
	BOOST_CHECK_EQUAL(Rgb("#1234").hex(),       "#11223344");
	BOOST_CHECK_EQUAL(Rgb(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Rgb("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Rgb(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Rgb(0x654321, 0.6).hex(), "#65432199");
	BOOST_CHECK_EQUAL(Rgb("#65432180").hex(),   "#65432180");
	BOOST_CHECK_SMALL(Rgb("#65432199").alpha() - 0.6, 1E-14);

	BOOST_CHECK_EQUAL(Hsl(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Hsl("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Hsl(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Hsl("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(Hwb(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Hwb("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Hwb(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Hwb("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(Lrgb(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Lrgb("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Lrgb(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Lrgb("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(XyzD50(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(XyzD50("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(XyzD50(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(XyzD50("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(Lab(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Lab("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Lab(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Lab("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(Lch(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Lch("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Lch(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Lch("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(Oklab(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Oklab("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Oklab(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Oklab("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(Oklch(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Oklch("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Oklch(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Oklch("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(Srgb(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Srgb("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Srgb(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Srgb("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(DisplayP3(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(DisplayP3("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(DisplayP3(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(DisplayP3("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(A98Rgb(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(A98Rgb("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(A98Rgb(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(A98Rgb("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(ProphotoRgb(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(ProphotoRgb("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(ProphotoRgb(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(ProphotoRgb("#65432180").hex(),   "#65432180");

	BOOST_CHECK_EQUAL(Rec2020(0x123456).hex(),      "#123456");
	BOOST_CHECK_EQUAL(Rec2020("#123456").hex(),     "#123456");
	BOOST_CHECK_EQUAL(Rec2020(0x654321, 0.5).hex(), "#65432180");
	BOOST_CHECK_EQUAL(Rec2020("#65432180").hex(),   "#65432180");
}

BOOST_AUTO_TEST_CASE(NAME)
{
	BOOST_CHECK_EQUAL(Rgb("#000000").name(),     "black");
	BOOST_CHECK_EQUAL(Rgb("#ffffff").name(),     "white");
	BOOST_CHECK_EQUAL(Rgb("aliceblue").name(),   "aliceblue");
	BOOST_CHECK_EQUAL(Rgb("yellowgreen").name(), "yellowgreen");
	try {
		Rgb("aliceblud").name();
		BOOST_ERROR("failed to parse \"aliceblud\"");
	} catch (const ParseError& e) {
		if (std::string(e.what()) != "aliceblud") {
			BOOST_ERROR("\"" + std::string(e.what()) + "\" != \"aliceblud\"");
		}
	}
	try {
		Rgb("yellowgreeo").name();
		BOOST_ERROR("failed to parse \"yellowgreeo\"");
	} catch (const ParseError& e) {
		if (std::string(e.what()) != "yellowgreeo") {
			BOOST_ERROR("\"" + std::string(e.what()) + "\" != \"yellowgreeo\"");
		}
	}

	BOOST_CHECK_EQUAL(Rgb(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Rgb(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Rgb("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Rgb("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Rgb("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Rgb(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Rgb("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(Hsl(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Hsl(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Hsl("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Hsl("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Hsl("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Hsl(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Hsl("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(Hwb(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Hwb(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Hwb("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Hwb("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Hwb("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Hwb(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Hwb("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(Lrgb(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Lrgb(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Lrgb("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Lrgb("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Lrgb("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Lrgb(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Lrgb("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(XyzD50(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(XyzD50(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(XyzD50("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(XyzD50("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(XyzD50("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(XyzD50(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(XyzD50("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(Lab(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Lab(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Lab("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Lab("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Lab("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Lab(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Lab("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(Lch(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Lch(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Lch("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Lch("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Lch("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Lch(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Lch("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(XyzD65(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(XyzD65(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(XyzD65("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(XyzD65("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(XyzD65("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(XyzD65(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(XyzD65("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(Oklab(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Oklab(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Oklab("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Oklab("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Oklab("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Oklab(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Oklab("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(Oklch(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Oklch(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Oklch("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Oklch("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Oklch("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Oklch(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Oklch("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(Srgb(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Srgb(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Srgb("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Srgb("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Srgb("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Srgb(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Srgb("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(DisplayP3(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(DisplayP3(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(DisplayP3("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(DisplayP3("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(DisplayP3("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(DisplayP3(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(DisplayP3("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(A98Rgb(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(A98Rgb(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(A98Rgb("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(A98Rgb("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(A98Rgb("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(A98Rgb(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(A98Rgb("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(ProphotoRgb(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(ProphotoRgb(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(ProphotoRgb("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(ProphotoRgb("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(ProphotoRgb("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(ProphotoRgb(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(ProphotoRgb("#9370db80").name(),           "#9370db80");

	BOOST_CHECK_EQUAL(Rec2020(Cn::Rebeccapurple).name(),     "#663399");
	BOOST_CHECK_EQUAL(Rec2020(Cn::Mediumpurple).name(),      "mediumpurple");
	BOOST_CHECK_EQUAL(Rec2020("mediumpurple").name(),        "mediumpurple");
	BOOST_CHECK_EQUAL(Rec2020("#9370db").name(),             "mediumpurple");
	BOOST_CHECK_EQUAL(Rec2020("#9370dc").name(),             "#9370dc");
	BOOST_CHECK_EQUAL(Rec2020(Cn::Mediumpurple, 0.5).name(), "#9370db80");
	BOOST_CHECK_EQUAL(Rec2020("#9370db80").name(),           "#9370db80");
}

BOOST_AUTO_TEST_CASE(NAME4)
{
	BOOST_CHECK_EQUAL(Rgb(Cn::Rebeccapurple).name4(),    "rebeccapurple");
	BOOST_CHECK_EQUAL(Hsl(Cn::Rebeccapurple).name4(),    "rebeccapurple");
	BOOST_CHECK_EQUAL(Hwb(Cn::Rebeccapurple).name4(),    "rebeccapurple");
	BOOST_CHECK_EQUAL(Lrgb(Cn::Rebeccapurple).name4(),   "rebeccapurple");
	BOOST_CHECK_EQUAL(XyzD50(Cn::Rebeccapurple).name4(), "rebeccapurple");
	BOOST_CHECK_EQUAL(Lab(Cn::Rebeccapurple).name4(),    "rebeccapurple");
	BOOST_CHECK_EQUAL(Lch(Cn::Rebeccapurple).name4(),    "rebeccapurple");
	BOOST_CHECK_EQUAL(XyzD65(Cn::Rebeccapurple).name4(), "rebeccapurple");
	BOOST_CHECK_EQUAL(Oklab(Cn::Rebeccapurple).name4(),  "rebeccapurple");
	BOOST_CHECK_EQUAL(Oklch(Cn::Rebeccapurple).name4(),  "rebeccapurple");
	BOOST_CHECK_EQUAL(Srgb(Cn::Rebeccapurple).name4(),        "rebeccapurple");
	BOOST_CHECK_EQUAL(DisplayP3(Cn::Rebeccapurple).name4(),   "rebeccapurple");
	BOOST_CHECK_EQUAL(A98Rgb(Cn::Rebeccapurple).name4(),      "rebeccapurple");
	BOOST_CHECK_EQUAL(ProphotoRgb(Cn::Rebeccapurple).name4(), "rebeccapurple");
	BOOST_CHECK_EQUAL(Rec2020(Cn::Rebeccapurple).name4(),     "rebeccapurple");

	BOOST_CHECK_EQUAL(Rgb(Cn::Mediumpurple).name4(),    "mediumpurple");
	BOOST_CHECK_EQUAL(Hsl(Cn::Mediumpurple).name4(),    "mediumpurple");
	BOOST_CHECK_EQUAL(Hwb(Cn::Mediumpurple).name4(),    "mediumpurple");
	BOOST_CHECK_EQUAL(Lrgb(Cn::Mediumpurple).name4(),   "mediumpurple");
	BOOST_CHECK_EQUAL(XyzD50(Cn::Mediumpurple).name4(), "mediumpurple");
	BOOST_CHECK_EQUAL(Lab(Cn::Mediumpurple).name4(),    "mediumpurple");
	BOOST_CHECK_EQUAL(Lch(Cn::Mediumpurple).name4(),    "mediumpurple");
	BOOST_CHECK_EQUAL(XyzD65(Cn::Mediumpurple).name4(), "mediumpurple");
	BOOST_CHECK_EQUAL(Oklab(Cn::Mediumpurple).name4(),  "mediumpurple");
	BOOST_CHECK_EQUAL(Oklch(Cn::Mediumpurple).name4(),  "mediumpurple");
	BOOST_CHECK_EQUAL(Srgb(Cn::Mediumpurple).name4(),        "mediumpurple");
	BOOST_CHECK_EQUAL(DisplayP3(Cn::Mediumpurple).name4(),   "mediumpurple");
	BOOST_CHECK_EQUAL(A98Rgb(Cn::Mediumpurple).name4(),      "mediumpurple");
	BOOST_CHECK_EQUAL(ProphotoRgb(Cn::Mediumpurple).name4(), "mediumpurple");
	BOOST_CHECK_EQUAL(Rec2020(Cn::Mediumpurple).name4(),     "mediumpurple");
}

BOOST_AUTO_TEST_CASE(CSS)
{
	const double d03 = 3.0 / 9.0;
	const double d04 = 4.0 / 9.0;
	const double d05 = 5.0 / 9.0;
	const double d06 = 6.0 / 9.0;

	const double d33 = 300.0 / 9.0;
	const double d44 = 400.0 / 9.0;
	const double d55 = 500.0 / 9.0;

	BOOST_CHECK_EQUAL(Rgb(256, 256, 265, 1.1).css(),       "rgb(255, 255, 255)");
	BOOST_CHECK_EQUAL(Rgb(-1.1, -1.1, -1.1, -1.1).css(),   "rgba(0, 0, 0, 0)");
	BOOST_CHECK_EQUAL(Hsl(101, 101, 101, 1.1).css(),       "hsl(0, 0%, 100%)");
	BOOST_CHECK_EQUAL(Hsl(-1.1, -1.1, -1.1, -1.1).css(),   "hsla(0, 0%, 0%, 0)");
	BOOST_CHECK_EQUAL(Hsl(d33 - 360, d44, d55, d06).css(), "hsla(33, 44%, 56%, .667)");
	BOOST_CHECK_EQUAL(Hsl(d33 + 360, d44, d55, d06).css(), "hsla(33, 44%, 56%, .667)");

	BOOST_CHECK_EQUAL(Rgb(d33, d44, d55, d06).css(),    "rgba(33, 44, 56, .667)");
	BOOST_CHECK_EQUAL(Hsl(d33, d44, d55, d06).css(),    "hsla(33, 44%, 56%, .667)");
	BOOST_CHECK_EQUAL(Hwb(d33, d44, d05, d06).css(),    "hwb(33 44% 1% / .667)");
	BOOST_CHECK_EQUAL(Lrgb(d03, d04, d05, d06).css(),   "color(srgb-linear 0.3333 0.4444 0.5556 / 0.6667)");
	BOOST_CHECK_EQUAL(XyzD50(d03, d04, d05, d06).css(), "color(xyz-d50 0.33333 0.44444 0.55556 / 0.6667)");
	BOOST_CHECK_EQUAL(Lab(d33, d44, d55, d06).css(),    "lab(33.333% 44.444 55.556 / 0.6667)");
	BOOST_CHECK_EQUAL(Lch(d33, d44, d55, d06).css(),    "lch(33.333% 44.444 55.556 / 0.6667)");
	BOOST_CHECK_EQUAL(XyzD65(d03, d04, d05, d06).css(), "color(xyz 0.33333 0.44444 0.55556 / 0.6667)");
	BOOST_CHECK_EQUAL(Oklab(d03, d04, d05, d06).css(),  "oklab(33.333% 0.44444 0.55556 / 0.6667)");
	BOOST_CHECK_EQUAL(Oklch(d03, d04, d55, d06).css(),  "oklch(33.333% 0.44444 55.556 / 0.6667)");
	BOOST_CHECK_EQUAL(Srgb(d03, d04, d05, d06).css(),        "color(srgb 0.3333 0.4444 0.5556 / 0.6667)");
	BOOST_CHECK_EQUAL(DisplayP3(d03, d04, d05, d06).css(),   "color(display-p3 0.3333 0.4444 0.5556 / 0.6667)");
	BOOST_CHECK_EQUAL(A98Rgb(d03, d04, d05, d06).css(),      "color(a98-rgb 0.3333 0.4444 0.5556 / 0.6667)");
	BOOST_CHECK_EQUAL(ProphotoRgb(d03, d04, d05, d06).css(), "color(prophoto-rgb 0.3333 0.4444 0.5556 / 0.6667)");
	BOOST_CHECK_EQUAL(Rec2020(d03, d04, d05, d06).css(),     "color(rec2020 0.3333 0.4444 0.5556 / 0.6667)");

	BOOST_CHECK_EQUAL(Rgb(60, 50, 40).css(),       "rgb(60, 50, 40)");
	BOOST_CHECK_EQUAL(Hsl(60, 50, 40).css(),       "hsl(60, 50%, 40%)");
	BOOST_CHECK_EQUAL(Hwb(60, 50, 0.4).css(),      "hwb(60 50% 0%)");
	BOOST_CHECK_EQUAL(Lrgb(0.6, 0.5, 0.4).css(),   "color(srgb-linear 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(XyzD50(0.6, 0.5, 0.4).css(), "color(xyz-d50 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(Lab(60, 50, 40).css(),       "lab(60% 50 40)");
	BOOST_CHECK_EQUAL(Lch(60, 50, 40).css(),       "lch(60% 50 40)");
	BOOST_CHECK_EQUAL(XyzD65(0.6, 0.5, 0.4).css(), "color(xyz 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(Oklab(0.6, 0.5, 0.4).css(),  "oklab(60% 0.5 0.4)");
	BOOST_CHECK_EQUAL(Oklch(0.6, 0.5, 40).css(),   "oklch(60% 0.5 40)");
	BOOST_CHECK_EQUAL(Srgb(0.6, 0.5, 0.4).css(),        "color(srgb 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(DisplayP3(0.6, 0.5, 0.4).css(),   "color(display-p3 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(A98Rgb(0.6, 0.5, 0.4).css(),      "color(a98-rgb 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(ProphotoRgb(0.6, 0.5, 0.4).css(), "color(prophoto-rgb 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(Rec2020(0.6, 0.5, 0.4).css(),     "color(rec2020 0.6 0.5 0.4)");
}

BOOST_AUTO_TEST_CASE(CSSF)
{
	const double d03 = 3.0 / 9.0;
	const double d04 = 4.0 / 9.0;
	const double d05 = 5.0 / 9.0;
	const double d06 = 6.0 / 9.0;

	const double d33 = 300.0 / 9.0;
	const double d44 = 400.0 / 9.0;
	const double d55 = 500.0 / 9.0;

	BOOST_CHECK_EQUAL(Rgb(256, 256, 256, 1.01).cssf(),        "rgb(255, 255, 255)");
	BOOST_CHECK_EQUAL(Rgb(-1.01, -1.01, -1.01, -0.01).cssf(), "rgba(0, 0, 0, 0)");
	BOOST_CHECK_EQUAL(Hsl(101, 101, 101, 1.01).cssf(),        "hsl(0, 0%, 100%)");
	BOOST_CHECK_EQUAL(Hsl(-1.01, -1.01, -1.01, -1.01).cssf(), "hsla(0, 0%, 0%, 0)");
	BOOST_CHECK_EQUAL(Hsl(d33 - 360, d44, d55, d06).cssf(),   "hsla(33.3, 44.4%, 55.6%, .6667)");
	BOOST_CHECK_EQUAL(Hsl(d33 + 360, d44, d55, d06).cssf(),   "hsla(33.3, 44.4%, 55.6%, .6667)");

	BOOST_CHECK_EQUAL(Rgb(d33, d44, d55, d06).cssf(),    "rgba(33.3, 44.4, 55.6, .6667)");
	BOOST_CHECK_EQUAL(Hsl(d33, d44, d55, d06).cssf(),    "hsla(33.3, 44.4%, 55.6%, .6667)");
	BOOST_CHECK_EQUAL(Hwb(d33, d44, d05, d06).cssf(),    "hwb(33.3 44.4% 0.6% / .6667)");
	BOOST_CHECK_EQUAL(Lrgb(d03, d04, d05, d06).cssf(),   "color(srgb-linear 0.33333 0.44444 0.55556 / 0.66667)");
	BOOST_CHECK_EQUAL(XyzD50(d03, d04, d05, d06).cssf(), "color(xyz-d50 0.333333 0.444444 0.555556 / 0.66667)");
	BOOST_CHECK_EQUAL(Lab(d33, d44, d55, d06).cssf(),    "lab(33.3333% 44.4444 55.5556 / 0.66667)");
	BOOST_CHECK_EQUAL(Lch(d33, d44, d55, d06).cssf(),    "lch(33.3333% 44.4444 55.5556 / 0.66667)");
	BOOST_CHECK_EQUAL(XyzD65(d03, d04, d05, d06).cssf(), "color(xyz 0.333333 0.444444 0.555556 / 0.66667)");
	BOOST_CHECK_EQUAL(Oklab(d03, d04, d05, d06).cssf(),  "oklab(33.3333% 0.444444 0.555556 / 0.66667)");
	BOOST_CHECK_EQUAL(Oklch(d03, d04, d55, d06).cssf(),  "oklch(33.3333% 0.444444 55.5556 / 0.66667)");
	BOOST_CHECK_EQUAL(Srgb(d03, d04, d05, d06).cssf(),        "color(srgb 0.33333 0.44444 0.55556 / 0.66667)");
	BOOST_CHECK_EQUAL(DisplayP3(d03, d04, d05, d06).cssf(),   "color(display-p3 0.33333 0.44444 0.55556 / 0.66667)");
	BOOST_CHECK_EQUAL(A98Rgb(d03, d04, d05, d06).cssf(),      "color(a98-rgb 0.33333 0.44444 0.55556 / 0.66667)");
	BOOST_CHECK_EQUAL(ProphotoRgb(d03, d04, d05, d06).cssf(), "color(prophoto-rgb 0.33333 0.44444 0.55556 / 0.66667)");
	BOOST_CHECK_EQUAL(Rec2020(d03, d04, d05, d06).cssf(),     "color(rec2020 0.33333 0.44444 0.55556 / 0.66667)");

	BOOST_CHECK_EQUAL(Rgb(60, 50, 40).cssf(),       "rgb(60, 50, 40)");
	BOOST_CHECK_EQUAL(Hsl(60, 50, 40).cssf(),       "hsl(60, 50%, 40%)");
	BOOST_CHECK_EQUAL(Hwb(60, 50, 0.4).cssf(),       "hwb(60 50% 0.4%)");
	BOOST_CHECK_EQUAL(Lrgb(0.6, 0.5, 0.4).cssf(),   "color(srgb-linear 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(XyzD50(0.6, 0.5, 0.4).cssf(), "color(xyz-d50 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(Lab(60, 50, 40).cssf(),       "lab(60% 50 40)");
	BOOST_CHECK_EQUAL(Lch(60, 50, 40).cssf(),       "lch(60% 50 40)");
	BOOST_CHECK_EQUAL(XyzD65(0.6, 0.5, 0.4).cssf(), "color(xyz 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(Oklab(0.6, 0.5, 0.4).cssf(),  "oklab(60% 0.5 0.4)");
	BOOST_CHECK_EQUAL(Oklch(0.6, 0.5, 40).cssf(),   "oklch(60% 0.5 40)");
	BOOST_CHECK_EQUAL(Srgb(0.6, 0.5, 0.4).cssf(),        "color(srgb 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(DisplayP3(0.6, 0.5, 0.4).cssf(),   "color(display-p3 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(A98Rgb(0.6, 0.5, 0.4).cssf(),      "color(a98-rgb 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(ProphotoRgb(0.6, 0.5, 0.4).cssf(), "color(prophoto-rgb 0.6 0.5 0.4)");
	BOOST_CHECK_EQUAL(Rec2020(0.6, 0.5, 0.4).cssf(),     "color(rec2020 0.6 0.5 0.4)");
}

BOOST_AUTO_TEST_CASE(CSSP)
{
	const double d03 = 3.0 / 9.0;
	const double d04 = 4.0 / 9.0;
	const double d05 = 5.0 / 9.0;
	const double d06 = 6.0 / 9.0;

	const double d33 = 300.0 / 9.0;
	const double d44 = 400.0 / 9.0;
	const double d55 = 500.0 / 9.0;
	const double d66 = 600.0 / 9.0;

	BOOST_CHECK_EQUAL(Rgb(255 * d06, 255 * d05, 255 * d04, d03).cssp(), "rgb(66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(Hsl(d66, d55, d44, d03).cssp(),                   "hsl(66.67 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(Hwb(d66, d55, d04, d03).cssp(),                   "hwb(66.67 55.556% 0.444% / 33.333%)");
	BOOST_CHECK_EQUAL(Lrgb(d06, d05, d04, d03).cssp(),                  "color(srgb-linear 66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(XyzD50(d06, d05, d04, d03).cssp(),                "color(xyz-d50 66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(Lab(d66, 125 * d05, 125 * d04, d03).cssp(),       "lab(66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(Lch(d66, 150 * d05, d44, d03).cssp(),             "lch(66.667% 55.556% 44.44 / 33.333%)");
	BOOST_CHECK_EQUAL(XyzD65(d06, d05, d04, d03).cssp(),                "color(xyz 66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(Oklab(d06, 0.4 * d05, 0.4 * d04, d03).cssp(),     "oklab(66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(Oklch(d06, 0.4 * d05, d44, d03).cssp(),           "oklch(66.667% 55.556% 44.44 / 33.333%)");
	BOOST_CHECK_EQUAL(Srgb(d06, d05, d04, d03).cssp(),                  "color(srgb 66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(DisplayP3(d06, d05, d04, d03).cssp(),             "color(display-p3 66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(A98Rgb(d06, d05, d04, d03).cssp(),                "color(a98-rgb 66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(ProphotoRgb(d06, d05, d04, d03).cssp(),           "color(prophoto-rgb 66.667% 55.556% 44.444% / 33.333%)");
	BOOST_CHECK_EQUAL(Rec2020(d06, d05, d04, d03).cssp(),               "color(rec2020 66.667% 55.556% 44.444% / 33.333%)");
}

BOOST_AUTO_TEST_CASE(READ_STRING)
{
	const char* a_rgb      = "rgba(33.3, 44.4, 55.6, .6667)";
	const char* a_rgb_2    = "rgb(33.3,44.4,55.6,0.6667)";
	const char* a_rgb_3    = "rgb(33.3 44.4 55.6/.6667)";
	const char* a_rgb_4    = " rgba(   33.3,44.4, 55.6  , .6667   )  ";
	const char* a_rgb_5    = " rgba(   33.3 44.4  55.6  / .6667   )  ";
	const char* a_hsl      = "hsla(33.3, 44.4%, 55.6%, .6667)";
	const char* a_hsl_2    = "hsl(33.3, 44.4%, 55.6%, .6667)";
	const char* a_hwb      = "hwb(33.3 44.4% 0.6% / .6667)";
	const char* a_lrgb     = "color(srgb-linear 0.33333 0.44444 0.55556 / 0.66667)";
	const char* a_xyzD50   = "color(xyz-d50 0.333333 0.444444 0.555556 / 0.66667)";
	const char* a_lab      = "lab(33.3333% 44.4444 55.5556 / 0.66667)";
	const char* a_lab_2    = "lab(33.3333 44.4444 55.5556 / 0.66667)";
	const char* a_lch      = "lch(33.3333% 44.4444 55.5556 / 0.66667)";
	const char* a_lch_2    = "lch(33.3333 44.4444 55.5556 / 0.66667)";
	const char* a_xyzD65   = "color(xyz 0.333333 0.444444 0.555556 / 0.66667)";
	const char* a_xyzD65_2 = "color(xyz-d65 0.333333 0.444444 0.555556 / 0.66667)";
	const char* a_oklab    = "oklab(33.3333% 0.444444 0.555556 / 0.66667)";
	const char* a_oklab_2  = "oklab(0.333333 0.444444 0.555556 / 0.66667)";
	const char* a_oklch    = "oklch(33.3333% 0.444444 55.5556 / 0.66667)";
	const char* a_oklch_2  = "oklch(0.333333 0.444444 55.5556 / 0.66667)";
	const char* a_srgb        = "color(srgb 0.33333 0.44444 0.55556 / 0.66667)";
	const char* a_displayP3   = "color(display-p3 0.33333 0.44444 0.55556 / 0.66667)";
	const char* a_a98Rgb      = "color(a98-rgb 0.33333 0.44444 0.55556 / 0.66667)";
	const char* a_prophotoRgb = "color(prophoto-rgb 0.33333 0.44444 0.55556 / 0.66667)";
	const char* a_rec2020     = "color(rec2020 0.33333 0.44444 0.55556 / 0.66667)";
	BOOST_CHECK_EQUAL(Rgb(a_rgb).cssf(),         a_rgb);
	BOOST_CHECK_EQUAL(Rgb(a_rgb_2).cssf(),       a_rgb);
	BOOST_CHECK_EQUAL(Rgb(a_rgb_3).cssf(),       a_rgb);
	BOOST_CHECK_EQUAL(Rgb(a_rgb_4).cssf(),       a_rgb);
	BOOST_CHECK_EQUAL(Rgb(a_rgb_5).cssf(),       a_rgb);
	BOOST_CHECK_EQUAL(Hsl(a_hsl).cssf(),         a_hsl);
	BOOST_CHECK_EQUAL(Hsl(a_hsl_2).cssf(),       a_hsl);
	BOOST_CHECK_EQUAL(Hwb(a_hwb).cssf(),         a_hwb);
	BOOST_CHECK_EQUAL(Lrgb(a_lrgb).cssf(),       a_lrgb);
	BOOST_CHECK_EQUAL(XyzD50(a_xyzD50).cssf(),   a_xyzD50);
	BOOST_CHECK_EQUAL(Lab(a_lab).cssf(),         a_lab);
	BOOST_CHECK_EQUAL(Lab(a_lab_2).cssf(),       a_lab);
	BOOST_CHECK_EQUAL(Lch(a_lch).cssf(),         a_lch);
	BOOST_CHECK_EQUAL(Lch(a_lch_2).cssf(),       a_lch);
	BOOST_CHECK_EQUAL(XyzD65(a_xyzD65).cssf(),   a_xyzD65);
	BOOST_CHECK_EQUAL(XyzD65(a_xyzD65_2).cssf(), a_xyzD65);
	BOOST_CHECK_EQUAL(Oklab(a_oklab).cssf(),     a_oklab);
	BOOST_CHECK_EQUAL(Oklab(a_oklab_2).cssf(),   a_oklab);
	BOOST_CHECK_EQUAL(Oklch(a_oklch).cssf(),     a_oklch);
	BOOST_CHECK_EQUAL(Oklch(a_oklch_2).cssf(),   a_oklch);
	BOOST_CHECK_EQUAL(Srgb(a_srgb).cssf(),               a_srgb);
	BOOST_CHECK_EQUAL(DisplayP3(a_displayP3).cssf(),     a_displayP3);
	BOOST_CHECK_EQUAL(A98Rgb(a_a98Rgb).cssf(),           a_a98Rgb);
	BOOST_CHECK_EQUAL(ProphotoRgb(a_prophotoRgb).cssf(), a_prophotoRgb);
	BOOST_CHECK_EQUAL(Rec2020(a_rec2020).cssf(),         a_rec2020);

	const char* b_rgb =    "rgb(66.667% 55.556% 44.444% / 33.333%)";
	const char* b_hsl =    "hsl(66.67 55.556% 44.444% / 33.333%)";
	const char* b_hwb =    "hwb(66.67 55.556% 0.444% / 33.333%)";
	const char* b_lrgb =   "color(srgb-linear 66.667% 55.556% 44.444% / 33.333%)";
	const char* b_xyzD50 = "color(xyz-d50 66.667% 55.556% 44.444% / 33.333%)";
	const char* b_lab =    "lab(66.667% 55.556% 44.444% / 33.333%)";
	const char* b_lch =    "lch(66.667% 55.556% 44.44 / 33.333%)";
	const char* b_xyzD65 = "color(xyz 66.667% 55.556% 44.444% / 33.333%)";
	const char* b_oklab =  "oklab(66.667% 55.556% 44.444% / 33.333%)";
	const char* b_oklch =  "oklch(66.667% 55.556% 44.44 / 33.333%)";
	const char* b_srgb =        "color(srgb 66.667% 55.556% 44.444% / 33.333%)";
	const char* b_displayP3 =   "color(display-p3 66.667% 55.556% 44.444% / 33.333%)";
	const char* b_a98Rgb =      "color(a98-rgb 66.667% 55.556% 44.444% / 33.333%)";
	const char* b_prophotoRgb = "color(prophoto-rgb 66.667% 55.556% 44.444% / 33.333%)";
	const char* b_rec2020 =     "color(rec2020 66.667% 55.556% 44.444% / 33.333%)";
	BOOST_CHECK_EQUAL(Rgb(b_rgb).cssp(),       b_rgb);
	BOOST_CHECK_EQUAL(Hsl(b_hsl).cssp(),       b_hsl);
	BOOST_CHECK_EQUAL(Hwb(b_hwb).cssp(),       b_hwb);
	BOOST_CHECK_EQUAL(Lrgb(b_lrgb).cssp(),     b_lrgb);
	BOOST_CHECK_EQUAL(XyzD50(b_xyzD50).cssp(), b_xyzD50);
	BOOST_CHECK_EQUAL(Lab(b_lab).cssp(),       b_lab);
	BOOST_CHECK_EQUAL(Lch(b_lch).cssp(),       b_lch);
	BOOST_CHECK_EQUAL(XyzD65(b_xyzD65).cssp(), b_xyzD65);
	BOOST_CHECK_EQUAL(Oklab(b_oklab).cssp(),   b_oklab);
	BOOST_CHECK_EQUAL(Oklch(b_oklch).cssp(),   b_oklch);
	BOOST_CHECK_EQUAL(Srgb(b_srgb).cssp(),               b_srgb);
	BOOST_CHECK_EQUAL(DisplayP3(b_displayP3).cssp(),     b_displayP3);
	BOOST_CHECK_EQUAL(A98Rgb(b_a98Rgb).cssp(),           b_a98Rgb);
	BOOST_CHECK_EQUAL(ProphotoRgb(b_prophotoRgb).cssp(), b_prophotoRgb);
	BOOST_CHECK_EQUAL(Rec2020(b_rec2020).cssp(),         b_rec2020);

	const char* c_rgb =      "rgb(33.3, 44.4, 55.6)";
	const char* c_rgb_2 =    "rgb(33.3,44.4,55.6)";
	const char* c_rgb_3 =    "rgb(33.3 44.4 55.6)";
	const char* c_rgb_4 =    " rgba(   33.3,44.4, 55.6   )  ";
	const char* c_rgb_5 =    " rgba(   33.3 44.4  55.6   )  ";
	const char* c_hsl =      "hsla(33.3, 44.4%, 55.6%)";
	const char* c_hsl_2 =    "hsl(33.3, 44.4%, 55.6%)";
	const char* c_hwb =      "hwb(33.3 44.4% 0.6%)";
	const char* c_lrgb =     "color(srgb-linear 0.33333 0.44444 0.55556)";
	const char* c_xyzD50 =   "color(xyz-d50 0.333333 0.444444 0.555556)";
	const char* c_lab =      "lab(33.3333% 44.4444 55.5556)";
	const char* c_lch =      "lch(33.3333% 44.4444 55.5556)";
	const char* c_xyzD65 =   "color(xyz 0.333333 0.444444 0.555556)";
	const char* c_xyzD65_2 = "color(xyz-d65 0.333333 0.444444 0.555556)";
	const char* c_oklab =    "oklab(33.3333% 0.444444 0.555556)";
	const char* c_oklch =    "oklch(33.3333% 0.444444 55.5556)";
	const char* c_srgb =        "color(srgb 0.33333 0.44444 0.55556)";
	const char* c_displayP3 =   "color(display-p3 0.33333 0.44444 0.55556)";
	const char* c_a98Rgb =      "color(a98-rgb 0.33333 0.44444 0.55556)";
	const char* c_prophotoRgb = "color(prophoto-rgb 0.33333 0.44444 0.55556)";
	const char* c_rec2020 =     "color(rec2020 0.33333 0.44444 0.55556)";
	BOOST_CHECK_EQUAL(Rgb(c_rgb).cssf(),         c_rgb);
	BOOST_CHECK_EQUAL(Rgb(c_rgb_2).cssf(),       c_rgb);
	BOOST_CHECK_EQUAL(Rgb(c_rgb_3).cssf(),       c_rgb);
	BOOST_CHECK_EQUAL(Rgb(c_rgb_4).cssf(),       c_rgb);
	BOOST_CHECK_EQUAL(Rgb(c_rgb_5).cssf(),       c_rgb);
	BOOST_CHECK_EQUAL(Hsl(c_hsl).cssf(),         c_hsl_2);
	BOOST_CHECK_EQUAL(Hsl(c_hsl_2).cssf(),       c_hsl_2);
	BOOST_CHECK_EQUAL(Hwb(c_hwb).cssf(),         c_hwb);
	BOOST_CHECK_EQUAL(Lrgb(c_lrgb).cssf(),       c_lrgb);
	BOOST_CHECK_EQUAL(XyzD50(c_xyzD50).cssf(),   c_xyzD50);
	BOOST_CHECK_EQUAL(Lab(c_lab).cssf(),         c_lab);
	BOOST_CHECK_EQUAL(Lch(c_lch).cssf(),         c_lch);
	BOOST_CHECK_EQUAL(XyzD65(c_xyzD65).cssf(),   c_xyzD65);
	BOOST_CHECK_EQUAL(XyzD65(c_xyzD65_2).cssf(), c_xyzD65);
	BOOST_CHECK_EQUAL(Oklab(c_oklab).cssf(),     c_oklab);
	BOOST_CHECK_EQUAL(Oklch(c_oklch).cssf(),     c_oklch);
	BOOST_CHECK_EQUAL(Srgb(c_srgb).cssf(),               c_srgb);
	BOOST_CHECK_EQUAL(DisplayP3(c_displayP3).cssf(),     c_displayP3);
	BOOST_CHECK_EQUAL(A98Rgb(c_a98Rgb).cssf(),           c_a98Rgb);
	BOOST_CHECK_EQUAL(ProphotoRgb(c_prophotoRgb).cssf(), c_prophotoRgb);
	BOOST_CHECK_EQUAL(Rec2020(c_rec2020).cssf(),         c_rec2020);

	BOOST_CHECK_EQUAL(Rgb("rgb(-12, -34, -45)").vec(), "(-12, -34, -45)");
	BOOST_CHECK_EQUAL(Rgb("rgb(-12 -34 -45)").vec(),   "(-12, -34, -45)");
	BOOST_CHECK_EQUAL(Rgb("rgb(-.87, -.65, -.45, -.12)").vec(), "(-0.87, -0.65, -0.45, 0)");
	BOOST_CHECK_SMALL(Rgb("rgb(-.87, -.65, -.45, -.12)").alpha() - (-0.12), 1E-10);
	BOOST_CHECK_EQUAL(Rgb("rgb(-.87 -.65 -.45 / -.12)").vec(),  "(-0.87, -0.65, -0.45, 0)");
	BOOST_CHECK_SMALL(Rgb("rgb(-.87 -.65 -.45 / -.12)").alpha() - (-0.12), 1E-10);

	BOOST_CHECK_EQUAL(Hsl("hsl(45deg, 45%, 45%)").cssf(),        "hsl(45, 45%, 45%)");
	BOOST_CHECK_EQUAL(Hsl("hsl(50grad, 45%, 45%)").cssf(),       "hsl(45, 45%, 45%)");
	BOOST_CHECK_EQUAL(Hsl("hsl(0.125turn, 45%, 45%)").cssf(),    "hsl(45, 45%, 45%)");
	BOOST_CHECK_EQUAL(Hsl("hsl(0.7853982rad, 45%, 45%)").cssf(), "hsl(45, 45%, 45%)");
	BOOST_CHECK_EQUAL(Lch("lch(45 45 -45deg)").cssf(),           "lch(45% 45 -45)");
	BOOST_CHECK_EQUAL(Lch("lch(45 45 -50grad)").cssf(),          "lch(45% 45 -45)");
	BOOST_CHECK_EQUAL(Lch("lch(45 45 -0.125turn)").cssf(),       "lch(45% 45 -45)");
	BOOST_CHECK_EQUAL(Lch("lch(45 45 -0.7853982rad)").cssf(),    "lch(45% 45 -45)");
	BOOST_CHECK_EQUAL(Oklch("oklch(0 0 210deg)").cssf(),         "oklch(0% 0 210)");
	BOOST_CHECK_EQUAL(Oklch("oklch(0 0 233.3333grad)").cssf(),   "oklch(0% 0 210)");
	BOOST_CHECK_EQUAL(Oklch("oklch(0 0 0.5833333turn)").cssf(),  "oklch(0% 0 210)");
	BOOST_CHECK_EQUAL(Oklch("oklch(0 0 3.6651914rad)").cssf(),   "oklch(0% 0 210)");
}

BOOST_AUTO_TEST_CASE(READ_TO_CONVERT)
{
	BOOST_CHECK_EQUAL(Rgb("color(rec2020 0.691948 0.685032 0.410996)").name(),         "darkkhaki");
	BOOST_CHECK_EQUAL(Hsl("rgb(189 183 107)").name(),                                  "darkkhaki");
	BOOST_CHECK_EQUAL(Hwb("hsl(55.609756 38.317757% 58.039216%)").name(),              "darkkhaki");
	BOOST_CHECK_EQUAL(Lrgb("hwb(55.609756 41.960784% 25.882353%)").name(),             "darkkhaki");
	BOOST_CHECK_EQUAL(XyzD50("color(srgb-linear 0.508881 0.473531 0.147027)").name(),  "darkkhaki");
	BOOST_CHECK_EQUAL(Lab("color(xyz-d50 0.42532 0.4616 0.15805)").name(),             "darkkhaki");
	BOOST_CHECK_EQUAL(Lch("lab(73.649 -5.816 39.278)").name(),                         "darkkhaki");
	BOOST_CHECK_EQUAL(XyzD65("lch(73.649 39.707 98.423)").name(),                      "darkkhaki");
	BOOST_CHECK_EQUAL(Oklab("color(xyz 0.405721 0.457477 0.206034)").name(),           "darkkhaki");
	BOOST_CHECK_EQUAL(Oklch("oklab(0.767474 -0.024571 0.09491)").name(),               "darkkhaki");
	BOOST_CHECK_EQUAL(Srgb("oklch(0.767474 0.098039 104.515)").name(),                 "darkkhaki");
	BOOST_CHECK_EQUAL(DisplayP3("color(srgb 0.741176 0.717647 0.419608)").name(),      "darkkhaki");
	BOOST_CHECK_EQUAL(A98Rgb("color(display-p3 0.73707 0.718444 0.457568)").name(),    "darkkhaki");
	BOOST_CHECK_EQUAL(ProphotoRgb("color(a98-rgb 0.728869 0.711834 0.435194)").name(), "darkkhaki");
	BOOST_CHECK_EQUAL(Rec2020("color(prophoto-rgb 0.63881 0.6557 0.39927)").name(),    "darkkhaki");
}

BOOST_AUTO_TEST_CASE(WRONG_STRING)
{
	BOOST_CHECK_THROW(Rgb("transparent"),             ParseError);
	BOOST_CHECK_THROW(Rgb("currentcolor"),            ParseError);
	BOOST_CHECK_THROW(Rgb("LinkText"),                ParseError);
	BOOST_CHECK_THROW(Rgb("rgb (255, 255, 255)"),     ParseError);
	BOOST_CHECK_THROW(Rgb("rgb(255 255 255deg)"),     ParseError);
	BOOST_CHECK_THROW(Rgb("rgb(255, , 255)"),         ParseError);
	BOOST_CHECK_THROW(Rgb("rgb(255, 255 255)"),       ParseError);
	BOOST_CHECK_THROW(Rgb("rgb(255 255 255 0.5)"),    ParseError);
	BOOST_CHECK_THROW(Rgb("rgb(255 255 255, 0.5)"),   ParseError);
	BOOST_CHECK_THROW(Rgb("rgb(255, 255, 255 / .5)"), ParseError);
	BOOST_CHECK_THROW(Rgb("rgb(255, 100%, 255)"),     ParseError);
	BOOST_CHECK_THROW(Hsl("hsl(10, 10, 10)"),         ParseError);
	BOOST_CHECK_THROW(Hsl("hsl(10 deg, 10%, 10%)"),   ParseError);
	BOOST_CHECK_THROW(Hsl("hsl(10, 10%, 10 %)"),      ParseError);
	BOOST_CHECK_THROW(Hwb("hwb(10 10 10)"),           ParseError);
	BOOST_CHECK_THROW(Hwb("hwb(10, 10%, 10%)"),       ParseError);
	BOOST_CHECK_THROW(Lab("lab(0.1, 0.1, 0.1)"),      ParseError);
	BOOST_CHECK_THROW(Lch("lch(0.1, 0.1, 0.1)"),      ParseError);
	BOOST_CHECK_THROW(Oklab("oklab(0.1, 0.1, 0.1)"),  ParseError);
	BOOST_CHECK_THROW(Oklch("oklch(0.1, 0.1, 0.1)"),  ParseError);
}
