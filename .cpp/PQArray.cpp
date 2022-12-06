//
// Created by Nicolas Macias on 11/21/22.
//

#include "../.h/PQArray.h"

PQArray::PQArray() {}

void PQArray::insert(Recipient recipient) {
    // Push back new element
    this->queue.push_back(recipient);
    int child = this->queue.size() - 1;
    int parent = (child - 1) / 2;

    // Swap up until correct position is found
    while (parent >= 0 && this->queue[parent].priority < this->queue[child].priority) {
        Recipient temp = this->queue[parent];
        this->queue[parent] = this->queue[child];
        this->queue[child] = temp;
        child = parent;
        parent = (child - 1) / 2;
    }
}

Recipient PQArray::extract() {
    // Max is at the beginning of queue
    Recipient max = this->queue[0];

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
        if (this->queue[leftPos].priority >= this->queue[rightPos].priority) {
            maxPos = leftPos;
        } else {
            maxPos = rightPos;
        }
    }

    // Swap at pos and maxPos
    Recipient temp = this->queue[pos];
    this->queue[pos] = this->queue[maxPos];
    this->queue[maxPos] = temp;

    // Heapify @ maxPos
    this->heapifyDown(maxPos);
}

Recipient PQArray::extractValid(Donor donor) {
    // Base case
    if (this->queue.size() == 0) {
        return Recipient("INVALID", -1, "INVALID", "INVALID", -1);
    }

    // Create vector for invalid extracts
    vector<Recipient> extracted;
    bool empty = false;

    // Loop til found
    while (!empty) {
        // Push back extracted element to extracted
        extracted.push_back(this->extract());

        // If valid found
        if (this->isValid(donor, extracted[extracted.size() - 1])) {
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

    // Return dummy invalid recipient if not found
    return Recipient("INVALID", -1, "INVALID", "INVALID", -1);
}

bool PQArray::isValid(Donor &donor, Recipient &recipient) {
    bool age = true;
    if ((donor.age >= 1 && donor.age <= 12) && (recipient.age >= 13 && recipient.age <= 100)) {
        age = false;
    } else if ((donor.age >= 13 && donor.age <= 100) && (recipient.age >= 1 && recipient.age <= 12)) {
        age = false;
    }

    bool region;
    if (donor.region == recipient.region) {
        region = true;
    } else {
        region = false;
    }

    if (age && region) {
        return true;
    } else {
        return false;
    }
}