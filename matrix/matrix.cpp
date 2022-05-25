#include <fstream>
#include <sstream>

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_access.hpp>
#include <boost/qvm/mat_operations.hpp>

using Matrix3x3 = boost::qvm::mat<double, 3, 3>;
using Vector3 = boost::qvm::mat<double, 3, 1>;

std::string ToString(const Matrix3x3& m)
{
    using namespace boost::qvm;

    std::ostringstream o;
    o.precision(16);
    o   << A00(m) << ", "
        << A01(m) << ", "
        << A02(m) << '\n'
        << A10(m) << ", "
        << A11(m) << ", "
        << A12(m) << '\n'
        << A20(m) << ", "
        << A21(m) << ", "
        << A22(m) << std::endl;
    return o.str();
}


// http://www.brucelindbloom.com/index.html?Eqn_RGB_XYZ_Matrix.html

Matrix3x3 compute(
	double xr, double yr,
	double xg, double yg,
	double xb, double yb,
	double XW, double YW, double ZW)
{
	using namespace boost::qvm;

	const double Xr = xr / yr;
	const double Yr = 1.0;
	const double Zr = (1.0 - xr - yr) / yr;

	const double Xg = xg / yg;
	const double Yg = 1.0;
	const double Zg = (1.0 - xg - yg) / yg;

	const double Xb = xb / yb;
	const double Yb = 1.0;
	const double Zb = (1.0 - xb - yb) / yb;

	const Matrix3x3 m = {
		Xr, Xg, Xb,
		Yr, Yg, Yb,
		Zr, Zg, Zb
	};

	const Vector3 v = {XW, YW, ZW};
	const auto mi = inverse(m);
	const auto s = mi * v;
	const Matrix3x3 m2 = {
		A00(s) * Xr, A10(s) * Xg, A20(s) * Xb,
		A00(s) * Yr, A10(s) * Yg, A20(s) * Yb,
		A00(s) * Zr, A10(s) * Zg, A20(s) * Zb
	};

	return m2;
}


// http://www.brucelindbloom.com/index.html?Eqn_xyY_to_XYZ.html

Matrix3x3 compute(
	double xr, double yr,
	double xg, double yg,
	double xb, double yb,
	double x, double y)
{
	return compute(xr, yr, xg, yg, xb, yb, x / y, 1.0, (1.0 - x - y) / y);
}


// http://www.brucelindbloom.com/index.html?Eqn_ChromAdapt.html

Matrix3x3 getAdaptationMatrix(
	double XWS, double YWS, double ZWS,
	double XWD, double YWD, double ZWD)
{
	using namespace boost::qvm;

	Matrix3x3 MA = {
		 0.8951,  0.2664, -0.1614,
		-0.7502,  1.7135,  0.0367,
		 0.0389, -0.0685,  1.0296
	};
	
	/* This matrix is not accurate. Don't use this.
	Matrix3x3 MAi = {
		 0.9869929, -0.1470543, 0.1599627,
		 0.4323053,  0.5183603, 0.0492912,
		-0.0085287,  0.0400428, 0.9684867
	};
	*/
	
	const auto MAi = inverse(MA);

	const Vector3 WS = {XWS, YWS, ZWS};
	const auto VS = MA * WS;

	const Vector3 WD = {XWD, YWD, ZWD};
	const auto VD = MA * WD;

	const Matrix3x3 MT = {
		A00(VD) / A00(VS), 0.0, 0.0,
		0.0, A10(VD) / A10(VS), 0.0,
		0.0, 0.0, A20(VD) / A20(VS)
	};
	const auto m = MAi * MT * MA;

	return m;
}


// http://www.brucelindbloom.com/index.html?Eqn_xyY_to_XYZ.html

Matrix3x3 getAdaptationMatrix(
	double x1, double y1,
	double x2, double y2)
{
	return getAdaptationMatrix(x1 / y1, 1.0, (1.0 - x1 - y1) / y1, x2 / y2, 1.0, (1.0 - x2 - y2) / y2);
}

void XYZ(std::ostream& o)
{
	using namespace boost::qvm;

	const auto m1 = compute(0.64, 0.33, 0.3, 0.6, 0.15, 0.06, 0.3127, 0.3290);
	const auto a = getAdaptationMatrix(0.3127, 0.3290, 0.3457, 0.3585);
	const auto m = a * m1;

	o << "LinearRGB -> XYZ(D50)\n" << ToString(m) << "\n\n";
	o << "LinearRGB -> XYZ(D65)\n" << ToString(m1) << "\n\n";
	o << "XYZ(D50) -> LinearRGB\n" << ToString(inverse(m)) << "\n\n";
	o << "XYZ(D65) -> LinearRGB\n" << ToString(inverse(m1)) << "\n\n";
}

void Oklab(std::ostream& o)
{
	using namespace boost::qvm;

	Matrix3x3 m1_1 = {
		1.0,  0.3963377774,  0.2158037573,
		1.0, -0.1055613458, -0.0638541728,
		1.0, -0.0894841775, -1.2914855480
	};

	Matrix3x3 m2_1 = {
		4.0767416621,  -3.3077115913,  0.2309699292,
		-1.2684380046,  2.6097574011, -0.3413193965,
		-0.0041960863, -0.7034186147,  1.7076147010
	};

	o << "LinearRGB -> Oklab\n";
	o << "M1:\n" << ToString(inverse(m1_1));
	o << "M2:\n" << ToString(inverse(m2_1)) << "\n\n";

	o << "Oklab -> LinearRGB\n";
	o << "M1-1:\n" << ToString(m1_1);
	o << "M2-1:\n" << ToString(m2_1) << "\n\n";
}

void DisplayP3(std::ostream& o)
{
	using namespace boost::qvm;

	const auto m = compute(0.68, 0.32, 0.265, 0.69, 0.15, 0.06, 0.3127, 0.3290);

	o << "display-p3 -> XYZ(D65)\n" << ToString(m) << "\n\n";
	o << "XYZ(D65) -> display-p3\n" << ToString(inverse(m)) << "\n\n";
}

void A98Rgb(std::ostream& o)
{
	using namespace boost::qvm;

	const auto m = compute(0.64, 0.33, 0.21, 0.71, 0.15, 0.06, 0.3127, 0.3290);

	o << "a98-rgb -> XYZ(D65)\n" << ToString(m) << "\n\n";
	o << "XYZ(D65) -> a98-rgb\n" << ToString(inverse(m)) << "\n\n";
}

void ProphotoRgb(std::ostream& o)
{
	using namespace boost::qvm;

	const auto m1 = compute(0.734699, 0.265301, 0.159597, 0.840403, 0.036598, 0.000105, 0.3457, 0.3585);
	const auto a = getAdaptationMatrix(0.3457, 0.3585, 0.3127, 0.3290);
	const auto m = a * m1;

	o << "prophoto-rgb -> XYZ(D65)\n" << ToString(m) << "\n\n";
	o << "XYZ(D65) -> prophoto-rgb\n" << ToString(inverse(m)) << "\n\n";
}

void Rec2020(std::ostream& o)
{
	using namespace boost::qvm;

	const auto m = compute(0.708, 0.292, 0.170, 0.797, 0.131, 0.046, 0.3127, 0.3290);
	o << "rec2020 -> XYZ(D65)\n" << ToString(m) << "\n\n";
	o << "XYZ(D65) -> rec2020\n" << ToString(inverse(m)) << "\n\n";

	o << "Rec.ITU - R BT.2020 - 2 Table 4\n";
	o << "alpha: 1.09929682680944\n";
	o << "beta:  0.018053968510807\n\n";
}

int main()
{
    std::ofstream o("matrices.txt");
	XYZ(o);
	Oklab(o);
	DisplayP3(o);
	A98Rgb(o);
	ProphotoRgb(o);
	Rec2020(o);
}
