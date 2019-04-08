//
// Created by Christian nahuel Rivera on 23/3/19.
//

#include <vector>
#include "KnapsackDesitionTree.h"
#include "../Request.h"
#include "../Solution.h"

#define SELECTED_BRANCH 1
#define NO_SELECTED_BRANCH 0

KnapsackDesitionTree::KnapsackDesitionTree(DesitionTreeStrategy *pBacktracking) {
    this->strategy = pBacktracking;
}

int KnapsackDesitionTree::maximumBenefit(int capacity, std::__1::vector <Request> *requests) {
    this->requests = requests;
    this->capacity = capacity;
    this->partialMaximum = 0;
    this->electionTree = new std::vector<int>(requests->size());
    this->solutions = new std::set<Solution>();

    this->solveKnapsack(0);
    return this->partialMaximum;
}

void KnapsackDesitionTree::solveKnapsack(int requestsIndex) {
    if(requestsIndex == this->requests->size()){
        this->solutions->insert(Solution(this->sumatoryOfActualSolution(),this->sumSelectedRequestsBenefits()));

        if(this->isValidActualSolution() && isABetterSolution()){
            this->partialMaximum = this->sumSelectedRequestsBenefits();
        }
    }else{
        if(this->strategyOptimization(requestsIndex)){

            this->electionTree->at(requestsIndex) = SELECTED_BRANCH;
            this->solveKnapsack(requestsIndex + 1);

            this->electionTree->at(requestsIndex) = NO_SELECTED_BRANCH;
            this->solveKnapsack(requestsIndex + 1);
        }
    }
}

bool KnapsackDesitionTree::isABetterSolution() { return sumSelectedRequestsBenefits() > partialMaximum; }

bool KnapsackDesitionTree::isValidActualSolution() {
    return this->sumatoryOfActualSolution() <= this->capacity;
}

int KnapsackDesitionTree::sumatoryOfActualSolution() {
    int summatory = 0;
    for(int iterator = 0; iterator < this->electionTree->size(); iterator++){
        if(this->electionTree->at(iterator) == SELECTED_BRANCH){
            summatory += this->requests->at(iterator).cost;
        }
    }
    return summatory;
}

int KnapsackDesitionTree::sumSelectedRequestsBenefits() {
    int summatory = 0;
    for(int iterator = 0; iterator < this->electionTree->size(); iterator++){
        if(this->electionTree->at(iterator) == SELECTED_BRANCH){
            summatory += this->requests->at(iterator).benefit;
        }
    }
    return summatory;
}

bool KnapsackDesitionTree::strategyOptimization(int requestsIndex) {
    return this->strategy->strategyOptimization(requestsIndex, this->electionTree, this->requests, this->capacity, this->partialMaximum);
}

std::set<Solution>* KnapsackDesitionTree::getSolutions() {
    return this->solutions;
}

