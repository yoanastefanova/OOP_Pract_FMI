#pragma once
#include "Worker.h"
class Manager :
	public Worker
{
private:

	size_t numOfPpl;

public:

	Manager(const char* _name, const size_t _exp, const double _sal, const size_t _ppl);


	Manager* clone() const;

	bool operator==(const Manager&);

	void print() const;

	void setNumOfPpl(size_t _num);
	const size_t getNumOfPpl() const;

	
};

