//
// Created by Christian nahuel Rivera on 23/3/19.
//

#include <vector>
#include "Knapback.h"
#include "Request.h"

#define SELECTED_BRANCH 1
#define NO_SELECTED_BRANCH 0

int Knapback::maximumBenefit(int capacity, std::__1::vector <Request> *requests) {
    this->requests = requests;
    this->capacity = capacity;
    this->partialMaximum = 0;
    this->electionTree.resize(requests->size());

    this->solveKnapback(0);
    return this->partialMaximum;
}

void Knapback::solveKnapback(int requestsIndex) {
    if(requestsIndex == this->requests->size()){
        if(this->isValidActualSolution() && isABetterSolution()){
            this->partialMaximum = this->sumSelectedRequestsBenefits();
        }
    }else{
        this->electionTree.at(requestsIndex) = SELECTED_BRANCH;
        this->solveKnapback(requestsIndex+1);

        this->electionTree.at(requestsIndex) = NO_SELECTED_BRANCH;
        this->solveKnapback(requestsIndex+1);
    }
}

bool Knapback::isABetterSolution() { return sumSelectedRequestsBenefits() > partialMaximum; }

bool Knapback::isValidActualSolution() {
    return this->sumatoryOfActualSolution() <= this->capacity;
}

int Knapback::sumatoryOfActualSolution() {
    int summatory = 0;
    for(int iterator = 0; iterator < this->electionTree.size(); iterator++){
        if(this->electionTree.at(iterator) == SELECTED_BRANCH){
            summatory += this->requests->at(iterator).cost;
        }
    }
    return summatory;
}

int Knapback::sumSelectedRequestsBenefits() {
    int summatory = 0;
    for(int iterator = 0; iterator < this->electionTree.size(); iterator++){
        if(this->electionTree.at(iterator) == SELECTED_BRANCH){
            summatory += this->requests->at(iterator).benefit;
        }
    }
    return summatory;
}
