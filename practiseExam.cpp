// prvctiseExam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

//FF:FF:FF:FF:FF:FF
class MacAddress
{
private:
	char address[17];

public:

	MacAddress()
	{
		strcpy(this->address, "FF:FF:FF:FF:FF:FF");

	}

	MacAddress(const char* address)
	{
		if (strlen(address) != 17)
		{
			cout << "Invalid Mac Address, Setting default.." << endl;
			strcpy(this->address, "FF:FF:FF:FF:FF:FF");
		}

		else
		{
			strcpy(this->address, address);
		}
	}

	const char* getAddress() const// първото конст е, за да не променяме стойността на това, което ще вземем
	{
		return this->address;
	}

	bool operator>(const MacAddress& other) const
	{
		return strcmp(this->address, other.address) > 0;

	}
	bool operator==(const MacAddress& other) const
	{
		return strcmp(this->address, other.address) == 0;
	}
	bool operator<(const MacAddress& other) const
	{
		return strcmp(this->address, other.address) < 0;

	}
};

class SmartPhone
{
private:

	char model[128];
	char brand[256];
	char owner[256];
	size_t year;
	size_t memory;
	MacAddress address;

public:

	SmartPhone()
	{
		strcpy(this->model, "Default Model");
		strcpy(this->brand, "Default Brand");
		strcpy(this->owner, "Default Owner");
		this->year = 2019;
		this->memory = 32; 
		this->address = MacAddress(); //извиква се дефолтния конструктор
	}


	SmartPhone(const char* model, const char* brand, const char* owner, size_t year, size_t memory, MacAddress address)
	{
		strcpy(this->model, model); // може и да се сложи и setModel
		strcpy(this->brand, brand);
		strcpy(this->owner, owner);
		this->year = year;
		this->memory = memory;
		this->address = address;
	}

	void setModel(const char* model)
	{
		strcpy(this->model, model);
	}
	const char* getModel() const
	{
		return this->model;
	}
	void setBrand(const char* brand)
	{
		strcpy(this->brand, brand);
	}
	const char* getBrand() const
	{
		return this->brand;
	}
	void setYear(size_t year)
	{
		this->year = year;
	}
	size_t getYear() const
	{
		return this->year;
	}
	void setMemory(size_t year)
	{
		this->memory = memory;
	}
	size_t getMemory() const
	{
		return this->memory;
	}
	void setAddress(MacAddress address)
	{
		this->address = address;
	}
	const MacAddress& getAddress() const
	{
		return this->address;
	}

	void print() const
	{
		cout << this->model << endl;
		cout << this->brand << endl;
		cout << this->owner << endl;
		cout << this->year << endl;
		cout << this->memory << endl;
		cout << address.getAddress() << endl; // getAddress - за да не се предефинира <<
	}

};


class Router
{
private:

	SmartPhone* phones;
	size_t size;
	size_t capacity;

	void copy(const Router& other)
	{
		this->capacity = other.capacity;
		this->size = other.size;

		this->phones = new SmartPhone[other.capacity];
		for (size_t i = 0; i < this->size; i++)
		{
			this->phones[i] = other.phones[i];
		}

	}
	void erase()
	{
		delete[] this->phones;
	}
	
	void resize()
	{
		this->capacity *= 2; // 8=> 16
		SmartPhone* newPhones = new SmartPhone[this->capacity]; // създаваме нова променлива, която да е с новото capacity
		// SmartPhone*, т.к. newphones е масив

		for (size_t i = 0; i < this->size; i++)// върти до размера
		{
			newPhones[i] = phones[i]; // запълва ги до 8 и след това остават 8 незапълнени
		}

		this->erase(); //delete[] phones; изтрива старите phones
		phones = newPhones;// на phones приравнява новите newPhones
	}


	void popAt(size_t index)
	{
		for (size_t i = index; i < this->size - 1 ; i++) // итерира от въведения до последния-1 елемент и се намалява размерът
		{
			this->phones[i] = this->phones[i + 1];// 1 2 3 4 5 6 (при въведен индекс 2) => 1 2 4 5 6
		}
		
		this->size--;
	}

public:

	Router()
	{
		this->capacity = 8;
		this->size = 0;
		this->phones = new SmartPhone[this->capacity];
	}

	Router(const Router& other)
	{
		this->copy(other);
	}

	Router& operator= (const Router& other)
	{
		if (this != &other)
		{
			this->erase();
			this->copy(other);
		}
		return *this;
	}

	~Router()
	{
		this->erase();
	}

	void addPhone(const SmartPhone& phone)
	{
		if (this->size >= this->capacity)
		{
			this->resize();
		}
		this->phones[this->size++] = phone;
	}

	void removePhone(MacAddress address)
	{
		int index = -1;// неутрален индекс

		for (size_t i = 0; i < this->size; i++)
		{
			if (address == this->phones[i].getAddress())  // ако някой елемент на някоя позиция от цикъла е равен на въведения елемент,
				                                         // индексът става равен на намерения елемент и цикълът прекъсва и отива във втория иф
			{
				index = i;
				break;
			}
		}

		if (index != -1) // след като се промени индексът в първия иф
		{
			this->popAt(index);
		}
		// ако не се намери такъв елемент, той не може да се изтрие
	}

	void sort()
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			for (size_t j = 0; j < this->size - 1; j++)
			{
				if (this->phones[j].getAddress() > this->phones[j + 1].getAddress)
				{
					swap(this->phones[j], this->phones[j+1]);
				}
			}
		}
	}

	Router& operator+= (const Router& other)
	{
		for (size_t i = 0; i < other.size; i++)
		{
			this->addPhone(other.phones[i]);
		}

		return *this;
	}

	Router& operator+= (const SmartPhone& other)
	{
		this->addPhone(other);
		return *this;
	}

	Router operator+(const SmartPhone& other)//няма &, защото връща копие
	{
		Router returned = *this;//returned е копие на текущия обект 
		returned += other;
		return returned;
	}

	void print() const
	{
		for (size_t i = 0; i < this->size; i++)
		{
			this->phones[i].print();
		}
	}
};

int main()
{
	SmartPhone phone;
	phone.print();
	MacAddress mac("AA:AA:AA:AA:AA:AA");
	SmartPhone bla("bla", "bla", "bla", 64, 2017, mac);
	bla.print();

	Router rt;
	rt += phone;
	rt += bla;
	rt.print();

    return 0; 
}

