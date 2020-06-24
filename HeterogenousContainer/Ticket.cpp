#include <iostream>
#include <cstring>
#include "Ticket.h"

Ticket::Ticket() : Ticket("Default", 0, 0, 0)
{}

Ticket::Ticket(const char* owner, unsigned int seat,
               double price, double luggage) : owner(nullptr)
{
    setOwner(owner);
    setSeat(seat);
    setPrice(price);
    setLuggage(luggage);
}

Ticket::Ticket(const Ticket& other) : Ticket(other.owner, other.seat, other.price, other.luggage)
{}

Ticket& Ticket::operator=(const Ticket& other)
{
    if(this != &other){
        setOwner(other.owner);
        setSeat(other.seat);
        setPrice(other.price);
        setLuggage(other.luggage);
    }

    return *this;
}

Ticket::~Ticket()
{
    delete [] owner;
    std::cout << "Ticket d-tor" << std::endl;
}

const char* Ticket::getOwner() const
{
    return owner;
}

unsigned int Ticket::getSeat() const
{
    return seat;
}

double Ticket::getPrice() const
{
    return price;
}

double Ticket::getLuggage() const
{
    return luggage;
}

void Ticket::setOwner(const char* newOwner)
{
    if(newOwner != nullptr){
        delete [] owner;

        owner = new char[strlen(newOwner) + 1];
        strcpy(owner, newOwner);
    }
}

void Ticket::setSeat(unsigned int newSeat)
{
    if(newSeat >= 0) seat = newSeat;
}

void Ticket::setPrice(double newPrice)
{
    if(newPrice >= 0) price = newPrice;
}

void Ticket::setLuggage(double newLuggage)
{
    if(newLuggage >= 0) luggage = newLuggage;
}

void Ticket::print() const
{
    std::cout << "Owner: " << owner
              << ", seat: " << seat
              << ", price: " << price
              << ", luggage: " << luggage << std::endl;

}

bool Ticket::operator==(const Ticket& other) const
{
    return strcmp(this->owner, other.owner) == 0;
}


