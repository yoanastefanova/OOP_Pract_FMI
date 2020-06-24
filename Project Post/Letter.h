
#ifndef POSTOFFICE_LETTER_H
#define POSTOFFICE_LETTER_H

#include "Mail.h"

class Letter : public Mail {
public:
    Letter();
    Letter(const Person& receiver, const Address& receiverAdr, const Person& sender,
                const Address& senderAdr,double price, bool valuable = false);

    double getPrice() const override;
    void print() const override;
    float getWeight() const;
    Letter* clone() const;

    void setPrice(double price);
    void setValuable(bool valuable);

protected:
    float const WEIGHT = 0.01;

    double price;
    bool valuable;
};


#endif //POSTOFFICE_LETTER_H
