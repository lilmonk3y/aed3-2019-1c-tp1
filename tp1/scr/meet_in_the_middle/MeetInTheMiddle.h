//
// Created by Christian nahuel Rivera on 4/4/19.
//

#ifndef TP1_MOCHILA_KNAPBACKMEETINTHEMIDDLE_H
#define TP1_MOCHILA_KNAPBACKMEETINTHEMIDDLE_H


#include "../Knapsack.h"
#include "../Solution.h"

class MeetInTheMiddle : public Knapsack{
public:
    double maximumBenefit(double capacity, std::vector<Request> *requests) override ;

    double mergeSolutions(std::vector<Solution> *firstHalfSolutions, std::vector<Solution> *secondHalfSolutions,
                       double capacity);
};


#endif //TP1_MOCHILA_KNAPBACKMEETINTHEMIDDLE_H
