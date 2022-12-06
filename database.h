#pragma once
#include "PQArray.h"
#include "Donor.h"
#include "Recipient.h"


struct Database
{
    Database();
    vector<Donor> donors;
    vector<Recipient> recipients;
    // PQArray recipientsArr;
     PQTree recipientsTree;

    void showData();
    void loadDonorData(std::string file, vector<Donor>& donors);
    void loadRecipientData(std::string file, vector<Recipient>& recipients);
};