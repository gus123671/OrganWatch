//
// Created by Nicolas Macias on 11/21/22.
// Modified by Augustus Rodriguez on 12/6/22
//

#ifndef PQARRAY_DONOR_H
#define PQARRAY_DONOR_H

#include <iostream>
#include <string>
using namespace std;

class Donor {
public:
    string name;
    int age;
    string organ;
    string region;

    Donor();
    Donor(string name, int age, string organ, string region);

    string getName();
    int getAge();
    string getOrgan();
    string getRegion();
};

#endif 
