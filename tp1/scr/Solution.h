//
// Created by Christian nahuel Rivera on 5/4/19.
//

#ifndef TP1_MOCHILA_SOLUTION_H
#define TP1_MOCHILA_SOLUTION_H


class Solution {
public:
    double cost;
    double benefit;

    Solution(double cost, double benefit) {
        this->cost = cost;
        this->benefit = benefit;
    }

    bool operator ==(const Solution& other) const{
         return this->benefit == other.benefit && this->cost == other.cost;
    }

    bool operator <(const Solution& other) const{
        return this->benefit < other.benefit && this->cost < other.cost;
    }
};

inline bool solutionCompare(Solution first, Solution second){
    bool response;
    if(first.cost == second.cost){
        response = first.benefit < second.benefit;
    }else{
        response = first.cost < second.cost;
    }
    return response;
}


#endif //TP1_MOCHILA_SOLUTION_H
