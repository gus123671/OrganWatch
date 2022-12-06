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
    double priority;

    Recipient(string name, int age, string organ, string region, double priority);
    string getName();
    int getAge();
    string getOrgan();
    string getRegion();
    double getPriority();
    void print();
};

#endif //PQARRAY_RECIPIENT_H
