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
    this->priority = 0;
}

Recipient::Recipient(string name, int age, string organ, string region, int urgency, int priority) {
    this->name = name;
    this->age = age;
    this->organ = organ;
    this->region = region;
    this->urgency = urgency;
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

void Recipient::equal(Recipient& rh) {
    this->name = rh.name;
    this->age = rh.age;
    this->organ = rh.organ;
    this->region = rh.region;
    this->urgency = rh.urgency;
    this->priority = rh.priority;
}
