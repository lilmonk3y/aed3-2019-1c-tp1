#include "DynamicProgrammingAlgorithm.h"
#include <algorithm>

// inicializa con ceros
std::vector<std::vector<int> > DynamicProgrammingAlgorithm::inicializarMatriz(int filas,int columnas) {	 // cuesta O(filas.columnas).
    std::vector<std::vector<int> > matrix;
    for(int i = 0; i<filas; i++) {
        std::vector<int> myvector; // inicializo una fila
        for(int j = 0; j<columnas; j++) {
            myvector.push_back(0); // seteo el valor '0' en cada posicion [i][j].
        }
        matrix.push_back(myvector);// vector columnas en vector filas (genera vector de vectores).
    }
    return matrix;
}

int DynamicProgrammingAlgorithm::maximo(int a, int b) {
    return std::max(a,b);
}

bool DynamicProgrammingAlgorithm::ningunRequestPuedeEntrar(std::vector<Request>* requests,int maxCapacity ) {
    for(int i = (*requests).size()-1; i >= 0; i = i-1) {
        if ((*requests)[i].cost <= maxCapacity  ) {
            return false;
        }
    }
    return true;
}


int DynamicProgrammingAlgorithm::maximumBenefit(int capacity, std::vector<Request>* requests) {
    if(requests->size()==0){
        return 0; // o -1??
    }
    std::vector<std::vector<int> >  matrix = inicializarMatriz(requests->size()+1,capacity+1);
    // se comienza en la posicion [1][1], ya que la 1er fila y la 1er columna tienen ceros
    int cantFilas = matrix.size();
    int cantCols = matrix[0].size();
    for(int i = 1; i<cantFilas; i++) { // i es el indice de los pedidos
        int volumenPedidoActual = (*requests)[i-1].cost;
        for(int j = 1; j<cantCols; j++) { // j es la capacidad parcial

            int maxBeneficioSinIncluirPedidoActual = maximo(matrix[i-1][j],matrix[i][j-1]);

            if(j-volumenPedidoActual>=0) {
                int beneficioPedidoActual = (*requests)[i-1].benefit;
                int maxBeneficioIncluyendoPedidoActual = beneficioPedidoActual + matrix[i-1][j-volumenPedidoActual];
                matrix[i][j] = maximo(maxBeneficioSinIncluirPedidoActual,maxBeneficioIncluyendoPedidoActual);
            }
            else {
                matrix[i][j] = maxBeneficioSinIncluirPedidoActual;
            }

        }
    }
    if(  matrix[cantFilas-1][cantCols-1]==0) {
        if( ningunRequestPuedeEntrar(requests, capacity) ) {
            return -1; // si no hay solucion, devuelvo -1
        }
    }
    return matrix[cantFilas-1][cantCols-1]; // ultima posicion
}


