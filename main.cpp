
#include <iostream>
#include "Shape.h"

int main()
{
	Circle circleTest(Vector(1, 2), 7);
	Square squareTest(Vector(1, 2), Vector(8, 6));

	circleTest.print();
	squareTest.print();

	std::cout << circleTest.getSquare() << std::endl << squareTest.getSquare();

	return 0;
}