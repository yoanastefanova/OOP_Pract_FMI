#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED

#include "Ticket.h"

class Train
{
    public:
        Train();
        Train(unsigned int capacity);
        Train(const Train& other);
        Train& operator=(const Train& other);
        ~Train();

        void addTicket(const Ticket& ticket);
        void removeTicket(const Ticket& ticket);

        bool hasPassenger(const char* name) const;
        bool isFull() const;

        double getTotalPrice() const;
        void showInfo() const;

        int getCapacity() const;
        int getSize() const;

        void showTicketInfo(const Ticket& ticket) const;

    private:
        int size;
        int capacity;
        Ticket** tickets;

        void resizeUp();
        void resizeDown();
        void copyOther(const Train& other);
        void destroy();
};


#endif // TRAIN_H_INCLUDED
