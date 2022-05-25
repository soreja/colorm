#include "pch.h"

#include <boost/test/unit_test.hpp>


using namespace colorm;

BOOST_AUTO_TEST_CASE(RGB_ACCESS)
{
	BOOST_CHECK_EQUAL(Rgb().red(), 0);
	BOOST_CHECK_EQUAL(Rgb().green(), 0);
	BOOST_CHECK_EQUAL(Rgb().blue(), 0);
	BOOST_CHECK_EQUAL(Rgb().alpha(), 1);
	BOOST_CHECK_EQUAL(Rgb().setRed(2).red(), 2);
	BOOST_CHECK_EQUAL(Rgb().setGreen(2).green(), 2);
	BOOST_CHECK_EQUAL(Rgb().setBlue(2).blue(), 2);
	BOOST_CHECK_EQUAL(Rgb().setAlpha(2).alpha(), 2);

	BOOST_CHECK_EQUAL(Rgb().setRed8(2).red8(), 2);
	BOOST_CHECK_EQUAL(Rgb().setGreen8(2).green8(), 2);
	BOOST_CHECK_EQUAL(Rgb().setBlue8(2).blue8(), 2);
	BOOST_CHECK_EQUAL(Rgb().setAlpha8(2).alpha8(), 2);
	BOOST_CHECK_EQUAL(Rgb().setRed8(999).red(), 255);
	BOOST_CHECK_EQUAL(Rgb().setGreen8(999).green(), 255);
	BOOST_CHECK_EQUAL(Rgb().setBlue8(999).blue(), 255);
	BOOST_CHECK_EQUAL(Rgb().setAlpha8(999).alpha(), 1);

	Rgb rgbM1(-1, -1, -1, -1);
	Rgb rgb12345605(12, 34, 56, 0.5);
	Rgb rgb999(999, 999, 999, 999);

	BOOST_CHECK_EQUAL(rgbM1.red(), -1);
	BOOST_CHECK_EQUAL(rgbM1.green(), -1);
	BOOST_CHECK_EQUAL(rgbM1.blue(), -1);
	BOOST_CHECK_EQUAL(rgbM1.alpha(), -1);
	BOOST_CHECK_EQUAL(rgb12345605.red(), 12);
	BOOST_CHECK_EQUAL(rgb12345605.green(), 34);
	BOOST_CHECK_EQUAL(rgb12345605.blue(), 56);
	BOOST_CHECK_EQUAL(rgb12345605.alpha(), 0.5);
	BOOST_CHECK_EQUAL(rgb999.red(), 999);
	BOOST_CHECK_EQUAL(rgb999.green(), 999);
	BOOST_CHECK_EQUAL(rgb999.blue(), 999);
	BOOST_CHECK_EQUAL(rgb999.alpha(), 999);

	BOOST_CHECK_EQUAL(rgbM1.red8(), 0);
	BOOST_CHECK_EQUAL(rgbM1.green8(), 0);
	BOOST_CHECK_EQUAL(rgbM1.blue8(), 0);
	BOOST_CHECK_EQUAL(rgb12345605.red8(), 12);
	BOOST_CHECK_EQUAL(rgb12345605.green8(), 34);
	BOOST_CHECK_EQUAL(rgb12345605.blue8(), 56);
	BOOST_CHECK_EQUAL(rgb12345605.alpha8(), 128);
	BOOST_CHECK_EQUAL(rgb999.red8(), 255);
	BOOST_CHECK_EQUAL(rgb999.green8(), 255);
	BOOST_CHECK_EQUAL(rgb999.blue8(), 255);
}

BOOST_AUTO_TEST_CASE(HSL_ACCESS)
{
	BOOST_CHECK_EQUAL(Hsl().hue(), 0);
	BOOST_CHECK_EQUAL(Hsl().saturation(), 0);
	BOOST_CHECK_EQUAL(Hsl().lightness(), 0);
	BOOST_CHECK_EQUAL(Hsl().alpha(), 1);
	BOOST_CHECK_EQUAL(Hsl().setHue(2).hue(), 2);
	BOOST_CHECK_EQUAL(Hsl().setSaturation(2).saturation(), 2);
	BOOST_CHECK_EQUAL(Hsl().setLightness(2).lightness(), 2);
	BOOST_CHECK_EQUAL(Hsl().setAlpha(2).alpha(), 2);

	Hsl hsl(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(hsl.hue(), 12);
	BOOST_CHECK_EQUAL(hsl.saturation(), 34);
	BOOST_CHECK_EQUAL(hsl.lightness(), 56);
	BOOST_CHECK_EQUAL(hsl.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(HWB_ACCESS)
{
	BOOST_CHECK_EQUAL(Hwb().hue(), 0);
	BOOST_CHECK_EQUAL(Hwb().whiteness(), 0);
	BOOST_CHECK_EQUAL(Hwb().blackness(), 0);
	BOOST_CHECK_EQUAL(Hwb().alpha(), 1);
	BOOST_CHECK_EQUAL(Hwb().setHue(2).hue(), 2);
	BOOST_CHECK_EQUAL(Hwb().setWhiteness(2).whiteness(), 2);
	BOOST_CHECK_EQUAL(Hwb().setBlackness(2).blackness(), 2);
	BOOST_CHECK_EQUAL(Hwb().setAlpha(2).alpha(), 2);

	Hwb hwb(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(hwb.hue(), 12);
	BOOST_CHECK_EQUAL(hwb.whiteness(), 34);
	BOOST_CHECK_EQUAL(hwb.blackness(), 56);
	BOOST_CHECK_EQUAL(hwb.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(LRGB_ACCESS)
{
	BOOST_CHECK_EQUAL(Lrgb().red(), 0);
	BOOST_CHECK_EQUAL(Lrgb().green(), 0);
	BOOST_CHECK_EQUAL(Lrgb().blue(), 0);
	BOOST_CHECK_EQUAL(Lrgb().alpha(), 1);
	BOOST_CHECK_EQUAL(Lrgb().setRed(2).red(), 2);
	BOOST_CHECK_EQUAL(Lrgb().setGreen(2).green(), 2);
	BOOST_CHECK_EQUAL(Lrgb().setBlue(2).blue(), 2);
	BOOST_CHECK_EQUAL(Lrgb().setAlpha(2).alpha(), 2);

	Lrgb lrgb(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(lrgb.red(), 12);
	BOOST_CHECK_EQUAL(lrgb.green(), 34);
	BOOST_CHECK_EQUAL(lrgb.blue(), 56);
	BOOST_CHECK_EQUAL(lrgb.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(XYZD50_ACCESS)
{
	BOOST_CHECK_EQUAL(XyzD50().x(), 0);
	BOOST_CHECK_EQUAL(XyzD50().y(), 0);
	BOOST_CHECK_EQUAL(XyzD50().z(), 0);
	BOOST_CHECK_EQUAL(XyzD50().alpha(), 1);
	BOOST_CHECK_EQUAL(XyzD50().setX(2).x(), 2);
	BOOST_CHECK_EQUAL(XyzD50().setY(2).y(), 2);
	BOOST_CHECK_EQUAL(XyzD50().setZ(2).z(), 2);
	BOOST_CHECK_EQUAL(XyzD50().setAlpha(2).alpha(), 2);

	XyzD50 xyzD50(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(xyzD50.x(), 12);
	BOOST_CHECK_EQUAL(xyzD50.y(), 34);
	BOOST_CHECK_EQUAL(xyzD50.z(), 56);
	BOOST_CHECK_EQUAL(xyzD50.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(LAB_ACCESS)
{
	BOOST_CHECK_EQUAL(Lab().lightness(), 0);
	BOOST_CHECK_EQUAL(Lab().a(), 0);
	BOOST_CHECK_EQUAL(Lab().b(), 0);
	BOOST_CHECK_EQUAL(Lab().alpha(), 1);
	BOOST_CHECK_EQUAL(Lab().setLightness(2).lightness(), 2);
	BOOST_CHECK_EQUAL(Lab().setA(2).a(), 2);
	BOOST_CHECK_EQUAL(Lab().setB(2).b(), 2);
	BOOST_CHECK_EQUAL(Lab().setAlpha(2).alpha(), 2);

	Lab lab(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(lab.lightness(), 12);
	BOOST_CHECK_EQUAL(lab.a(), 34);
	BOOST_CHECK_EQUAL(lab.b(), 56);
	BOOST_CHECK_EQUAL(lab.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(LCH_ACCESS)
{
	BOOST_CHECK_EQUAL(Lch().lightness(), 0);
	BOOST_CHECK_EQUAL(Lch().chroma(), 0);
	BOOST_CHECK_EQUAL(Lch().hue(), 0);
	BOOST_CHECK_EQUAL(Lch().alpha(), 1);
	BOOST_CHECK_EQUAL(Lch().setLightness(2).lightness(), 2);
	BOOST_CHECK_EQUAL(Lch().setChroma(2).chroma(), 2);
	BOOST_CHECK_EQUAL(Lch().setHue(2).hue(), 2);
	BOOST_CHECK_EQUAL(Lch().setAlpha(2).alpha(), 2);

	Lch lch(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(lch.lightness(), 12);
	BOOST_CHECK_EQUAL(lch.chroma(), 34);
	BOOST_CHECK_EQUAL(lch.hue(), 56);
	BOOST_CHECK_EQUAL(lch.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(XYZD65_ACCESS)
{
	BOOST_CHECK_EQUAL(XyzD65().x(), 0);
	BOOST_CHECK_EQUAL(XyzD65().y(), 0);
	BOOST_CHECK_EQUAL(XyzD65().z(), 0);
	BOOST_CHECK_EQUAL(XyzD65().alpha(), 1);
	BOOST_CHECK_EQUAL(XyzD65().setX(2).x(), 2);
	BOOST_CHECK_EQUAL(XyzD65().setY(2).y(), 2);
	BOOST_CHECK_EQUAL(XyzD65().setZ(2).z(), 2);
	BOOST_CHECK_EQUAL(XyzD65().setAlpha(2).alpha(), 2);

	XyzD65 xyzD65(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(xyzD65.x(), 12);
	BOOST_CHECK_EQUAL(xyzD65.y(), 34);
	BOOST_CHECK_EQUAL(xyzD65.z(), 56);
	BOOST_CHECK_EQUAL(xyzD65.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(OKLAB_ACCESS)
{
	BOOST_CHECK_EQUAL(Oklab().lightness(), 0);
	BOOST_CHECK_EQUAL(Oklab().a(), 0);
	BOOST_CHECK_EQUAL(Oklab().b(), 0);
	BOOST_CHECK_EQUAL(Oklab().alpha(), 1);
	BOOST_CHECK_EQUAL(Oklab().setLightness(2).lightness(), 2);
	BOOST_CHECK_EQUAL(Oklab().setA(2).a(), 2);
	BOOST_CHECK_EQUAL(Oklab().setB(2).b(), 2);
	BOOST_CHECK_EQUAL(Oklab().setAlpha(2).alpha(), 2);

	Oklab oklab(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(oklab.lightness(), 12);
	BOOST_CHECK_EQUAL(oklab.a(), 34);
	BOOST_CHECK_EQUAL(oklab.b(), 56);
	BOOST_CHECK_EQUAL(oklab.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(OKLCH_ACCESS)
{
	BOOST_CHECK_EQUAL(Oklch().lightness(), 0);
	BOOST_CHECK_EQUAL(Oklch().chroma(), 0);
	BOOST_CHECK_EQUAL(Oklch().hue(), 0);
	BOOST_CHECK_EQUAL(Oklch().alpha(), 1);
	BOOST_CHECK_EQUAL(Oklch().setLightness(2).lightness(), 2);
	BOOST_CHECK_EQUAL(Oklch().setChroma(2).chroma(), 2);
	BOOST_CHECK_EQUAL(Oklch().setHue(2).hue(), 2);
	BOOST_CHECK_EQUAL(Oklch().setAlpha(2).alpha(), 2);

	Oklch oklch(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(oklch.lightness(), 12);
	BOOST_CHECK_EQUAL(oklch.chroma(), 34);
	BOOST_CHECK_EQUAL(oklch.hue(), 56);
	BOOST_CHECK_EQUAL(oklch.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(SRGB_ACCESS)
{
	BOOST_CHECK_EQUAL(Srgb().red(), 0);
	BOOST_CHECK_EQUAL(Srgb().green(), 0);
	BOOST_CHECK_EQUAL(Srgb().blue(), 0);
	BOOST_CHECK_EQUAL(Srgb().alpha(), 1);
	BOOST_CHECK_EQUAL(Srgb().setRed(2).red(), 2);
	BOOST_CHECK_EQUAL(Srgb().setGreen(2).green(), 2);
	BOOST_CHECK_EQUAL(Srgb().setBlue(2).blue(), 2);
	BOOST_CHECK_EQUAL(Srgb().setAlpha(2).alpha(), 2);

	Srgb srgb(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(srgb.red(), 12);
	BOOST_CHECK_EQUAL(srgb.green(), 34);
	BOOST_CHECK_EQUAL(srgb.blue(), 56);
	BOOST_CHECK_EQUAL(srgb.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(DISPLAYP3_ACCESS)
{
	BOOST_CHECK_EQUAL(DisplayP3().red(), 0);
	BOOST_CHECK_EQUAL(DisplayP3().green(), 0);
	BOOST_CHECK_EQUAL(DisplayP3().blue(), 0);
	BOOST_CHECK_EQUAL(DisplayP3().alpha(), 1);
	BOOST_CHECK_EQUAL(DisplayP3().setRed(2).red(), 2);
	BOOST_CHECK_EQUAL(DisplayP3().setGreen(2).green(), 2);
	BOOST_CHECK_EQUAL(DisplayP3().setBlue(2).blue(), 2);
	BOOST_CHECK_EQUAL(DisplayP3().setAlpha(2).alpha(), 2);

	DisplayP3 displayP3(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(displayP3.red(), 12);
	BOOST_CHECK_EQUAL(displayP3.green(), 34);
	BOOST_CHECK_EQUAL(displayP3.blue(), 56);
	BOOST_CHECK_EQUAL(displayP3.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(A98RGB_ACCESS)
{
	BOOST_CHECK_EQUAL(A98Rgb().red(), 0);
	BOOST_CHECK_EQUAL(A98Rgb().green(), 0);
	BOOST_CHECK_EQUAL(A98Rgb().blue(), 0);
	BOOST_CHECK_EQUAL(A98Rgb().alpha(), 1);
	BOOST_CHECK_EQUAL(A98Rgb().setRed(2).red(), 2);
	BOOST_CHECK_EQUAL(A98Rgb().setGreen(2).green(), 2);
	BOOST_CHECK_EQUAL(A98Rgb().setBlue(2).blue(), 2);
	BOOST_CHECK_EQUAL(A98Rgb().setAlpha(2).alpha(), 2);

	A98Rgb a98Rgb(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(a98Rgb.red(), 12);
	BOOST_CHECK_EQUAL(a98Rgb.green(), 34);
	BOOST_CHECK_EQUAL(a98Rgb.blue(), 56);
	BOOST_CHECK_EQUAL(a98Rgb.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(PROPHOTORGB_ACCESS)
{
	BOOST_CHECK_EQUAL(ProphotoRgb().red(), 0);
	BOOST_CHECK_EQUAL(ProphotoRgb().green(), 0);
	BOOST_CHECK_EQUAL(ProphotoRgb().blue(), 0);
	BOOST_CHECK_EQUAL(ProphotoRgb().alpha(), 1);
	BOOST_CHECK_EQUAL(ProphotoRgb().setRed(2).red(), 2);
	BOOST_CHECK_EQUAL(ProphotoRgb().setGreen(2).green(), 2);
	BOOST_CHECK_EQUAL(ProphotoRgb().setBlue(2).blue(), 2);
	BOOST_CHECK_EQUAL(ProphotoRgb().setAlpha(2).alpha(), 2);

	ProphotoRgb prophotoRgb(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(prophotoRgb.red(), 12);
	BOOST_CHECK_EQUAL(prophotoRgb.green(), 34);
	BOOST_CHECK_EQUAL(prophotoRgb.blue(), 56);
	BOOST_CHECK_EQUAL(prophotoRgb.alpha(), 0.5);
}

BOOST_AUTO_TEST_CASE(REC2020_ACCESS)
{
	BOOST_CHECK_EQUAL(Rec2020().red(), 0);
	BOOST_CHECK_EQUAL(Rec2020().green(), 0);
	BOOST_CHECK_EQUAL(Rec2020().blue(), 0);
	BOOST_CHECK_EQUAL(Rec2020().alpha(), 1);
	BOOST_CHECK_EQUAL(Rec2020().setRed(2).red(), 2);
	BOOST_CHECK_EQUAL(Rec2020().setGreen(2).green(), 2);
	BOOST_CHECK_EQUAL(Rec2020().setBlue(2).blue(), 2);
	BOOST_CHECK_EQUAL(Rec2020().setAlpha(2).alpha(), 2);

	Rec2020 rec2020(12, 34, 56, 0.5);
	BOOST_CHECK_EQUAL(rec2020.red(), 12);
	BOOST_CHECK_EQUAL(rec2020.green(), 34);
	BOOST_CHECK_EQUAL(rec2020.blue(), 56);
	BOOST_CHECK_EQUAL(rec2020.alpha(), 0.5);
}
