//
// Created by Nicolas Macias on 11/21/22.
//

#ifndef PQARRAY_RECIPIENT_H
#define PQARRAY_RECIPIENT_H

#include <iostream>
using namespace std;

class Recipient {
public:
    string name;
    int age;
    string organ;
    string region;
    int urgency;
    int priority = 0;

    Recipient();
    Recipient(string name, int age, string organ, string region, int urgency, int priority);
    void equal(Recipient& rh);
    string getName();
    int getAge();
    string getOrgan();
    string getRegion();
    int getUrgency();
    int getPriority();
    void setPriority(int prio);
    void print();
};

#endif //PQARRAY_RECIPIENT_H
