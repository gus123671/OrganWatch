//
// Created by Nicolas Macias on 11/21/22.
//

#ifndef PQARRAY_PQARRAY_H
#define PQARRAY_PQARRAY_H

#include <vector>
#include "Donor.h"
#include "Recipient.h"

class PQArray {
public:
    vector<Recipient> queue;
    PQArray();

    int size = queue.size();
    void insert(Recipient recipient);
    Recipient extract();
    void heapifyDown(int pos);
    Recipient extractValid(Donor& donor);
    bool isValid(Donor &donor, Recipient &recipient);
};


#endif //PQARRAY_PQARRAY_H
