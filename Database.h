#pragma once

#include "PQArray.h"
#include "Donor.h"
#include "Recipient.h"

struct Database
{
    Database();
    vector<Donor> donors;
    // PQArray recipientsArr;
    // PQTree recipientsTree;
    
    void showData();
    void loadData();
};
