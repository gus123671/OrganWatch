//
// Created by Nicolas Macias on 11/21/22.
// Modified by Augustus Rodriguez on 11/27/22
//

#ifndef PQARRAY_DONOR_H
#define PQARRAY_DONOR_H

#include <iostream>
#include <vector>
using namespace std;

class Donor 
{
    string name;
    int age;
    string organ;

    vector<Donor> donors;
public:
    Donor(string name, int age, string organ);
    string getName();
    int getAge();
    string getOrgan();
}; 


#endif //PQARRAY_DONOR_H
