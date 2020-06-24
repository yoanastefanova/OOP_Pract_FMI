#include <iostream>
#include <cstring>
#include "EconomicTicket.h"

EconomicTicket::EconomicTicket() : EconomicTicket("Default", 0, 0, 0, true)
{}

EconomicTicket::EconomicTicket(const char* owner, unsigned int seat, double price,
                               double luggage, bool reservedSeat) : Ticket(owner, seat, price, luggage)
{
    setReservedSeat(reservedSeat);
}

EconomicTicket::~EconomicTicket()
{
    std::cout << "D-tor: "; print();
}


EconomicTicket* EconomicTicket::clone() const
{
    return new EconomicTicket(*this);
}

double EconomicTicket::getPrice() const
{
    return ((reservedSeat) ? price + 0.50 : price);
}

bool EconomicTicket::getReserved() const
{
    return reservedSeat;
}

void EconomicTicket::setReservedSeat(bool newReservedSeat)
{
    reservedSeat = newReservedSeat;
}

void EconomicTicket::print() const
{
    std::cout << "Owner of ticket(e): " << owner
              << ", price: " << getPrice()
              << ", luggage: " << luggage
              << ", seat: " << seat << ((reservedSeat) ? " (reserved)" : "") << std::endl;
}

