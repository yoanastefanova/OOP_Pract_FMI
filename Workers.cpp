// Workers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Да се дефинира основен клас Worker, който определя работник с име и заплащане за 1 час. 
Да се дефинират два производни на Worker класа HourlyWorker, определящ почасов работники SalariedWorker, 
определящ щатен работник.За всеки вид работник се задават броят на часовете, които той е работил през седмицата и видът на работата,
която е извършвал(символен низ).Работник може да работи само един вид работа през седмицата.
Почасовият работник получава заплата за седмицата по следното правило : 
Всеки час до 40 часа сe заплаща по указаната цена.За всеки час от 41 до 60 час се заплаща по 1.5 пъти повече от указаната цена,
а за часовете на 60 - 2 пъти повече.Щатния работник получава заплата за 40 часа независимо колко е работил.
Класовете да реализират голяма четворка.Да се демонстрира работата на класовете в кратка програма.
*/
#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

class Worker
{
private:
	char *name;
	double salaryPerHour;

	void copy(const Worker &other)
	{
		name = nullptr;
		setName(other.name);
		setSalaryPerHour(other.salaryPerHour);
	}
	void destroy()
	{
		delete[] name;
	}

public:
	Worker()
	{
		name = new char[1];
		strcpy_s(name, 1, "");
		salaryPerHour = 0;
	}

	Worker &operator=(const Worker &other)
	{
		if (this != &other)
		{
			destroy();
			copy(other);
		}

		return *this;
	}

	~Worker()
	{
		destroy();
	}

	void print() const
	{
		cout << getName() << endl;
		cout << getSalaryPerHour();
	}

	void setName(const char* _name)
	{
		if (!_name)
		{
			_name = "";
		}

		delete[] name;
		int length = strlen(_name) + 1;
		name = new char[length];
		strcpy_s(name, length, _name);
	}

	void setSalaryPerHour(const double _salaryPerHour)
	{
		salaryPerHour = _salaryPerHour;
	}

	const double getSalaryPerHour() const
	{
		return salaryPerHour;
	}

	const char* getName() const
	{
		return name;
	}
};

class HourlyWorker : public Worker
{
private:
	char *typeOfWork;
	double weekWorkingHours;
	double salary;

	void copy(const HourlyWorker &other) 
	{
		typeOfWork = nullptr;
		setTypeOfWork(other.typeOfWork);
		setWeekWorkingHours(other.weekWorkingHours);
		//setSalary(other.salary);
	}

public:

	HourlyWorker() //: Worker()
	{
		typeOfWork = new char[1];
		strcpy_s(typeOfWork, 1, "");
		weekWorkingHours = 0;
		salary = 0;
	}


	HourlyWorker(const HourlyWorker &other) : Worker(other)
	{
		copy(other);
	}

	HourlyWorker &operator=(const HourlyWorker &other)
	{
		if (this != &other)
		{
			Worker::operator=(other); // !!!!!!!!!!!
			delete[] typeOfWork;
			copy(other);
		}
		return *this;
	}

	~HourlyWorker()
	{
		delete[] typeOfWork;
	}

	void setTypeOfWork(const char *_typeOfWork)
	{
		if (!_typeOfWork)
		{
			_typeOfWork = "";
		}

		delete[] typeOfWork;
		int length = strlen(_typeOfWork) + 1;
		typeOfWork = new char[length];
		strcpy_s(typeOfWork, length, _typeOfWork);
	}

	void setWeekWorkingHours(const double _weekWorkingHours)
	{
		weekWorkingHours = _weekWorkingHours;
	}

	const char *getTypeOfWork() const
	{
		return typeOfWork;
	}

	const double getWeekWorkingHours() const
	{
		return weekWorkingHours;
	}

	const double getSalary() const
	{
		if (weekWorkingHours < 41)
		{
			return salaryPerHour * 40;
		}

		else if (weekWorkingHours > 40 && weekWorkingHours < 61)
		{
			return (salaryPerHour * 40) * 1.5;
		}
		
		else if (weekWorkingHours > 60)
		{
			return (salaryPerHour * 40) * 2;
		}
	}
};


class SalariedWorker : public Worker
{
private:
	char *typeOfWork;
	double weekWorkingHours;
	double salary;

	void copy(const SalariedWorker &other)
	{
		typeOfWork = nullptr;
		setTypeOfWork(other.typeOfWork);
		setSalaryPerHour(other.salaryPerHour);
		//setSalary(other.salary);
	}

public:

	SalariedWorker() : Worker()//!!!!!!!
	{
		typeOfWork = new char[1];
		strcpy_s(typeOfWork, 1, "");
		weekWorkingHours = 0;
		salary = 0;
	}

	SalariedWorker(const SalariedWorker &other) : Worker(other)//!!!!!
	{
		copy(other);
	}

	SalariedWorker &operator=(const SalariedWorker &other)
	{
		if (this != &other)
		{
			Worker::operator=(other); // !!!!!!!!!
			delete[] typeOfWork;
			copy(other);
		}
		return *this;
	}

	~SalariedWorker()
	{
		delete[] typeOfWork;
	}

	void setTypeOfWork(const char *_typeOfWork)
	{
		if (!_typeOfWork)
		{
			_typeOfWork = "";
		}

		delete[] typeOfWork;
		int length = strlen(_typeOfWork) + 1;
		typeOfWork = new char[length];
		strcpy_s(typeOfWork, length, _typeOfWork);
	}

	void setWeekWorkingHours(const double _weekWorkingHours)
	{
		weekWorkingHours = _weekWorkingHours;
	}
	
	const char *getTypeOfWork() const
	{
		return typeOfWork;
	}

	const double getWeekWorkingHours() const
	{
		return weekWorkingHours;
	}

	const double getSalary() const
	{
		return salaryPerHour * 40;
	}
};


int main()
{
	Worker bleh("Ivan", 23);
	bleh.print();
	

    return 0; 
}

