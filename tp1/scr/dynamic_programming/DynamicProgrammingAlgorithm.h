#ifndef TP1_MOCHILA_DYNAMICPROGRAMMINGALGORITHM_H
#define TP1_MOCHILA_DYNAMICPROGRAMMINGALGORITHM_H


class DynamicProgrammingAlgorithm  {

public:

    bool
    strategyOptimization(int requestsIndex, std::vector<int> *electionTree, std::vector<Request> *requests,
                         int capacity, int actualMaximum) override;

private:


}

#endif //TP1_MOCHILA_DYNAMICPROGRAMMINGALGORITHM_H
