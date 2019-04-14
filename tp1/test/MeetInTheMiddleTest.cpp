//
// Created by Christian nahuel Rivera on 6/4/19.
//

#include <gtest/gtest.h>
#include "../scr/Knapsack.h"
#include "../scr/meet_in_the_middle/MeetInTheMiddle.h"
#include "../scr/brute_force/KnapsackDesitionTree.h"
#include "../scr/brute_force/BruteForce.h"

struct MeetTest : testing::Test{
    MeetInTheMiddle *meet;

    MeetTest(){
        meet = new MeetInTheMiddle();
    }

    ~MeetTest(){
        delete meet;
    }
};


TEST_F(MeetTest, iteratorTest1){

    std::vector<Request> requests;
    requests.push_back(Request(10,5));
    requests.push_back(Request(15,4));
    requests.push_back(Request(5,13));
    requests.push_back(Request(10,8));
    requests.push_back(Request(5,8));

    std::vector<Request>::iterator last = requests.begin() + (requests.size()/2);

    std::vector<Request> firstHalf(requests.begin(),last);
    std::vector<Request> secondHalf(last++,requests.end());


    ASSERT_EQ(2, firstHalf.size());
    ASSERT_EQ(3, secondHalf.size());
}

TEST_F(MeetTest, iteratorTest2){

    std::vector<Request> requests;
    requests.push_back(Request(10,5));
    requests.push_back(Request(15,4));
    requests.push_back(Request(5,13));
    requests.push_back(Request(10,8));
    requests.push_back(Request(5,8));
    requests.push_back(Request(5,8));

    std::vector<Request>::iterator last = requests.begin() + (requests.size()/2);

    std::vector<Request> firstHalf(requests.begin(),last);
    std::vector<Request> secondHalf(last++,requests.end());


    ASSERT_EQ(3, firstHalf.size());
    ASSERT_EQ(3, secondHalf.size());
}

TEST_F(MeetTest, sortTest1){
    std::vector<Solution> solutions;
    solutions.push_back(Solution(10,5));
    solutions.push_back(Solution(5,6));
    solutions.push_back(Solution(1,7));

    std::sort(solutions.begin(),solutions.end(), solutionCompare);

    ASSERT_EQ(1, solutions.at(0).cost);
    ASSERT_EQ(5, solutions.at(1).cost);
    ASSERT_EQ(10, solutions.at(2).cost);
}

TEST_F(MeetTest, sortTest2){
    std::vector<Solution> solutions;
    solutions.push_back(Solution(5,5));
    solutions.push_back(Solution(5,7));
    solutions.push_back(Solution(5,6));

    std::sort(solutions.begin(),solutions.end(), solutionCompare);

    ASSERT_EQ(5, solutions.at(0).benefit);
    ASSERT_EQ(6, solutions.at(1).benefit);
    ASSERT_EQ(7, solutions.at(2).benefit);
}

TEST_F(MeetTest, mergeTest1){
    std::vector<Solution> first;
    first.push_back(Solution(10,5));
    first.push_back(Solution(5,6));
    first.push_back(Solution(1,7));

    std::vector<Solution> second;
    second.push_back(Solution(10,5));
    second.push_back(Solution(5,6));
    second.push_back(Solution(1,7));

    double capacity = 2;

    double actualBenefit = meet->mergeSolutions(&first, &second, capacity);

    ASSERT_EQ(14, actualBenefit);
}

TEST_F(MeetTest, mergeTest2){
    std::vector<Solution> first;
    first.push_back(Solution(10,5));
    first.push_back(Solution(5,10));
    first.push_back(Solution(1,7));

    std::vector<Solution> second;
    second.push_back(Solution(10,10));
    second.push_back(Solution(5,6));
    second.push_back(Solution(1,7));

    double capacity = 30;

    double actualBenefit = meet->mergeSolutions(&first, &second, capacity);

    ASSERT_EQ(20, actualBenefit);
}

TEST_F(MeetTest, setToVectorTest){
    std::set<Solution> firstSolutionSet;
    firstSolutionSet.insert(Solution(1,1));
    firstSolutionSet.insert(Solution(2,2));

    std::vector<Solution> firstHalfSolutions(firstSolutionSet.begin(),firstSolutionSet.end());

    ASSERT_EQ(2, firstHalfSolutions.size());

    ASSERT_EQ(1, firstHalfSolutions.at(0).benefit);
    ASSERT_EQ(2, firstHalfSolutions.at(1).benefit);
}

TEST_F(MeetTest, whenMakingSolutionsWithBruteForce_mustReturnAllTheTreeLeafs){
    KnapsackDesitionTree *bruteForce = new KnapsackDesitionTree(new BruteForce());

    std::vector<Request> requests;
    requests.push_back(Request(2,3));
    requests.push_back(Request(11,13));
    requests.push_back(Request(23,21));

    bruteForce->maximumBenefit(50,&requests);


    std::set<Solution> *actualSolutions = bruteForce->getSolutions();


    std::set<Solution>::iterator endOfSolutions = actualSolutions->end();

    ASSERT_EQ(8, actualSolutions->size());

    ASSERT_TRUE(endOfSolutions != actualSolutions->find(Solution(2,3)));
    ASSERT_TRUE(endOfSolutions != actualSolutions->find(Solution(0,0)));
    ASSERT_TRUE(endOfSolutions != actualSolutions->find(Solution(13,16)));
    ASSERT_TRUE(endOfSolutions != actualSolutions->find(Solution(11,13)));
    ASSERT_TRUE(endOfSolutions != actualSolutions->find(Solution(36,37)));
    ASSERT_TRUE(endOfSolutions != actualSolutions->find(Solution(34,34)));
    ASSERT_TRUE(endOfSolutions != actualSolutions->find(Solution(25,24)));
    ASSERT_TRUE(endOfSolutions != actualSolutions->find(Solution(23,21)));

}