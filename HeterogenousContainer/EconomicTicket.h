#ifndef ECONOMICTICKET_H_INCLUDED
#define ECONOMICTICKET_H_INCLUDED

#include "Ticket.h"

class EconomicTicket: public Ticket
{
    public:
        EconomicTicket();
        EconomicTicket(const char* owner, unsigned int seat,
                       double price, double luggage, bool reservedSeat);
        ~EconomicTicket();

        EconomicTicket* clone() const; /// override virtual function

        double getPrice() const; /// override virtual function
        bool getReserved() const;

        void setReservedSeat(bool newReservedSeat);

        void print() const; /// override virtual function

    private:
        bool reservedSeat;
};

#endif // ECONOMICTICKET_H_INCLUDED
