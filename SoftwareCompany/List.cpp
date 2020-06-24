#include "List.h"


List::List() :size(0), capacity(8)
{
	list = new Worker*[capacity];
}

List::~List()
{
	for (int i = 0; i < size; ++i)
	{
		delete list[i];
	}

	delete[] list;
}

void List::addEmpl(const Worker &_newEmpl)
{
	if (size >= capacity)
	{
		resizeUp();
	}

	list[size++] = _newEmpl.clone();
}



void List::removeEmpl(const Worker &_delEmpl)
{
	size_t index = -1;

	for (size_t i = 0; i < size; ++i)
	{
		if (_delEmpl.clone() == list[i])
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		popAt(index);
	}
}

void List::inputCommon(Worker * other)
{
	char name[300];
	std::cout << "Name: ";
	std::cin >> name;
	other->setName(name);

	int exp;
	std::cout << "Experience: ";
	std::cin >> exp;
	other->setExp(exp);

	int salary;
	std::cout << "Salary: ";
	std::cin >> salary;
	other->setSalary(salary);
}



void List::copy(const List& other)
{
	capacity = other.capacity;
	size = other.size;

	list = new Worker*[other.capacity];

	for (size_t i = 0; i < size; ++i)
	{
		list[i] = other.list[i];
	}
}

void List::destroy()
{
	delete[] list;
}

void List::newWorker()
{
	char type;
	std::cout << "Type of worker(p/m) : " << endl;
	std::cin >> type;
	
	Worker* newWorker = createWorker(type);

	if (newWorker)
	{
		addEmpl(*newWorker);
	}
}

Worker * List::createWorker(char type)
{
	switch (type)
	{
	case 'p': return createProg();
	case 'm': return createMan();
	}

	return nullptr;
}

Programmer * List::createProg()
{
	Programmer *prog = new Programmer("", 0, 0, false, false);
	int knows;
	inputCommon(prog);
	bool knowsCPP, knowsS;
	std::cout << "Does the programmer know C++(1/0) : ";
	std::cin >> knows;
	knowsCPP = knows == 1;
	prog->setCPP(knowsCPP);
	std::cout << "Does the programmer know C#(1/0) : ";
	std::cin >> knows;
	knowsS = knows == 1;
	prog->setSharp(knowsS);
	return prog;
}

Manager * List::createMan()
{
	Manager *man = new Manager("", 0, 0, 0);
	inputCommon(man);
	int inCharge;
	std::cout << "How many people is the manager in charge of : ";
	std::cin >> inCharge;
	man->setNumOfPpl(inCharge);
	return man;
}

void List::increaseSal(Worker * other)
{
	Programmer *prog = dynamic_cast<Programmer*> (other);

	if (prog != nullptr && prog->getPP())
	{
		other->setSalary(other->getSal() + 300);
	}

	if (prog != nullptr && prog->getSharp())
	{
		other->setSalary(other->getSal() + 200);
	}
	
	Manager *man = dynamic_cast<Manager*> (other);

	if (man != nullptr && (man->getNumOfPpl() > 5))
	{
		other->setSalary(other->getSal() + 500);
	}

}


void List::popAt(const size_t _ind)
{
	for (size_t i = _ind; i < size; ++i)
	{
		list[i] = list[i + 1];
	}

	size--;
}


double List::totalSalExpense() const
{
	double total = 0;

	for (size_t i = 0; i < size; ++i)
	{
		total = total + list[i]->getSal();
	}

	return total;
}

void List::printWorkersExp(const size_t _exp) const
{
	List newList;
	
	for (size_t i = 0; i < size; ++i)
	{
		if (_exp < list[i]->getExp())
		{
			newList.addEmpl(*(list[i]));
		}
	}

	newList.printAll();
}

void List::printAll() const
{
	for (size_t i = 0; i < size; ++i)
	{
		list[i]->print();
	}
}

void List::resizeUp()
{
	capacity = capacity * 2;
	Worker** newWorker = new Worker*[capacity];

	for (size_t i = 0; i < size; ++i)
	{
		newWorker[i] = list[i];
	}

	delete[] list;
	list = newWorker;
}

void List::resizeDown()
{
	capacity /= 2;
	Worker** newWorkers = new Worker *[capacity];
	for (size_t i = 0; i < size; i++)
	{
		newWorkers[i] = list[i];
	}

	delete[] list;
	list = newWorkers;

}

void List::decreaseIfEmpty()
{
	if (size == 0.25 * capacity)
	{
		resizeDown();
	}
}
