#pragma once

#include <iostream>

struct Vector
{
	int x, y;
	Vector(int x, int y) : x(x), y(y) {};
	friend std::ostream& operator<<(std::ostream& out, const Vector& pos) { return out << "[ x: " << pos.x << " | y: " << pos.y << " ]"; }
};

class Shape
{
private:
	Vector position;

public:
	Shape(Vector value) : position(value) {};

	Vector getPosition() const { return position; }
	void setPosition(Vector value) { position = value; }

	virtual void print() const { std::cout << "Position: " << position << std::endl; }
	virtual float getSquare() const { return 0; }
};


class Square : public Shape
{
private:
	Vector size;
public:
	Square(Vector pPosition, Vector pSize) : Shape(pPosition), size(pSize) {};

	Vector getSize() const { return size; }
	void setSize(Vector pSize)
	{
		if (pSize.x <= 0 || pSize.y <= 0)
			throw std::invalid_argument("invalide value");
		size = pSize;
	}

	void print() const override { std::cout << "Position: " << getPosition() << " Size: " << size << std::endl; };
	float getSquare() const override { return size.x * size.y; }
};


class Circle : public Shape
{
private:
	int radius;
public:
	Circle(Vector pPosition, int pRadius) : Shape(pPosition) { setRadius(pRadius); };

	int getRadius() const { return radius; }
	void setRadius(int value) {
		if (value <= 0)
			throw std::invalid_argument("invalide value");
		radius = value;
	}

	void print() const override { std::cout << "Position: " << getPosition() << " Radius: " << radius << std::endl; };
	float getSquare() const override { return 3.14159265f * radius * radius; }
};