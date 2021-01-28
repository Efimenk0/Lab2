#ifndef DELTOID_H
#define DELTOID_H

#include <cmath>
#include <string>
#include <stdexcept>

// �����, ����������� ������ "���������"
namespace Del {
	class Deltoid {
		double r;                                 
	public:
		// ������ ���������� � ����������� � ����������
		Deltoid(double r = 2);
		// ������
		Deltoid& setr(double); 
		// ������ ��� r
		double getr() const { return r; };
		// �. 3
		double get_length_of_intersection() const;
		// �. 4
		double get_length() const;
		// �. 5
		double  get_area() const;
		// �. 6
		Deltoid& get_coords(double, double&, double&);
		// �. 7
		std::string equation() const;


	};

}


#endif // !DELTOID_H

