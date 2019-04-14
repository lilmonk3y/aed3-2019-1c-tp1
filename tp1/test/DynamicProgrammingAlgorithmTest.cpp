#include <gtest/gtest.h>
#include "../scr/dynamic_programming/DynamicProgrammingAlgorithm.h"

struct DynamicProgrammingAlgorithmTest : testing::Test{
    DynamicProgrammingAlgorithm* dynamicProgrammingAlgorithm; // singleton instance.

    DynamicProgrammingAlgorithmTest(){
        dynamicProgrammingAlgorithm = new DynamicProgrammingAlgorithm();
    }

    ~DynamicProgrammingAlgorithmTest(){
        delete dynamicProgrammingAlgorithm;
    }
};

TEST_F(DynamicProgrammingAlgorithmTest, maximoTest){

    int a = 2;
    int b = 1;
    int result = dynamicProgrammingAlgorithm->maximo(a,b);
    ASSERT_EQ(2, result);

    a = 2;
    b = 3;
    result = dynamicProgrammingAlgorithm->maximo(a,b);
    ASSERT_EQ(3, result);

    a = 4;
    b = 4;
    result = dynamicProgrammingAlgorithm->maximo(a,b);
    ASSERT_EQ(4, result);
}

TEST_F(DynamicProgrammingAlgorithmTest, iniciarMatriz) {
    std::vector<std::vector<int> > matrix = dynamicProgrammingAlgorithm->inicializarMatriz(10, 6);
    bool result = true;

    int cantFilas = matrix.size();
    int cantCols = matrix[0].size();
    for(int i = 0; i<cantFilas; i++) {
        for(int j = 0; j<cantCols; j++) {
            if(matrix[i][j]!=0) {
                result = false;
            }
        }
    }
    ASSERT_EQ(true, result);
}

TEST_F(DynamicProgrammingAlgorithmTest, iniciarMatrizFalseValorModificado) {
    std::vector<std::vector<int> > matrix = dynamicProgrammingAlgorithm->inicializarMatriz(10, 6);
    matrix[5][4] = 1;

    bool result = true;

    int cantFilas = matrix.size();
    int cantCols = matrix[0].size();
    for(int i = 0; i<cantFilas; i++) {
        for(int j = 0; j<cantCols; j++) {
            if( matrix[i][j] != 0 ) {
                result = false;
            }
        }
    }
    ASSERT_EQ(false, result);
}

TEST_F(DynamicProgrammingAlgorithmTest, requestMayorACapacidad) {

    int capacity = 3;
    std::vector<Request> requests;
    requests.push_back(Request(6,12));
    requests.push_back(Request(4,15));
    requests.push_back(Request(8,13));
    requests.push_back(Request(7,20));

    bool result = dynamicProgrammingAlgorithm->ningunRequestPuedeEntrar(&requests,capacity);
    ASSERT_EQ(true, result);
}

TEST_F(DynamicProgrammingAlgorithmTest, requestMenorACapacidad) {

    int capacity = 8;
    std::vector<Request> requests;
    requests.push_back(Request(6,12));
    requests.push_back(Request(4,15));
    requests.push_back(Request(8,13));
    requests.push_back(Request(7,20));

    bool result = dynamicProgrammingAlgorithm->ningunRequestPuedeEntrar(&requests,capacity);
    ASSERT_EQ(false, result);

    capacity = 4;
    result = dynamicProgrammingAlgorithm->ningunRequestPuedeEntrar(&requests,capacity);
    ASSERT_EQ(false, result);

    capacity = 9;
    result = dynamicProgrammingAlgorithm->ningunRequestPuedeEntrar(&requests,capacity);
    ASSERT_EQ(false, result);
}