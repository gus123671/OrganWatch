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
    double priority;

    Recipient();
    Recipient(string name, int age, string organ, string region, int urgency);
    string getName();
    int getAge();
    string getOrgan();
    string getRegion();
    int getUrgency();
    double getPriority();
    void print();
};

#endif //PQARRAY_RECIPIENT_H
