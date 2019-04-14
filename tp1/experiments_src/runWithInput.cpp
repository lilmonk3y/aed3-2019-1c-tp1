//
// Created by Christian nahuel Rivera on 04/10/2018.
//

#include <iostream>
#include <array>
#include "../scr/Knapsack.h"
#include "../scr/meet_in_the_middle/MeetInTheMiddle.h"
#include "../scr/brute_force/KnapsackDesitionTree.h"
#include "../scr/brute_force/BruteForce.h"

double callSolution(std::vector<Request> *elements, double objectiveValue) {
    Knapsack* knapsack = new KnapsackDesitionTree(new BruteForce());
    double response = knapsack->maximumBenefit(objectiveValue,elements);
    return response;
}

int main(){

    int sizeOfArray;
    double objectiveValue;
    std::cout << "Pass sets of values and finally 0 0 for expresing end of values." << std::endl;
    std::cin >> sizeOfArray;
    std::cin >> objectiveValue;
    while(sizeOfArray != 0 && objectiveValue != 0){
        std::vector<Request> elements;
        elements.clear();
        double cost;
        double benefit;
        for(int index = 0; index < sizeOfArray; index ++){
            std::cin >> cost;
            std::cin >> benefit;
            elements.push_back(Request(cost,benefit));
        }

        std::cout << callSolution(&elements ,objectiveValue) << std::endl;

        std::cin >> sizeOfArray;
        std::cin >> objectiveValue;
    }

    std::cout << "No more elements expected" << std::endl;
}