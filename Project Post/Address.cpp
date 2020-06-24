
#include <cstring>
#include <iostream>
#include "../Headers/Address.h"

Address::Address() : Address("-", '-', 0, "-", "-") {
}

Address::Address(const char* town, char entrance, int apt, const char* street, const char* building)
                                                    : town(nullptr), street(nullptr), building(nullptr) {
    setTown(town);
    setStreet(street);
    setBuilding(building);
    setEntrance(entrance);
    setApt(apt);
}

Address::Address(const Address& other) : Address(other.town, other.entrance, other.apt, other.street, other.building) {
}

Address &Address::operator=(const Address& other) {
    if (this != &other) {
        setTown(other.town);
        setStreet(other.street);
        setBuilding(other.building);
        setEntrance(other.entrance);
        setApt(other.apt);
    }

    return *this;
}

Address::~Address() {
    delete [] town;
    delete [] street;
    delete [] building;
}

bool Address::operator==(const Address& other) const {
    return strcmp(town, other.town) == 0 && strcmp(street, other.street) == 0
            && strcmp(building, other.building) == 0 && entrance == other.entrance && apt == other.apt;
}

void Address::setTown(const char* town) {
    if (town != nullptr) {
        delete [] this->town;

        this->town = new char[strlen(town) + 1];
        strcpy(this->town, town);
    }
}

void Address::setStreet(const char* street) {
    if (street != nullptr) {
        delete [] this->street;

        this->street = new char[strlen(street) + 1];
        strcpy(this->street, street);
    }
}

void Address::setBuilding(const char* building) {
    if (building != nullptr) {
        delete [] this->building;

        this->building = new char[strlen(building) + 1];
        strcpy(this->building, building);
    }
}

void Address::setEntrance(const char entrance) {
    this->entrance = entrance;
}

void Address::setApt(int apt) {
    this->apt = apt;
}

void Address::destroy() {
    delete [] town;
    delete [] street;
    delete [] building;
}

void Address::print() const {
    std::cout << "Address: {" << std::endl;
    std::cout << "\tTown: " << town << std::endl;

    if (!strcmp(street, "-")) {
        std::cout << "\tStreet: " << street << std::endl;
    }

    if (!strcmp(building, "-")) {
        std::cout << "\tBuilding: " << building << std::endl;
    }

    std::cout << "\tEntrance: " << entrance << std::endl;
    std::cout << "\tApt: " << apt << std::endl;
    std::cout << "}" << std::endl;
}
