#include "Programmer.h"
#include <cstring>


Programmer::Programmer(const char* _name, const size_t _exp, const double _sal, const bool _sharp, const bool _pp) :
	Worker(_name, _exp, _sal),
	knowsSharp(_sharp),
	knowsPlusPlus(_pp)
{
}

Programmer * Programmer::clone() const
{
	return new Programmer (*this);
}

bool Programmer::operator==(const Programmer &other)
{
	Worker::operator==(other);

	return knowsPlusPlus==other.knowsPlusPlus
		&& knowsSharp==other.knowsSharp;
}

void Programmer::print() const
{
	Worker::print();
	std::cout << "Knows C#: " << knowsSharp << std::endl
		<< "Knows C++: " << knowsPlusPlus<< std::endl;
		
}

void Programmer::setCPP(bool knowsCpp)
{
	knowsPlusPlus = knowsCpp;
}

void Programmer::setSharp(bool knowsS)
{
	knowsSharp = knowsS;
}

const bool Programmer::getSharp() const
{
	return knowsSharp;
}

const bool Programmer::getPP() const
{
	return knowsPlusPlus;
}

/*
bool Programmer::operator==(const Programmer &other)
{
	return strcmp(name, other.getName())
		&& salary == other.getSal()
		&& experience == other.getExp()
		&& knowsSharp == other.getSharp()
		&& knowsPlusPlus == other.getPP();
}
*/
