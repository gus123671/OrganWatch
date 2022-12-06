//
// Created by Nicolas Macias on 11/21/22.
//

#include "../.h/Recipient.h"

Recipient::Recipient()
{
    this->name = "INVALID";
    this->age = -1;
    this->organ = "INVALID";
    this->region = "INVALID";
    this->urgency = -1;
}

Recipient::Recipient(string name, int age, string organ, string region, int urgency) {
    this->name = name;
    this->age = age;
    this->organ = organ;
    this->region = region;
    this->urgency = urgency;
    this->priority = 0;
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

int Recipient::getPriority() {
    return this->priority;
}

void Recipient::setPriority(int prio)
{
    this->priority = prio;
}

int Recipient::getUrgency()
{
    return this->urgency;
}

void Recipient::print() {
    cout << name << endl;
    cout << age << endl;
    cout << organ << endl;
    cout << region << endl;
    cout << priority << endl << endl;
}