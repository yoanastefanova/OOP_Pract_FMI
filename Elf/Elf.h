#pragma once

#ifndef ELF_H
#define ELF_H

#include <iostream>

class String
{
public:
	String();
	String(const char* src);
	String(const String& other);
	String& operator=(const String& rhs);
	~String();

	const char* c_str() const;
	size_t length() const;

	String operator+(const String& other) const;
	String& operator+=(const String& other);

	bool operator==(const String& rhs) const;

private:
	char* str;
	size_t size;
};

std::ostream& operator<<(std::ostream& os, const String& elf);

class Elf
{
public:
	Elf();
	Elf(const String& name_, size_t age_, size_t ability_);

	const String& GetName() const;
	size_t GetAge() const;
	size_t GetAbility() const;

	void SetName(const String& newName);
	void SetAge(size_t newAge);
	void SetAbility(size_t newAbility);

	friend std::ostream& operator<<(std::ostream& os, const Elf& elf);

private:
	String name;
	size_t age;
	size_t ability;
};

std::ostream& operator<<(std::ostream& os, const Elf& elf);

#endif // !ELF_H
