#include <iostream>
#include "Ticket.h"
#include "EconomicTicket.h"
#include "BusinessTicket.h"
#include "Train.h"
using namespace std;

int main()
{
    EconomicTicket et1("E1", 1, 5.75, 10.23, true),
                   et2("E3", 3, 5.75, 5.25, false),
                   et3("E5", 5, 5.75, 6.35, true),
                   et4("E7", 7, 4.25, 10.25, false);

    BusinessTicket bt1("B2", 2, 11.25, 10.23, 4),
                   bt2("B4", 4, 4.25, 4.90, 3),
                   bt3("B6", 6, 6.30, 4.00, 2),
                   bt4("B8", 8, 2.30, 7.50, 1);

    Train train;

    cout << "Size: " << train.getSize() <<
            ", capacity: " << train.getCapacity() << std::endl;

    train.addTicket(et1);
    cout << "Size: " << train.getSize() <<
            ", capacity: " << train.getCapacity() << std::endl;

    train.addTicket(bt1);
    cout << "Size: " << train.getSize() <<
            ", capacity: " << train.getCapacity() << std::endl;

    train.addTicket(bt2);
    cout << "Size: " << train.getSize() <<
            ", capacity: " << train.getCapacity() << std::endl;

    train.addTicket(et2);
    cout << "Size: " << train.getSize() <<
            ", capacity: " << train.getCapacity() << std::endl;

    train.addTicket(bt3);
    cout << "Size: " << train.getSize() <<
            ", capacity: " << train.getCapacity() << std::endl;

    train.addTicket(et3);
    cout << "Size: " << train.getSize() <<
            ", capacity: " << train.getCapacity() << std::endl;

    train.addTicket(bt4);
    cout << "Size: " << train.getSize() <<
            ", capacity: " << train.getCapacity() << std::endl;

    train.addTicket(et4);
    cout << "Size: " << train.getSize() <<
            ", capacity: " << train.getCapacity() << std::endl;

    train.showInfo();

    train.removeTicket(et1);
    train.removeTicket(et2);
    train.removeTicket(bt1);
    train.removeTicket(bt2);
    train.removeTicket(bt3);

    train.showInfo();

    return 0;
}
