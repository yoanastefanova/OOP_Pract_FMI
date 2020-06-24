
#include <iostream>
#include "../Headers/Mail.h"

void Mail::getInfo() const {
    std::cout << "Receiver: ";
    receiver.print();

    std::cout << "Receiver address: ";
    receiverAddress.print();

    std::cout << "Sender: ";
    sender.print();
    std::cout << "Sender address: ";
    senderAddress.print();
}

const Person& Mail::getReceiver() const {
    return receiver;
}

const Address& Mail::getReceiverAddress() const {
    return receiverAddress;
}

const Person& Mail::getSender() const {
    return sender;
}

const Address& Mail::getSenderAddress() const {
    return senderAddress;
}
