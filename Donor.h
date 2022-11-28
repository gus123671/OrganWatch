//
// Created by Nicolas Macias on 11/21/22.
//
#pragma once
<<<<<<< HEAD
=======

#ifndef PQARRAY_DONOR_H
#define PQARRAY_DONOR_H
>>>>>>> f17f5ceb4e709cb9a7707dac8accf14e18727a4a

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
<<<<<<< HEAD
}; 
=======
    static vector<Donor> donors;
}; 


#endif //PQARRAY_DONOR_H
>>>>>>> f17f5ceb4e709cb9a7707dac8accf14e18727a4a
