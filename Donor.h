//
// Created by Nicolas Macias on 11/21/22.
//

#ifndef PQARRAY_DONOR_H
#define PQARRAY_DONOR_H

#include <iostream>
using namespace std;

class Donor {
public:
    string name;
    int age;
    string organ;
    string region;

    Donor(string name, int age, string organ, string region);
    string getName();
    int getAge();
    string getOrgan();

};


#endif //PQARRAY_DONOR_H
