#pragma once
#include "Worker.h"

class Programmer :
	public Worker
{
protected:
	bool knowsSharp;
	bool knowsPlusPlus;


public:
	Programmer(const char* _name, const size_t _exp, const double _sal,
		const bool _sharp, const bool _pp);

	Programmer* clone() const;

	bool operator==(const Programmer&);

	void print() const;

	void setCPP(bool knowsCpp);
	void setSharp(bool knowsS);

	const bool getSharp() const;
	const bool getPP() const;

	
};

