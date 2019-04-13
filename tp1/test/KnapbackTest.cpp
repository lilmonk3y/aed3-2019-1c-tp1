//
// Created by Christian nahuel Rivera on 23/3/19.
//

#include <gtest/gtest.h>
#include "../scr/brute_force/KnapsackDesitionTree.h"
#include "../scr/Request.h"
#include "../scr/brute_force/BruteForce.h"
#include "../scr/backtracking/Backtracking.h"
#include "../scr/Knapsack.h"
#include "../scr/meet_in_the_middle/MeetInTheMiddle.h"

struct KnapbackTest : testing::Test{
    Knapsack *knapsack;

    KnapbackTest(){
        //knapsack = new KnapsackDesitionTree(new BruteForce());
        //knapsack = new KnapsackDesitionTree(new Backtracking());
        knapsack = new MeetInTheMiddle();
        //knapsack = new ProgramaciónDinamica();
    }

    ~KnapbackTest(){
        delete knapsack;
    }
};

TEST_F(KnapbackTest, whenHaveOnlyOneRequest_mustReturnItsBenefit){
    int capacity = 10;
    std::vector<Request> requests;
    int cost = 5;
    int benefit = 15;
    requests.push_back(Request(cost, benefit));

    int actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(benefit, actualBenefit);
}

TEST_F(KnapbackTest, whenCostIsBiggerThanCapacity_mustNotSaveSolution){
    int capacity = 10;
    std::vector<Request> requests;
    int cost = 50;
    int benefit = 15;
    requests.push_back(Request(cost, benefit));

    int actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(-1, actualBenefit);
}

TEST_F(KnapbackTest, whenHaveMultipleRequest_mustGiveCorrectBenefit){
    int capacity = 10;
    std::vector<Request> requests;
    requests.push_back(Request(6,12));
    requests.push_back(Request(4,15));
    requests.push_back(Request(3,13));
    requests.push_back(Request(7,20));

    int actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(33, actualBenefit);
}

TEST_F(KnapbackTest, whenDoesNotExistSolution_mustReturnZero){
    int capacity = 2;
    std::vector<Request> requests;
    requests.push_back(Request(6,12));
    requests.push_back(Request(4,15));
    requests.push_back(Request(3,13));
    requests.push_back(Request(7,20));

    int actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(-1, actualBenefit);
}

TEST_F(KnapbackTest, testingScenario_01){
    int capacity = 25;
    std::vector<Request> requests;
    requests.push_back(Request(10,5));
    requests.push_back(Request(15,4));
    requests.push_back(Request(5,13));
    requests.push_back(Request(10,8));
    requests.push_back(Request(5,8));

    int actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(29, actualBenefit);
}