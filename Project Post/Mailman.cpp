
#include <iostream>
#include "../Headers/Mailman.h"

Mailman::Mailman() : Mailman("Default", "Default", 1) {
}

Mailman::Mailman(const char* name, const char* ucn, double weight, int capacity) : Person(name, ucn) {
    this->maxWeight = weight;
    this->size = 0;
    this->capacity = capacity >= 5 ? capacity : 5;
    mails = new Mail*[this->capacity];
}

Mailman::Mailman(const Mailman& other) {
    copy(other);
}

Mailman& Mailman::operator=(const Mailman& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Mailman::~Mailman() {
    destroy();
}

void Mailman::addMail(const Mail& mail) {
    if (mail.getWeight() + currentWeight > maxWeight) {
        std::cout << "The package is too heavy!" << std::endl;
        return;
    }

    if (isFull()) {
        resize();
    }

    mails[size++] = mail.clone();
    currentWeight += mail.getWeight();
}

void Mailman::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << "{" << std::endl;
        mails[i]->print();
        std::cout << "}" << std::endl;
    }
}

void Mailman::sort(bool (*toSwap)(const Mail*, const Mail*)) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i; j < size; ++j) {
            if (toSwap(mails[i], mails[j])) {
                std::swap(mails[i], mails[j]);
            }
        }
    }
}

void Mailman::deliver(Address** pAddresses, int adrSize) {
    for (int i = 0; i < adrSize; ++i) {
        std::cout << std::endl;
        std::cout << "Address " << i + 1 << ":" << std::endl << std::endl;
        for (int j = size-1; j >= 0; --j) {
            if (*pAddresses[i] == mails[j]->getReceiverAddress()) {
                mails[j]->print();
                remove(pAddresses[i]);
            }
        }
        std::cout << std::endl;
    }
}

void Mailman::remove(const Address* pAddress) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (mails[i]->getReceiverAddress() == *pAddress) {
            index = i;
        }
    }
    if (index != -1) {
        currentWeight -= mails[index]->getWeight();
        delete mails[index];
        for (int i = index; i < size - 1; ++i) {
            mails[i] = mails[i + 1];
        }
        size--;
    }
}

float Mailman::getWeight() const {
    return currentWeight;
}

bool Mailman::isFull() const {
    return size == capacity;
}

bool Mailman::isEmpty() const {
    return size == 0;
}

void Mailman::resize() {
    capacity *= 2;

    Mail** temp = new Mail*[capacity];

    for (int i = 0; i < size; ++i) {
        temp[i] = mails[i]->clone();
    }

    delete [] mails;

    mails = temp;
}

void Mailman::copy(const Mailman &other) {
    size = other.size;
    capacity = other.capacity;
    mails = new Mail*[other.capacity];

    for (int i = 0; i < size; ++i) {
        mails[i] = other.mails[i]->clone();
    }
}

void Mailman::destroy() {
    for (int i = 0; i < size; ++i) {
        delete mails[i];
    }

    delete [] mails;
}

const Mail& Mailman::cheapestMail() const {
    Mail* cheapest = mails[0];

    for (int i = 1; i < size; ++i) {
        if (mails[i]->getPrice() < cheapest->getPrice()) {
            cheapest = mails[i];
        }
    }

    return *cheapest;
}



