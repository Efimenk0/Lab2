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
			std::cout << "Ошибка ввода! Попробуйте еще раз.\n> ";
		}
	}

	int dialog(Deltoid& MyObj) {
		std::cout << "\n> Добро пожаловать в тестирующую программу для класса \"Дельтоида\"!";
		double a;
		bool state = true;
		while (state) {
			try {
				std::cout << "\n > Введите радиус внутренней окружности дельтоиды: --> \n > ";
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
			std::cout << "\n\n>Выберите:\n>> ";
			std::cin >> opt;
			if (opt == 0) {
				std::cout << "\n>До свидания!\n";
				return 0;
			}
			if (opt == 1) {
				std::cout << ">>:\n>" << MyObj.get_length();
			}
			if (opt == 2) {
				std::cout << ">> Длина пересечения области, ограниченной дельтоидой, с её касательной:\n>" << MyObj.get_length_of_intersection();
			}
			if (opt == 3)
				std::cout << ">> Площадь дельтоиды:\n>" << MyObj.get_area();

			if (opt == 4)
			{
				std::cout << "\n\nУравнения:\n\n>x = 2r*cos(t) + r*cos(2t)\n";
				std::cout << ">y = 2r*sin(t) + r*sin(2*t)\n\n";
				double t;
				std::cout << "\n\nВведите параметр t>\nT = ";
				getDouble(t);
				double x = 0;
				double y = 0;
				MyObj.get_coords(t, x, y);
				std::cout << "Координаты, соотвествующие параметру t =  <<" << t << ">>: " << "\n>x = " << x << "\n>y = " << y;
			}
			if (opt == 5)
				std::cout << MyObj.equation();
			if (opt == 6)
				std::cout << "Радиус внутренней окружности дельтоиды: " << MyObj.getr();
			if (opt == 7) {
					try {
						std::cout << "\n > Введите радиус внутреннего круга дельтоиды\n > ";
						getDouble(a);
						MyObj.setr(a);
						std::cout << "\n>Радиус успешно изменен!\n";
						}
					catch (const std::invalid_argument& ex) {
						std::cout << ex.what() << '\n';
					}
			}
			if (opt > 7)
				std::cout << "\n>Неверный ввод! Попробуйте еще раз.";

		}
	}

	void showOptions() {
		std::cout << "\n*1* - Найти длину дельтоиды\n";
		std::cout << "*2* - Найти длину пересечения области, ограниченной дельтоидой, с любой её касательной\n";
		std::cout << "*3* - Найти площадь дельтоиды\n";
		std::cout << "*4* - Вернуть значения координат x и y в зависимости от заданного параметра t\n";
		std::cout << "*5* - Показать текстовое представление уравнения дельтоиды\n";
		std::cout << "*6* - Вывести параметры дельтоиды\n";
		std::cout << "*7* - Изменить радиус внутренней окружности дельтоиды\n";
		std::cout << "*0* - Выйти";
	}
}