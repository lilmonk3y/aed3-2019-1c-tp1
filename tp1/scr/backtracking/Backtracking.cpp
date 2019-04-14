//
// Created by Christian nahuel Rivera on 25/3/19.
//

#include "Backtracking.h"

#define SELECTED_BRANCH 1
#define NO_SELECTED_BRANCH 0

bool
Backtracking::strategyOptimization(int requestsIndex, std::vector<int> *electionTree, std::vector<Request> *requests,
                                   double capacity, double actualMaximum) {
    return factabilityCut(requestsIndex, electionTree, requests, capacity) &&
            optimalityCut(requestsIndex, electionTree, requests, actualMaximum);
}

bool Backtracking::optimalityCut(int requestsIndex, std::vector<int> *electionTree,
                                 std::vector<Request> *requests, double actualMaximum) {
    return sumSelectedRequestsBenefits(requestsIndex, electionTree, requests) +
           sumNextRequestsBenefits(requestsIndex, requests) >= actualMaximum;
}

bool Backtracking::factabilityCut(int requestsIndex, std::vector<int> *electionTree,
                                  std::vector<Request> *requests, double capacity) {
    return sumSelectedRequestsCosts(requestsIndex, electionTree, requests) <= capacity;
}

double Backtracking::sumSelectedRequestsCosts(int index, std::vector<int> *electionTree, std::vector <Request> *requests) {
    double summatory = 0;
    for(int iterator = 0; iterator < index; iterator++){
        if(electionTree->at(iterator) == SELECTED_BRANCH){
            summatory += requests->at(iterator).cost;
        }
    }
    return summatory;
}

double Backtracking::sumSelectedRequestsBenefits(int requestsIndex, std::vector<int> *electionTree,
                                              std::vector<Request> *requests) {
    double summatory = 0;
    for(int iterator = 0; iterator < requestsIndex; iterator++){
        if(electionTree->at(iterator) == SELECTED_BRANCH){
            summatory += requests->at(iterator).benefit;
        }
    }
    return summatory;
}

double Backtracking::sumNextRequestsBenefits(int requestsIndex, std::vector<Request> *requests) {
    double summatory = 0;
    for(int iterator = requestsIndex; iterator < requests->size(); iterator++){
        summatory += requests->at(iterator).benefit;
    }
    return summatory;
}
