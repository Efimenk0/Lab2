#include "Deltoid.h"


#define PI 3.14159265

namespace Del {

	Deltoid::Deltoid(double r1) {
		if (r1 < 0)
			throw std::invalid_argument("Радиус малой окружности не может быть отрицательным. Попробуйте еще раз.");
		r = r1;
	}

	Deltoid& Deltoid::setr(double r1) {
		if (r1 <= 0)
			throw std::invalid_argument("Радиус малой окружности не может быть отрицательным. Попробуйте еще раз.");
			r = r1;
			return *this;
	}

	double Deltoid::get_length() const {
		return r * 16 / 3;
	}

	double Deltoid::get_area() const {
		return 2 * PI * r * r / 9;
	}

	std::string Deltoid::equation() const {
		std::string eq = "(x^2 + y^2)^2 + 18(x^2 + y^2) = 8x^3 - 24y^2x + 27";
		return eq;
	}

	Deltoid& Deltoid::get_coords(double t, double& x, double& y) {
		x = 2 * r * cos(t * PI / 180) + r * cos(2 * t * PI / 180);
		y = 2 * r * sin(t * PI / 180) + r * sin(2 * t * PI / 180);
		return *this;
	}

	double Deltoid::get_length_of_intersection() const {
		return 4* r;
	}


}