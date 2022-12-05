//
// Created by Nicolas Macias on 11/21/22.
//

#include "Recipient.h"

Recipient::Recipient(string name, int age, string organ, string region, double priority) {
    this->name = name;
    this->age = age;
    this->organ = organ;
    this->region = region;
    this->priority = priority;
}

string Recipient::getName() {
    return this->name;
}

int Recipient::getAge() {
    return this->age;
}

string Recipient::getOrgan() {
    return this->organ;
}

string Recipient::getRegion() {
    return this->region;
}

double Recipient::getPriority() {
    return this->priority;
}

void Recipient::print() {
    cout << name << endl;
    cout << age << endl;
    cout << organ << endl;
    cout << region << endl;
    cout << priority << endl << endl;
}