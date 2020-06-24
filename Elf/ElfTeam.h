#pragma once

#include "Elf.h"

#include <vector>

class ElfTeam
{
public:
	ElfTeam(const String& nam);
	ElfTeam(const ElfTeam& other);
	ElfTeam& operator=(const ElfTeam& rhs);
	~ElfTeam();

	bool operator<(const ElfTeam& rhs) const;
	ElfTeam operator+(const ElfTeam& rhs) const;
	ElfTeam& operator+=(const ElfTeam& rhs);

	void AddElf(const Elf& elf);
	void RemoveElf(const String& name);

	const String& GetName() const;
	size_t GetCumulativeAge() const;
	size_t GetCumulativeAbility() const;

	friend std::ostream& operator<<(std::ostream& os, const ElfTeam& elf);

private:
	void copy(const ElfTeam& other);
	void del();
	void resize(size_t required = 0);

	String name;
	Elf* members;

	size_t size;
	size_t capacity;
};

std::ostream& operator<<(std::ostream& os, const ElfTeam& elfTeam);

//find max element based on operator<
void analyze(const std::vector<ElfTeam>& teams);