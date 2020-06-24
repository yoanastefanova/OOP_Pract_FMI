#ifndef BUSINESSTICKET_H_INCLUDED
#define BUSINESSTICKET_H_INCLUDED

#include "Ticket.h"

class BusinessTicket: public Ticket
{
    public:
        BusinessTicket();
        BusinessTicket(const char* owner, unsigned int seat,
                       double price, double luggage, unsigned short features);
        ~BusinessTicket();

        BusinessTicket* clone() const; /// override virtual function

        double getPrice() const; /// override virtual function
        unsigned short getFeatures() const;

        void setFeatures(unsigned short newFeatures);

        void print() const; /// override virtual function

    private:
        unsigned short features;
};

#endif // BUSINESSTICKET_H_INCLUDED
