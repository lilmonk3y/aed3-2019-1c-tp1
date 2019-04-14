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
#include "../scr/dynamic_programming/DynamicProgrammingAlgorithm.h"

struct KnapbackTest : testing::Test{
    Knapsack *knapsack;

    KnapbackTest(){
        //knapsack = new KnapsackDesitionTree(new BruteForce());
        //knapsack = new KnapsackDesitionTree(new Backtracking());
        //knapsack = new MeetInTheMiddle();// FALLA EN 3 test
        knapsack = new DynamicProgrammingAlgorithm();
    }

    ~KnapbackTest(){
       delete knapsack;
    }
};

TEST_F(KnapbackTest, whenHaveOnlyOneRequest_mustReturnItsBenefit){
    double capacity = 10;
    std::vector<Request> requests;
    double cost = 5;
    double benefit = 15;
    requests.push_back(Request(cost, benefit));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(benefit, actualBenefit);
}

TEST_F(KnapbackTest, whenCostIsBiggerThanCapacity_mustNotSaveSolution){
    double capacity = 10;
    std::vector<Request> requests;
    double cost = 50;
    double benefit = 15;
    requests.push_back(Request(cost, benefit));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(-1, actualBenefit);
}

TEST_F(KnapbackTest, whenHaveMultipleRequest_mustGiveCorrectBenefit){
    double capacity = 10;
    std::vector<Request> requests;
    requests.push_back(Request(6,12));
    requests.push_back(Request(4,15));
    requests.push_back(Request(3,13));
    requests.push_back(Request(7,20));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(33, actualBenefit);
}

TEST_F(KnapbackTest, whenDoesNotExistSolution_mustReturnZero){
    double capacity = 2;
    std::vector<Request> requests;
    requests.push_back(Request(6,12));
    requests.push_back(Request(4,15));
    requests.push_back(Request(3,13));
    requests.push_back(Request(7,20));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(-1, actualBenefit);
}

TEST_F(KnapbackTest, testingScenario_01){
    double capacity = 25;
    std::vector<Request> requests;
    requests.push_back(Request(10,5));
    requests.push_back(Request(15,4));
    requests.push_back(Request(5,13));
    requests.push_back(Request(10,8));
    requests.push_back(Request(5,8));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(29, actualBenefit);
}

TEST_F(KnapbackTest, testWithoutRequest) {
    double capacity = 25;
    std::vector<Request> requests;

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(-1, actualBenefit);
}

TEST_F(KnapbackTest, testCapacityZero) {
    double capacity = 0;
    std::vector<Request> requests;
    requests.push_back(Request(10,5));
    requests.push_back(Request(15,4));
    requests.push_back(Request(5,13));
    requests.push_back(Request(10,8));
    requests.push_back(Request(5,8));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(-1, actualBenefit);
}

TEST_F(KnapbackTest, testBasicRequest) {

    double capacity = 9;
    std::vector<Request> requests;

    requests.push_back(Request(2,5));
    requests.push_back(Request(5,7));
    requests.push_back(Request(7,2));
    requests.push_back(Request(1,4));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(16, actualBenefit);
}

TEST_F(KnapbackTest, testSameValuesBenefitAndCost_1) {

    double capacity = 1;
    std::vector<Request> requests;

    requests.push_back(Request(1,1));
    requests.push_back(Request(2,2));
    requests.push_back(Request(3,3));
    requests.push_back(Request(4,4));
    requests.push_back(Request(5,5));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(1, actualBenefit);
}

TEST_F(KnapbackTest, testSameValuesBenefitAndCost_2) {

    double capacity = 2;
    std::vector<Request> requests;

    requests.push_back(Request(1,1));
    requests.push_back(Request(2,2));
    requests.push_back(Request(3,3));
    requests.push_back(Request(4,4));
    requests.push_back(Request(5,5));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(2, actualBenefit);
}

TEST_F(KnapbackTest, testSameValuesBenefitAndCost_3) {

    double capacity = 3;
    std::vector<Request> requests;

    requests.push_back(Request(1,1));
    requests.push_back(Request(2,2));
    requests.push_back(Request(3,3));
    requests.push_back(Request(4,4));
    requests.push_back(Request(5,5));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(3, actualBenefit);
}

TEST_F(KnapbackTest, testSameValuesBenefitAndCost_4) {

    double capacity = 4;
    std::vector<Request> requests;

    requests.push_back(Request(1,1));
    requests.push_back(Request(2,2));
    requests.push_back(Request(3,3));
    requests.push_back(Request(4,4));
    requests.push_back(Request(5,5));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(4, actualBenefit);
}

TEST_F(KnapbackTest, testSameValuesBenefitAndCost_5) {

    double capacity = 5;
    std::vector<Request> requests;

    requests.push_back(Request(1,1));
    requests.push_back(Request(2,2));
    requests.push_back(Request(3,3));
    requests.push_back(Request(4,4));
    requests.push_back(Request(5,5));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(5, actualBenefit);
}

TEST_F(KnapbackTest, testSameValuesBenefitAndCost_all_request_solution_15) {

    double capacity = 15;
    std::vector<Request> requests;

    requests.push_back(Request(1,1));
    requests.push_back(Request(2,2));
    requests.push_back(Request(3,3));
    requests.push_back(Request(4,4));
    requests.push_back(Request(5,5));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(15, actualBenefit);
}

TEST_F(KnapbackTest, testSameValuesBenefitAndCost_all_request_solution_anything_solution_is_equal_capacity) {

    double capacity = 9;
    std::vector<Request> requests;

    requests.push_back(Request(1,1));
    requests.push_back(Request(2,2));
    requests.push_back(Request(3,3));
    requests.push_back(Request(4,4));
    requests.push_back(Request(5,5));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(capacity, actualBenefit);
}

TEST_F(KnapbackTest, several_solutions) {
    std::vector<Request> requests;
    requests.push_back(Request(10,1)); // lower benefit and highest cost
    requests.push_back(Request(5,5)); // same, middle values
    requests.push_back(Request(1,10)); // highest benefit and lower cost

    double capacity = 0;
    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(-1, actualBenefit);

    capacity = 1;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(10, actualBenefit);

    capacity = 5;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(10, actualBenefit);

    capacity = 6;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(15, actualBenefit);

    capacity = 11;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(15, actualBenefit);

    capacity = 15;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(15, actualBenefit);

    capacity = 16;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(16, actualBenefit);

    capacity = 17;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(16, actualBenefit);

    capacity = 1000;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(16, actualBenefit);

}


TEST_F(KnapbackTest, test_same_benefint) {
    std::vector<Request> requests;
    requests.push_back(Request(1,3));
    requests.push_back(Request(2,3));
    requests.push_back(Request(3,3));

    double capacity = 1;
    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(3, actualBenefit);

    capacity = 2;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(3, actualBenefit);

    capacity = 3;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(6, actualBenefit);

    capacity = 4;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(6, actualBenefit);

    capacity = 5;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(6, actualBenefit);

    capacity = 6;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(9, actualBenefit);

    capacity = 7;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(9, actualBenefit);

}


TEST_F(KnapbackTest, test_same_cost) {
    std::vector<Request> requests;
    requests.push_back(Request(1,1));
    requests.push_back(Request(1,2));
    requests.push_back(Request(1,3));

    double capacity = 1;
    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(3, actualBenefit);

    capacity = 2;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(5, actualBenefit);

    capacity = 3;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(6, actualBenefit);

    capacity = 4;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(6, actualBenefit);

    capacity = 5;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(6, actualBenefit);
}

TEST_F(KnapbackTest, test_all_combinations_were_solutions) {
    std::vector<Request> requests;
    requests.push_back(Request(2,5));
    requests.push_back(Request(3,4));
    requests.push_back(Request(6,100));

    double capacity = 0;
    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(-1, actualBenefit);

    capacity = 1;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(-1, actualBenefit);

    capacity = 2;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(5, actualBenefit);

    capacity = 3;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(5, actualBenefit);

    capacity = 4;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(5, actualBenefit);

    capacity = 5;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(9, actualBenefit);

    capacity = 6;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(100, actualBenefit);

    capacity = 7;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(100, actualBenefit);

    capacity = 8;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(105, actualBenefit);

    capacity = 9;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(105, actualBenefit);

    capacity = 10;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(105, actualBenefit);

    capacity = 11;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(109, actualBenefit);

    capacity = 12;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(109, actualBenefit);

}


TEST_F(KnapbackTest, test_middle_is_best_solution) {

    double capacity = 4;
    std::vector<Request> requests;

    requests.push_back(Request(4,100));
    requests.push_back(Request(1,100));
    requests.push_back(Request(5,3));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);

    ASSERT_EQ(100, actualBenefit);
}

TEST_F(KnapbackTest, test_first_and_then_last_is_best_solution) {

    double capacity = 4;
    std::vector<Request> requests;

    requests.push_back(Request(1,100));
    requests.push_back(Request(4,99));
    requests.push_back(Request(1,98));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(198, actualBenefit);

    capacity = 2;
    actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(198, actualBenefit);
}

TEST_F(KnapbackTest, test_last_is_best_solution) {

    double capacity = 3;
    std::vector<Request> requests;

    requests.push_back(Request(3,100));
    requests.push_back(Request(4,99));
    requests.push_back(Request(1,200));

    double actualBenefit = knapsack->maximumBenefit(capacity,&requests);
    ASSERT_EQ(200, actualBenefit);
}