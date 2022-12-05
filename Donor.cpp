//
// Created by Nicolas Macias on 11/21/22.
//

#include "Donor.h"

Donor::Donor(string name, int age, string organ, string region) {
    this->name = name;
    this->age = age;
    this->organ = organ;
    this->region = region;
}

string Donor::getName() {
    return this->name;
}

int Donor::getAge() {
    return this->age;
}

string Donor::getOrgan() {
    return this->organ;
}
