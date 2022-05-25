#include "pch.h"

#include <boost/test/unit_test.hpp>


using namespace colorm;

BOOST_AUTO_TEST_CASE(DARK_KHAKI)
{
	Rgb rgb(189, 183, 107);
	BOOST_CHECK_EQUAL(Hsl(rgb).vec(",666!"), "(55.609756, 38.317757, 58.039216)");
	BOOST_CHECK_EQUAL(Hwb(rgb).vec(",666!"), "(55.609756, 41.960784, 25.882353)");
	BOOST_CHECK_EQUAL(Lrgb(rgb).vec(",666!"), "(0.508881, 0.473531, 0.147027)");
	BOOST_CHECK_EQUAL(XyzD50(rgb).vec(",555!"), "(0.42532, 0.4616, 0.15805)");
	BOOST_CHECK_EQUAL(Lab(rgb).vec(",333!"), "(73.649, -5.816, 39.278)");
	BOOST_CHECK_EQUAL(Lch(rgb).vec(",333!"), "(73.649, 39.707, 98.423)");
	BOOST_CHECK_EQUAL(XyzD65(rgb).vec(",666!"), "(0.405721, 0.457477, 0.206034)");
	BOOST_CHECK_EQUAL(Oklab(rgb).vec(",666!"), "(0.767474, -0.024571, 0.09491)");
	BOOST_CHECK_EQUAL(Oklch(rgb).vec(",663!"), "(0.767474, 0.098039, 104.515)");
	BOOST_CHECK_EQUAL(Srgb(rgb).vec(",666!"), "(0.741176, 0.717647, 0.419608)");
	BOOST_CHECK_EQUAL(DisplayP3(rgb).vec(",666!"), "(0.73707, 0.718444, 0.457568)");
	BOOST_CHECK_EQUAL(A98Rgb(rgb).vec(",666!"), "(0.728869, 0.711834, 0.435194)");
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).vec(",555!"), "(0.63881, 0.6557, 0.39927)");
	BOOST_CHECK_EQUAL(Rec2020(rgb).vec(",666!"), "(0.691948, 0.685032, 0.410996)");
}

BOOST_AUTO_TEST_CASE(DARK_KHAKI_NEG)
{
	Rgb rgb(-189, -183, -107);
	BOOST_CHECK_EQUAL(Hwb(rgb).vec(",666!"), "(235.609756, -74.117647, 141.960784)");
	BOOST_CHECK_EQUAL(Lrgb(rgb).vec(",666!"), "(-0.508881, -0.473531, -0.147027)");
	BOOST_CHECK_EQUAL(XyzD50(rgb).vec(",555!"), "(-0.42532, -0.4616, -0.15805)");
	BOOST_CHECK_EQUAL(Lab(rgb).vec(",333!"), "(-416.965, 79.943, -420.584)");
	BOOST_CHECK_EQUAL(Lch(rgb).vec(",333!"), "(-416.965, 428.114, 280.762)");
	BOOST_CHECK_EQUAL(XyzD65(rgb).vec(",666!"), "(-0.405721, -0.457477, -0.206034)");
	BOOST_CHECK_EQUAL(Oklab(rgb).vec(",666!"), "(-0.767474, 0.024571, -0.09491)");
	BOOST_CHECK_EQUAL(Oklch(rgb).vec(",663!"), "(-0.767474, 0.098039, 284.515)");
	BOOST_CHECK_EQUAL(Srgb(rgb).vec(",666!"), "(-0.741176, -0.717647, -0.419608)");
	BOOST_CHECK_EQUAL(DisplayP3(rgb).vec(",666!"), "(-0.73707, -0.718444, -0.457568)");
	BOOST_CHECK_EQUAL(A98Rgb(rgb).vec(",666!"), "(-0.728869, -0.711834, -0.435194)");
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).vec(",555!"), "(-0.63881, -0.6557, -0.39927)");
	BOOST_CHECK_EQUAL(Rec2020(rgb).vec(",666!"), "(-0.691948, -0.685032, -0.410996)");
}

BOOST_AUTO_TEST_CASE(DARK_KHAKI_10)
{
	Rgb rgb(1890, 1830, 1070);
	BOOST_CHECK_EQUAL(Hwb(rgb).vec(",555!"), "(55.60976, 419.60784, -641.17647)");
	BOOST_CHECK_EQUAL(Lrgb(rgb).vec(",555!"), "(109.57514, 101.47008, 28.35254)");
	BOOST_CHECK_EQUAL(XyzD50(rgb).vec(",444!"), "(90.92, 98.841, 31.6231)");
	BOOST_CHECK_EQUAL(Lab(rgb).vec(",333!"), "(520.336, -36.069, 250.404)");
	BOOST_CHECK_EQUAL(Lch(rgb).vec(",333!"), "(520.336, 252.989, 98.197)");
	BOOST_CHECK_EQUAL(XyzD65(rgb).vec(",555!"), "(86.58898, 97.91501, 41.16288)");
	BOOST_CHECK_EQUAL(Oklab(rgb).vec(",555!"), "(4.59011, -0.1562, 0.60041)");
	BOOST_CHECK_EQUAL(Oklch(rgb).vec(",553!"), "(4.59011, 0.62039, 104.583)");
	BOOST_CHECK_EQUAL(Srgb(rgb).vec(",555!"), "(7.41176, 7.17647, 4.19608)");
	BOOST_CHECK_EQUAL(DisplayP3(rgb).vec(",555!"), "(7.37075, 7.18445, 4.58788)");
	BOOST_CHECK_EQUAL(A98Rgb(rgb).vec(",555!"), "(8.38042, 8.17139, 4.791)");
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).vec(",444!"), "(12.588, 12.9304, 7.5809)");
	BOOST_CHECK_EQUAL(Rec2020(rgb).vec(",555!"), "(8.76465, 8.6797, 5.42271)");
}

BOOST_AUTO_TEST_CASE(BLACK)
{
	Rgb rgb(0, 0, 0);
	BOOST_CHECK_EQUAL(Hsl(rgb).vec(",555!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(Hwb(rgb).vec(",555!"), "(0, 0, 100)");
	BOOST_CHECK_EQUAL(Lrgb(rgb).vec(",555!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(XyzD50(rgb).vec(",555!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(Lab(rgb).vec(",333!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(Lch(rgb).vec(",333!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(XyzD65(rgb).vec(",555!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(Oklab(rgb).vec(",555!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(Oklch(rgb).vec(",553!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(Srgb(rgb).vec(",555!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(DisplayP3(rgb).vec(",555!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(A98Rgb(rgb).vec(",555!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).vec(",555!"), "(0, 0, 0)");
	BOOST_CHECK_EQUAL(Rec2020(rgb).vec(",555!"), "(0, 0, 0)");
}

BOOST_AUTO_TEST_CASE(WHITE)
{
	Rgb rgb(255, 255, 255);
	BOOST_CHECK_EQUAL(Hsl(rgb).vec(",555!"), "(0, 0, 100)");
	BOOST_CHECK_EQUAL(Hwb(rgb).vec(",555!"), "(0, 100, 0)");
	BOOST_CHECK_EQUAL(Lrgb(rgb).vec(",555!"), "(1, 1, 1)");
	BOOST_CHECK_EQUAL(XyzD50(rgb).vec(",555!"), "(0.9643, 1, 0.8251)");
	BOOST_CHECK_EQUAL(Lab(rgb).vec(",333!"), "(100, 0, 0)");
	BOOST_CHECK_EQUAL(Lch(rgb).vec(",333!"), "(100, 0, 0)");
	BOOST_CHECK_EQUAL(XyzD65(rgb).vec(",555!"), "(0.95046, 1, 1.08906)");
	BOOST_CHECK_EQUAL(Oklab(rgb).vec(",555!"), "(1, 0, 0)");
	BOOST_CHECK_EQUAL(Oklch(rgb).vec(",553!"), "(1, 0, 0)");
	BOOST_CHECK_EQUAL(Srgb(rgb).vec(",555!"), "(1, 1, 1)");
	BOOST_CHECK_EQUAL(DisplayP3(rgb).vec(",555!"), "(1, 1, 1)");
	BOOST_CHECK_EQUAL(A98Rgb(rgb).vec(",555!"), "(1, 1, 1)");
	BOOST_CHECK_EQUAL(ProphotoRgb(rgb).vec(",555!"), "(1, 1, 1)");
	BOOST_CHECK_EQUAL(Rec2020(rgb).vec(",555!"), "(1, 1, 1)");
}

BOOST_AUTO_TEST_CASE(RGB)
{
	Rgb rgb(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Rgb(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Rgb(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Hsl(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Hsl(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Hwb(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Hwb(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Lrgb(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Lrgb(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(XyzD50(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(XyzD50(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Lab(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Lab(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Lch(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Lch(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(XyzD65(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(XyzD65(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Oklab(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Oklab(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Oklch(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Oklch(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Srgb(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Srgb(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(DisplayP3(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(DisplayP3(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(A98Rgb(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(A98Rgb(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(ProphotoRgb(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(ProphotoRgb(rgb)).alpha(), rgb.alpha());
	BOOST_CHECK_SMALL(rgb.distance(Rgb(Rec2020(rgb))), 1E-10);
	BOOST_CHECK_EQUAL(Rgb(Rec2020(rgb)).alpha(), rgb.alpha());
}

BOOST_AUTO_TEST_CASE(HSL)
{
	Hsl hsl(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Rgb(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Rgb(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Hsl(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Hsl(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Hwb(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Hwb(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Lrgb(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Lrgb(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(XyzD50(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(XyzD50(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Lab(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Lab(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Lch(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Lch(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(XyzD65(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(XyzD65(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Oklab(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Oklab(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Oklch(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Oklch(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Srgb(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Srgb(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(DisplayP3(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(DisplayP3(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(A98Rgb(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(A98Rgb(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(ProphotoRgb(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(ProphotoRgb(hsl)).alpha(), hsl.alpha());
	BOOST_CHECK_SMALL(hsl.distance(Hsl(Rec2020(hsl))), 1E-10);
	BOOST_CHECK_EQUAL(Hsl(Rec2020(hsl)).alpha(), hsl.alpha());
}

BOOST_AUTO_TEST_CASE(HWB)
{
	Hwb hwb(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Rgb(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Rgb(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Hsl(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Hsl(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Hwb(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Hwb(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Lrgb(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Lrgb(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(XyzD50(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(XyzD50(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Lab(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Lab(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Lch(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Lch(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(XyzD65(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(XyzD65(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Oklab(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Oklab(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Oklch(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Oklch(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Srgb(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Srgb(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(DisplayP3(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(DisplayP3(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(A98Rgb(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(A98Rgb(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(ProphotoRgb(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(ProphotoRgb(hwb)).alpha(), hwb.alpha());
	BOOST_CHECK_SMALL(hwb.distance(Hwb(Rec2020(hwb))), 1E-10);
	BOOST_CHECK_EQUAL(Hwb(Rec2020(hwb)).alpha(), hwb.alpha());
}

BOOST_AUTO_TEST_CASE(LRGB)
{
	Lrgb lrgb(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Rgb(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Rgb(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Hsl(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Hsl(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Hwb(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Hwb(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Lrgb(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Lrgb(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(XyzD50(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(XyzD50(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Lab(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Lab(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Lch(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Lch(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(XyzD65(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(XyzD65(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Oklab(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Oklab(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Oklch(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Oklch(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Srgb(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Srgb(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(DisplayP3(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(DisplayP3(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(A98Rgb(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(A98Rgb(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(ProphotoRgb(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(ProphotoRgb(lrgb)).alpha(), lrgb.alpha());
	BOOST_CHECK_SMALL(lrgb.distance(Lrgb(Rec2020(lrgb))), 1E-10);
	BOOST_CHECK_EQUAL(Lrgb(Rec2020(lrgb)).alpha(), lrgb.alpha());
}

BOOST_AUTO_TEST_CASE(XYZD50)
{
	XyzD50 xyzd50(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Rgb(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Rgb(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Hsl(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Hsl(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Hwb(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Hwb(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Lrgb(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Lrgb(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(XyzD50(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(XyzD50(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Lab(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Lab(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Lch(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Lch(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(XyzD65(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(XyzD65(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Oklab(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Oklab(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Oklch(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Oklch(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Srgb(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Srgb(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(DisplayP3(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(DisplayP3(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(A98Rgb(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(A98Rgb(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(ProphotoRgb(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(ProphotoRgb(xyzd50)).alpha(), xyzd50.alpha());
	BOOST_CHECK_SMALL(xyzd50.distance(XyzD50(Rec2020(xyzd50))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD50(Rec2020(xyzd50)).alpha(), xyzd50.alpha());
}

BOOST_AUTO_TEST_CASE(LAB)
{
	Lab lab(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(lab.distance(Lab(Rgb(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Rgb(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(Hsl(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Hsl(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(Hwb(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Hwb(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(Lrgb(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Lrgb(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(XyzD50(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(XyzD50(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(Lab(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Lab(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(Lch(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Lch(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(XyzD65(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(XyzD65(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(Oklab(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Oklab(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(Oklch(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Oklch(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(Srgb(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Srgb(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(DisplayP3(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(DisplayP3(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(A98Rgb(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(A98Rgb(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(ProphotoRgb(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(ProphotoRgb(lab)).alpha(), lab.alpha());
	BOOST_CHECK_SMALL(lab.distance(Lab(Rec2020(lab))), 1E-10);
	BOOST_CHECK_EQUAL(Lab(Rec2020(lab)).alpha(), lab.alpha());
}

BOOST_AUTO_TEST_CASE(LCH)
{
	Lch lch(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(lch.distance(Lch(Rgb(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Rgb(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(Hsl(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Hsl(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(Hwb(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Hwb(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(Lrgb(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Lrgb(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(XyzD50(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(XyzD50(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(Lab(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Lab(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(Lch(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Lch(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(XyzD65(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(XyzD65(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(Oklab(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Oklab(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(Oklch(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Oklch(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(Srgb(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Srgb(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(DisplayP3(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(DisplayP3(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(A98Rgb(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(A98Rgb(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(ProphotoRgb(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(ProphotoRgb(lch)).alpha(), lch.alpha());
	BOOST_CHECK_SMALL(lch.distance(Lch(Rec2020(lch))), 1E-10);
	BOOST_CHECK_EQUAL(Lch(Rec2020(lch)).alpha(), lch.alpha());
}

BOOST_AUTO_TEST_CASE(XYZD65)
{
	XyzD65 xyzd65(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Rgb(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Rgb(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Hsl(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Hsl(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Hwb(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Hwb(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Lrgb(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Lrgb(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(XyzD50(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(XyzD50(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Lab(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Lab(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Lch(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Lch(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(XyzD65(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(XyzD65(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Oklab(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Oklab(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Oklch(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Oklch(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Srgb(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Srgb(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(DisplayP3(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(DisplayP3(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(A98Rgb(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(A98Rgb(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(ProphotoRgb(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(ProphotoRgb(xyzd65)).alpha(), xyzd65.alpha());
	BOOST_CHECK_SMALL(xyzd65.distance(XyzD65(Rec2020(xyzd65))), 1E-10);
	BOOST_CHECK_EQUAL(XyzD65(Rec2020(xyzd65)).alpha(), xyzd65.alpha());
}

BOOST_AUTO_TEST_CASE(OKLAB)
{
	Oklab oklab(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Rgb(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Rgb(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Hsl(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Hsl(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Hwb(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Hwb(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Lrgb(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Lrgb(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(XyzD50(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(XyzD50(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Lab(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Lab(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Lch(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Lch(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(XyzD65(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(XyzD65(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Oklab(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Oklab(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Oklch(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Oklch(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Srgb(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Srgb(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(DisplayP3(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(DisplayP3(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(A98Rgb(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(A98Rgb(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(ProphotoRgb(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(ProphotoRgb(oklab)).alpha(), oklab.alpha());
	BOOST_CHECK_SMALL(oklab.distance(Oklab(Rec2020(oklab))), 1E-10);
	BOOST_CHECK_EQUAL(Oklab(Rec2020(oklab)).alpha(), oklab.alpha());
}

BOOST_AUTO_TEST_CASE(OKLCH)
{
	Oklch oklch(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Rgb(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Rgb(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Hsl(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Hsl(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Hwb(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Hwb(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Lrgb(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Lrgb(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(XyzD50(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(XyzD50(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Lab(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Lab(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Lch(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Lch(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(XyzD65(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(XyzD65(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Oklab(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Oklab(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Oklch(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Oklch(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Srgb(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Srgb(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(DisplayP3(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(DisplayP3(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(A98Rgb(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(A98Rgb(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(ProphotoRgb(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(ProphotoRgb(oklch)).alpha(), oklch.alpha());
	BOOST_CHECK_SMALL(oklch.distance(Oklch(Rec2020(oklch))), 1E-10);
	BOOST_CHECK_EQUAL(Oklch(Rec2020(oklch)).alpha(), oklch.alpha());
}

BOOST_AUTO_TEST_CASE(SRGB)
{
	Srgb srgb(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Rgb(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Rgb(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Hsl(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Hsl(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Hwb(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Hwb(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Lrgb(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Lrgb(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(XyzD50(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(XyzD50(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Lab(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Lab(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Lch(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Lch(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(XyzD65(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(XyzD65(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Oklab(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Oklab(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Oklch(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Oklch(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Srgb(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Srgb(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(DisplayP3(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(DisplayP3(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(A98Rgb(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(A98Rgb(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(ProphotoRgb(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(ProphotoRgb(srgb)).alpha(), srgb.alpha());
	BOOST_CHECK_SMALL(srgb.distance(Srgb(Rec2020(srgb))), 1E-10);
	BOOST_CHECK_EQUAL(Srgb(Rec2020(srgb)).alpha(), srgb.alpha());
}

BOOST_AUTO_TEST_CASE(DISPLAYP3)
{
	DisplayP3 displayp3(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Rgb(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Rgb(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Hsl(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Hsl(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Hwb(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Hwb(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Lrgb(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Lrgb(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(XyzD50(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(XyzD50(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Lab(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Lab(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Lch(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Lch(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(XyzD65(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(XyzD65(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Oklab(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Oklab(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Oklch(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Oklch(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Srgb(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Srgb(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(DisplayP3(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(DisplayP3(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(A98Rgb(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(A98Rgb(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(ProphotoRgb(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(ProphotoRgb(displayp3)).alpha(), displayp3.alpha());
	BOOST_CHECK_SMALL(displayp3.distance(DisplayP3(Rec2020(displayp3))), 1E-10);
	BOOST_CHECK_EQUAL(DisplayP3(Rec2020(displayp3)).alpha(), displayp3.alpha());
}

BOOST_AUTO_TEST_CASE(A98RGB)
{
	A98Rgb a98rgb(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Rgb(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Rgb(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Hsl(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Hsl(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Hwb(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Hwb(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Lrgb(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Lrgb(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(XyzD50(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(XyzD50(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Lab(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Lab(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Lch(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Lch(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(XyzD65(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(XyzD65(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Oklab(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Oklab(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Oklch(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Oklch(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Srgb(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Srgb(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(DisplayP3(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(DisplayP3(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(A98Rgb(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(A98Rgb(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(ProphotoRgb(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(ProphotoRgb(a98rgb)).alpha(), a98rgb.alpha());
	BOOST_CHECK_SMALL(a98rgb.distance(A98Rgb(Rec2020(a98rgb))), 1E-10);
	BOOST_CHECK_EQUAL(A98Rgb(Rec2020(a98rgb)).alpha(), a98rgb.alpha());
}

BOOST_AUTO_TEST_CASE(PROPHOTORGB)
{
	ProphotoRgb prophotorgb(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Rgb(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Rgb(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Hsl(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Hsl(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Hwb(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Hwb(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Lrgb(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Lrgb(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(XyzD50(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(XyzD50(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Lab(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Lab(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Lch(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Lch(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(XyzD65(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(XyzD65(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Oklab(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Oklab(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Oklch(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Oklch(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Srgb(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Srgb(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(DisplayP3(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(DisplayP3(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(A98Rgb(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(A98Rgb(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(ProphotoRgb(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(ProphotoRgb(prophotorgb)).alpha(), prophotorgb.alpha());
	BOOST_CHECK_SMALL(prophotorgb.distance(ProphotoRgb(Rec2020(prophotorgb))), 1E-10);
	BOOST_CHECK_EQUAL(ProphotoRgb(Rec2020(prophotorgb)).alpha(), prophotorgb.alpha());
}

BOOST_AUTO_TEST_CASE(REC2020)
{
	Rec2020 rec2020(Cn::Lightblue, 0.89);
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Rgb(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Rgb(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Hsl(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Hsl(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Hwb(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Hwb(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Lrgb(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Lrgb(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(XyzD50(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(XyzD50(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Lab(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Lab(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Lch(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Lch(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(XyzD65(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(XyzD65(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Oklab(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Oklab(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Oklch(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Oklch(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Srgb(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Srgb(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(DisplayP3(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(DisplayP3(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(A98Rgb(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(A98Rgb(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(ProphotoRgb(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(ProphotoRgb(rec2020)).alpha(), rec2020.alpha());
	BOOST_CHECK_SMALL(rec2020.distance(Rec2020(Rec2020(rec2020))), 1E-10);
	BOOST_CHECK_EQUAL(Rec2020(Rec2020(rec2020)).alpha(), rec2020.alpha());
}

BOOST_AUTO_TEST_CASE(HUE)
{
	BOOST_CHECK_EQUAL(Hsl(Rgb(Hsl(56 - 360, 38, 58))).vec(), "(56, 38, 58)");
	BOOST_CHECK_EQUAL(Hsl(Rgb(Hsl(56 + 360, 38, 58))).vec(), "(56, 38, 58)");
	BOOST_CHECK_EQUAL(Lch(Rgb(Lch(73.6, 39.7, 98.4 - 360))).vec(), "(73.6, 39.7, 98.4)");
	BOOST_CHECK_EQUAL(Lch(Rgb(Lch(73.6, 39.7, 98.4 + 360))).vec(), "(73.6, 39.7, 98.4)");
	BOOST_CHECK_EQUAL(Oklch(Rgb(Oklch(0.767, 0.098, 104.5 - 360.0))).vec(), "(0.767, 0.098, 104.5)");
	BOOST_CHECK_EQUAL(Oklch(Rgb(Oklch(0.767, 0.098, 104.5 - 360.0))).vec(), "(0.767, 0.098, 104.5)");
}

BOOST_AUTO_TEST_CASE(NEGATIVE_VALUE)
{
	Rgb rgb(300, -300, 300);
	const std::string rgbVec= rgb.vec(",666!");
	BOOST_CHECK_EQUAL(Rgb(Hwb(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(Lrgb(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(XyzD50(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(Lab(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(Lch(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(XyzD65(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(Oklab(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(Oklch(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(Srgb(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(DisplayP3(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(A98Rgb(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(ProphotoRgb(rgb)).vec(",666!"), rgbVec);
	BOOST_CHECK_EQUAL(Rgb(Rec2020(rgb)).vec(",666!"), rgbVec);
}

BOOST_AUTO_TEST_CASE(FULL_CONVERSION)
{
	Rgb rgb(Cn::Darkolivegreen, 0.2);
	BOOST_CHECK_EQUAL(Rec2020(ProphotoRgb(A98Rgb(DisplayP3(Srgb(Oklch(Hsl(Lch(Hwb(rgb))))))))).hex(), rgb.hex());
}
