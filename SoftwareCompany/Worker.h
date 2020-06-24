#pragma once

#include <iostream>

class Worker
{
protected:

	char* name;
	size_t experience;
	double salary;

	void destroy();
	void copy(const Worker& other);

public:

	Worker(); //  не е задължително
	Worker(const Worker&);
	Worker(const char* _name, const size_t _exp, const double _sal);
	Worker& operator=(const Worker&);
	virtual ~Worker();

	virtual bool operator==(const Worker&);

	virtual Worker* clone() const = 0;

	virtual void print() const;

	void setName(const char* _name);
	void setExp(const size_t _exp);
	void setSalary(const double _sal);

	const char* getName() const;
	const size_t getExp() const;
	const double getSal() const;
};

