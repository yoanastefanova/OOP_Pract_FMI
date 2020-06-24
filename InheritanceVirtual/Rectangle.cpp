#include "Rectangle.h"



void Rectangle::print()
{
	std::cout << "height= "<< this->getHeight() << std::endl;
	std::cout <<"width= "<<this->getWidth() << std::endl;
}

int Rectangle::area()
{
	double ar = height * width;
	return ar;
}

Rectangle::Rectangle()
{
	double height = 0;
	double width = 0;
}


Rectangle::~Rectangle()
{}

void Rectangle::setHeight(const double _width)
{
	width = _width;
}

void Rectangle::setWidth(const double _width)
{
	width = _width;
}

const double Rectangle::getHeight() const
{
	return height;
}

const double Rectangle::getWidth() const
{
	return width;
}
