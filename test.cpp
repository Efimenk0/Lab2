#include "DeltoidClass/Deltoid.h"
#include "gtest/gtest.h"

using namespace Del;

TEST(Constructors, EmptyConstructor) {
	Deltoid d;
	EXPECT_EQ(2, d.getr());
}

TEST(Constructors, DefaultConstructor) {
	Deltoid d(5.6);
	EXPECT_EQ(5.6, d.getr());
	EXPECT_ANY_THROW(Deltoid d2(-2));
}

TEST(Setters, serR) {
	Deltoid d(3.2);
	d.setr(2.6);
	EXPECT_EQ(2.6, d.getr());
	EXPECT_ANY_THROW(d.setr(-2));
	EXPECT_ANY_THROW(d.setr(0));
}

TEST(Getters, Equation) {
	Deltoid d(2.4);
	Deltoid d2(1.1);
	EXPECT_EQ("(x^2 + y^2)^2 + 18(x^2 + y^2) = 8x^3 - 24y^2x + 27", d.equation());
	EXPECT_EQ("(x^2 + y^2)^2 + 18(x^2 + y^2) = 8x^3 - 24y^2x + 27", d2.equation());
}

TEST(Getters, GetLengthOfIntersection) {
	Deltoid d(1.0);
	EXPECT_EQ(4.0, d.get_length_of_intersection());
	Deltoid d2(3.2);
	EXPECT_EQ(12.8, d2.get_length_of_intersection());
}

TEST(Getters, GetLength) {
	Deltoid d(3.2);
	EXPECT_NEAR(17.07, d.get_length(), 0.01);
	Deltoid d2(5.0);
	EXPECT_NEAR(26.7, d2.get_length(), 0.1);
}

TEST(Getters, GetArea) {
	Deltoid d(2.1);
	EXPECT_NEAR(3.08, d.get_area(), 0.1);
	Deltoid d2(0);
	EXPECT_NEAR(0, d2.get_area(), 0.1);
}

TEST(Getters, GetCoords) {
	double x1, x2;
	Deltoid d(2.6);
	d.get_coords(2.5, x1, x2);
	EXPECT_NEAR(7.78, x1, 0.1);
	EXPECT_NEAR(0.45, x2, 0.1);
}