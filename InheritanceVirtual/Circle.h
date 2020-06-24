#pragma once
#include <iostream>
#include <cstring>
#include "Shape.h"

class Circle : public Shape
{
private:
	double radius;

public:
	Circle();
	void print();
	int area();
	~Circle();

	void setRadius(const double);
	const double getRadius() const;
	
};

