#include "pch.h"

#include <boost/test/unit_test.hpp>


using namespace colorm;

BOOST_AUTO_TEST_CASE(CUBEHELIX)
{
	Cubehelix cu1;
	BOOST_CHECK_EQUAL(cu1(0.0).hex(), "#000000");
	BOOST_CHECK_EQUAL(cu1(0.2).hex(), "#163d4e");
	BOOST_CHECK_EQUAL(cu1(0.4).hex(), "#54792f");
	BOOST_CHECK_EQUAL(cu1(0.6).hex(), "#d07e93");
	BOOST_CHECK_EQUAL(cu1(0.8).hex(), "#c1caf3");
	BOOST_CHECK_EQUAL(cu1(1.0).hex(), "#ffffff");

	Cubehelix cu2(-0.5, -1.0, 0.9, 0.8);
	BOOST_CHECK_EQUAL(cu2(0.0).hex(), "#000000");
	BOOST_CHECK_EQUAL(cu2(0.2).hex(), "#2a5a28");
	BOOST_CHECK_EQUAL(cu2(0.4).hex(), "#937847");
	BOOST_CHECK_EQUAL(cu2(0.6).hex(), "#d692af");
	BOOST_CHECK_EQUAL(cu2(0.8).hex(), "#d9cef4");
	BOOST_CHECK_EQUAL(cu2(1.0).hex(), "#ffffff");

	Cubehelix cu3;
	cu3.setStart(-0.5).setRotations(-1.0).setHue(0.9).setGamma(0.8);
	BOOST_CHECK_EQUAL(cu2(0.6).hex(), cu3(0.6).hex());
}

BOOST_AUTO_TEST_CASE(COLOR_SCALE)
{
	const unsigned int shu   = 0xdd4827;
	const unsigned int moegi = 0x97a61e;
	const unsigned int ruri  = 0x00519a;

	Rgb rgbaShu(shu, 0.5), rgbaMoegi(moegi, 0.7), rgbaRuri(ruri, 0.9);

	Rgb    rgbShu(shu),    rgbMoegi(moegi),    rgbRuri(ruri);
	Hsl    hslShu(shu),    hslMoegi(moegi),    hslRuri(ruri);
	Hwb    hwbShu(shu),    hwbMoegi(moegi),    hwbRuri(ruri);
	Lrgb   lrgbShu(shu),   lrgbMoegi(moegi),   lrgbRuri(ruri);
	XyzD50 xyzD50Shu(shu), xyzD50Moegi(moegi), xyzD50Ruri(ruri);
	Lab    labShu(shu),    labMoegi(moegi),    labRuri(ruri);
	Lch    lchShu(shu),    lchMoegi(moegi),    lchRuri(ruri);
	XyzD65 xyzD65Shu(shu), xyzD65Moegi(moegi), xyzD65Ruri(ruri);
	Oklab  oklabShu(shu),  oklabMoegi(moegi),  oklabRuri(ruri);
	Oklch  oklchShu(shu),  oklchMoegi(moegi),  oklchRuri(ruri);
	Srgb        srgbShu(shu),        srgbMoegi(moegi),        srgbRuri(ruri);
	DisplayP3   displayP3Shu(shu),   displayP3Moegi(moegi),   displayP3Ruri(ruri);
	A98Rgb      a98RgbShu(shu),      a98RgbMoegi(moegi),      a98RgbRuri(ruri);
	ProphotoRgb prophotoRgbShu(shu), prophotoRgbMoegi(moegi), prophotoRgbRuri(ruri);
	Rec2020     rec2020Shu(shu),     rec2020Moegi(moegi),     rec2020Ruri(ruri);

	ColorScale<Rgb> cs1({rgbShu, rgbRuri});
	BOOST_CHECK_EQUAL(cs1(-1.0).cssf(), rgbShu.cssf());
	BOOST_CHECK_EQUAL(cs1(0.0).cssf(),  rgbShu.cssf());
	BOOST_CHECK_EQUAL(cs1(0.8).cssf(),  rgbShu.mix(rgbRuri, 0.8).cssf());
	BOOST_CHECK_EQUAL(cs1(1.0).cssf(),  rgbRuri.cssf());
	BOOST_CHECK_EQUAL(cs1(2.0).cssf(),  rgbRuri.cssf());
	BOOST_CHECK_EQUAL(cs1.colors(11).size(),    11U);
	BOOST_CHECK_EQUAL(cs1.colors(11)[3].cssf(), rgbShu.mix(rgbRuri, 0.3).cssf());

	BOOST_CHECK_EQUAL(cs1(-1.0, 0.5).cssf(), rgbShu.cssf());
	BOOST_CHECK_EQUAL(cs1(0.0, 0.5).cssf(),  rgbShu.cssf());
	BOOST_CHECK_EQUAL(cs1(0.8, 0.5).cssf(),  rgbShu.mix(rgbRuri, std::sqrt(0.8)).cssf());
	BOOST_CHECK_EQUAL(cs1(1.0, 0.5).cssf(),  rgbRuri.cssf());
	BOOST_CHECK_EQUAL(cs1(2.0, 0.5).cssf(),  rgbRuri.cssf());
	BOOST_CHECK_EQUAL(cs1.colors(11, 0.5)[3].cssf(), rgbShu.mix(rgbRuri, std::sqrt(0.3)).cssf());

	ColorScale<Rgb> cs1a({rgbaShu, rgbaRuri}, {100, 0});
	BOOST_CHECK_EQUAL(cs1a(100.0).cssf(), rgbaShu.cssf());
	BOOST_CHECK_EQUAL(cs1a(80.0).cssf(),  rgbaShu.mix(rgbaRuri, 0.2).cssf());
	BOOST_CHECK_EQUAL(cs1a(0.0).cssf(),   rgbaRuri.cssf());

	ColorScale<Rgb> cs1b({"#dd4827", "#00519a"}, {100, 0});
	BOOST_CHECK_EQUAL(cs1b(100.0).cssf(), rgbShu.cssf());
	BOOST_CHECK_EQUAL(cs1b(80.0).cssf(),  rgbShu.mix(rgbRuri, 0.2).cssf());
	BOOST_CHECK_EQUAL(cs1b(0.0).cssf(),   rgbRuri.cssf());

	ColorScale<Rgb> cs2({rgbaShu});
	BOOST_CHECK_EQUAL(cs2(-1.0).cssf(), rgbaShu.cssf());
	BOOST_CHECK_EQUAL(cs2(0.5).cssf(),  rgbaShu.cssf());
	BOOST_CHECK_EQUAL(cs2(2.0).cssf(),  rgbaShu.cssf());

	ColorScale<Rgb> cs3({rgbaShu, rgbaMoegi, rgbaRuri});
	BOOST_CHECK_EQUAL(cs3(0.0).cssf(), rgbaShu.cssf());
	BOOST_CHECK_EQUAL(cs3(0.2).cssf(), rgbaShu.mix(rgbaMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(cs3(0.5).cssf(), rgbaMoegi.cssf());
	BOOST_CHECK_EQUAL(cs3(0.8).cssf(), rgbaMoegi.mix(rgbaRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(cs3(1.0).cssf(), rgbaRuri.cssf());

	ColorScale<Rgb> cs4({rgbShu, rgbMoegi, rgbRuri}, {-20, -8, 40});
	BOOST_CHECK_EQUAL(cs4(16).cssf(), rgbMoegi.mix(rgbRuri, 0.5).cssf());

	auto cs4b = cs4.correctLightness();

	double lightness1 = (cs4b(40).lightness() - cs4b(-20).lightness()) * 0.2 + cs4b(-20).lightness();
	BOOST_CHECK_CLOSE(cs4b(-8).lightness(), lightness1, 1.0E-12);
	BOOST_CHECK_EQUAL(cs4b.getColorList().size(), 3U);
	BOOST_CHECK_EQUAL(cs4b.getColorList()[0].cssf(), oklabShu.cssf());
	BOOST_CHECK_EQUAL(cs4b.getColorList()[1].cssf(), Oklab(oklabMoegi).setLightness(lightness1).cssf());
	BOOST_CHECK_EQUAL(cs4b.getColorList()[2].cssf(), oklabRuri.cssf());
	BOOST_CHECK(cs4b.getColorList() == cs4b.colors());

	BOOST_CHECK_EQUAL(cs4b.getDomain().size(), 3U);
	BOOST_CHECK_EQUAL(cs4b.getDomain()[0], -20);
	BOOST_CHECK_EQUAL(cs4b.getDomain()[1], -8);
	BOOST_CHECK_EQUAL(cs4b.getDomain()[2], 40);

	double lightness2 = (cs4b(40).lightness() - cs4b(-20).lightness()) * 0.6 + cs4b(-20).lightness();
	BOOST_CHECK_CLOSE(cs4b(16).lightness(), lightness2, 1.0E-12);

	ColorScale<Rgb> cs5({Rgb(Cn::Black), rgbaShu, rgbaMoegi, rgbaRuri, Rgb(Cn::White)});
	BOOST_CHECK_EQUAL(cs5(0.75).cssf(), rgbaRuri.cssf());

	try {
		ColorScale<Rgb> cs6({"#abcde"});
		BOOST_ERROR("ColorScale<Rgb> cs6({\"#abcde\"}) should throw an exception.");
	} catch (const ParseError& e) {
		BOOST_CHECK_EQUAL(std::string(e.what()), "#abcde");
	}

	ColorScale<Rgb> csRgb({rgbShu, rgbMoegi});
	const std::string rgb08 = csRgb(0.8).cssf();
	BOOST_CHECK_EQUAL(rgb08, rgbShu.mix(rgbMoegi, 0.8).cssf());
	BOOST_CHECK_EQUAL(rgb08, csRgb.increasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(rgb08, csRgb.decreasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(rgb08, csRgb.shorter()(0.8).cssf());
	BOOST_CHECK_EQUAL(rgb08, csRgb.longer()(0.8).cssf());
	BOOST_CHECK_EQUAL(rgb08, csRgb.increasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(rgb08, csRgb.decreasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(rgb08, csRgb.shorter(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(rgb08, csRgb.longer(0)(0.8).cssf());

	ColorScale<Lrgb> csLrgb({lrgbShu, lrgbMoegi});
	const std::string lrgb08 = csLrgb(0.8).cssf();
	BOOST_CHECK_EQUAL(lrgb08, lrgbShu.mix(lrgbMoegi, 0.8).cssf());
	BOOST_CHECK_EQUAL(lrgb08, csLrgb.increasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(lrgb08, csLrgb.decreasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(lrgb08, csLrgb.shorter()(0.8).cssf());
	BOOST_CHECK_EQUAL(lrgb08, csLrgb.longer()(0.8).cssf());
	BOOST_CHECK_EQUAL(lrgb08, csLrgb.increasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(lrgb08, csLrgb.decreasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(lrgb08, csLrgb.shorter(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(lrgb08, csLrgb.longer(0)(0.8).cssf());

	ColorScale<XyzD50> csXyzD50({xyzD50Shu, xyzD50Moegi});
	const std::string xyzD5008 = csXyzD50(0.8).cssf();
	BOOST_CHECK_EQUAL(xyzD5008, xyzD50Shu.mix(xyzD50Moegi, 0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD5008, csXyzD50.increasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD5008, csXyzD50.decreasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD5008, csXyzD50.shorter()(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD5008, csXyzD50.longer()(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD5008, csXyzD50.increasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD5008, csXyzD50.decreasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD5008, csXyzD50.shorter(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD5008, csXyzD50.longer(0)(0.8).cssf());

	ColorScale<Lab> csLab({labShu, labMoegi});
	const std::string lab08 = csLab(0.8).cssf();
	BOOST_CHECK_EQUAL(lab08, labShu.mix(labMoegi, 0.8).cssf());
	BOOST_CHECK_EQUAL(lab08, csLab.increasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(lab08, csLab.decreasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(lab08, csLab.shorter()(0.8).cssf());
	BOOST_CHECK_EQUAL(lab08, csLab.longer()(0.8).cssf());
	BOOST_CHECK_EQUAL(lab08, csLab.increasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(lab08, csLab.decreasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(lab08, csLab.shorter(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(lab08, csLab.longer(0)(0.8).cssf());

	ColorScale<XyzD65> csXyzD65({xyzD65Shu, xyzD65Moegi});
	const std::string xyzD6508 = csXyzD65(0.8).cssf();
	BOOST_CHECK_EQUAL(xyzD6508, xyzD65Shu.mix(xyzD65Moegi, 0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD6508, csXyzD65.increasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD6508, csXyzD65.decreasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD6508, csXyzD65.shorter()(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD6508, csXyzD65.longer()(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD6508, csXyzD65.increasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD6508, csXyzD65.decreasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD6508, csXyzD65.shorter(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(xyzD6508, csXyzD65.longer(0)(0.8).cssf());

	ColorScale<Oklab> csOklab({oklabShu, oklabMoegi});
	const std::string oklab08 = csOklab(0.8).cssf();
	BOOST_CHECK_EQUAL(oklab08, oklabShu.mix(oklabMoegi, 0.8).cssf());
	BOOST_CHECK_EQUAL(oklab08, csOklab.increasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(oklab08, csOklab.decreasing()(0.8).cssf());
	BOOST_CHECK_EQUAL(oklab08, csOklab.shorter()(0.8).cssf());
	BOOST_CHECK_EQUAL(oklab08, csOklab.longer()(0.8).cssf());
	BOOST_CHECK_EQUAL(oklab08, csOklab.increasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(oklab08, csOklab.decreasing(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(oklab08, csOklab.shorter(0)(0.8).cssf());
	BOOST_CHECK_EQUAL(oklab08, csOklab.longer(0)(0.8).cssf());

	ColorScale<Hsl> csHsl1({hslShu, hslMoegi, hslRuri});
	BOOST_CHECK_EQUAL(csHsl1(0.8).cssf(),                          hslMoegi.mix(hslRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.decreasing()(0.8).cssf(),             hslMoegi.mix(hslRuri - Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.decreasing(1)(0.8).cssf(),            hslMoegi.mix(hslRuri - Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.decreasing(1).shorter(0)(0.8).cssf(), hslMoegi.mix(hslRuri - Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.decreasing(1).shorter(0)(0.2).cssf(), hslShu.mix(hslMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csHsl1.decreasing(0).shorter(1)(0.8).cssf(), hslMoegi.mix(hslRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.decreasing(0).shorter(1)(0.2).cssf(), hslShu.mix(hslMoegi - Hsl(360, 0, 0, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csHsl1.decreasing(0)(0.8).cssf(),            hslMoegi.mix(hslRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.longer()(0.8).cssf(),                 hslMoegi.mix(hslRuri - Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.longer(1)(0.8).cssf(),                hslMoegi.mix(hslRuri - Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.longer(1).increasing(0)(0.8).cssf(),  hslMoegi.mix(hslRuri - Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.longer(1).increasing(0)(0.2).cssf(),  hslShu.mix(hslMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csHsl1.longer(0).increasing(1)(0.8).cssf(),  hslMoegi.mix(hslRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl1.longer(0).increasing(1)(0.2).cssf(),  hslShu.mix(hslMoegi - Hsl(360, 0, 0, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csHsl1.longer(0)(0.8).cssf(),                hslMoegi.mix(hslRuri, 0.6).cssf());

	ColorScale<Hsl> csHsl2({hslRuri, hslMoegi, hslShu});
	BOOST_CHECK_EQUAL(csHsl2(0.8).cssf(),                          hslMoegi.mix(hslShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.increasing()(0.8).cssf(),             hslMoegi.mix(hslShu + Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.increasing(1)(0.8).cssf(),            hslMoegi.mix(hslShu + Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.increasing(1).shorter(0)(0.8).cssf(), hslMoegi.mix(hslShu + Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.increasing(1).shorter(0)(0.2).cssf(), hslRuri.mix(hslMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csHsl2.increasing(0).shorter(1)(0.8).cssf(), hslMoegi.mix(hslShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.increasing(0).shorter(1)(0.2).cssf(), hslRuri.mix(hslMoegi + Hsl(360, 0, 0, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csHsl2.increasing(0)(0.8).cssf(),            hslMoegi.mix(hslShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.longer()(0.8).cssf(),                 hslMoegi.mix(hslShu + Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.longer(1)(0.8).cssf(),                hslMoegi.mix(hslShu + Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.longer(1).decreasing(0)(0.8).cssf(),  hslMoegi.mix(hslShu + Hsl(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.longer(1).decreasing(0)(0.2).cssf(),  hslRuri.mix(hslMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csHsl2.longer(0).decreasing(1)(0.8).cssf(),  hslMoegi.mix(hslShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHsl2.longer(0).decreasing(1)(0.2).cssf(),  hslRuri.mix(hslMoegi + Hsl(360, 0, 0, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csHsl2.longer(0)(0.8).cssf(),                hslMoegi.mix(hslShu, 0.6).cssf());

	ColorScale<Hsl> csHsl3({hslMoegi, hslMoegi, hslMoegi});
	BOOST_CHECK_EQUAL(csHsl3(0.2).cssf(), hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3(0.8).cssf(), hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.increasing()(0.2).cssf(),  hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.increasing()(0.8).cssf(),  hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.increasing(0)(0.2).cssf(), hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.increasing(1)(0.8).cssf(), hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.decreasing()(0.2).cssf(),  hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.decreasing()(0.8).cssf(),  hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.decreasing(0)(0.2).cssf(), hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.decreasing(1)(0.8).cssf(), hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.shorter()(0.2).cssf(),  hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.shorter()(0.8).cssf(),  hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.shorter(0)(0.2).cssf(), hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.shorter(1)(0.8).cssf(), hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.longer()(0.2).cssf(),   hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.longer()(0.8).cssf(),   hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.longer(0)(0.2).cssf(),  hslMoegi.cssf());
	BOOST_CHECK_EQUAL(csHsl3.longer(1)(0.8).cssf(),  hslMoegi.cssf());

	ColorScale<Hwb> csHwb1({hwbShu, hwbMoegi, hwbRuri});
	BOOST_CHECK_EQUAL(csHwb1(0.8).cssf(),                          hwbMoegi.mix(hwbRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.decreasing()(0.8).cssf(),             hwbMoegi.mix(hwbRuri - Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.decreasing(1)(0.8).cssf(),            hwbMoegi.mix(hwbRuri - Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.decreasing(1).shorter(0)(0.8).cssf(), hwbMoegi.mix(hwbRuri - Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.decreasing(1).shorter(0)(0.2).cssf(), hwbShu.mix(hwbMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csHwb1.decreasing(0).shorter(1)(0.8).cssf(), hwbMoegi.mix(hwbRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.decreasing(0).shorter(1)(0.2).cssf(), hwbShu.mix(hwbMoegi - Hwb(360, 0, 0, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csHwb1.decreasing(0)(0.8).cssf(),            hwbMoegi.mix(hwbRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.longer()(0.8).cssf(),                 hwbMoegi.mix(hwbRuri - Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.longer(1)(0.8).cssf(),                hwbMoegi.mix(hwbRuri - Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.longer(1).increasing(0)(0.8).cssf(),  hwbMoegi.mix(hwbRuri - Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.longer(1).increasing(0)(0.2).cssf(),  hwbShu.mix(hwbMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csHwb1.longer(0).increasing(1)(0.8).cssf(),  hwbMoegi.mix(hwbRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb1.longer(0).increasing(1)(0.2).cssf(),  hwbShu.mix(hwbMoegi - Hwb(360, 0, 0, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csHwb1.longer(0)(0.8).cssf(),                hwbMoegi.mix(hwbRuri, 0.6).cssf());

	ColorScale<Hwb> csHwb2({hwbRuri, hwbMoegi, hwbShu});
	BOOST_CHECK_EQUAL(csHwb2(0.8).cssf(),                          hwbMoegi.mix(hwbShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.increasing()(0.8).cssf(),             hwbMoegi.mix(hwbShu + Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.increasing(1)(0.8).cssf(),            hwbMoegi.mix(hwbShu + Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.increasing(1).shorter(0)(0.8).cssf(), hwbMoegi.mix(hwbShu + Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.increasing(1).shorter(0)(0.2).cssf(), hwbRuri.mix(hwbMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csHwb2.increasing(0).shorter(1)(0.8).cssf(), hwbMoegi.mix(hwbShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.increasing(0).shorter(1)(0.2).cssf(), hwbRuri.mix(hwbMoegi + Hwb(360, 0, 0, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csHwb2.increasing(0)(0.8).cssf(),            hwbMoegi.mix(hwbShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.longer()(0.8).cssf(),                 hwbMoegi.mix(hwbShu + Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.longer(1)(0.8).cssf(),                hwbMoegi.mix(hwbShu + Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.longer(1).decreasing(0)(0.8).cssf(),  hwbMoegi.mix(hwbShu + Hwb(360, 0, 0, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.longer(1).decreasing(0)(0.2).cssf(),  hwbRuri.mix(hwbMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csHwb2.longer(0).decreasing(1)(0.8).cssf(),  hwbMoegi.mix(hwbShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csHwb2.longer(0).decreasing(1)(0.2).cssf(),  hwbRuri.mix(hwbMoegi + Hwb(360, 0, 0, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csHwb2.longer(0)(0.8).cssf(),                hwbMoegi.mix(hwbShu, 0.6).cssf());
	
	ColorScale<Lch> csLch1({lchShu, lchMoegi, lchRuri});
	BOOST_CHECK_EQUAL(csLch1(0.8).cssf(),                          lchMoegi.mix(lchRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.decreasing()(0.8).cssf(),             lchMoegi.mix(lchRuri - Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.decreasing(1)(0.8).cssf(),            lchMoegi.mix(lchRuri - Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.decreasing(1).shorter(0)(0.8).cssf(), lchMoegi.mix(lchRuri - Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.decreasing(1).shorter(0)(0.2).cssf(), lchShu.mix(lchMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csLch1.decreasing(0).shorter(1)(0.8).cssf(), lchMoegi.mix(lchRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.decreasing(0).shorter(1)(0.2).cssf(), lchShu.mix(lchMoegi - Lch(0, 0, 360, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csLch1.decreasing(0)(0.8).cssf(),            lchMoegi.mix(lchRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.longer()(0.8).cssf(),                 lchMoegi.mix(lchRuri - Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.longer(1)(0.8).cssf(),                lchMoegi.mix(lchRuri - Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.longer(1).increasing(0)(0.8).cssf(),  lchMoegi.mix(lchRuri - Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.longer(1).increasing(0)(0.2).cssf(),  lchShu.mix(lchMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csLch1.longer(0).increasing(1)(0.8).cssf(),  lchMoegi.mix(lchRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch1.longer(0).increasing(1)(0.2).cssf(),  lchShu.mix(lchMoegi - Lch(0, 0, 360, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csLch1.longer(0)(0.8).cssf(),                lchMoegi.mix(lchRuri, 0.6).cssf());

	ColorScale<Lch> csLch2({lchRuri, lchMoegi, lchShu});
	BOOST_CHECK_EQUAL(csLch2(0.8).cssf(),                          lchMoegi.mix(lchShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.increasing()(0.8).cssf(),             lchMoegi.mix(lchShu + Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.increasing(1)(0.8).cssf(),            lchMoegi.mix(lchShu + Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.increasing(1).shorter(0)(0.8).cssf(), lchMoegi.mix(lchShu + Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.increasing(1).shorter(0)(0.2).cssf(), lchRuri.mix(lchMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csLch2.increasing(0).shorter(1)(0.8).cssf(), lchMoegi.mix(lchShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.increasing(0).shorter(1)(0.2).cssf(), lchRuri.mix(lchMoegi + Lch(0, 0, 360, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csLch2.increasing(0)(0.8).cssf(),            lchMoegi.mix(lchShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.longer()(0.8).cssf(),                 lchMoegi.mix(lchShu + Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.longer(1)(0.8).cssf(),                lchMoegi.mix(lchShu + Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.longer(1).decreasing(0)(0.8).cssf(),  lchMoegi.mix(lchShu + Lch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.longer(1).decreasing(0)(0.2).cssf(),  lchRuri.mix(lchMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csLch2.longer(0).decreasing(1)(0.8).cssf(),  lchMoegi.mix(lchShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csLch2.longer(0).decreasing(1)(0.2).cssf(),  lchRuri.mix(lchMoegi + Lch(0, 0, 360, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csLch2.longer(0)(0.8).cssf(),                lchMoegi.mix(lchShu, 0.6).cssf());

	ColorScale<Oklch> csOklch1({oklchShu, oklchMoegi, oklchRuri});
	BOOST_CHECK_EQUAL(csOklch1(0.8).cssf(),                          oklchMoegi.mix(oklchRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.decreasing()(0.8).cssf(),             oklchMoegi.mix(oklchRuri - Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.decreasing(1)(0.8).cssf(),            oklchMoegi.mix(oklchRuri - Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.decreasing(1).shorter(0)(0.8).cssf(), oklchMoegi.mix(oklchRuri - Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.decreasing(1).shorter(0)(0.2).cssf(), oklchShu.mix(oklchMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csOklch1.decreasing(0).shorter(1)(0.8).cssf(), oklchMoegi.mix(oklchRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.decreasing(0).shorter(1)(0.2).cssf(), oklchShu.mix(oklchMoegi - Oklch(0, 0, 360, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csOklch1.decreasing(0)(0.8).cssf(),            oklchMoegi.mix(oklchRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.longer()(0.8).cssf(),                 oklchMoegi.mix(oklchRuri - Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.longer(1)(0.8).cssf(),                oklchMoegi.mix(oklchRuri - Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.longer(1).increasing(0)(0.8).cssf(),  oklchMoegi.mix(oklchRuri - Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.longer(1).increasing(0)(0.2).cssf(),  oklchShu.mix(oklchMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csOklch1.longer(0).increasing(1)(0.8).cssf(),  oklchMoegi.mix(oklchRuri, 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch1.longer(0).increasing(1)(0.2).cssf(),  oklchShu.mix(oklchMoegi - Oklch(0, 0, 360, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csOklch1.longer(0)(0.8).cssf(),                oklchMoegi.mix(oklchRuri, 0.6).cssf());

	ColorScale<Oklch> csOklch2({oklchRuri, oklchMoegi, oklchShu});
	BOOST_CHECK_EQUAL(csOklch2(0.8).cssf(),                          oklchMoegi.mix(oklchShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.increasing()(0.8).cssf(),             oklchMoegi.mix(oklchShu + Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.increasing(1)(0.8).cssf(),            oklchMoegi.mix(oklchShu + Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.increasing(1).shorter(0)(0.8).cssf(), oklchMoegi.mix(oklchShu + Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.increasing(1).shorter(0)(0.2).cssf(), oklchRuri.mix(oklchMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csOklch2.increasing(0).shorter(1)(0.8).cssf(), oklchMoegi.mix(oklchShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.increasing(0).shorter(1)(0.2).cssf(), oklchRuri.mix(oklchMoegi + Oklch(0, 0, 360, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csOklch2.increasing(0)(0.8).cssf(),            oklchMoegi.mix(oklchShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.longer()(0.8).cssf(),                 oklchMoegi.mix(oklchShu + Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.longer(1)(0.8).cssf(),                oklchMoegi.mix(oklchShu + Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.longer(1).decreasing(0)(0.8).cssf(),  oklchMoegi.mix(oklchShu + Oklch(0, 0, 360, 0), 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.longer(1).decreasing(0)(0.2).cssf(),  oklchRuri.mix(oklchMoegi, 0.4).cssf());
	BOOST_CHECK_EQUAL(csOklch2.longer(0).decreasing(1)(0.8).cssf(),  oklchMoegi.mix(oklchShu, 0.6).cssf());
	BOOST_CHECK_EQUAL(csOklch2.longer(0).decreasing(1)(0.2).cssf(),  oklchRuri.mix(oklchMoegi + Oklch(0, 0, 360, 0), 0.4).cssf());
	BOOST_CHECK_EQUAL(csOklch2.longer(0)(0.8).cssf(),                oklchMoegi.mix(oklchShu, 0.6).cssf());
}

BOOST_AUTO_TEST_CASE(COLOR_SCALE_BEZIER)
{
	Oklab oklabRed(Cn::Red), oklabYellow(Cn::Yellow), oklabBlue(Cn::Blue);
	Oklab oklab03  = oklabRed.mix(oklabYellow, 0.3).mix(oklabYellow.mix(oklabBlue, 0.3), 0.3);
	Oklab oklab064 = oklabRed.mix(oklabYellow, 0.64).mix(oklabYellow.mix(oklabBlue, 0.64), 0.64);

	ColorScaleBezier csb1({oklabRed, oklabYellow, oklabBlue});
	BOOST_CHECK_EQUAL(csb1(-1.0).cssf(),     oklabRed.cssf());
	BOOST_CHECK_EQUAL(csb1(0.0).cssf(),      oklabRed.cssf());
	BOOST_CHECK_EQUAL(csb1(0.64).cssf(),     oklab064.cssf());
	BOOST_CHECK_EQUAL(csb1(0.8, 2.0).cssf(), oklab064.cssf());
	BOOST_CHECK_EQUAL(csb1(1.0).cssf(),      oklabBlue.cssf());
	BOOST_CHECK_EQUAL(csb1(2.0).cssf(),      oklabBlue.cssf());
	BOOST_CHECK_EQUAL(csb1.colors(11).size(),        11U);
	BOOST_CHECK_EQUAL(csb1.colors(11)[3].cssf(),     oklab03.cssf());
	BOOST_CHECK_EQUAL(csb1.colors(6, 2.0).size(),    6U);
	BOOST_CHECK_EQUAL(csb1.colors(6, 2.0)[4].cssf(), oklab064.cssf());

	ColorScaleBezier csb2({oklabRed, oklabYellow, oklabBlue}, {10.0, -10.0});
	BOOST_CHECK_EQUAL(csb2(11.0).cssf(),    oklabRed.cssf());
	BOOST_CHECK_EQUAL(csb2(10.0).cssf(),    oklabRed.cssf());
	BOOST_CHECK_EQUAL(csb2(-2.8).cssf(),    oklab064.cssf());
	BOOST_CHECK_EQUAL(csb2(-6, 2.0).cssf(), oklab064.cssf());
	BOOST_CHECK_EQUAL(csb2(-10.0).cssf(),   oklabBlue.cssf());
	BOOST_CHECK_EQUAL(csb2(-11.0).cssf(),   oklabBlue.cssf());

	BOOST_CHECK_EQUAL(csb2.getColorList().size(), 3U);
	BOOST_CHECK_EQUAL(csb2.getColorList()[0].cssf(), oklabRed.cssf());
	BOOST_CHECK_EQUAL(csb2.getColorList()[1].cssf(), oklabYellow.cssf());
	BOOST_CHECK_EQUAL(csb2.getColorList()[2].cssf(), oklabBlue.cssf());
	BOOST_CHECK(csb2.getColorList() == csb2.colors());

	BOOST_CHECK_EQUAL(csb2.getDomain()[0], 10.0);
	BOOST_CHECK_EQUAL(csb2.getDomain()[1], -10.0);
}
