#include <iostream>
#include <cstring>
#include <cmath>
#include "Train.h"


Train::Train() : Train(4)
{}

Train::Train(unsigned int capacity)
{
    this->size = 0;
    this->capacity = (capacity >= 4) ? capacity : 4;
    this->tickets = new Ticket*[this->capacity];
}

Train::Train(const Train& other)
{
    copyOther(other);
}

Train& Train::operator=(const Train& other)
{
    if(this != &other){
        destroy();
        copyOther(other);
    }
    return *this;
}

Train::~Train()
{
    destroy();
}

void Train::addTicket(const Ticket& ticket)
{
    if(hasPassenger(ticket.getOwner())) return;

    if(isFull()) resizeUp();

    tickets[size++] = ticket.clone();
}

void Train::removeTicket(const Ticket& ticket)
{
    for(int i = 0; i < size; ++i){
        if(*(tickets[i]) == ticket){
            delete tickets[i];

            tickets[i] = tickets[size - 1];
            size--;

            if(size < capacity / 2) resizeDown();

            break;
        }
    }

}

bool Train::hasPassenger(const char* owner) const
{
    for(int i = 0; i < size; ++i){
        if(strcmp(tickets[i]->getOwner(), owner) == 0){
            return true;
        }
    }

    return false;
}

bool Train::isFull() const
{
    return size == capacity;
}


double Train::getTotalPrice() const
{
    double totalPrice = 0;

    for(int i = 0; i < size; ++i){
        totalPrice += tickets[i]->getPrice();
    }

    return totalPrice;
}

void Train::showInfo() const
{
    std::cout << "Size: " << size << ", capacity: " << capacity << std::endl;
    for(int i = 0; i < size; ++i){
        tickets[i]->print();
    }
    std::cout << std::endl;
}

int Train::getCapacity() const
{
    return capacity;
}

int Train::getSize() const
{
    return size;
}

void Train::showTicketInfo(const Ticket& ticket) const
{
    for(int i = 0; i < size; ++i){
        if(*(tickets[i]) == ticket){
            tickets[i]->print();
            return;
        }
    }
}

void Train::resizeUp()
{
    capacity *= 2;

    Ticket** temp = new Ticket*[capacity];

    for(int i = 0; i < size; ++i){
        temp[i] = tickets[i];
    }

    delete [] tickets;

    tickets = temp;
}

void Train::resizeDown()
{
    capacity /= 2;

    Ticket** temp = new Ticket*[capacity];

    for(int i = 0; i < size; ++i){
        temp[i] = tickets[i];
    }

    delete [] tickets;

    tickets = temp;
}

void Train::copyOther(const Train& other)
{
    size = other.size;
    capacity = other.capacity;
    tickets = new Ticket*[other.capacity];

    for(int i = 0; i < size; ++i){
        tickets[i] = other.tickets[i]->clone();
    }
}

void Train::destroy()
{
    for(int i = 0; i < size; ++i){
        delete tickets[i];
    }
    delete [] tickets;
}
