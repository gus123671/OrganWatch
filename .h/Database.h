/*
	Author: Augustus Rodriguez
	Email: augustusrodriguez007@gmail.com
	Github: gus123671
	Created: 11/24/22
*/

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <string>
#include "Donor.h"
#include "Recipient.h"
#include "PQArray.h"
#include "PQTree.h"

using namespace std;

struct Database
{
    Database();

    vector<Donor> donors;
    vector<Recipient> recipients;
    PQArray recipientsArr;
    PQTree recipientsTree;

    void loadDonorData(std::string file, std::vector<Donor>& donors);
    void loadRecipientData(std::string file, vector<Recipient>& recipients);
    void calculatePriorities(vector<Recipient>& recipients);
    bool isValid(Donor &donor, Recipient &recipient);
};

#endif
