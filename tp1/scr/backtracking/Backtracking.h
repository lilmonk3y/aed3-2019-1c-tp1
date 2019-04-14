//
// Created by Christian nahuel Rivera on 25/3/19.
//

#ifndef TP1_MOCHILA_BACKTRACKING_H
#define TP1_MOCHILA_BACKTRACKING_H


#include "../brute_force/DesitionTreeStrategy.h"

class Backtracking : public DesitionTreeStrategy {
public:
    bool
    strategyOptimization(int requestsIndex, std::vector<int> *electionTree, std::vector<Request> *requests,
                         double capacity, double actualMaximum) override;

    double sumSelectedRequestsCosts(int index, std::vector<int> *electionTree, std::vector<Request> *requests);

    bool factabilityCut(int requestsIndex, std::vector<int> *electionTree, std::vector<Request> *requests,
                        double capacity);

    double sumSelectedRequestsBenefits(int requestsIndex, std::vector<int> *electionTree, std::vector<Request> *requests);

    double sumNextRequestsBenefits(int requestsIndex, std::vector<Request> *requests);

    bool optimalityCut(int requestsIndex, std::vector<int> *electionTree, std::vector<Request> *requests,
                       double actualMaximum);
};


#endif //TP1_MOCHILA_BACKTRACKING_H
