#include "Deltoid.h"

#define PI 3.14159265

namespace Del {

	Deltoida::Deltoida(float r1, float R1) {
		r = r1;
		R = R1;
	}

	Deltoida& Deltoida::setr(float r2) {
		if (r2 <= 0)
			throw std::invalid_argument("Try again! Enter a positive number!");
			r = r2;
			return *this;
	}

	Deltoida& Deltoida::setR(float R2) {
		if (R2 <= 0)
			throw std::invalid_argument("Try again! Enter a positive number!");
		R = R2;
		return *this;
	}

	float Deltoida::outputLengthOfCurve() {
		float Res = R * 16 / 3;
		return Res;
	}

	float Deltoida::outputAreaOfCurve() {
		float Res = 2 * PI * R * R / 9;
		return Res;
	}

	void Deltoida::equation() {
		string eq = "(x^2 + y^2)^2 + 18(x^2 + y^2) = 8x^3 - 24y^2x + 27";
		cout << "\n*****<<+>>*****\n>Equation in the Cartesian coordinate system:\n>" << eq;
	}

	int Deltoida::coordinateValuesDependingT(float t, float r, float R, float* X, float* Y) {
		float x = (R - r) * cos(t * PI / 180) + r * cos(((R - r) / r) * t * PI / 180);
		float y = (R - r) * sin(t * PI / 180) + r * sin(((R - r) / r) * t * PI / 180);
		*X = x;
		*Y = y;

		return 0;
	}
	float Deltoida::lengthOfTheIntersection(float r, float R, float X, float Y, float T) {
		return (R + r) / 7 * cos(T * PI / 180);
	}


}