//
// Created by Christian nahuel Rivera on 23/3/19.
//

#ifndef TP1_MOCHILA_KNAPBACK_DESITION_TREE_H
#define TP1_MOCHILA_KNAPBACK_DESITION_TREE_H


#include <set>
#include "../Request.h"
#include "DesitionTreeStrategy.h"
#include "../Knapsack.h"
#include "../Solution.h"

class KnapsackDesitionTree : public Knapsack{
public:
    int maximumBenefit(double capacity, std::vector<Request> *requests) override;

    KnapsackDesitionTree(DesitionTreeStrategy *pBacktracking);

    std::set<Solution> *getSolutions();

private:
    std::vector<Request> *requests;
    double capacity;
    int partialMaximum;
    std::vector<int> *electionTree;
    DesitionTreeStrategy *strategy;
    std::set<Solution> *solutions;

    void solveKnapsack(int requestsIndex);

    bool isValidActualSolution();

    int sumatoryOfActualSolution();

    int sumSelectedRequestsBenefits();

    bool isABetterSolution();

    bool strategyOptimization(int requestsIndex);

};


#endif //TP1_MOCHILA_KNAPBACK_DESITION_TREE_H
