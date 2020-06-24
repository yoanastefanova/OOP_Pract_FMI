#include "Manager.h"
#include <cstring>



Manager::Manager(const char* _name, const size_t _exp, const double _sal, const size_t _ppl) :
	Worker(_name, _exp, _sal),
	numOfPpl(_ppl)
{
}

Manager * Manager::clone() const
{
	return new Manager (*this);
}

bool Manager::operator==(const Manager &other)
{
	Worker::operator==(other);

	return numOfPpl==other.numOfPpl;
}

void Manager::print() const
{
	Worker::print();
	std::cout << "Num of People: " << numOfPpl << std::endl;
}

void Manager::setNumOfPpl(size_t _num)
{
	if (_num < 0) std::cout << "Invalid Input!" << std::endl;
	numOfPpl = _num;
}

const size_t Manager::getNumOfPpl() const
{
	return numOfPpl;
}

/*
bool Manager::operator==(const Manager &other)
{
	return strcmp(name, other.getName())
		&& salary == other.getSal()
		&& experience == other.getExp()
		&& numOfPpl == other.getNumOfPpl();	
}
*/
