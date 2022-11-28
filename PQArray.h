//
// Created by Nicolas Macias on 11/21/22.
//

#ifndef PQARRAY_PQARRAY_H
#define PQARRAY_PQARRAY_H

#include <vector>
#include "Donor.h"
#include "Recipient.h"

class PQArray {
    vector<int> queue;
public:
    PQArray();
    void insert(int n);
    int extract();
    void heapifyDown(int pos);
    int extractValid(int n);
};

#endif //PQARRAY_PQARRAY_H