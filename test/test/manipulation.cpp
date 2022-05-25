#include "pch.h"

#include <boost/test/unit_test.hpp>


using namespace colorm;

BOOST_AUTO_TEST_CASE(IS_DISPLAYABALE)
{
	Rgb rgbT[3] = {
		{255, 255, 255}, {100, 100, 100}, {0, 0, 0}
	};
	Rgb rgbF[6] = {
		{-1.0E-10, 0, 0}, {0, -1.0E-10, 0}, {0, 0, -1.0E-10},
		{255 + 1.0E-8, 0, 0}, {0, 255 + 1.0E-8, 0}, {0, 0, 255 + 1.0E-8}
	};
	for (const auto& rgb : rgbT) {
		BOOST_CHECK(rgb.isDisplayable());
		BOOST_CHECK(Hwb(rgb).isDisplayable());
		BOOST_CHECK(Lrgb(rgb).isDisplayable());
		BOOST_CHECK(XyzD50(rgb).isDisplayable());
		BOOST_CHECK(Lab(rgb).isDisplayable());
		BOOST_CHECK(Lch(rgb).isDisplayable());
		BOOST_CHECK(XyzD65(rgb).isDisplayable());
		BOOST_CHECK(Oklab(rgb).isDisplayable());
		BOOST_CHECK(Oklch(rgb).isDisplayable());
		BOOST_CHECK(Srgb(rgb).isDisplayable());
		BOOST_CHECK(DisplayP3(rgb).isDisplayable());
		BOOST_CHECK(A98Rgb(rgb).isDisplayable());
		BOOST_CHECK(ProphotoRgb(rgb).isDisplayable());
		BOOST_CHECK(Rec2020(rgb).isDisplayable());
	}
	for (const auto& rgb : rgbF) {
		BOOST_CHECK(!rgb.isDisplayable());
		BOOST_CHECK(!Hwb(rgb).isDisplayable());
		BOOST_CHECK(!Lrgb(rgb).isDisplayable());
		BOOST_CHECK(!XyzD50(rgb).isDisplayable());
		BOOST_CHECK(!Lab(rgb).isDisplayable());
		BOOST_CHECK(!Lch(rgb).isDisplayable());
		BOOST_CHECK(!XyzD65(rgb).isDisplayable());
		BOOST_CHECK(!Oklab(rgb).isDisplayable());
		BOOST_CHECK(!Oklch(rgb).isDisplayable());
		BOOST_CHECK(!Srgb(rgb).isDisplayable());
		BOOST_CHECK(!DisplayP3(rgb).isDisplayable());
		BOOST_CHECK(!A98Rgb(rgb).isDisplayable());
		BOOST_CHECK(!ProphotoRgb(rgb).isDisplayable());
		BOOST_CHECK(!Rec2020(rgb).isDisplayable());
	}

	BOOST_CHECK(Hsl(0, 0, 0).isDisplayable());
	BOOST_CHECK(Hsl(0, 0, 100).isDisplayable());
	BOOST_CHECK(Hsl(0, 100, 100).isDisplayable());
	BOOST_CHECK(Hsl(1000, 0, 0).isDisplayable());
	BOOST_CHECK(Hsl(-1000, 0, 100).isDisplayable());
	BOOST_CHECK(!Hsl(0, 0, -1).isDisplayable());
	BOOST_CHECK(!Hsl(0, 0, 101).isDisplayable());
	BOOST_CHECK(!Hsl(0, -1, 100).isDisplayable());
	BOOST_CHECK(!Hsl(0, 101, 100).isDisplayable());
}

BOOST_AUTO_TEST_CASE(HAS_POWERLESS_HUE)
{
	BOOST_CHECK(Hsl(100, 50, 0).hasPowerlessHue());
	BOOST_CHECK(Hsl(100, 50, 100).hasPowerlessHue());
	BOOST_CHECK(Hsl(100, 0, 50).hasPowerlessHue());
	BOOST_CHECK(!Hsl(100, 100, 50).hasPowerlessHue());
	BOOST_CHECK(!Hsl(100, 50, 0.1).hasPowerlessHue());
	BOOST_CHECK(!Hsl(100, 50, 99.9).hasPowerlessHue());
	BOOST_CHECK(!Hsl(100, 0.1, 50).hasPowerlessHue());
	BOOST_CHECK(!Hsl(100, 99.9, 50).hasPowerlessHue());

	BOOST_CHECK(Hwb(100, 10, 90).hasPowerlessHue());
	BOOST_CHECK(Hwb(100, 90, 10).hasPowerlessHue());
	BOOST_CHECK(!Hwb(100, 10, 89.9).hasPowerlessHue());
	BOOST_CHECK(!Hwb(100, 89.9, 10).hasPowerlessHue());

	BOOST_CHECK(Lch(50, 0, 100).hasPowerlessHue());
	BOOST_CHECK(!Lch(50, 0.1, 100).hasPowerlessHue());

	BOOST_CHECK(Oklch(50, 0, 100).hasPowerlessHue());
	BOOST_CHECK(!Oklch(50, 0.1, 100).hasPowerlessHue());
}

BOOST_AUTO_TEST_CASE(CLIP)
{
	BOOST_CHECK(Rgb(-1, 50, 300, -1).clip()  == Rgb(0, 50, 255, 0));
	BOOST_CHECK(Rgb(50, 300, -1, 1.1).clip() == Rgb(50, 255, 0));

	BOOST_CHECK(Hsl(-1, 50, 300, -1).clip()  == Hsl(0, 0, 100, 0));
	BOOST_CHECK(Hsl(300, -1, 50, 0).clip()   == Hsl(0, 0, 50, 0));
	BOOST_CHECK(Hsl(50, 300, -1, 1.1).clip() == Hsl(0, 0, 0));
	BOOST_CHECK(Hsl(300, 300, 300).clip()    == Hsl(0, 0, 100));
	BOOST_CHECK(Hsl(-1, 50, 10).clip()       == Hsl(359, 50, 10));
	BOOST_CHECK(Hsl(361, 101, 10).clip()     == Hsl(1, 100, 10));

	BOOST_CHECK(Hwb(50, 25, 100, -1).clip()   == Hwb(0, 20, 80, 0));
	BOOST_CHECK(Hwb(50, -10, -10, 1.1).clip() == Hwb(50, 0, 0));
	BOOST_CHECK(Hwb(300, 300, 0).clip()       == Hwb(0, 100, 0));
	BOOST_CHECK(Hwb(300, 0, 300).clip()       == Hwb(0, 0, 100));
	BOOST_CHECK(Hwb(-1, 25, 25).clip()        == Hwb(359, 25, 25));
	BOOST_CHECK(Hwb(361, 25, 25).clip()       == Hwb(1, 25, 25));

	BOOST_CHECK(Lrgb(-1, 0.2, 1.1, -1).clip()    == Lrgb(0, 0.2, 1.1, 0));
	BOOST_CHECK(Lrgb(1.1, -1, 0.2, 1.1).clip()   == Lrgb(1.1, 0, 0.2));
	BOOST_CHECK(Lrgb(0.2, 1.1, -1, 1.1).clip()   == Lrgb(0.2, 1.1, 0));

	BOOST_CHECK(XyzD50(-1, 0.2, 1.1, -1).clip()  == XyzD50(-1, 0.2, 1.1, 0));
	BOOST_CHECK(XyzD50(1.1, -1, 0.2, 1.1).clip() == XyzD50(1.1, 0, 0.2));
	BOOST_CHECK(XyzD50(0.2, 1.1, -1, 1.1).clip() == XyzD50(0.2, 1.1, -1));

	BOOST_CHECK(Lab(-100, 20, 101, -1).clip()    == Lab(0, 20, 101, 0));
	BOOST_CHECK(Lab(101, -100, 20, 1.1).clip()   == Lab(101, -100, 20));
	BOOST_CHECK(Lab(20, 101, -100, 1.1).clip()   == Lab(20, 101, -100));

	BOOST_CHECK(Lch(-100, 20, 101, -1).clip()    == Lch(0, 20, 101, 0));
	BOOST_CHECK(Lch(101, -100, 20, 1.1).clip()   == Lch(101, 0, 0));
	BOOST_CHECK(Lch(20, 101, -100, 1.1).clip()   == Lch(20, 101, 260));

	BOOST_CHECK(XyzD65(-1, 0.2, 1.1, -1).clip()  == XyzD65(-1, 0.2, 1.1, 0));
	BOOST_CHECK(XyzD65(1.1, -1, 0.2, 1.1).clip() == XyzD65(1.1, 0, 0.2));
	BOOST_CHECK(XyzD65(0.2, 1.1, -1, 1.1).clip() == XyzD65(0.2, 1.1, -1));

	BOOST_CHECK(Oklab(-1.0, 0.2, 1.01, -1).clip()  == Oklab(0, 0.2, 1.01, 0));
	BOOST_CHECK(Oklab(1.01, -1.0, 0.2, 1.1).clip() == Oklab(1.01, -1.0, 0.2));
	BOOST_CHECK(Oklab(0.2, 1.01, -1.0, 1.1).clip() == Oklab(0.2, 1.01, -1.0));

	BOOST_CHECK(Oklch(-1.0, 0.2, 101, -1).clip()   == Oklch(0, 0.2, 101, 0));
	BOOST_CHECK(Oklch(1.01, -1.0, 20, 1.1).clip()  == Oklch(1.01, 0, 0));
	BOOST_CHECK(Oklch(0.2, 1.01, -100, 1.1).clip() == Oklch(0.2, 1.01, 260));

	BOOST_CHECK(Srgb(-1, 0.2, 1.1, -1).clip()  == Srgb(0, 0.2, 1.1, 0));
	BOOST_CHECK(Srgb(1.1, -1, 0.2, 1.1).clip() == Srgb(1.1, 0, 0.2));
	BOOST_CHECK(Srgb(0.2, 1.1, -1, 1.1).clip() == Srgb(0.2, 1.1, 0));

	BOOST_CHECK(DisplayP3(-1, 0.2, 1.1, -1).clip()  == DisplayP3(0, 0.2, 1.1, 0));
	BOOST_CHECK(DisplayP3(1.1, -1, 0.2, 1.1).clip() == DisplayP3(1.1, 0, 0.2));
	BOOST_CHECK(DisplayP3(0.2, 1.1, -1, 1.1).clip() == DisplayP3(0.2, 1.1, 0));

	BOOST_CHECK(A98Rgb(-1, 0.2, 1.1, -1).clip()  == A98Rgb(0, 0.2, 1.1, 0));
	BOOST_CHECK(A98Rgb(1.1, -1, 0.2, 1.1).clip() == A98Rgb(1.1, 0, 0.2));
	BOOST_CHECK(A98Rgb(0.2, 1.1, -1, 1.1).clip() == A98Rgb(0.2, 1.1, 0));

	BOOST_CHECK(ProphotoRgb(-1, 0.2, 1.1, -1).clip()  == ProphotoRgb(0, 0.2, 1.1, 0));
	BOOST_CHECK(ProphotoRgb(1.1, -1, 0.2, 1.1).clip() == ProphotoRgb(1.1, 0, 0.2));
	BOOST_CHECK(ProphotoRgb(0.2, 1.1, -1, 1.1).clip() == ProphotoRgb(0.2, 1.1, 0));

	BOOST_CHECK(Rec2020(-1, 0.2, 1.1, -1).clip()  == Rec2020(0, 0.2, 1.1, 0));
	BOOST_CHECK(Rec2020(1.1, -1, 0.2, 1.1).clip() == Rec2020(1.1, 0, 0.2));
	BOOST_CHECK(Rec2020(0.2, 1.1, -1, 1.1).clip() == Rec2020(0.2, 1.1, 0));
}

BOOST_AUTO_TEST_CASE(ROUND)
{
	Rgb rgb(33.3, 44.4, 55.5, 0.666);
	BOOST_CHECK(rgb.round() == Rgb(33, 44, 56, 0.666));
}

BOOST_AUTO_TEST_CASE(FIT)
{
	const char f[] = ",333!";

	Rgb rgb1(70, 170, 270, 0.7);
	BOOST_CHECK(rgb1.fit().isDisplayable());
	BOOST_CHECK_CLOSE(rgb1.fit().blue(), 255.0, 0.001);
	BOOST_CHECK_EQUAL(rgb1.fit().alpha(), 0.7);
	BOOST_CHECK_CLOSE(Oklch(rgb1).lightness(), Oklch(rgb1.fit()).lightness(), 0.001);
	BOOST_CHECK_CLOSE(Oklch(rgb1).hue(), Oklch(rgb1.fit()).hue(), 1.0E-11);

	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(Hsl(rgb1)).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(Hwb(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(Lrgb(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(XyzD50(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(Lab(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(Lch(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(XyzD65(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(Oklab(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(Oklch(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(Srgb(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(DisplayP3(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(A98Rgb(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(ProphotoRgb(rgb1).fit()).vec(f));
	BOOST_CHECK_EQUAL(rgb1.fit().vec(f), Rgb(Rec2020(rgb1).fit()).vec(f));

	Rgb rgb2(170, 270, 70);
	BOOST_CHECK(rgb2.fit().isDisplayable());
	BOOST_CHECK_CLOSE(rgb2.fit().green(), 255.0, 0.001);
	BOOST_CHECK_CLOSE(Oklch(rgb2).lightness(), Oklch(rgb2.fit()).lightness(), 0.001);
	BOOST_CHECK_CLOSE(Oklch(rgb2).hue(), Oklch(rgb2.fit()).hue(), 1.0E-11);

	Rgb rgb3(55, 155, -55);
	BOOST_CHECK(rgb3.fit().isDisplayable());
	BOOST_CHECK(rgb3.fit().green() < 155.0);
	BOOST_CHECK_SMALL(rgb3.fit().blue(), 0.001);
	BOOST_CHECK_CLOSE(Oklch(rgb3).lightness(), Oklch(rgb3.fit()).lightness(), 0.001);
	BOOST_CHECK_CLOSE(Oklch(rgb3).hue(), Oklch(rgb3.fit()).hue(), 1.0E-11);
}

BOOST_AUTO_TEST_CASE(INVERT)
{
	BOOST_CHECK_EQUAL(Rgb(0, 51, 102, 0.3).invert().cssf(), "rgba(255, 204, 153, .3)");
	BOOST_CHECK_EQUAL(Rgb(-1, 256, -1).invert().vec(), "(255, 0, 255)");
}

BOOST_AUTO_TEST_CASE(DISTANCE)
{
	BOOST_CHECK_CLOSE(Rgb(11, 12, 13, 0.4).distance(Rgb(10, 15, 8, 0.9)),       std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(Hsl(11, 12, 13, 0.4).distance(Hsl(10, 15, 8, 0.9)),       std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(Hwb(11, 12, 13, 0.4).distance(Hwb(10, 15, 8, 0.9)),       std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(Lrgb(11, 12, 13, 0.4).distance(Lrgb(10, 15, 8, 0.9)),     std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD50(11, 12, 13, 0.4).distance(XyzD50(10, 15, 8, 0.9)), std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(Lab(11, 12, 13, 0.4).distance(Lab(10, 15, 8, 0.9)),       std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(Lch(11, 12, 13, 0.4).distance(Lch(10, 15, 8, 0.9)),       std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD65(11, 12, 13, 0.4).distance(XyzD65(10, 15, 8, 0.9)), std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(Oklab(11, 12, 13, 0.4).distance(Oklab(10, 15, 8, 0.9)),   std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(11, 12, 13, 0.4).distance(Oklch(10, 15, 8, 0.9)),   std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(Srgb(11, 12, 13, 0.4).distance(Srgb(10, 15, 8, 0.9)),               std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(DisplayP3(11, 12, 13, 0.4).distance(DisplayP3(10, 15, 8, 0.9)),     std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(A98Rgb(11, 12, 13, 0.4).distance(A98Rgb(10, 15, 8, 0.9)),           std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(ProphotoRgb(11, 12, 13, 0.4).distance(ProphotoRgb(10, 15, 8, 0.9)), std::sqrt(35.0), 1.0E-12);
	BOOST_CHECK_CLOSE(Rec2020(11, 12, 13, 0.4).distance(Rec2020(10, 15, 8, 0.9)),         std::sqrt(35.0), 1.0E-12);
}

BOOST_AUTO_TEST_CASE(CALCULATE_LUMINANCE)
{
	Rgb rgb(Cn::Darkolivegreen);
	Rgb rgb0(Cn::Darkolivegreen, 0.0);
	const double lumi = rgb.calculateLuminance();

	BOOST_CHECK_EQUAL(lumi, rgb0.calculateLuminance());
	BOOST_CHECK_EQUAL(lumi, XyzD65(rgb).y());

	BOOST_CHECK_CLOSE(Hsl(rgb).calculateLuminance(),    lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(Hwb(rgb).calculateLuminance(),    lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(Lrgb(rgb).calculateLuminance(),   lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD50(rgb).calculateLuminance(), lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(Lab(rgb).calculateLuminance(),    lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(Lch(rgb).calculateLuminance(),    lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD65(rgb).calculateLuminance(), lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklab(rgb).calculateLuminance(),  lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb).calculateLuminance(),  lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(Srgb(rgb).calculateLuminance(),        lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(DisplayP3(rgb).calculateLuminance(),   lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(A98Rgb(rgb).calculateLuminance(),      lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(ProphotoRgb(rgb).calculateLuminance(), lumi, 1.0E-12);
	BOOST_CHECK_CLOSE(Rec2020(rgb).calculateLuminance(),     lumi, 1.0E-12);
}

BOOST_AUTO_TEST_CASE(MAXIMAIZE_LUMINANCE)
{
	Rgb rgb(Cn::Darkolivegreen, 0.2);

	BOOST_CHECK(rgb.maximizeLightness().isDisplayable());
	BOOST_CHECK_CLOSE(rgb.maximizeLightness().green(), 255.0, 0.001);
	BOOST_CHECK_EQUAL(rgb.maximizeLightness().alpha(), 0.2);

	const std::string hex = rgb.maximizeLightness().hex();
	BOOST_CHECK_EQUAL(Hsl(rgb).maximizeLightness().hex(),    hex);
	BOOST_CHECK_EQUAL(Hwb(rgb).maximizeLightness().hex(),    hex);
	BOOST_CHECK_EQUAL(Lrgb(rgb).maximizeLightness().hex(),   hex);
	BOOST_CHECK_EQUAL(XyzD50(rgb).maximizeLightness().hex(), hex);
	BOOST_CHECK_EQUAL(Lab(rgb).maximizeLightness().hex(),    hex);
	BOOST_CHECK_EQUAL(Lch(rgb).maximizeLightness().hex(),    hex);
	BOOST_CHECK_EQUAL(XyzD65(rgb).maximizeLightness().hex(), hex);
	BOOST_CHECK_EQUAL(Oklab(rgb).maximizeLightness().hex(),  hex);
	BOOST_CHECK_EQUAL(Oklch(rgb).maximizeLightness().hex(),  hex);
	BOOST_CHECK_EQUAL(Srgb(rgb).maximizeLightness().hex(),        hex);
	BOOST_CHECK_EQUAL(DisplayP3(rgb).maximizeLightness().hex(),   hex);
	BOOST_CHECK_EQUAL(A98Rgb(rgb).maximizeLightness().hex(),      hex);
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).maximizeLightness().hex(), hex);
	BOOST_CHECK_EQUAL(Rec2020(rgb).maximizeLightness().hex(),     hex);
}

BOOST_AUTO_TEST_CASE(BRIGHTEN)
{
	Rgb rgb(Cn::Darkolivegreen, 0.2);

	BOOST_CHECK_CLOSE(Oklch(rgb.brighten()).lightness(), Oklch(rgb).lightness() + 0.1, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.brighten()).chroma(),    Oklch(rgb).chroma(),          1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.brighten()).hue(),       Oklch(rgb).hue(),             1.0E-12);
	BOOST_CHECK_EQUAL(rgb.brighten().alpha(), 0.2);

	const std::string hex = rgb.brighten().hex();
	BOOST_CHECK_EQUAL(Rgb(rgb).brighten(0.1).hex(), hex);
	BOOST_CHECK_EQUAL(Rgb(rgb).darken(-0.1).hex(),  hex);
	BOOST_CHECK_EQUAL(Hsl(rgb).brighten().hex(),    hex);
	BOOST_CHECK_EQUAL(Hwb(rgb).brighten().hex(),    hex);
	BOOST_CHECK_EQUAL(Lrgb(rgb).brighten().hex(),   hex);
	BOOST_CHECK_EQUAL(XyzD50(rgb).brighten().hex(), hex);
	BOOST_CHECK_EQUAL(Lab(rgb).brighten().hex(),    hex);
	BOOST_CHECK_EQUAL(Lch(rgb).brighten().hex(),    hex);
	BOOST_CHECK_EQUAL(XyzD65(rgb).brighten().hex(), hex);
	BOOST_CHECK_EQUAL(Oklab(rgb).brighten().hex(),  hex);
	BOOST_CHECK_EQUAL(Oklch(rgb).brighten().hex(),  hex);
	BOOST_CHECK_EQUAL(Srgb(rgb).brighten().hex(),        hex);
	BOOST_CHECK_EQUAL(DisplayP3(rgb).brighten().hex(),   hex);
	BOOST_CHECK_EQUAL(A98Rgb(rgb).brighten().hex(),      hex);
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).brighten().hex(), hex);
	BOOST_CHECK_EQUAL(Rec2020(rgb).brighten().hex(),     hex);
}

BOOST_AUTO_TEST_CASE(DARKEN)
{
	Rgb rgb(Cn::Darkolivegreen, 0.2);

	BOOST_CHECK_CLOSE(Oklch(rgb.darken()).lightness(), Oklch(rgb).lightness() - 0.1, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.darken()).chroma(),    Oklch(rgb).chroma(),          1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.darken()).hue(),       Oklch(rgb).hue(),             1.0E-12);
	BOOST_CHECK_EQUAL(rgb.darken().alpha(), 0.2);

	const std::string hex = rgb.darken().hex();
	BOOST_CHECK_EQUAL(Rgb(rgb).darken(0.1).hex(),    hex);
	BOOST_CHECK_EQUAL(Rgb(rgb).brighten(-0.1).hex(), hex);
	BOOST_CHECK_EQUAL(Hsl(rgb).darken().hex(),       hex);
	BOOST_CHECK_EQUAL(Hwb(rgb).darken().hex(),       hex);
	BOOST_CHECK_EQUAL(Lrgb(rgb).darken().hex(),      hex);
	BOOST_CHECK_EQUAL(XyzD50(rgb).darken().hex(),    hex);
	BOOST_CHECK_EQUAL(Lab(rgb).darken().hex(),       hex);
	BOOST_CHECK_EQUAL(Lch(rgb).darken().hex(),       hex);
	BOOST_CHECK_EQUAL(XyzD65(rgb).darken().hex(),    hex);
	BOOST_CHECK_EQUAL(Oklab(rgb).darken().hex(),     hex);
	BOOST_CHECK_EQUAL(Oklch(rgb).darken().hex(),     hex);
	BOOST_CHECK_EQUAL(Srgb(rgb).darken().hex(),        hex);
	BOOST_CHECK_EQUAL(DisplayP3(rgb).darken().hex(),   hex);
	BOOST_CHECK_EQUAL(A98Rgb(rgb).darken().hex(),      hex);
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).darken().hex(), hex);
	BOOST_CHECK_EQUAL(Rec2020(rgb).darken().hex(),     hex);
}

BOOST_AUTO_TEST_CASE(SATURATE)
{
	Rgb rgb(Cn::Darkolivegreen, 0.2);

	BOOST_CHECK_CLOSE(Oklch(rgb.saturate()).chroma(),    Oklch(rgb).chroma() + 0.04, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.saturate()).lightness(), Oklch(rgb).lightness(),     1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.saturate()).hue(),       Oklch(rgb).hue(),           1.0E-12);
	BOOST_CHECK_EQUAL(rgb.saturate().alpha(), 0.2);

	const std::string hex = rgb.saturate().hex();
	BOOST_CHECK_EQUAL(Rgb(rgb).saturate(0.04).hex(),    hex);
	BOOST_CHECK_EQUAL(Rgb(rgb).desaturate(-0.04).hex(), hex);
	BOOST_CHECK_EQUAL(Hsl(rgb).saturate().hex(),        hex);
	BOOST_CHECK_EQUAL(Hwb(rgb).saturate().hex(),        hex);
	BOOST_CHECK_EQUAL(Lrgb(rgb).saturate().hex(),       hex);
	BOOST_CHECK_EQUAL(XyzD50(rgb).saturate().hex(),     hex);
	BOOST_CHECK_EQUAL(Lab(rgb).saturate().hex(),        hex);
	BOOST_CHECK_EQUAL(Lch(rgb).saturate().hex(),        hex);
	BOOST_CHECK_EQUAL(XyzD65(rgb).saturate().hex(),     hex);
	BOOST_CHECK_EQUAL(Oklab(rgb).saturate().hex(),      hex);
	BOOST_CHECK_EQUAL(Oklch(rgb).saturate().hex(),      hex);
	BOOST_CHECK_EQUAL(Srgb(rgb).saturate().hex(),        hex);
	BOOST_CHECK_EQUAL(DisplayP3(rgb).saturate().hex(),   hex);
	BOOST_CHECK_EQUAL(A98Rgb(rgb).saturate().hex(),      hex);
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).saturate().hex(), hex);
	BOOST_CHECK_EQUAL(Rec2020(rgb).saturate().hex(),     hex);
}

BOOST_AUTO_TEST_CASE(DESATURATE)
{
	Rgb rgb(Cn::Darkolivegreen, 0.2);

	BOOST_CHECK_CLOSE(Oklch(rgb.desaturate()).chroma(),    Oklch(rgb).chroma() - 0.04, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.desaturate()).lightness(), Oklch(rgb).lightness(),     1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.desaturate()).hue(),       Oklch(rgb).hue(),           1.0E-12);
	BOOST_CHECK_EQUAL(rgb.desaturate().alpha(), 0.2);

	const std::string hex = rgb.desaturate().hex();
	BOOST_CHECK_EQUAL(Rgb(rgb).desaturate(0.04).hex(), hex);
	BOOST_CHECK_EQUAL(Rgb(rgb).saturate(-0.04).hex(),  hex);
	BOOST_CHECK_EQUAL(Hsl(rgb).desaturate().hex(),     hex);
	BOOST_CHECK_EQUAL(Hwb(rgb).desaturate().hex(),     hex);
	BOOST_CHECK_EQUAL(Lrgb(rgb).desaturate().hex(),    hex);
	BOOST_CHECK_EQUAL(XyzD50(rgb).desaturate().hex(),  hex);
	BOOST_CHECK_EQUAL(Lab(rgb).desaturate().hex(),     hex);
	BOOST_CHECK_EQUAL(Lch(rgb).desaturate().hex(),     hex);
	BOOST_CHECK_EQUAL(XyzD65(rgb).desaturate().hex(),  hex);
	BOOST_CHECK_EQUAL(Oklab(rgb).desaturate().hex(),   hex);
	BOOST_CHECK_EQUAL(Oklch(rgb).desaturate().hex(),   hex);
	BOOST_CHECK_EQUAL(Srgb(rgb).desaturate().hex(),        hex);
	BOOST_CHECK_EQUAL(DisplayP3(rgb).desaturate().hex(),   hex);
	BOOST_CHECK_EQUAL(A98Rgb(rgb).desaturate().hex(),      hex);
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).desaturate().hex(), hex);
	BOOST_CHECK_EQUAL(Rec2020(rgb).desaturate().hex(),     hex);
}

BOOST_AUTO_TEST_CASE(ROTATE)
{
	Rgb rgb(Cn::Darkolivegreen, 0.2);

	BOOST_CHECK_CLOSE(Oklch(rgb.rotate()).hue(),       Oklch(rgb).hue() + 36.0, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.rotate()).lightness(), Oklch(rgb).lightness(),  1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb.rotate()).chroma(),    Oklch(rgb).chroma(),     1.0E-12);
	BOOST_CHECK_EQUAL(rgb.rotate().alpha(), 0.2);

	const std::string hex = rgb.rotate().hex();
	BOOST_CHECK_EQUAL(Rgb(rgb).rotate(36.0).hex(),   hex);
	BOOST_CHECK_EQUAL(Rgb(rgb).rotate(-324.0).hex(), hex);
	BOOST_CHECK_EQUAL(Hsl(rgb).rotate().hex(),       hex);
	BOOST_CHECK_EQUAL(Hwb(rgb).rotate().hex(),       hex);
	BOOST_CHECK_EQUAL(Lrgb(rgb).rotate().hex(),      hex);
	BOOST_CHECK_EQUAL(XyzD50(rgb).rotate().hex(),    hex);
	BOOST_CHECK_EQUAL(Lab(rgb).rotate().hex(),       hex);
	BOOST_CHECK_EQUAL(Lch(rgb).rotate().hex(),       hex);
	BOOST_CHECK_EQUAL(XyzD65(rgb).rotate().hex(),    hex);
	BOOST_CHECK_EQUAL(Oklab(rgb).rotate().hex(),     hex);
	BOOST_CHECK_EQUAL(Oklch(rgb).rotate().hex(),     hex);
	BOOST_CHECK_EQUAL(Srgb(rgb).rotate().hex(),        hex);
	BOOST_CHECK_EQUAL(DisplayP3(rgb).rotate().hex(),   hex);
	BOOST_CHECK_EQUAL(A98Rgb(rgb).rotate().hex(),      hex);
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).rotate().hex(), hex);
	BOOST_CHECK_EQUAL(Rec2020(rgb).rotate().hex(),     hex);
}

BOOST_AUTO_TEST_CASE(FLIP)
{
	Rgb rgb(Cn::Darkolivegreen, 0.2);

	BOOST_CHECK_CLOSE(Oklch(rgb).flip().hue(),       0.0 - Oklch(rgb).hue(), 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb).flip().lightness(), Oklch(rgb).lightness(), 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb).flip().chroma(),    Oklch(rgb).chroma(),    1.0E-12);
	BOOST_CHECK_EQUAL(Oklch(rgb).flip().alpha(), 0.2);

	const std::string hex = rgb.flip(10.0).hex();
	BOOST_CHECK_EQUAL(Rgb(rgb).flip(10.0).hex(),    hex);
	BOOST_CHECK_EQUAL(Rgb(rgb).flip(190.0).hex(),   hex);
	BOOST_CHECK_EQUAL(Hsl(rgb).flip(10.0).hex(),    hex);
	BOOST_CHECK_EQUAL(Hwb(rgb).flip(10.0).hex(),    hex);
	BOOST_CHECK_EQUAL(Lrgb(rgb).flip(10.0).hex(),   hex);
	BOOST_CHECK_EQUAL(XyzD50(rgb).flip(10.0).hex(), hex);
	BOOST_CHECK_EQUAL(Lab(rgb).flip(10.0).hex(),    hex);
	BOOST_CHECK_EQUAL(Lch(rgb).flip(10.0).hex(),    hex);
	BOOST_CHECK_EQUAL(XyzD65(rgb).flip(10.0).hex(), hex);
	BOOST_CHECK_EQUAL(Oklab(rgb).flip(10.0).hex(),  hex);
	BOOST_CHECK_EQUAL(Oklch(rgb).flip(10.0).hex(),  hex);
	BOOST_CHECK_EQUAL(Srgb(rgb).flip(10.0).hex(),        hex);
	BOOST_CHECK_EQUAL(DisplayP3(rgb).flip(10.0).hex(),   hex);
	BOOST_CHECK_EQUAL(A98Rgb(rgb).flip(10.0).hex(),      hex);
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).flip(10.0).hex(), hex);
	BOOST_CHECK_EQUAL(Rec2020(rgb).flip(10.0).hex(),     hex);
}

BOOST_AUTO_TEST_CASE(MIX)
{
	BOOST_CHECK_EQUAL(Rgb(50, 100, 150, 0.8).mix(Rgb(300, 200, 100, 0.6), 0.25).vec(), "(100, 120, 140, 0.75)");
	BOOST_CHECK_EQUAL(Hsl(5, 10, 15, 0.8).mix(Hsl(30, 20, 10, 0.6), 0.25).vec(),       "(11.25, 12, 14, 0.75)");
	BOOST_CHECK_EQUAL(Hsl(5, 0, 15, 0.8).mix(Hsl(30, 20, 10, 0.6), 0.25).vec(),        "(30, 4, 14, 0.75)");
	BOOST_CHECK_EQUAL(Hsl(5, 10, 100, 0.8).mix(Hsl(30, 20, 10, 0.6), 0.25).vec(),      "(30, 12, 82, 0.75)");
	BOOST_CHECK_EQUAL(Hsl(5, 10, 15, 0.8).mix(Hsl(30, 20, 100, 0.6), 0.25).vec(),      "(5, 12, 32, 0.75)");
	BOOST_CHECK_EQUAL(Hwb(5, 10, 15, 0.8).mix(Hwb(30, 20, 10, 0.6), 0.25).vec(),       "(11.25, 12, 14, 0.75)");
	BOOST_CHECK_EQUAL(Hwb(5, 10, 100, 0.8).mix(Hwb(30, 20, 10, 0.6), 0.25).vec(),      "(30, 12, 82, 0.75)");
	BOOST_CHECK_EQUAL(Hwb(5, 10, 15, 0.8).mix(Hwb(30, 20, 100, 0.6), 0.25).vec(),      "(5, 12, 32, 0.75)");
	BOOST_CHECK_EQUAL(XyzD50(0.05, 0.1, 0.15, 0.8).mix(XyzD50(0.3, 0.2, 0.1, 0.6), 0.25).vec(), "(0.1, 0.12, 0.14, 0.75)");
	BOOST_CHECK_EQUAL(Lab(50, 100, 150, 0.8).mix(Lab(300, 200, 100, 0.6), 0.25).vec(),          "(100, 120, 140, 0.75)");
	BOOST_CHECK_EQUAL(Lch(50, 100, 150, 0.8).mix(Lch(300, 200, 100, 0.6), 0.25).vec(),          "(100, 120, 137.5, 0.75)");
	BOOST_CHECK_EQUAL(Lch(50, 0.0, 150, 0.8).mix(Lch(300, 200, 100, 0.6), 0.25).vec(),          "(100, 40, 100, 0.75)");
	BOOST_CHECK_EQUAL(Lch(50, 100, 150, 0.8).mix(Lch(300, 0, 100, 0.6), 0.25).vec(),            "(100, 80, 150, 0.75)");
	BOOST_CHECK_EQUAL(XyzD65(0.05, 0.1, 0.15, 0.8).mix(XyzD65(0.3, 0.2, 0.1, 0.6), 0.25).vec(), "(0.1, 0.12, 0.14, 0.75)");
	BOOST_CHECK_EQUAL(Oklab(0.05, 0.1, 0.15, 0.8).mix(Oklab(0.3, 0.2, 0.1, 0.6), 0.25).vec(),   "(0.1, 0.12, 0.14, 0.75)");
	BOOST_CHECK_EQUAL(Oklch(0.05, 0.1, 150, 0.8).mix(Oklch(0.3, 0.2, 100, 0.6), 0.25).vec(),    "(0.1, 0.12, 137.5, 0.75)");
	BOOST_CHECK_EQUAL(Oklch(0.05, 0.0, 150, 0.8).mix(Oklch(0.3, 0.2, 100, 0.6), 0.25).vec(),    "(0.1, 0.04, 100, 0.75)");
	BOOST_CHECK_EQUAL(Oklch(0.05, 0.1, 150, 0.8).mix(Oklch(0.3, 0.0, 100, 0.6), 0.25).vec(),    "(0.1, 0.08, 150, 0.75)");
	BOOST_CHECK_EQUAL(Srgb(0.05, 0.1, 0.15, 0.8).mix(Srgb(0.3, 0.2, 0.1, 0.6), 0.25).vec(),               "(0.1, 0.12, 0.14, 0.75)");
	BOOST_CHECK_EQUAL(DisplayP3(0.05, 0.1, 0.15, 0.8).mix(DisplayP3(0.3, 0.2, 0.1, 0.6), 0.25).vec(),     "(0.1, 0.12, 0.14, 0.75)");
	BOOST_CHECK_EQUAL(A98Rgb(0.05, 0.1, 0.15, 0.8).mix(A98Rgb(0.3, 0.2, 0.1, 0.6), 0.25).vec(),           "(0.1, 0.12, 0.14, 0.75)");
	BOOST_CHECK_EQUAL(ProphotoRgb(0.05, 0.1, 0.15, 0.8).mix(ProphotoRgb(0.3, 0.2, 0.1, 0.6), 0.25).vec(), "(0.1, 0.12, 0.14, 0.75)");
	BOOST_CHECK_EQUAL(Rec2020(0.05, 0.1, 0.15, 0.8).mix(Rec2020(0.3, 0.2, 0.1, 0.6), 0.25).vec(),         "(0.1, 0.12, 0.14, 0.75)");
}

BOOST_AUTO_TEST_CASE(DELTA_E_00)
{
	Lab lab1(42.3591, -16.4012, 30.3153);
	Lab lab2(86.5974, -43.0231, 36.3925);
	BOOST_CHECK_CLOSE_FRACTION(lab1.deltaE_00(lab2), 38.364314, 0.000005);
	BOOST_CHECK_CLOSE_FRACTION(lab2.deltaE_00(lab1), 38.364314, 0.000005);

	const double de = lab1.deltaE_00(lab2);
	BOOST_CHECK_CLOSE(Rgb(lab1).deltaE_00(Rgb(lab2)),       de, 1.0E-12);
	BOOST_CHECK_CLOSE(Hsl(lab1).deltaE_00(Hsl(lab2)),       de, 1.0E-12);
	BOOST_CHECK_CLOSE(Hwb(lab1).deltaE_00(Hwb(lab2)),       de, 1.0E-12);
	BOOST_CHECK_CLOSE(Lrgb(lab1).deltaE_00(Lrgb(lab2)),     de, 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD50(lab1).deltaE_00(XyzD50(lab2)), de, 1.0E-12);
	BOOST_CHECK_CLOSE(Lch(lab1).deltaE_00(Lch(lab2)),       de, 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD65(lab1).deltaE_00(XyzD65(lab2)), de, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklab(lab1).deltaE_00(Oklab(lab2)),   de, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(lab1).deltaE_00(Oklch(lab2)),   de, 1.0E-12);
	BOOST_CHECK_CLOSE(Srgb(lab1).deltaE_00(Srgb(lab2)),               de, 1.0E-12);
	BOOST_CHECK_CLOSE(A98Rgb(lab1).deltaE_00(A98Rgb(lab2)),           de, 1.0E-12);
	BOOST_CHECK_CLOSE(DisplayP3(lab1).deltaE_00(DisplayP3(lab2)),     de, 1.0E-12);
	BOOST_CHECK_CLOSE(ProphotoRgb(lab1).deltaE_00(ProphotoRgb(lab2)), de, 1.0E-12);
	BOOST_CHECK_CLOSE(Rec2020(lab1).deltaE_00(Rec2020(lab2)),         de, 1.0E-12);
}

BOOST_AUTO_TEST_CASE(DELTA_E)
{
	Oklab oklab1(Cn::Darkolivegreen);
	Oklab oklab2(Cn::Lightgreen);

	const double de = oklab1.deltaE(oklab2);
	BOOST_CHECK_EQUAL(oklab1.distance(oklab2), de);

	BOOST_CHECK_CLOSE(Rgb(oklab1).deltaE(Rgb(oklab2)),       de, 1.0E-12);
	BOOST_CHECK_CLOSE(Hsl(oklab1).deltaE(Hsl(oklab2)),       de, 1.0E-12);
	BOOST_CHECK_CLOSE(Hwb(oklab1).deltaE(Hwb(oklab2)),       de, 1.0E-12);
	BOOST_CHECK_CLOSE(Lrgb(oklab1).deltaE(Lrgb(oklab2)),     de, 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD50(oklab1).deltaE(XyzD50(oklab2)), de, 1.0E-12);
	BOOST_CHECK_CLOSE(Lab(oklab1).deltaE(Lab(oklab2)),       de, 1.0E-12);
	BOOST_CHECK_CLOSE(Lch(oklab1).deltaE(Lch(oklab2)),       de, 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD65(oklab1).deltaE(XyzD65(oklab2)), de, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(oklab1).deltaE(Oklch(oklab2)),   de, 1.0E-12);
	BOOST_CHECK_CLOSE(Srgb(oklab1).deltaE(Srgb(oklab2)),               de, 1.0E-12);
	BOOST_CHECK_CLOSE(A98Rgb(oklab1).deltaE(A98Rgb(oklab2)),           de, 1.0E-12);
	BOOST_CHECK_CLOSE(DisplayP3(oklab1).deltaE(DisplayP3(oklab2)),     de, 1.0E-12);
	BOOST_CHECK_CLOSE(ProphotoRgb(oklab1).deltaE(ProphotoRgb(oklab2)), de, 1.0E-12);
	BOOST_CHECK_CLOSE(Rec2020(oklab1).deltaE(Rec2020(oklab2)),         de, 1.0E-12);
}

BOOST_AUTO_TEST_CASE(GRAYSCALE)
{
	Oklab oklab(Cn::Darkolivegreen);
	Oklab gray(oklab.lightness(), 0.0, 0.0, oklab.alpha());

	BOOST_CHECK(oklab.grayscale() == gray);

	BOOST_CHECK_SMALL(Rgb(oklab).grayscale().distance(Rgb(gray)),       1.0E-12);
	BOOST_CHECK_SMALL(Hsl(oklab).grayscale().distance(Hsl(gray)),       1.0E-12);
	BOOST_CHECK_SMALL(Hwb(oklab).grayscale().distance(Hwb(gray)),       1.0E-12);
	BOOST_CHECK_SMALL(Lrgb(oklab).grayscale().distance(Lrgb(gray)),     1.0E-12);
	BOOST_CHECK_SMALL(XyzD50(oklab).grayscale().distance(XyzD50(gray)), 1.0E-12);
	BOOST_CHECK_SMALL(Lab(oklab).grayscale().distance(Lab(gray)),       1.0E-12);
	BOOST_CHECK_SMALL(Lch(oklab).grayscale().distance(Lch(gray)),       1.0E-12);
	BOOST_CHECK_SMALL(XyzD65(oklab).grayscale().distance(XyzD65(gray)), 1.0E-12);
	BOOST_CHECK_SMALL(Oklch(oklab).grayscale().distance(Oklch(gray)),   1.0E-12);
	BOOST_CHECK_SMALL(Srgb(oklab).grayscale().distance(Srgb(gray)),               1.0E-12);
	BOOST_CHECK_SMALL(DisplayP3(oklab).grayscale().distance(DisplayP3(gray)),     1.0E-12);
	BOOST_CHECK_SMALL(A98Rgb(oklab).grayscale().distance(A98Rgb(gray)),           1.0E-12);
	BOOST_CHECK_SMALL(ProphotoRgb(oklab).grayscale().distance(ProphotoRgb(gray)), 1.0E-12);
	BOOST_CHECK_SMALL(Rec2020(oklab).grayscale().distance(Rec2020(gray)),         1.0E-12);
}

BOOST_AUTO_TEST_CASE(CONTRAST)
{
	Rgb rgb1(Cn::Darkolivegreen);
	Rgb rgb2(Cn::Lightgreen);

	BOOST_CHECK_CLOSE_FRACTION(rgb1.contrast(rgb2), 4.1974, 0.00005);

	const double con = rgb1.contrast(rgb2);
	BOOST_CHECK_CLOSE(Hsl(rgb1).contrast(Hsl(rgb2)),       con, 1.0E-12);
	BOOST_CHECK_CLOSE(Hwb(rgb1).contrast(Hwb(rgb2)),       con, 1.0E-12);
	BOOST_CHECK_CLOSE(Lrgb(rgb1).contrast(Lrgb(rgb2)),     con, 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD50(rgb1).contrast(XyzD50(rgb2)), con, 1.0E-12);
	BOOST_CHECK_CLOSE(Lab(rgb1).contrast(Lab(rgb2)),       con, 1.0E-12);
	BOOST_CHECK_CLOSE(Lch(rgb1).contrast(Lch(rgb2)),       con, 1.0E-12);
	BOOST_CHECK_CLOSE(XyzD65(rgb1).contrast(XyzD65(rgb2)), con, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklab(rgb1).contrast(Oklab(rgb2)),   con, 1.0E-12);
	BOOST_CHECK_CLOSE(Oklch(rgb1).contrast(Oklch(rgb2)),   con, 1.0E-12);
	BOOST_CHECK_CLOSE(Srgb(rgb1).contrast(Srgb(rgb2)),               con, 1.0E-12);
	BOOST_CHECK_CLOSE(DisplayP3(rgb1).contrast(DisplayP3(rgb2)),     con, 1.0E-12);
	BOOST_CHECK_CLOSE(A98Rgb(rgb1).contrast(A98Rgb(rgb2)),           con, 1.0E-12);
	BOOST_CHECK_CLOSE(ProphotoRgb(rgb1).contrast(ProphotoRgb(rgb2)), con, 1.0E-12);
	BOOST_CHECK_CLOSE(Rec2020(rgb1).contrast(Rec2020(rgb2)),         con, 1.0E-12);
}
