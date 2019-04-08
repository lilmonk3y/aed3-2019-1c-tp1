//
// Created by Christian nahuel Rivera on 23/3/19.
//

#ifndef TP1_MOCHILA_KNAPBACK_DESITION_TREE_H
#define TP1_MOCHILA_KNAPBACK_DESITION_TREE_H


#include <set>
#include "Request.h"
#include "DesitionTreeStrategy.h"
#include "Knapback.h"
#include "meet_in_the_middle/Solution.h"

class KnapbackDesitionTree : public Knapback{
public:
    int maximumBenefit(int capacity, std::vector <Request> *requests) override;

    KnapbackDesitionTree(DesitionTreeStrategy *pBacktracking);

    std::set<Solution> *getSolutions();

private:
    std::vector<Request> *requests;
    int capacity;
    int partialMaximum;
    std::vector<int> *electionTree;
    DesitionTreeStrategy *strategy;
    std::set<Solution> *solutions;

    void solveKnapback(int requestsIndex);

    bool isValidActualSolution();

    int sumatoryOfActualSolution();

    int sumSelectedRequestsBenefits();

    bool isABetterSolution();

    bool strategyOptimization(int requestsIndex);

};


#endif //TP1_MOCHILA_KNAPBACK_DESITION_TREE_H
