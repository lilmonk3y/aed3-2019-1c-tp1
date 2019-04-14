//
// Created by Christian nahuel Rivera on 26/3/19.
//

#include <gtest/gtest.h>
#include "../scr/backtracking/Backtracking.h"

#define SELECTED_BRANCH 1
#define NO_SELECTED_BRANCH 0

struct BacktrackingTest : testing::Test{
    Backtracking *backtracking;
    std::vector<Request> requests1;

    BacktrackingTest(){
        backtracking = new Backtracking();
        requests1.push_back(Request(6,12));
        requests1.push_back(Request(4,15));
        requests1.push_back(Request(3,13));
        requests1.push_back(Request(7,20));
    }

    ~BacktrackingTest(){
        delete backtracking;
    }
};

TEST_F(BacktrackingTest, whenABackpackIsValidToContinue_mustReturnTrue){
    double capacity = 15;
    std::vector<int> electionTree{SELECTED_BRANCH,SELECTED_BRANCH};
    int requestsIndex = 2;

    bool actualResponce = backtracking->strategyOptimization(requestsIndex, &electionTree, &requests1, capacity, 0);

    ASSERT_TRUE(actualResponce);
}

TEST_F(BacktrackingTest, whenABackpackHasAHigherCostThanItsCapacity_mustReturnFalse){
    double capacity = 9;
    std::vector<int> electionTree{SELECTED_BRANCH,SELECTED_BRANCH};
    int requestsIndex = 2;

    bool actualResponce = backtracking->strategyOptimization(requestsIndex, &electionTree, &requests1, capacity, 0);

    ASSERT_FALSE(actualResponce);
}

TEST_F(BacktrackingTest, whenAKnapbackMayImproveAPartialMaximum_mustReturnTrue){
    std::vector<int> electionTree{NO_SELECTED_BRANCH,SELECTED_BRANCH};
    int requestsIndex = 2;
    double actualMaximum = 12 + 13 + 20;

    bool actualResponce = backtracking->strategyOptimization(requestsIndex, &electionTree, &requests1, 100, actualMaximum);

    ASSERT_TRUE(actualResponce);
}

TEST_F(BacktrackingTest, whenAKnapbackCantImproveAPartialMaximum_mustReturnFalse){
    std::vector<int> electionTree{SELECTED_BRANCH,NO_SELECTED_BRANCH};
    int requestsIndex = 2;
    double actualMaximum = 15 + 13 + 20;

    bool actualResponce = backtracking->strategyOptimization(requestsIndex, &electionTree, &requests1, 100, actualMaximum);

    ASSERT_FALSE(actualResponce);
}