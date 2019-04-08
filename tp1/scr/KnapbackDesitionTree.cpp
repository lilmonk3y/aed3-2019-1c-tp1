//
// Created by Christian nahuel Rivera on 23/3/19.
//

#include <vector>
#include "KnapbackDesitionTree.h"
#include "Request.h"
#include "meet_in_the_middle/Solution.h"

#define SELECTED_BRANCH 1
#define NO_SELECTED_BRANCH 0

KnapbackDesitionTree::KnapbackDesitionTree(DesitionTreeStrategy *pBacktracking) {
    this->strategy = pBacktracking;
}

int KnapbackDesitionTree::maximumBenefit(int capacity, std::__1::vector <Request> *requests) {
    this->requests = requests;
    this->capacity = capacity;
    this->partialMaximum = 0;
    this->electionTree = new std::vector<int>(requests->size());
    this->solutions = new std::set<Solution>();

    this->solveKnapback(0);
    return this->partialMaximum;
}

void KnapbackDesitionTree::solveKnapback(int requestsIndex) {
    if(requestsIndex == this->requests->size()){
        this->solutions->insert(Solution(this->sumatoryOfActualSolution(),this->sumSelectedRequestsBenefits()));
        if(this->isValidActualSolution() && isABetterSolution()){
            this->partialMaximum = this->sumSelectedRequestsBenefits();
        }
    }else{
        if(this->strategyOptimization(requestsIndex)){

            this->electionTree->at(requestsIndex) = SELECTED_BRANCH;
            this->solveKnapback(requestsIndex+1);

            this->electionTree->at(requestsIndex) = NO_SELECTED_BRANCH;
            this->solveKnapback(requestsIndex+1);
        }
    }
}

bool KnapbackDesitionTree::isABetterSolution() { return sumSelectedRequestsBenefits() > partialMaximum; }

bool KnapbackDesitionTree::isValidActualSolution() {
    return this->sumatoryOfActualSolution() <= this->capacity;
}

int KnapbackDesitionTree::sumatoryOfActualSolution() {
    int summatory = 0;
    for(int iterator = 0; iterator < this->electionTree->size(); iterator++){
        if(this->electionTree->at(iterator) == SELECTED_BRANCH){
            summatory += this->requests->at(iterator).cost;
        }
    }
    return summatory;
}

int KnapbackDesitionTree::sumSelectedRequestsBenefits() {
    int summatory = 0;
    for(int iterator = 0; iterator < this->electionTree->size(); iterator++){
        if(this->electionTree->at(iterator) == SELECTED_BRANCH){
            summatory += this->requests->at(iterator).benefit;
        }
    }
    return summatory;
}

bool KnapbackDesitionTree::strategyOptimization(int requestsIndex) {
    return this->strategy->strategyOptimization(requestsIndex, this->electionTree, this->requests, this->capacity, this->partialMaximum);
}

std::set<Solution>* KnapbackDesitionTree::getSolutions() {
    return this->solutions;
}

