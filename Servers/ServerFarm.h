#pragma once
#include <iostream>
#include <cstring>
#include "WebServer.h"

class ServerFarm
{
private:
	WebServer* servers;
	int size;
	int capacity;

	void copy(const ServerFarm &other);
	void destroy();

public:
	ServerFarm();
	ServerFarm(int _capacity);
	ServerFarm(const ServerFarm &other);
	ServerFarm &operator=(const ServerFarm &other);

	const int getSize() const;
	const int getCapacity() const;

	void print() const;

	ServerFarm &operator+=(const ServerFarm &other);

	ServerFarm &removeServer(int *other);
	void popAt(int _index);


	bool isInNetwork() const;
	int countInNetwork();

	void findMinNetwork() const;

	void swap(WebServer *first, WebServer *second);
	ServerFarm &sort();
};