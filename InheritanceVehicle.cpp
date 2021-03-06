// InheritanceVehicle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>

class Vehicle
{
private:
	char *colour;
	char *brand;
	int yearOfProduction;
	int seats;
	double maxSpeed;

	void copy(const Vehicle &other)
	{
		colour = nullptr;
		brand = nullptr;
		setColour(other.colour);
		setBrand(other.brand);
		setYearOfProduction(other.yearOfProduction);
		setSeats(other.seats);
		setMaxSpeed(other.maxSpeed);
	}

	void destroy()
	{
		delete[] colour;
		delete[] brand;
	}

public:

	Vehicle()
	{
		colour = new char[1];
		strcpy_s(colour, 1, "");
		brand = new char[1];
		strcpy_s(brand, 1, "");
		yearOfProduction = 0;
		seats = 1;
		maxSpeed = 0;
	}

	Vehicle(const Vehicle &other)
	{
		copy(other);
	}

	Vehicle(const char *_colour, const char *_brand, int _yearOfProduction, int _seats, double _maxSpeed)
	{
		colour = nullptr;
		brand = nullptr;
		setColour(_colour);
		setBrand(_brand);
		setYearOfProduction(_yearOfProduction);
		setSeats(_seats);
		setMaxSpeed(_maxSpeed);
	}

	Vehicle &operator=(const Vehicle &other)
	{
		if (this != &other)
		{
			destroy();
			copy(other);		
		}
		return *this;
	}
	
	~Vehicle()
	{
		destroy();
	}

	void setColour(const char *_colour)
	{
		if (!_colour)
		{
			_colour = "";
		}

		delete[] colour;
		int length = strlen(_colour) + 1;
		colour = new char[length];
		strcpy_s(colour, length, _colour);		
	}


	void setBrand(const char *_brand)
	{
		if (!_brand)
		{
			_brand = "";
		}

		delete[] brand;
		int length = strlen(_brand) + 1;
		brand = new char[length];
		strcpy_s(brand, length, _brand);
	}

	void setYearOfProduction(const int _yearOfProduction)
	{
		yearOfProduction = _yearOfProduction;
	}

	void setSeats(const int _seats)
	{
		seats = _seats;
	}

	void setMaxSpeed(const double _maxSpeed)
	{
		maxSpeed = _maxSpeed;
	}
	
	const char *getColour() const
	{
		return colour;
	}

	const char *getBrand() const
	{
		return brand;
	}

	const int getYearOfProduction() const
	{
		return yearOfProduction;
	}

	const int getSeats() const
	{
		return seats;
	}

	const int getMaxSpeed() const
	{
		return maxSpeed;
	}

};


class Bicycle : public Vehicle
{
private:
	int numOfGears;
	bool lights;
	bool bell;

	void copy(const Bicycle &other)
	{
		setNumOfGears(other.numOfGears);
		setLights(other.lights);
		setBell(other.bell);
	}

public:

	/*
	Bicycle()
	{
		numOfGears = 0;
		lights = 0;
		bell = 0;
	}
	*/

	Bicycle(const char *colour, const char *brand, const int yearOfProduction, const int seats, const double maxSpeed,
		const int _numOfGears, const int _lights, const bool _bell) : Vehicle(colour, brand, yearOfProduction, seats, maxSpeed)
	{
		numOfGears = _numOfGears;
		lights = _lights;
		bell = _bell;
	}

	Bicycle(const Bicycle &other) : Vehicle(other) // !!!!!!!!!!!!!!!!!!!!!!!!
	{
		copy(other);
	}

	Bicycle &operator=(const Bicycle &other)
	{
		if (this != &other)
		{
			Vehicle::operator=(other); // !!!!!!!!
			copy(other);
		}
		return *this;
	}

	~Bicycle()
	{} // !!!!!!!!!

	void setNumOfGears(const int _numOfGears)
	{
		numOfGears = _numOfGears;
	}

	void setLights(const bool _lights)
	{
		lights = _lights;
	}

	void setBell(const bool _bell)
	{
		bell = _bell;
	}

	const int getNumOfGears() const
	{
		return numOfGears;
	}

	const bool hasLights() const
	{
		return lights;
	}
	
	const bool hasBell() const
	{
		return bell;
	}

};

class Car : public Vehicle
{
private:
	int numOfDoors;
	int horsePower;

	void copy(const Car &other)
	{
		setNumOfDoors(other.numOfDoors);
		setHorsePower(other.horsePower);
	}

public:

	Car(const char* _colour, const char* _brand, const int _yearOfProduction, const int _seats, const double _maxSpeed,
		const int _numOfDoors, const int _horsePower) :  Vehicle (_colour, _brand, _yearOfProduction, _seats, _maxSpeed)
	{
		numOfDoors = _numOfDoors;
		horsePower = _horsePower;
	}
	
	Car(const Car &other)
	{
		copy(other);
	}

	Car &operator=(const Car &other)
	{
		if (this != &other)
		{
			Vehicle::operator=(other);
			copy(other);
		}
		return *this;
	}

	~Car()
	{}
	
	void setNumOfDoors(const int _numOfDoors)
	{
		numOfDoors = _numOfDoors;
	}

	void setHorsePower(const int _horsePower)
	{
		horsePower = _horsePower;
	}

	const int getNumOfDoors() const
	{
		return numOfDoors;
	}

	const int getHorsePower() const
	{
		return horsePower;
	}

		
};



int main()
{

    return 0; 
}

