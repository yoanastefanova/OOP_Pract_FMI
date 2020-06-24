#include "Circle.h"



Circle::Circle()
{
	radius = 0;
}

void Circle::print()
{
	std::cout <<this->getRadius();
}

int Circle::area()
{
	double ar;
	ar = 3.14159 * radius * radius;
	return ar;
}


Circle::~Circle()
{}

void Circle::setRadius(const double _radius)
{
	radius = _radius;
}

const double Circle::getRadius() const
{
	return radius;
}
