#include "ElfTeam.h"

#include <iostream>

ElfTeam::ElfTeam(const String& nam) : members(nullptr), size(0), capacity(0), name(nam)
{}

ElfTeam::ElfTeam(const ElfTeam& other)
{
	copy(other);
}

ElfTeam& ElfTeam::operator=(const ElfTeam& rhs)
{
	if (this != &rhs)
	{
		del();
		copy(rhs);
	}
	return *this;
}

ElfTeam::~ElfTeam()
{
	del();
}


bool ElfTeam::operator<(const ElfTeam& rhs) const
{
	size_t ageA = 0;
	size_t abilityA = 0;
	size_t ageB = 0;
	size_t abilityB = 0;

	for (size_t i = 0; i < size; i++)
	{
		ageA += members[i].GetAge();
		abilityA += members[i].GetAbility();
	}

	for (size_t i = 0; i < rhs.size; i++)
	{
		ageB += rhs.members[i].GetAge();
		abilityB += rhs.members[i].GetAbility();
	}

	//all numbers are positive so with some 5th grade algebra we get this alternative formula
	//bonus: no casting -> faster and not floating point errors prone; can't have a division by 0
	return ageA * abilityB < ageB * abilityA;
	return ageA / (double)abilityA < ageB / (double)abilityB;
}

ElfTeam ElfTeam::operator+(const ElfTeam& rhs) const
{
	//we can come up with a smarter way that allocate at most once
	//now it can happen that we first allocate to copy and then again to make room for the new elements
	ElfTeam result(*this);
	result += rhs;

	//same for the string
	result.name = name + rhs.name;
	//result.name += rhs.name

	return result;
}

ElfTeam& ElfTeam::operator+=(const ElfTeam& rhs)
{
	if (size + rhs.size > capacity)
	{
		resize(size + rhs.size + 5);
	}

	for (size_t j = 0; j < rhs.size; j++)
	{
		members[size + j] = rhs.members[j];
	}

	size += rhs.size;

	return *this;
}

void ElfTeam::AddElf(const Elf& elf)
{
	if (size == capacity)
	{
		resize();
	}

	members[size++] = elf;
}

void ElfTeam::RemoveElf(const String& name)
{
	size_t found = -1;

	for (size_t i = 0; i < size; i++)
	{
		if (members[i].GetName() == name)
		{
			found = i;
			break;
		}
	}

	//if we want to keep the order
	for (size_t i = found; i < size - 1; i++)
	{
		members[i] = members[i + 1];
	}
	//otherwise we can just swap the last and the found

	if (found != -1)
	{
		size--;
	}

	//if we want to delete all with that name

	//option one

	//do
	//{
	//	found = false;
	//	//search
	//	found = true;
	//	//delete
	//} while (found);

	//option two
	//RemoveElf(name)
}

const String& ElfTeam::GetName() const
{
	return name;
}

size_t ElfTeam::GetCumulativeAge() const
{
	size_t ageSum = 0;

	for (size_t i = 0; i < size; i++)
	{
		ageSum += members[i].GetAge();
	}

	return ageSum;
}

size_t ElfTeam::GetCumulativeAbility() const
{
	size_t abilitySum = 0;

	for (size_t i = 0; i < size; i++)
	{
		abilitySum += members[i].GetAbility();
	}

	return abilitySum;
}


void ElfTeam::copy(const ElfTeam& other)
{
	name = other.name;
	size = other.size;
	capacity = other.capacity;

	members = new Elf[capacity];

	for (size_t i = 0; i < size; i++)
	{
		members[i] = other.members[i];
	}
}

void ElfTeam::del()
{
	delete[] members;
}

void ElfTeam::resize(size_t required)
{
	if (members)
	{
		//we won't allow allocating less memory than we currently have
		capacity = required > capacity ? required : 1.5 * capacity;
		Elf* temp = new Elf[capacity];

		for (size_t i = 0; i < size; i++)
		{
			temp[i] = members[i];
		}

		delete[] members;
		members = temp;
	}
	else
	{
		capacity = required > 1 ? required : 8;
		members = new Elf[capacity];
	}
}

std::ostream& operator<<(std::ostream& os, const ElfTeam& elfTeam)
{
	os << elfTeam.name << std::endl;
	for ( size_t i = 0; i < elfTeam.size; i++ )
	{
		os << elfTeam.members[ i ] << std::endl;
	}

	return os;
}

void analyze(const std::vector<ElfTeam>& teams)
{
	size_t ind = 0;
	size_t length = teams.size();

	for ( size_t i = 1; i < length; i++ )
	{
		if ( teams[ ind ] < teams[ i ] )
		{
			ind = i;
		}
	}

	if ( ind < length )
	{
		std::cout << "Strongest team is " << teams[ ind ].GetName()
			<< " with combined age of " << teams[ ind ].GetCumulativeAge()
			<< " and combined ability of " << teams[ ind ].GetCumulativeAbility()
			<< std::endl;

		std::cout << teams[ ind ];
	}
}
