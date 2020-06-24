#include <iostream>
#include "Headers/Mailman.h"
#include "Headers/Letter.h"
#include "Headers/Package.h"

bool sortByWeight(const Mail* mail1, const Mail* mail2) {
    return mail1->getWeight() >= mail2->getWeight();
}

int main() {
    Person sender1("Gosho", "1234567890");
    Person sender2("Pesho", "0987654321");
    Address sender1Adr("Sofia", 'A', 2, "", "bl. 101");
    Address sender2Adr("Varna", '1', 20, "st. Gosho jin", "");

    Person receiver1("Petko", "0099887766");
    Person receiver2("Samoletko", "1122334455");
    Address receiver1Adr("Plovdiv", '1', 14, "", "45");
    Address receiver2Adr("Sofia", 'A', 38, "", "301");

    Letter letter1(receiver1, receiver1Adr, sender1, sender1Adr, 1.60, true);
    Package package(receiver2, receiver2Adr, sender1, sender1Adr, 1, 2.50, false);

    ///last function and Person init in Letter and Package
    Mailman mailman("Peio", "9902091223", 3);

    mailman.addMail(package);
    mailman.addMail(letter1);
    mailman.addMail(letter1);
    mailman.addMail(package);
    mailman.addMail(letter1);

    std::cout << "Output cheapest mail:" << std::endl;
    const Mail* m = mailman.cheapestMail().clone();

    std::cout << "Before sorting" << std::endl;

    mailman.print();

    mailman.sort(sortByWeight);

    std::cout << "After sorting" << std::endl;

    mailman.print();

    std::cout << std::endl << std::endl;

    Address** delivers = new Address*[2];
    delivers[0] = &receiver1Adr;
    delivers[1] = &receiver2Adr;

    std::cout << mailman.getWeight() << std::endl;

    mailman.deliver(delivers, 2);

    std::cout << "Alter delivering" << std::endl;
    mailman.print();

    std::cout << mailman.getWeight() << std::endl;
    m->print();

    delete [] delivers;
    delete m;

    return 0;
}