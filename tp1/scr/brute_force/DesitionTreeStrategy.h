//
// Created by Christian nahuel Rivera on 25/3/19.
//

#ifndef TP1_MOCHILA_DESITIONTREESTRATEGY_H
#define TP1_MOCHILA_DESITIONTREESTRATEGY_H

#include <vector>
#include "../Request.h"

class DesitionTreeStrategy {
public:
    virtual bool
    strategyOptimization(int requestsIndex, std::vector<int> *electionTree, std::vector<Request> *requests,
                         double capacity, double actualMaximum) = 0;
};

#endif //TP1_MOCHILA_DESITIONTREESTRATEGY_H
