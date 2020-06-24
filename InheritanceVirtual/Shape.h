#pragma once
#include <iostream>
#include <cstring>

class Shape
{
public:
	virtual void print() const;
	virtual int area() const = 0;
	//Shape();
	//~Shape();
};

