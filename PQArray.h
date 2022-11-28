//
// Created by Nicolas Macias on 11/21/22.
//
#pragma once
<<<<<<< HEAD
=======

#ifndef PQARRAY_PQARRAY_H
#define PQARRAY_PQARRAY_H
>>>>>>> f17f5ceb4e709cb9a7707dac8accf14e18727a4a

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