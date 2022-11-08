#include "Knapsack.h"
#include <iostream>

using namespace std;

int maximumProfit(Knapsack *knapsack, int numOfItem);

int weight[3] = {4, 6, 8};
int profit[3] = {7, 6, 9};

int main() {
    Knapsack *knapsack = new Knapsack(14);
    int maxProfit = maximumProfit(knapsack, 3);
    cout << "The maximum profit is: " << maxProfit << endl;
}


int maximumProfit(Knapsack *knapsack, int numOfItem) {
    int DP[knapsack->getCapacity() + 1];

    for (int i = 0; i < knapsack->getCapacity() + 1; i ++) {
        DP[i] = 0;
    }

    for (int i = 0; i < knapsack->getCapacity() + 1; i ++) {
        for (int j = 0; j < numOfItem; j ++) {
            if (weight[j] <= i) {
                DP[i] = max(DP[i], DP[i - weight[j]] + profit[j]);
            }
        }
    }

    cout << "DP Array: " << endl;

    for (int i = 0; i < knapsack->getCapacity() + 1; i ++) {
        cout << DP[i] << " ";
    }
    cout << endl;
    return DP[knapsack->getCapacity()];
}