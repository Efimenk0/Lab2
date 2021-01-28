#include "lab2.h"


namespace Lab2
{
	void getDouble(double& a)
	{
		while (1)
		{
			if (std::cin >> a)
				break;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "������ �����! ���������� ��� ���.\n> ";
		}
	}

	int dialog(Deltoid& MyObj) {
		std::cout << "\n> ����� ���������� � ����������� ��������� ��� ������ \"���������\"!";
		double a;
		bool state = true;
		while (state) {
			try {
				std::cout << "\n > ������� ������ ���������� ���������� ���������: --> \n > ";
				getDouble(a);
				MyObj.setr(a);
				state = false;
				}
			catch (const std::invalid_argument& ex) {
				std::cout << ex.what() << '\n';
			}
		}
		showOptions();
		int opt;
		while (true)
		{
			std::cout << "\n\n>��������:\n>> ";
			std::cin >> opt;
			if (opt == 0) {
				std::cout << "\n>�� ��������!\n";
				return 0;
			}
			if (opt == 1) {
				std::cout << ">>:\n>" << MyObj.get_length();
			}
			if (opt == 2) {
				std::cout << ">> ����� ����������� �������, ������������ ����������, � � �����������:\n>" << MyObj.get_length_of_intersection();
			}
			if (opt == 3)
				std::cout << ">> ������� ���������:\n>" << MyObj.get_area();

			if (opt == 4)
			{
				std::cout << "\n\n���������:\n\n>x = 2r*cos(t) + r*cos(2t)\n";
				std::cout << ">y = 2r*sin(t) + r*sin(2*t)\n\n";
				double t;
				std::cout << "\n\n������� �������� t>\nT = ";
				getDouble(t);
				double x = 0;
				double y = 0;
				MyObj.get_coords(t, x, y);
				std::cout << "����������, �������������� ��������� t =  <<" << t << ">>: " << "\n>x = " << x << "\n>y = " << y;
			}
			if (opt == 5)
				std::cout << MyObj.equation();
			if (opt == 6)
				std::cout << "������ ���������� ���������� ���������: " << MyObj.getr();
			if (opt == 7) {
					try {
						std::cout << "\n > ������� ������ ����������� ����� ���������\n > ";
						getDouble(a);
						MyObj.setr(a);
						std::cout << "\n>������ ������� �������!\n";
						}
					catch (const std::invalid_argument& ex) {
						std::cout << ex.what() << '\n';
					}
			}
			if (opt > 7)
				std::cout << "\n>�������� ����! ���������� ��� ���.";

		}
	}

	void showOptions() {
		std::cout << "\n*1* - ����� ����� ���������\n";
		std::cout << "*2* - ����� ����� ����������� �������, ������������ ����������, � ����� � �����������\n";
		std::cout << "*3* - ����� ������� ���������\n";
		std::cout << "*4* - ������� �������� ��������� x � y � ����������� �� ��������� ��������� t\n";
		std::cout << "*5* - �������� ��������� ������������� ��������� ���������\n";
		std::cout << "*6* - ������� ��������� ���������\n";
		std::cout << "*7* - �������� ������ ���������� ���������� ���������\n";
		std::cout << "*0* - �����";
	}
}