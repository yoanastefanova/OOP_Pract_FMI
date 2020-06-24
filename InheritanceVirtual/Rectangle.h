#pragma once
#include <iostream>
#include <cstring>
#include "Shape.h"

class Rectangle : public Shape
{
private:
	double height;
	double width;

public:
	Rectangle();
	void print();
	int area();
	~Rectangle();

	void setHeight(const double);
	void setWidth(const double);
	const double getHeight() const;
	const double getWidth() const;
};

