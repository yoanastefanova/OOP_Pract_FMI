#pragma once
#include <iostream>
#include <cstring>

const int SIZE_URL = 500;
const int SIZE_OS = 20;

struct WebServer
{
	char url[SIZE_URL];
	int IPv4Address[4];
	char OS[SIZE_OS];


	bool operator<(const WebServer &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (IPv4Address[i] >= other.IPv4Address[i])
			{
				return false;
			}
		}

		return true;
	}


	bool operator==(const WebServer &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (IPv4Address[i] != other.IPv4Address[i])
			{
				return false;
			}
		}
		
		return strcmp(url, other.url) == 0
			&& strcmp(OS, other.OS) == 0;
	}

	void print() const
	{
		std::cout << "IPv4Address: ";

		for (int i = 0; i < 4; i++)
		{
			std::cout << IPv4Address[i];
		}

		std::cout << "URL: " << url << std::endl
			<< "OS: " << OS << std::endl;
	}


	void read()
	{
		std::cin >> url;

		for (int i = 0; i < 4; i++)
		{
			std::cin >> IPv4Address[i];
		}

		std::cin >> OS;
	}
};


