#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

class Ticket
{
    public:
        Ticket();
        Ticket(const char* owner, unsigned int seat,
               double price, double luggage);
        Ticket(const Ticket& other);
        Ticket& operator=(const Ticket& other);
        virtual ~Ticket();

        virtual Ticket* clone() const = 0;

        const char* getOwner() const;
        unsigned int getSeat() const;
        virtual double getPrice() const = 0;
        double getLuggage() const;

        void setOwner(const char* newOwner);
        void setSeat(unsigned int newSeat);
        void setPrice(double newPrice);
        void setLuggage(double newLuggage);

        virtual void print() const = 0;

        bool operator==(const Ticket& other) const;

    protected:
        char* owner;
        unsigned int seat;
        double price;
        double luggage;
};


#endif // TICKET_H_INCLUDED
