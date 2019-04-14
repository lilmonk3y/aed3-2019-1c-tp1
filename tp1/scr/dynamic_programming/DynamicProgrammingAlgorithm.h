#ifndef TP1_MOCHILA_DYNAMICPROGRAMMINGALGORITHM_H
#define TP1_MOCHILA_DYNAMICPROGRAMMINGALGORITHM_H

#include "../Knapsack.h"

class DynamicProgrammingAlgorithm  : public Knapsack {

public:

    int maximumBenefit(int capacity, std::vector <Request> *requests) override ;

private:

    std::vector<std::vector<int> > inicializarMatriz(int filas,int columnas);
    int maximo(int a, int b);
    bool ningunRequestPuedeEntrar(std::vector<Request>* requests,int maxCapacity );
};

#endif //TP1_MOCHILA_DYNAMICPROGRAMMINGALGORITHM_H