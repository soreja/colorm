#include "pch.h"

#include <boost/test/unit_test.hpp>


using namespace colorm;

BOOST_AUTO_TEST_CASE(BLEND_NORMAL)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendNormal(Rgb(0x993366)).hex(), "#336699");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendNormal(Rgb(0x99ccff)).hex(), "#993366");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendNormal(Rgb(0x669933)).hex(), "#cc33cc");
	BOOST_CHECK_EQUAL(Rgb(0x336699, 0.4).blendNormal(Rgb(0x993366, 0.6)).hex(), "#634e81c2");
}

BOOST_AUTO_TEST_CASE(BLEND_MULTIPLY)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendMultiply(Rgb(0x993366)).hex(), "#1f143d");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendMultiply(Rgb(0x99ccff)).hex(), "#5c2966");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendMultiply(Rgb(0x669933)).hex(), "#521f29");
	BOOST_CHECK_EQUAL(Rgb(0x336699, 0.4).blendMultiply(Rgb(0x993366, 0.6)).hex(), "#5d3464c2");
}

BOOST_AUTO_TEST_CASE(BLEND_DARKEN)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendDarken(Rgb(0x993366)).hex(), "#333366");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendDarken(Rgb(0x99ccff)).hex(), "#993366");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendDarken(Rgb(0x669933)).hex(), "#663333");
}

BOOST_AUTO_TEST_CASE(BLEND_LIGHTEN)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendLighten(Rgb(0x993366)).hex(), "#996699");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendLighten(Rgb(0x99ccff)).hex(), "#99ccff");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendLighten(Rgb(0x669933)).hex(), "#cc99cc");
}

BOOST_AUTO_TEST_CASE(BLEND_SCREEN)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendScreen(Rgb(0x993366)).hex(), "#ad85c2");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendScreen(Rgb(0x99ccff)).hex(), "#d6d6ff");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendScreen(Rgb(0x669933)).hex(), "#e0add6");

	//E0ADD6
}

BOOST_AUTO_TEST_CASE(BLEND_OVERLAY)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendOverlay(Rgb(0x993366)).hex(), "#5c297a");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendOverlay(Rgb(0x99ccff)).hex(), "#adadff");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendOverlay(Rgb(0x669933)).hex(), "#a35c52");
}

BOOST_AUTO_TEST_CASE(BLEND_COLOR_DODGE)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendColorDodge(Rgb(0x993366)).hex(), "#bf55ff");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendColorDodge(Rgb(0x99ccff)).hex(), "#ffffff");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendColorDodge(Rgb(0x669933)).hex(), "#ffbfff");
}

BOOST_AUTO_TEST_CASE(BLEND_COLOR_BURN)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendColorBurn(Rgb(0x993366)).hex(), "#000000");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendColorBurn(Rgb(0x99ccff)).hex(), "#5500ff");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendColorBurn(Rgb(0x669933)).hex(), "#400000");
}

BOOST_AUTO_TEST_CASE(BLEND_HARD_LIGHT)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendHardLight(Rgb(0x993366)).hex(), "#3d2985");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendHardLight(Rgb(0x99ccff)).hex(), "#ad52cc");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendHardLight(Rgb(0x669933)).hex(), "#c23dad");
}

BOOST_AUTO_TEST_CASE(BLEND_SOFT_LIGHT)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendSoftLight(Rgb(0x993366)).hex(), "#742b72");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendSoftLight(Rgb(0x99ccff)).hex(), "#a2b4ff");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendSoftLight(Rgb(0x669933)).hex(), "#8a7459");
}

BOOST_AUTO_TEST_CASE(BLEND_DIFFERENCE)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendDifference(Rgb(0x993366)).hex(), "#663333");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendDifference(Rgb(0x99ccff)).hex(), "#009999");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendDifference(Rgb(0x669933)).hex(), "#666699");
}

BOOST_AUTO_TEST_CASE(BLEND_EXCLUSION)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendExclusion(Rgb(0x993366)).hex(), "#8f7085");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendExclusion(Rgb(0x99ccff)).hex(), "#7aad99");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendExclusion(Rgb(0x669933)).hex(), "#8f8fad");
}

BOOST_AUTO_TEST_CASE(BLEND_HUE)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendHue(Rgb(0x993366)).hex(), "#2e6194");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendHue(Rgb(0x99ccff)).hex(), "#ffa1d0");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendHue(Rgb(0x669933)).hex(), "#bb55bb");
	BOOST_CHECK_EQUAL(Rgb(0x336699, 0.4).blendHue(Rgb(0x669933)).hex(), "#5f9269");
}

BOOST_AUTO_TEST_CASE(BLEND_SASTURATION)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendSaturation(Rgb(0x993366)).hex(), "#993366");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendSaturation(Rgb(0x99ccff)).hex(), "#99ccff");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendSaturation(Rgb(0x669933)).hex(), "#5aa60d");
}

BOOST_AUTO_TEST_CASE(BLEND_COLOR)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendColor(Rgb(0x993366)).hex(), "#2e6194");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendColor(Rgb(0x99ccff)).hex(), "#ffa1d0");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendColor(Rgb(0x669933)).hex(), "#d940d9");
}

BOOST_AUTO_TEST_CASE(BLEND_LUMINOSITY)
{
	BOOST_CHECK_EQUAL(Rgb(0x336699).blendLuminosity(Rgb(0x993366)).hex(), "#9e386b");
	BOOST_CHECK_EQUAL(Rgb(0x993366).blendLuminosity(Rgb(0x99ccff)).hex(), "#2e6194");
	BOOST_CHECK_EQUAL(Rgb(0xcc33cc).blendLuminosity(Rgb(0x669933)).hex(), "#598c26");
}
