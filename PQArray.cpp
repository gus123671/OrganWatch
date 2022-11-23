//
// Created by Nicolas Macias on 11/21/22.
//

#include "PQArray.h"

PQArray::PQArray() {}

void PQArray::insert(int n) {
    this->queue.push_back(n);
    int child = this->queue.size() - 1;
    int parent = (child - 1) / 2;

    while (parent >= 0 && this->queue[parent] < this->queue[child]) {
        int temp = this->queue[parent];
        this->queue[parent] = this->queue[child];
        this->queue[child] = temp;
        child = parent;
        parent = (child - 1) / 2;
    }
}

int PQArray::extract() {
    this->queue[0] = 
}
