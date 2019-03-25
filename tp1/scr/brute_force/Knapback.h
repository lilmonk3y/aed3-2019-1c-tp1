//
// Created by Christian nahuel Rivera on 23/3/19.
//

#ifndef TP1_MOCHILA_KNAPBACK_H
#define TP1_MOCHILA_KNAPBACK_H


#include "Request.h"

class Knapback {
public:

    int maximumBenefit(int capacity, std::vector <Request> *requests);
private:
    std::vector<Request> *requests;
    int capacity;
    int partialMaximum;
    std::vector<int> electionTree;

    void solveKnapback(int requestsIndex);

    bool isValidActualSolution();

    int sumatoryOfActualSolution();

    int sumSelectedRequestsBenefits();

    bool isABetterSolution();
};


#endif //TP1_MOCHILA_KNAPBACK_H
