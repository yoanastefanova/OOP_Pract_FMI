
#ifndef POSTOFFICE_MAIN_H
#define POSTOFFICE_MAIN_H


#include "Person.h"
#include "Address.h"

class Mail {
public:
    virtual double getPrice() const = 0;
    virtual void print() const = 0;
    virtual float getWeight() const = 0;

    virtual Mail* clone() const = 0;

    void getInfo() const;

    const Person& getReceiver() const;
    const Address& getReceiverAddress() const;
    const Person& getSender() const;
    const Address& getSenderAddress() const;

protected:
    Person receiver;
    Address receiverAddress;

    Person sender;
    Address senderAddress;
};


#endif //POSTOFFICE_MAIN_H
