
#ifndef POSTOFFICE_MAILMAN_H
#define POSTOFFICE_MAILMAN_H


#include "Person.h"
#include "Mail.h"

class Mailman : public Person {
public:
    Mailman();
    Mailman(const char* name, const char* ucn, double weight, int capacity = 5);
    Mailman(const Mailman& other);
    Mailman& operator=(const Mailman& other);
    virtual ~Mailman();

    void addMail(const Mail& mail);
    void print() const;

    void sort(bool (*toSwap)(const Mail*, const Mail*));
    void deliver(Address** pAddresses, int adrSize);
    void remove(const Address* pAddress);

    float getWeight() const;
    const Mail& cheapestMail() const;

private:
    int size;
    int capacity;
    Mail** mails;

    float currentWeight = 0;
    double maxWeight;


    bool isFull() const;
    bool isEmpty() const;

    void resize();
    void copy(const Mailman& other);
    void destroy();
};


#endif //POSTOFFICE_MAILMAN_H
