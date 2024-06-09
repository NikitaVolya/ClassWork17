#include "Shape.h"

void Square::setSize(Vector pSize)
{
	if (pSize.x <= 0 || pSize.y <= 0)
		throw std::invalid_argument("invalide value");
	size = pSize;
}

void Circle::setRadius(int value)
{
	if (value <= 0)
		throw std::invalid_argument("invalide value");
	radius = value;
}


