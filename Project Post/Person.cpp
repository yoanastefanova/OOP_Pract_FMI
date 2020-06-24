
#include <cstring>
#include <iostream>
#include "../Headers/Person.h"

Person::Person() : Person("Default", "-") {
}

Person::Person(const char* name, const char* ucn) : name(nullptr), ucn(nullptr) {
    setName(name);
    setUcn(ucn);
}

Person::Person(const Person& other) : Person(other.name, other.ucn) {
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        setName(other.name);
        setUcn(other.ucn);
    }
    return *this;
}

Person::~Person() {
    destroy();
}

void Person::setName(const char* name) {
    if (name != nullptr) {
        delete [] this->name;

        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

void Person::setUcn(const char* ucn) {
    if (ucn != nullptr && isNumeric(ucn) && strlen(ucn) == 10) {
        delete [] this->ucn;
        this->ucn = new char[strlen(ucn) + 1];
        strcpy(this->ucn, ucn);
    }
}

void Person::print() const {
    std::cout << "Person: {" << std::endl;
    std::cout << "\tName: " << name << std::endl;
    std::cout << "\tUCN: " << ucn << std::endl;
    std::cout << "}" << std::endl;
}

void Person::destroy() {
    delete [] name;
    delete [] ucn;
}

bool Person::isNumeric(const char* ucn) {
    for (int i = 0; i < strlen(ucn); i++) {
        if (ucn[i] < '0' && ucn[i] > '9') {
            return false;
        }
    }

    return true;
}
