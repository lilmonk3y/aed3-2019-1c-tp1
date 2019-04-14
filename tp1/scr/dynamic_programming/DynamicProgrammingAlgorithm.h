#ifndef TP1_MOCHILA_DYNAMICPROGRAMMINGALGORITHM_H
#define TP1_MOCHILA_DYNAMICPROGRAMMINGALGORITHM_H

#include "../Knapsack.h"

class DynamicProgrammingAlgorithm  : public Knapsack {

public:

    double maximumBenefit(double capacity, std::vector <Request> *requests) override ;

//protected: // (is all public for testing)

    std::vector<std::vector<double> > inicializarMatriz(int filas,int columnas);
    double maximo(double a, double b);
    bool ningunRequestPuedeEntrar(std::vector<Request>* requests,double maxCapacity );
};

#endif //TP1_MOCHILA_DYNAMICPROGRAMMINGALGORITHM_H