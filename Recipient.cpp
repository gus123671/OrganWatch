//
// Created by Nicolas Macias on 11/21/22.
//

#include "Recipient.h"

Recipient::Recipient(string name, int age, string organ, double priority) {
    this->name = name;
    this->age = age;
    this->organ = organ;
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

double Recipient::getPriority() {
    return this->priority;
}