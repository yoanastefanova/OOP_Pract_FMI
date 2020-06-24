
#include <iostream>
#include "../Headers/Letter.h"

Letter::Letter() {
}

Letter::Letter(const Person& receiver, const Address& receiverAdr, const Person& sender,
                const Address& senderAdr, double price, bool valuable) {
    Mail::receiver = receiver;
    Mail::receiverAddress = receiverAdr;
    Mail::sender = sender;
    Mail::senderAddress = senderAdr;

    setPrice(price);
    setValuable(valuable);
}

double Letter::getPrice() const {
    return price * (1 + 0.3 * valuable);
}

void Letter::print() const {
    std::cout << "Price: " << price << std::endl;
    std::cout << "Valuable: " << std::boolalpha << valuable << std::endl;
    std::cout << "Total price: " << getPrice() << std::endl;
    std::cout << "Weight: " << WEIGHT << std::endl;

    Mail::getInfo();
}

Letter* Letter::clone() const {
    return new Letter(*this);
}

void Letter::setPrice(double price) {
    this->price = price;
}

void Letter::setValuable(bool valuable) {
    this->valuable = valuable;
}

float Letter::getWeight() const {
    return WEIGHT;
}
