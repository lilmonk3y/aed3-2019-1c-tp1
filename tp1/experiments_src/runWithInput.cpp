//
// Created by Christian nahuel Rivera on 04/10/2018.
//

#include <iostream>
#include <array>
#include "../scr/Knapsack.h"
#include "../scr/meet_in_the_middle/MeetInTheMiddle.h"
#include "../scr/brute_force/KnapsackDesitionTree.h"
#include "../scr/brute_force/BruteForce.h"
#include "../scr/backtracking/Backtracking.h"
#include "../scr/dynamic_programming/DynamicProgrammingAlgorithm.h"


int callSolution(std::vector<Request> *elements, int objectiveValue) {
    //Knapsack* knapsack = new KnapsackDesitionTree(new BruteForce());
    Knapsack* knapsack = new KnapsackDesitionTree(new Backtracking());
    //Knapsack* knapsack = new MeetInTheMiddle();
    //Knapsack* knapsack = new DynamicProgrammingAlgorithm();
    int response = knapsack->maximumBenefit(objectiveValue,elements);
    return response;
}

int main(){

    int sizeOfArray;
    int objectiveValue;
    std::cout << "Pass sets of values and finally 0 0 for expresing end of values." << std::endl;
    std::cin >> sizeOfArray;
    std::cin >> objectiveValue;
    while(sizeOfArray != 0 && objectiveValue != 0){
        std::vector<Request> elements;
        elements.clear();
        int cost;
        int benefit;
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