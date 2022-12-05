//
// Created by Nicolas Macias on 11/21/22.
//

#ifndef PQARRAY_RECIPIENT_H
#define PQARRAY_RECIPIENT_H

#include <iostream>
#include <vector>
using namespace std;

class Recipient 
{
    string name;
    int age;
    string organ;
    double priority;

public:
    Recipient(string name, int age, string organ, double priority);

    string getName();
    int getAge();
    string getOrgan();
    double getPriority();
};

#endif //PQARRAY_RECIPIENT_H
