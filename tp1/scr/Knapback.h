//
// Created by Christian nahuel Rivera on 4/4/19.
//

#ifndef TP1_MOCHILA_KNAPBACK_H
#define TP1_MOCHILA_KNAPBACK_H

#include <vector>
#include "Request.h"

class Knapback {
public:
    virtual int maximumBenefit(int capacity, std::vector <Request> *requests) = 0;
};


#endif //TP1_MOCHILA_KNAPBACK_H
