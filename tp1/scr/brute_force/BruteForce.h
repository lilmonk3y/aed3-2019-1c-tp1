//
// Created by Christian nahuel Rivera on 25/3/19.
//

#ifndef TP1_MOCHILA_BRUTEFORCE_H
#define TP1_MOCHILA_BRUTEFORCE_H

#include "DesitionTreeStrategy.h"

class BruteForce : public DesitionTreeStrategy{
public:
    bool strategyOptimization(int requestsIndex, std::vector<int> *electionTree, std::vector<Request> *requests,
                              double capacity, int actualMaximum) override;
};


#endif //TP1_MOCHILA_BRUTEFORCE_H
