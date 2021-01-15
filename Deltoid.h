#ifndef DELTOID_H
#define DELTOID_H

#include <exception>
#include <iostream>
#include <cmath>

using namespace std;

namespace Del
{
	class Deltoida {
		float r, R;                                 //��������� ������
	public:
		Deltoida(float r = 0, float R = 0);         //����������� ������
		Deltoida& setr(float r); //  ������ ��� r
		Deltoida& setR(float R); //  ������ ��� R
		float getr() const { return r; } //  ������ ��� r
		float getR() const { return R; } //  ������ ��� R
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

