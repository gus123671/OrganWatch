//
// Created by Nicolas Macias on 11/21/22.
// Modified by Augustus Rodriguez on 11/27/22
//
#pragma once

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

public:
    Donor(string name, int age, string organ);
    string getName();
    int getAge();
    string getOrgan();
    static vector<Donor> donors;
}; 


#endif //PQARRAY_DONOR_H
