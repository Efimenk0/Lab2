#ifndef DELTOID_H
#define DELTOID_H

#include <exception>
#include <iostream>
#include <cmath>

using namespace std;

namespace Del
{
	class Deltoida {
		float r, R;                                 //состояние класса
	public:
		Deltoida(float r = 0, float R = 0);         //конструктор класса
		Deltoida& setr(float r); //  сеттер для r
		Deltoida& setR(float R); //  сеттер для R
		float getr() const { return r; } //  геттер для r
		float getR() const { return R; } //  геттер для R
		float outputLengthOfCurve();
		float  outputAreaOfCurve();
		void equation();
		int coordinateValuesDependingT(float t, float r, float R, float* X, float* Y);
		float lengthOfTheIntersection(float r, float R, float X, float Y, float T);
	};

	void getFloat(float& a);

	int dialog(Deltoida MyObj);

	void showOptions();
}


#endif // !DELTOID_H

