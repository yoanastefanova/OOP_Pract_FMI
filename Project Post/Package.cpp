
#include <iostream>
#include "../Headers/Package.h"

Package::Package() {
}

Package::Package(const Person& receiver, const Address& receiverAdr, const Person& sender,
                    const Address& senderAdr, float weight, double pricePerKilo, bool fragile) {
    Mail::receiver = receiver;
    Mail::receiverAddress = receiverAdr;
    Mail::sender = sender;
    Mail::senderAddress = senderAdr;

    setWeight(weight);
    setPricePerKilo(pricePerKilo);
    setFragile(fragile);
}

double Package::getPrice() const {
    return pricePerKilo * (1 + 0.2 * fragile) * weight;
}

void Package::print() const {
    std::cout << "Weight: " << weight << std::endl;
    std::cout << "Price per kilogram: " << pricePerKilo << std::endl;
    std::cout << "Fragile: " << std::boolalpha << fragile << std::endl;

    Mail::getInfo();
}

float Package::getWeight() const {
    return weight;
}

Package* Package::clone() const {
    return new Package(*this);
}

void Package::setWeight(float weight) {
    this->weight = weight;
}

void Package::setPricePerKilo(double pricePerKilo) {
    this->pricePerKilo = pricePerKilo;
}

void Package::setFragile(bool fragile) {
    this->fragile = fragile;
}
