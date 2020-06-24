#include <iostream>
#include <cstring>
#include "BusinessTicket.h"

BusinessTicket::BusinessTicket() : BusinessTicket("Default", 0, 0, 0, 1)
{}

BusinessTicket::BusinessTicket(const char* owner, unsigned int seat,
                               double price, double luggage, unsigned short features)
   : Ticket(owner, seat, price, luggage)
{
    setFeatures(features);
}

BusinessTicket::~BusinessTicket()
{
    std::cout << "D-tor: "; print();
}


BusinessTicket* BusinessTicket::clone() const
{
    return new BusinessTicket(*this);
}


double BusinessTicket::getPrice() const
{
    return price + features * 1.5;
}

unsigned short BusinessTicket::getFeatures() const
{
    return features;
}

void BusinessTicket::setFeatures(unsigned short newFeatures)
{
    features = newFeatures;
}

void BusinessTicket::print() const
{
    std::cout << "Owner of ticket(b): " << owner
              << ", price: " << getPrice()
              << ", luggage: " << luggage
              << ", number of features: " << features << std::endl;
}

