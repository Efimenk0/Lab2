#include "lab2.h"


namespace Lab2
{
	void getFloat(float& a)
	{
		while (1)
		{
			if (std::cin >> a)
				break;

			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Try again!\n>";
		}
	}

	int dialog(Deltoida& MyObj) {
		cout << "\n>Hi, now you have launched a program for working with Deltoida!";
		cout << "\n\n>So, lets start.\n";
		float a;
		bool state = true;
		while (state) {
			try {
				cout << "\n > Enter Small Radius\n > ";
				getFloat(a);
				MyObj.setr(a);
				cout << "\n>Then Enter Big Radius\n>";
				a = 0;
				getFloat(a);
				MyObj.setR(a);
				a = 0;
				if (MyObj.getR() < MyObj.getr()) {
					int b = 0;
					while (b == 0)
					{
						cout << "\n>Try again! First is SMALL radius, and only then is BIG radius, both must be greater than zero\n\n>Enter Small Radius\n> ";
						getFloat(a);
						MyObj.setr(a);
						cout << "\n>Then Enter Big Radius\n>";
						getFloat(a);
						MyObj.setR(a);
						if (MyObj.getR() > MyObj.getr())
							b = 1;
					}
				}
			}
			catch (const invalid_argument& ex) {
				cout << ex.what() << '\n';
			}
			state = false;
		}
		cout << "\n>Perfectly!\n";
		showOptions();
		int opt;
		while (1)
		{
			cout << "\n\n>Chouse the Option:\n>>";
			cin >> opt;
			if (opt == 0) {
				cout << "\n>OK, Goodbye!\n";
				return 0;
			}
			if (opt == 1) {
				cout << ">>The length of the Deltoid curve is:\n>" << MyObj.outputLengthOfCurve();
			}
			if (opt == 2) {
				float X;
				float Y;
				float T;
				cout << "\n\nEnter parametr X :>\nX = ";
				getFloat(X);
				cout << "\n\nEnter parametr Y :>\nY = ";
				getFloat(Y);
				cout << "\n\nEnter parametr T in Degrees:>\nT = ";
				getFloat(T);
				cout << ">>The length of intersection of the tangent with the Deltoid area is:\n>" << MyObj.lengthOfTheIntersection(MyObj.getr(), MyObj.getR(), X, Y, T);
			}
			if (opt == 3)
				cout << ">>The Area of the Deltoid curve is:\n>" << MyObj.outputAreaOfCurve();

			if (opt == 4)
			{
				cout << "\n\nEquations:\n\n>X = (R - r)*cos(t) + r*cos(((R-r)/r)*t)\n";
				cout << ">Y = (R - r)*sin(t) + r*sin(((R-r)/r)*t)\n\n";
				float t;
				cout << "\n\nEnter parametr T in Degrees:>\nT = ";
				getFloat(t);
				float x = 0;
				float* X = &x;
				float y = 0;
				float* Y = &y;
				MyObj.coordinateValuesDependingT(t, MyObj.getr(), MyObj.getR(), X, Y);
				cout << "X and y coordinate values depending on the specified parameter t <<" << t << ">> is:" << "\n>X = " << x << "\n>Y = " << y;
			}

			if (opt == 5)
				MyObj.equation();
			if (opt == 6)
				showOptions();
			if (opt == 7) {
				bool state = true;
				while (state) {
					try {
						cout << "\n > Enter Small Radius\n > ";
						getFloat(a);
						MyObj.setr(a);
						cout << "\n>Then Enter Big Radius\n>";
						a = 0;
						getFloat(a);
						MyObj.setR(a);
						a = 0;
						if (MyObj.getR() < MyObj.getr()) {
							int b = 0;
							while (b == 0)
							{
								cout << "\n>Try again! First is SMALL radius, and only then is BIG radius, both must be greater than zero\n\n>Enter Small Radius\n> ";
								getFloat(a);
								MyObj.setr(a);
								cout << "\n>Then Enter Big Radius\n>";
								getFloat(a);
								MyObj.setR(a);
								if (MyObj.getR() > MyObj.getr())
									b = 1;
							}
						}
					}
					catch (const invalid_argument& ex) {
						cout << ex.what() << '\n';
					}
					state = false;
				}
				cout << "\n>Perfectly!\n";
			}
			if (opt > 7)
				cout << "\n>Wrong option! Try again!";

		}
	}

	void showOptions() {
		cout << "\n*1* - Print the length of the curve\n";
		cout << "*2* - The length of the intersection of the area bounded by the Deltoid with any tangent\n";
		cout << "*3* - Area bounded by the Deltoid curve\n";
		cout << "*4* - Print the x and y coordinate values depending on the specified parameter t\n";
		cout << "*5* - Text representation of the Deltoida equation in the Cartesian coordinate system\n";
		cout << "*6* - Repeat Options\n";
		cout << "*7* - Change the Radius\n";
		cout << "*0* - Exit";
	}
}