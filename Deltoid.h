#ifndef DELTOID_H
#define DELTOID_H

#include <cmath>
#include <string>
#include <stdexcept>

// Класс, описывающий кривую "Дельтоида"
namespace Del {
	class Deltoid {
		double r;                                 
	public:
		// Пустой конструтор и конструктор с параметром
		Deltoid(double r = 2);
		// Сеттер
		Deltoid& setr(double); 
		// Геттер для r
		double getr() const { return r; };
		// п. 3
		double get_length_of_intersection() const;
		// п. 4
		double get_length() const;
		// п. 5
		double  get_area() const;
		// п. 6
		Deltoid& get_coords(double, double&, double&);
		// п. 7
		std::string equation() const;


	};

}


#endif // !DELTOID_H

