#include "Knapsack.h"

Knapsack::Knapsack(int capacity) {
    this->setCapacity(capacity);
}

int Knapsack::getCapacity() {
    return this->capacity;
}

void Knapsack::setCapacity(int capacity) {
    this->capacity = capacity;
}