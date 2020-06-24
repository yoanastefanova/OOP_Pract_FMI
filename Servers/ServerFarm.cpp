#include "ServerFarm.h"
#include <iostream>

void ServerFarm::copy(const ServerFarm &other)
{
	size = other.size;
	capacity = other.capacity;
	
	servers = new WebServer[capacity];

	for (int i = 0; i < size; i++)
	{
		servers[i] = other.servers[i];
	}
}

void ServerFarm::destroy()
{
	delete[] servers;
}

ServerFarm::ServerFarm() : ServerFarm(8)
{}

ServerFarm::ServerFarm(int _capacity)
{
	size = 0;
	capacity = _capacity >= 8 ? _capacity : 8;
	servers = new WebServer[capacity];
}

ServerFarm::ServerFarm(const ServerFarm & other)
{
	copy(other);
}

ServerFarm & ServerFarm::operator=(const ServerFarm & other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

const int ServerFarm::getSize() const
{
	return size;
}

const int ServerFarm::getCapacity() const
{
	return capacity;
}

void ServerFarm::print() const
{
	for (int i = 0; i < size; i++)
	{
		servers[i].print();
		std::cout << std::endl;
	}

}

ServerFarm & ServerFarm::removeServer(int *other)
{
	int index = -1;

	for (int i = 0; i < size; i++) {
		int counter = 0;
		for (int j = 0; j < 4; j++)
		{
			if (servers[i].IPv4Address[j] == other[j]) {
				counter++;
			}
		}
		if (counter == 4) {
			popAt(i);
			return *this;
		}
	}
}

void ServerFarm::popAt(int _index)
{
	int index = -1;

	for (int i = index; i < size; i++)
	{
		servers[i] = servers[i + 1];
	}

	size--;
}

bool ServerFarm::isInNetwork() const
{
	for (int i = 0; i < size; i++)
	{
		int counter = 0;

		for (int j = 0; j < 4; j++)
		{
			if (servers[i].IPv4Address[j] == servers[i + 1].IPv4Address[j])
			{
				counter++;
			}
		}

		if (counter != 3)
		{
			return false;
		}
	}

	return true;
}

int ServerFarm::countInNetwork() 
{
	int countServ = 0, maxNet = 0;

	sort();

	for (int i = 0; i < size-1; i++)
	{
		int counter = 0;

		for (int j = 0; j < 3; j++)
		{
			if (servers[i].IPv4Address[j] != servers[i+1].IPv4Address[j])
			{
				counter = -1;
				break;
			}
		}

		if (counter != -1)
		{
			countServ++;
		}
		else {
			if (countServ > maxNet) {
				maxNet = countServ;
			}
			countServ = 0;
		}
	}

	return countServ;
}

void ServerFarm::	findMinNetwork() const
{
}

void ServerFarm::swap(WebServer * first, WebServer * second)
{
	WebServer temp = *first;
	*first = *second;
	*second = temp;
}

ServerFarm & ServerFarm::sort()
{
	int index = -1;

	for (int i = 0; i < size - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (servers[j].IPv4Address > servers[index].IPv4Address)
			{
				index = j;
			}

			swap(&servers[index], &servers[i]);
		}
	}

	return *this;
}
