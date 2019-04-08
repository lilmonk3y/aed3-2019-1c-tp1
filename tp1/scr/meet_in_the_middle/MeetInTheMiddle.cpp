//
// Created by Christian nahuel Rivera on 4/4/19.
//

#include "MeetInTheMiddle.h"
#include "../brute_force/BruteForce.h"
#include "../brute_force/KnapsackDesitionTree.h"
#include "../Solution.h"
#include <algorithm>

int MeetInTheMiddle::maximumBenefit(int capacity, std::vector <Request> *requests) {
    KnapsackDesitionTree *bruteForce = new KnapsackDesitionTree(new BruteForce());
    std::vector<Request>::iterator last = requests->begin() + (requests->size()/2);

    std::vector<Request> firstHalf(requests->begin(),last);
    std::vector<Request> secondHalf(last++,requests->end());

    bruteForce->maximumBenefit(capacity, &firstHalf);
    std::set<Solution> *firstSolutionSet =  bruteForce->getSolutions();
    std::vector<Solution> firstHalfSolutions(firstSolutionSet->begin(),firstSolutionSet->end());

    bruteForce->maximumBenefit(capacity, &secondHalf);
    std::set<Solution> *secondSolutionSet =  bruteForce->getSolutions();
    std::vector<Solution> secondHalfSolutions(secondSolutionSet->begin(),secondSolutionSet->end());

    return mergeSolutions(&firstHalfSolutions,&secondHalfSolutions, capacity);
}

int MeetInTheMiddle::mergeSolutions(std::vector<Solution> *firstHalfSolutions, std::vector<Solution> *secondHalfSolutions,
                                int capacity) {
    std::sort(firstHalfSolutions->begin(),firstHalfSolutions->end(), solutionCompare);
    std::sort(secondHalfSolutions->begin(),secondHalfSolutions->end(), solutionCompare);

    bool search = true;
    unsigned long firstHalfIndex = 0;
    unsigned long secondHalfIndex = secondHalfSolutions->size()-1;
    int bestBenefit = -1;
    while(search){
        if(firstHalfIndex == firstHalfSolutions->size() || secondHalfIndex == -1){
            search = false;
        }else if(firstHalfSolutions->at(firstHalfIndex).cost + secondHalfSolutions->at(secondHalfIndex).cost > capacity){
            secondHalfIndex--;
        }else if(firstHalfSolutions->at(firstHalfIndex).benefit + secondHalfSolutions->at(secondHalfIndex).benefit > bestBenefit){
            bestBenefit = firstHalfSolutions->at(firstHalfIndex).benefit + secondHalfSolutions->at(secondHalfIndex).benefit;
            firstHalfIndex++;
        }else{
            firstHalfIndex++;
        }
    }

    return bestBenefit;
}
