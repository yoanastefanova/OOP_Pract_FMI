// IceCream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;



class IceCream
{
private:
	char *name;
	char *flavour;
	double pricePerBall;
	int numOfBalls;


	void copy(const IceCream &other)
	{
		name = nullptr;
		flavour = nullptr;
		setName(other.name);
		setFlavour(other.flavour);	
		setPricePerBall(other.pricePerBall);
		setNumOfBalls(other.numOfBalls);
	}

	void destroy()
	{
		delete[] name;
		delete[] flavour;		
	}

public:

	IceCream()
	{
		name = new char[1];
		strcpy_s(name, 1, "");
		flavour = new char[1];		
		strcpy_s(flavour, 1, "");		
		numOfBalls = 0;		
		pricePerBall = 0;
	}
	
	IceCream(const char *_name, const char *_flavour, int _numOfBalls, double _pricePerBall) :
		name(nullptr),
		flavour(nullptr),
		numOfBalls(0),
		pricePerBall(0)
	{
		name = nullptr;
		flavour = nullptr;
		setName(_name);
		setFlavour(_flavour);
		setNumOfBalls(_numOfBalls);
		setPricePerBall(_pricePerBall);
	}
	

	~IceCream()
	{
		destroy();
	}

	IceCream(const IceCream &other) : // copy constructor
		name(nullptr),
		flavour(nullptr),
		numOfBalls(0),
		pricePerBall(0)
		
	{
		copy(other);
	}

	//OPERATORS
	IceCream &operator= (const IceCream &other)
	{ 
		if (this != &other) // сравнява адресите
		{	
			destroy(); //ако са различни, да изтрие дясното и на негово място да сложи новото	
			copy(other);
		}
		return *this; // this e референция(адрес), а *this е самото нещо
	}

	
	 bool operator== (const IceCream &other) const

	{
		return strcmp(this->flavour, other.flavour) == 0
			   && this->pricePerBall == other.pricePerBall
			   && this-> numOfBalls == other.numOfBalls
     		   && strcmp(this->name, other.name) == 0;	  
	}

	 bool operator!= (const IceCream &other) const
	{
		//return !(*this == other);
		 
		return  strcmp(this->flavour, other.flavour) != 0
				&& this->pricePerBall != other.pricePerBall
				&& this->numOfBalls != other.numOfBalls
				&& strcmp(this->name, other.name) != 0;
				
	}
	

	 bool operator<(const IceCream &other) const
	 {

		 return (strcmp(this->flavour, other.flavour) < 0//ако вкусът на първото лексикографски е по-малък от този на второто, ще върне истина
			 && (pricePerBall < other.pricePerBall)
			 && (numOfBalls < other.numOfBalls)
			 && strcmp(this->name, other.name) < 0);
	 }
	

	 bool operator>(const IceCream &other) const 
	{ 
		return strcmp(this->flavour, other.flavour) > 0
			   && (pricePerBall > other.pricePerBall)
			   && (numOfBalls > other.numOfBalls)
			   && strcmp(this->name, other.name) > 0;

	}
	
	bool operator>=(const IceCream &other) const
	{
		return !(*this < other);
	}

	bool operator<=(const IceCream &other) const
	{
		return !(*this > other);
	}


//GET + SET
	const char *getName() const
	{
		return name;
	}

	const char *getFlavour() const
	{
		return flavour;
	}

	int getNumOfBalls() const
	{
		return numOfBalls;
	}

	double getPriceperBall() const
	{
		return pricePerBall;
	}

	double getPrice() const
	{
		return pricePerBall * numOfBalls;
	}

	void setName(const char *_name)
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

	void setFlavour(const char *_flavour)
	{
		if (!_flavour)// ако е nullptr, да извежда празно място
		{
			_flavour = "";
		}

		delete[] flavour;// изтрива заделената памет
		int length = strlen(_flavour); // правим променлива, която да пази дължината новия обект
		flavour = new char[length + 1];// заделяме нова памет в хийпа
		strcpy_s(flavour, length + 1, _flavour); // във flavour слагаме новото _flavour, което е с дължината + 1, заради '\0'
	}


	void setNumOfBalls(const int _numOfBalls)
	{
		numOfBalls = _numOfBalls;
	}

	void setPricePerBall(const double _pricePerBall)
	{
		pricePerBall = _pricePerBall;
	}


	void printIC() const
	{
		cout << "Name: " << getName() << endl;
		cout << "Flavour: " << getFlavour() << endl;
		cout << "Number of Balls: " << getNumOfBalls() << endl;
		cout << "Price Per Ball: " << getPriceperBall() << endl;
		cout << "Overall Price: " << getPrice() << endl;
		cout << endl;
	}
};


class IceCreamContainer
{
private:

	IceCream *iceCream;
	int size;
	int capacity;

	void resize()
	{
		/*
		if (capacity == 0)
		{
			capacity += 8;
		}
		*/

		this->capacity = capacity * 2 + 1;
		IceCream* newIceCream = new IceCream[capacity];

		for (int i = 0; i < this->size; i++)
		{
			newIceCream[i] = this->iceCream[i]; // новите взимат ст-ста на старите
		}		
		delete[] iceCream;// изтриваме старите
		iceCream = newIceCream; // след като са празни, на старите присвояваме новите
	}

	void resizeDecrease()
	{
		this->capacity /= 2;
		IceCream* newIceCreamDecrease = new IceCream[this->capacity];

		for (int i = 0; i < this->size; i++)
		{
			newIceCreamDecrease[i] = iceCream[i];
		}

		delete[] iceCream;
		iceCream = newIceCreamDecrease;
	}

	void decreseIfEmptyCells()
	{
		if (size == (0.25 * capacity))
		{
			this->resizeDecrease();
		}
	}
	
	void copy(const IceCreamContainer &other)
	{
		capacity = 0;
		size = 0;
		iceCream = nullptr;

		this->capacity = other.capacity;
		this->size = other.size;

		this->iceCream = new IceCream[other.capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->iceCream[i] = other.iceCream[i];
		}
	}

	void del()
	{
		delete[] this->iceCream;
	}


	void popAt(int index)
	{
		for (int i = index; i < this->size - 1; i++)
		{
			this->iceCream[i] = this->iceCream[i + 1]; 
		}

		this->size--;
	}
		
public:

	IceCreamContainer()
	{
		this->capacity = 0;
		this->size = 0;
		this->iceCream = nullptr;	
	}

	IceCreamContainer(const IceCreamContainer &other)
	{
		copy(other);
	}

	~IceCreamContainer()
	{
		del();
	}

	IceCreamContainer &operator=(const IceCreamContainer &other)
	{
		if (this != &other)
		{
			this->del();
			this->copy(other);
		}
		return *this;
	}

	void addIceCream(const IceCream &_iceCream)
	{
		if (this->size >= this->capacity)
		{
			this->resize();
		}
		this->iceCream[this->size++] = _iceCream;// на следващата позиция слага новия	
	}

	void removeIceCream(IceCream _iceCreamRemove)
	{
		int index = -1;

		for (int i = 0; i < this->size; i++)
		{
			/*
			if (this->iceCream[i].getFlavour() == _iceCreamRemove.getFlavour()
				&& this->iceCream[i].getName() == _iceCreamRemove.getName()
				&& this->iceCream->getPriceperBall() == _iceCreamRemove.getPriceperBall())
				*/

			if (_iceCreamRemove == iceCream[i])
			{
				index = i;
				break;
			}
		}

		if (index != -1)
		{
			this->popAt(index);
		}
	}

	bool has(const IceCream _wantedIceCream)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (_wantedIceCream == iceCream[i])
			{
				return true;
			}
		}
	    return false;
	}

	double priceAll(const IceCreamContainer &container)
	{
		double sum = 0;

		for (int i = 0; i < this->size; i++)
		{
			sum = sum + iceCream[i].getPrice();
		}

		return sum;
	} 


	void print()
	{
		cout << "IceCream Container: " << endl;
		cout << endl;
		for (int i = 0; i < this->size; i++)
		{
			this->iceCream[i].printIC();
			cout << endl;
		}
	}

	int getSize() const
	{
		return size;
	}
	
	int getCapacity() const
	{
		return capacity;
	}
};


int main()
{
	IceCream bleh("bleh", "chocolate", 3, 1.50);
	bleh.printIC();
	IceCream blob("pepi", "vanilla", 7, 1.30);
	blob.printIC();
	IceCream aaa(bleh);
	aaa.printIC();	
	IceCream bla("bla", "biscuits", 11, 2.70);
	bla.printIC();
	IceCream pz("pz", "oreo", 3, 3.40);
	IceCreamContainer container;	
	container.addIceCream(bleh);
	container.addIceCream(blob);
	container.addIceCream(aaa);
	container.print();
	container.removeIceCream(blob);
	container.print();
	container.addIceCream(bla);
	container.print();
	cout<<"Overall sum of the container: "<< container.priceAll(container);
	cout << endl;
	cout << boolalpha << container.has(pz) << endl;
	cout << boolalpha << container.has(bleh) << endl;
	

	return 0;
}

