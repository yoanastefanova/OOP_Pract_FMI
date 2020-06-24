
#ifndef POSTOFFICE_PACKAGE_H
#define POSTOFFICE_PACKAGE_H


#include "Mail.h"

class Package : public Mail {
public:
    Package();
    Package(const Person& receiver, const Address& receiverAdr, const Person& sender,
                const Address& senderAdr, float weight, double pricePerKilo, bool fragile);

    double getPrice() const override;
    void print() const override;
    float getWeight() const;

    Package* clone() const;

    void setWeight(float weight);
    void setPricePerKilo(double pricePerKilo);
    void setFragile(bool fragile);

protected:
    float weight;
    double pricePerKilo;
    bool fragile;
};


#endif //POSTOFFICE_PACKAGE_H
