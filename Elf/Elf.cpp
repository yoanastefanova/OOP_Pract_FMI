#include "Elf.h"

String::String() : str(nullptr), size(0)
{}

String::String(const char* src)
{
	size = strlen(src);
	str = new char[size + 1];
	strcpy_s(str, size + 1, src);
}

String::String(const String& other)
{
	size = other.size;
	str = new char[size + 1];
	strcpy_s(str, size + 1, other.str);
}

String& String::operator=(const String& rhs)
{
	if (this != &rhs)
	{
		delete[] str;

		size = rhs.size;
		str = new char[size + 1];
		strcpy_s(str, size + 1, rhs.str);
	}
	return *this;
}

String::~String()
{
	delete[] str;
}

const char* String::c_str() const
{
	return str;
}

size_t String::length() const
{
	return size;
}

String String::operator+(const String& other) const
{
	String res;
	res.size = size + other.size;
	res.str = new char[ res.size + 1 ];

	strcpy_s(res.str, size + 1, str);
	strcat_s(res.str, other.size + 1, other.str);

	return res;

	//operator+= would be analogous:
	
}

String& String::operator+=(const String& other)
{
	//1. allocate new memory with size = this->size + other.size + 1
	size_t newSize = size + other.size;
	char* temp = new char[ newSize + 1 ];

	//2. copy this->str into the new memory
	strcpy_s(temp, size + 1, str);

	//3. concatenate other.str to the new memory
	strcat_s(temp, other.size + 1, other.str);

	//4. delete this->str
	delete str;

	//5. set this->str = the new memory
	str = temp;

	//6. set size and return
	size = newSize;
	return *this;
}

bool String::operator==(const String& rhs) const
{
	return strcmp(str, rhs.str) == 0;
}

Elf::Elf() : age(0), ability(1)
{
}

Elf::Elf(const String& name_, size_t age_, size_t ability_)
	: name( name_ )
	, age( age_ <= 300 ? age_ : 300 )
	, ability( ability_ < 1
						? 1
						: ability_ > 15
									? 15
									: ability_ )
{
}

const String& Elf::GetName() const
{
	return name;
}

size_t Elf::GetAge() const
{
	return age;
}

size_t Elf::GetAbility() const
{
	return ability;
}


void Elf::SetName(const String& newName)
{
	name = newName;
}

void Elf::SetAge(size_t newAge)
{
	age = newAge < 300 ? newAge : 300;
}

void Elf::SetAbility(size_t newAbility)
{
	ability = newAbility < 1
							? 1
							: newAbility > 15
											? 15
											: newAbility;
}

std::ostream& operator<<(std::ostream& os, const String& elf)
{
	return os << elf.c_str();
}

std::ostream& operator<<(std::ostream& os, const Elf& elf)
{
	os << "Name: " << elf.name << std::endl;
	os << "Age: " << elf.age << std::endl;
	os << "Ability: " << elf.ability << std::endl;

	return os;
}
