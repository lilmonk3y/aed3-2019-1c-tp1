//
// Created by Christian nahuel Rivera on 23/3/19.
//

#ifndef TP1_MOCHILA_KNAPBACK_H
#define TP1_MOCHILA_KNAPBACK_H


#include "Request.h"
#include "DesitionTreeStrategy.h"

class Knapback {
public:
    int maximumBenefit(int capacity, std::vector <Request> *requests);

    void setDecitionTreeStrategy(DesitionTreeStrategy *pForce);

    void setRequests(std::vector<Request> *requests);

    void setCapacity(int capacity);

    void setElectionTree(std::vector<int> *electionTree);

    std::vector<Request> * getRequests();

    std::vector<int> *getElectionTree();

    int getCapacity();

private:
    std::vector<Request> *requests;
    int capacity;
    int partialMaximum;
    std::vector<int> *electionTree;
    DesitionTreeStrategy *strategy;

    void solveKnapback(int requestsIndex);

    bool isValidActualSolution();

    int sumatoryOfActualSolution();

    int sumSelectedRequestsBenefits();

    bool isABetterSolution();

    bool strategyOptimization(int requestsIndex);
};


#endif //TP1_MOCHILA_KNAPBACK_H
