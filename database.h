#include "PQArray.h"
#include "Donor.h"
#include "Recipient.h"

struct Database
{
    vector<Donor> donors;
    // PQArray recipientsArr;
    // PQTree recipientsTree;
    
    void showData();
};