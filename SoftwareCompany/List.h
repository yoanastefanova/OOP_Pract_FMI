#pragma once
#include "Worker.h"
#include "Manager.h"
#include "Programmer.h"
#include <string>
using namespace std;

class List
{
public:

	
	List();
	/*
	List(const List&);
	List& operator=(const List&);
	*/
	~List();
	
	
	void increaseSal(Worker *other);
	double totalSalExpense() const;
	void printWorkersExp(const size_t) const;

	
	void addEmpl(const Worker&);
	void removeEmpl(const Worker&);

	void printAll() const;

private:
	Worker** list;
	size_t size;
	size_t capacity;

	void copy(const List&);
	void destroy();


	void inputCommon(Worker *other);

	void newWorker();
	Worker*  createWorker(char type);
	Programmer* createProg();
	Manager* createMan();

	void popAt(const size_t);
	

	void resizeUp();
	void resizeDown();
	void decreaseIfEmpty();
};

