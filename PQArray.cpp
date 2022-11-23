//
// Created by Nicolas Macias on 11/21/22.
//

#include "PQArray.h"

PQArray::PQArray() {}

void PQArray::insert(int n) {
    // Push back new element
    this->queue.push_back(n);
    int child = this->queue.size() - 1;
    int parent = (child - 1) / 2;

    // Swap up until correct position is found
    while (parent >= 0 && this->queue[parent] < this->queue[child]) {
        int temp = this->queue[parent];
        this->queue[parent] = this->queue[child];
        this->queue[child] = temp;
        child = parent;
        parent = (child - 1) / 2;
    }
}

int PQArray::extract() {
    // Max is at the beginning of queue
    int max = this->queue[0];

    // Process for heapifying down
    this->queue[0] = this->queue[this->queue.size() - 1];
    this->queue.pop_back();
    this->heapifyDown(0);

    // Return max element
    return max;
}

void PQArray::heapifyDown(int pos) {
    // Return if pos exceeds vector size
    int size = this->queue.size() - 1;
    if (pos > size) {
        return;
    }

    // Define child pos
    int leftPos = 2 * pos + 1;
    int rightPos = 2 * pos + 2;

    // Define characteristics of element at pos
    bool leaf = false;
    bool leftOnly = false;
    bool twoChildren = true;

    // Set characteristics of element at pos
    if (leftPos > this->queue.size() - 1 && rightPos > this->queue.size() - 1) {
        leaf = true;
        twoChildren = false;
    } else if (leftPos > this->queue.size() - 1) {
        leftOnly = true;
        twoChildren = false;
    } else if (rightPos > this->queue.size() - 1) {
        twoChildren = false;
    }

    // Return if leaf
    if (leaf) {
        return;
    }

    // Position of max child
    int maxPos;

    // Define pos with max
    if (leftOnly &&  !twoChildren) {
        maxPos = leftPos;
    } else if (!leftOnly && !twoChildren) {
        maxPos = rightPos;
    } else if (twoChildren) {
        if (this->queue[leftPos] >= this->queue[rightPos]) {
            maxPos = leftPos;
        } else {
            maxPos = rightPos;
        }
    }

    // Swap at pos and maxPos
    int temp = this->queue[pos];
    this->queue[pos] = this->queue[maxPos];
    this->queue[maxPos] = temp;

    // Heapify @ maxPos
    this->heapifyDown(maxPos);
}

int PQArray::extractValid(int n) {
    // Create vector for invalid extracts
    vector<int> extracted;
    bool empty = false;

    // Loop til found
    while (!empty) {
        // Push back extracted element to extracted
        extracted.push_back(this->extract());

        // If valid found
        if (extracted[extracted.size() - 1] == n) {
            // Reinsert elements in extracted, found
            for (int i = 0; i < extracted.size() - 1; i++) {
                this->insert(extracted[i]);
            }

            // Return found element
            return extracted[extracted.size() - 1];

        // Extracted all, not found
        } else if (this->queue.size() == 0) {
            empty = true;
        }
    }

    // Reinsert elements in extracted, not found
    for (int i = 0; i < extracted.size(); i++) {
        this->insert(extracted[i]);
    }

    // Return -1 if not found
    return -1;
}
