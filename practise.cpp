// practise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


class DateAndTime
{
	char* day;
	char* month;
	int year;
	int hours;
	int minutes;
	int seconds;

public:
	DateAndTime()
	{
		day = nullptr;
		month = nullptr;
		year = 0;
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	DateAndTime(const char* day, const char* month, int year, int hours, int minutes, int seconds) 
	{


		this->day = new char[strlen(day) + 1];
		strcpy_s(this->day, 9, day);
		this->month = new char[strlen(month) + 1];
		strcpy_s(this->month, 9, month);
		this->year = year;
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;

		if ((hours > 60 || hours < 0) || (minutes > 60 || minutes < 0) || (seconds > 60 || seconds < 0))

		{
			cout << "Enter valid information";
		}

	}

	DateAndTime &operator=(const DateAndTime &other)
	{
		if (this != &other)
		{
			DateAndTime :: operator=(other)
			{
				delete[] this->day;
				this->day = new char[strlen(other.day) + 1)];
				strcpy(this->day, other.day);
			}

		}
	}

	int getYear()
	{
		return year;
	}

	int getHours()
	{
		return hours;
	}

	int getMinutes()
	{
		return minutes;
	}

	int getSeconds()
	{
		return seconds;
	}


	~DateAndTime()
	{
		delete[] day;
		delete[] month;
	}
};



class telephoneCall
{
	int number;
	int duration;
	Start time;

public:
	telephoneCall()
	{
		number = 0;
		duration = 0;
	}

	telephoneCall(int number, int duration, Start time)
	{
		this->number = number;
		this->duration = duration;
		this->time = time;
	}

};
class Start
{
	int hour;
	int minute;

public:
	Start()
	{
		hour = 0;
		minute = 0;
	}

	Start(int hour, int minute)
	{
		this->hour = hour;
		this->minute = minute;
	}



	int getHour()
	{
		return hour;
	}

	int getMin()
	{
		return minute;
	}

	~Start();
};


int main()
{
	DateAndTime dt("Monday", "February", 2019, 12, 67, 11);
	cout << dt.getMinutes();

	return 0;


	