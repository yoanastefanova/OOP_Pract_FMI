#include "Worker.h"
#include <iostream>
#include <cstring>


void Worker::destroy()
{
	delete[] name;
}

void Worker::copy(const Worker& other)
{
	name = nullptr;
	setName(other.name);
	setExp(other.experience);
	setSalary(other.salary);
}

Worker::Worker()
{
	name = new char[1];
	strcpy_s(name, 1, "");
	experience = 0;
	salary = 0;
}

Worker::Worker(const Worker &other)
{
	copy(other);
}

Worker::Worker(const char* _name, const std::size_t _exp, const double _sal) : name(nullptr)
{
	setName(_name);
	experience = _exp;
	salary = _sal;
}

Worker& Worker::operator=(const Worker &other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;

}

Worker::~Worker()
{
	destroy();
}

bool Worker::operator==(const Worker &other)
{
	return strcmp(name, other.name) == 0
		&& experience == other.experience
		&& salary == other.salary;
}

void Worker::print() const
{
	std::cout << "Name: " << name << std::endl
		<< "Experience: " << experience << std::endl
		<< "Salary: " << salary << std::endl;
}

void Worker::setName(const char* _name)
{
	
	if (!_name)
	{
		throw std::runtime_error("Invalid name!");

		// _name = "";
	}
	
	delete[] name;

	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	
}

void Worker::setExp(const size_t _exp)
{
	if (_exp < 0) std::cout << "Invalid Input!" << std::endl;
	experience = _exp;
}

void Worker::setSalary(const double _sal)
{
	if (_sal < 0) std::cout << "Invalid Input!" << std::endl;
	salary = _sal;
}

const char* Worker::getName() const
{
	return name;
}

const std::size_t Worker::getExp() const
{
	return experience;
}

const double Worker::getSal() const
{
	return salary;
}