#include "pch.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(OPERATOR)
{
	using Color = colorm::Oklab;

	const Color ca(1, 0, 0, 0);
	const Color cb(0, 1, 0, 0);
	const Color cc(0, 0, 1, 0);
	const Color cd(0, 0, 0, 1);
	const Color ce(0, 0, 0, 0);

	BOOST_CHECK(ca == ca && cb == cb && cc == cc && cd == cd);
	BOOST_CHECK(ca != cb && cb != cc && cc != cd && cd != ca);
	BOOST_CHECK(ca >= ca && cb >= cb && cc >= cc && cd >= cd);
	BOOST_CHECK(ca <= ca && cb <= cb && cc <= cc && cd <= cd);
	BOOST_CHECK(ca > cb && cb > cc && cc > cd && cd > ce);
	BOOST_CHECK(ce < cd && cd < cc && cc < cb && cb < ca);

	BOOST_CHECK(!(ca != ca) && !(cb != cb) && !(cc != cc) && !(cd != cd));
	BOOST_CHECK(!(ca == cb) && !(cb == cc) && !(cc == cd) && !(cd == ca));
	BOOST_CHECK(!(ca < ca) && !(cb < cb) && !(cc < cc) && !(cd < cd));
	BOOST_CHECK(!(ca > ca) && !(cb > cb) && !(cc > cc) && !(cd > cd));
	BOOST_CHECK(!(ca <= cb) && !(cb <= cc) && !(cc <= cd) && !(cd <= ce));
	BOOST_CHECK(!(ce >= cd) && !(cd >= cc) && !(cc >= cb) && !(cb >= ca));

	const Color c1(2, 3, 4, 5);
	const Color c2(4, 5, 6, 7);
	const Color c3(7, 15, 25, 37);
	const Color c4(5, 6, 7, 8);
	const Color c5(1, 2, 3, 4);

	BOOST_CHECK(c1 * c2 == Color(8, 15, 24, 35));
	BOOST_CHECK((c1 * c2 + c3) / c4 - c5 == c1);

	Color ct = c1;
	ct *= c2;
	BOOST_CHECK(ct == Color(8, 15, 24, 35));
	ct += c3;
	BOOST_CHECK(ct == Color(15, 30, 49, 72));
	ct /= c4;
	BOOST_CHECK(ct == Color(3, 5, 7, 9));
	ct -= c5;
	BOOST_CHECK(ct == c1);

	ct = c1 * 10;
	BOOST_CHECK(ct == Color(20, 30, 40, 50));
	ct = ct / 10;
	BOOST_CHECK(ct == Color(2, 3, 4, 5));
	ct = ct + 10;
	BOOST_CHECK(ct == Color(12, 13, 14, 15));
	ct = ct - 10;
	BOOST_CHECK(ct == Color(2, 3, 4, 5));
}
