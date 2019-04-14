//
// Created by Christian nahuel Rivera on 05/10/2018.
//
#include <iostream>
#include <cmath>
#include <fstream>
#include "../scr/Knapsack.h"
#include "../scr/brute_force/KnapsackDesitionTree.h"
#include "../scr/brute_force/BruteForce.h"
#include "../scr/backtracking/Backtracking.h"
#include "../scr/meet_in_the_middle/MeetInTheMiddle.h"
double calcularTiempos(Knapsack *knapsack, int cantidadDeIteraciones, double capacity, std::vector<Request> *requests);

std::vector<Request> crearInstanciaConCostoYBeneficioAleatorio(int elementos, double capacidad);

std::vector<Request> crearInstanciaExperimento4(int elementos, double capacidad);

std::vector<Request> crearInstanciaExperimento5(int elementos, double capacidad);

int main(){

    ////////////////////////////////// SET UP /////////////////////////////////////////
    // V = capacidad
    std::cout << "steady_clock" << std::endl;
    std::cout << std::chrono::steady_clock::period::num << std::endl;
    std::cout << std::chrono::steady_clock::period::den << std::endl;
    std::cout << "steady = " << std::boolalpha << std::chrono::steady_clock::is_steady << std::endl << std::endl;


    Knapsack *fuerzaBruta = new KnapsackDesitionTree(new BruteForce());
    Knapsack *backtracking = new KnapsackDesitionTree(new Backtracking());
    Knapsack *meetInTheMiddle = new MeetInTheMiddle();
    //Cuando lo tengamos listo lo instanciamos con PD
    Knapsack *programacionDinamica = new MeetInTheMiddle();

    int limpiarDatos = 100;
    int tamanoMaximoInstancia;
    double capacidad;

    std::vector<Request> originalSet;

    ////////////////////////////////// EXPERIMENTO 1 /////////////////////////////////////////
/*
     * Experimento 1
     * Los cuatro algoritmos compiten entre ellos.
     * La idea es ver el comportamiento de los mismos en igualdad de condiciones sin perjudicar a ninguno en especial.
     * Para ello las instancias se hacen con números aleatorios
*/
    capacidad = 50;
    tamanoMaximoInstancia = 30;
    std::ofstream tiempos1;
    tiempos1.open("experimento_1.csv",std::ios::out);

    tiempos1 << "instancias,n,v,fruerza_bruta,backtracking,meet_in_the_middle,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaConCostoYBeneficioAleatorio(cantidadElementos, capacidad);

        tiempos1 << cantidadElementos << "," << cantidadElementos << "," << capacidad << ",";

        double mediana;
        mediana = calcularTiempos(fuerzaBruta, limpiarDatos, capacidad, &originalSet);
        tiempos1 << mediana << ",";

        mediana = calcularTiempos(backtracking, limpiarDatos, capacidad, &originalSet);
        tiempos1 << mediana << ",";

        mediana = calcularTiempos(meetInTheMiddle, limpiarDatos, capacidad, &originalSet);
        tiempos1 << mediana << ",";

        mediana = calcularTiempos(programacionDinamica, limpiarDatos, capacidad, &originalSet);
        tiempos1 << mediana << std::endl;
    }
    tiempos1.close();

    ////////////////////////////////// EXPERIMENTO 2 /////////////////////////////////////////
/*
     * Experimento 2
     * Compiten BT y PD
     * V fijo y N ordenado de menor a mayor. Esto va a ayudar a BT ya que este va a cortar muchas más ramas por sus podas
*/
    capacidad = 100;
    tamanoMaximoInstancia = 40;
    std::ofstream tiempos2;
    tiempos2.open("experimento_2.csv",std::ios::out);

    tiempos2 << "instancias,n,v,backtracking,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaConCostoYBeneficioAleatorio(cantidadElementos, capacidad * 2);
        std::sort(originalSet.begin(),originalSet.end(),requestCompare);

        tiempos2 << cantidadElementos << "," << cantidadElementos << "," << capacidad << ",";

        double mediana;
        mediana = calcularTiempos(backtracking, limpiarDatos, capacidad, &originalSet);
        tiempos2 << mediana << ",";

        mediana = calcularTiempos(programacionDinamica, limpiarDatos, capacidad, &originalSet);
        tiempos2 << mediana << std::endl;
    }
    tiempos2.close();


    ////////////////////////////////// EXPERIMENTO 3 /////////////////////////////////////////
    /*
     * Experimento 3
     * Compiten BT y PD
     * V fijo y N ordenado de mayor a menor. Esto va a perjudicar a BT porque va a podar mucho menos.
    */
    capacidad = 100;
    tamanoMaximoInstancia = 50;
    std::ofstream tiempos3;
    tiempos3.open("experimento_3.csv",std::ios::out);

    tiempos3 << "instancias,n,v,backtracking,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaConCostoYBeneficioAleatorio(cantidadElementos, capacidad * 2);
        std::sort(originalSet.begin(),originalSet.end(),requestCompareReverse);

        tiempos3 << cantidadElementos << "," << cantidadElementos << "," << capacidad << ",";

        double mediana;
        mediana = calcularTiempos(backtracking, limpiarDatos, capacidad, &originalSet);
        tiempos3 << mediana << ",";

        mediana = calcularTiempos(programacionDinamica, limpiarDatos, capacidad, &originalSet);
        tiempos3 << mediana << std::endl;
    }
    tiempos3.close();


    ////////////////////////////////// EXPERIMENTO 4 /////////////////////////////////////////
    /*
     * Experimento 4
     * Compiten BT, MITM y PD
     * V fijo y N con los elementos entre [0,n-1) mayores que V y el elemento n-1 tiene costo 0.
     * Por esto se perjudica a BT porque tiene que ver el arbol de completo.
     */
    capacidad = 100;
    tamanoMaximoInstancia = 50;
    std::ofstream tiempos4;
    tiempos4.open("experimento_4.csv",std::ios::out);

    tiempos4 << "instancias,n,v,backtracking,meet_in_the_middle,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaExperimento4(cantidadElementos, capacidad);

        tiempos4 << cantidadElementos << "," << cantidadElementos << "," << capacidad << ",";

        double mediana;
        mediana = calcularTiempos(backtracking, limpiarDatos, capacidad, &originalSet);
        tiempos4 << mediana << ",";

        mediana = calcularTiempos(meetInTheMiddle, limpiarDatos, capacidad, &originalSet);
        tiempos4 << mediana << ",";

        mediana = calcularTiempos(programacionDinamica, limpiarDatos, capacidad, &originalSet);
        tiempos4 << mediana << std::endl;
    }
    tiempos4.close();

    ////////////////////////////////// EXPERIMENTO 5 /////////////////////////////////////////
    /*
     * Experimento 5
     * Compiten BT , MITM y PD
     * V fijo y N con los elementos entre [1,n) mayores que V y el elemento 0 tiene a V.
     * Por esto se beneficia a BT porque va a podar mucho. MITM va a tener un arbol que poda y el otro no poda nada.
     */
    capacidad = 100;
    tamanoMaximoInstancia = 50;
    std::ofstream tiempos5;
    tiempos5.open("experimento_5.csv",std::ios::out);

    tiempos5 << "instancias,n,v,backtracking,meet_in_the_middle,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaExperimento5(cantidadElementos, capacidad);

        tiempos5 << cantidadElementos << "," << cantidadElementos << "," << capacidad << ",";

        double mediana;
        mediana = calcularTiempos(backtracking, limpiarDatos, capacidad, &originalSet);
        tiempos5 << mediana << ",";

        mediana = calcularTiempos(meetInTheMiddle, limpiarDatos, capacidad, &originalSet);
        tiempos5 << mediana << ",";

        mediana = calcularTiempos(programacionDinamica, limpiarDatos, capacidad, &originalSet);
        tiempos5 << mediana << std::endl;
    }
    tiempos5.close();

    ////////////////////////////////// EXPERIMENTO 6 /////////////////////////////////////////
/*
     * Experimento 6
     * Compiten MITM y PD
     * La idea es perjudicar a PD teniendo un V muy grande.
     * OBS: Intenté con INT_MAX/2 pero no termina.
*/
    // capacidad = INT_MAX/2;
    //capacidad = 500*500;
    capacidad = 100*100;
    tamanoMaximoInstancia = 20;
    std::ofstream tiempos06;
    tiempos06.open("experimento_6.csv",std::ios::out);
    tiempos06 << "instancias,n,v,meet_in_the_middle,programacion_dinamica" << std::endl;
    for(int cantidadElementos = 1; cantidadElementos <= tamanoMaximoInstancia; cantidadElementos++){

        originalSet = crearInstanciaConCostoYBeneficioAleatorio(cantidadElementos, capacidad);

        tiempos06 << cantidadElementos << "," << cantidadElementos << "," << capacidad << ",";

        double mediana;
        mediana = calcularTiempos(meetInTheMiddle, limpiarDatos, capacidad, &originalSet);
        tiempos06 << mediana << ",";

        mediana = calcularTiempos(programacionDinamica, limpiarDatos, capacidad, &originalSet);
        tiempos06 << mediana << std::endl;
    }
    tiempos06.close();

    ////////////////////////////////// EXPERIMENTO 7 /////////////////////////////////////////
/*
     * Experimento 7
     * Compiten BT, MITM y PD
     * Dejar instancias de tamaño fijo y mover la capacidad.
     * La idea es perjudicar a PD teniendo un V muy grande.
     * OBS: Intenté con INT_MAX/2 pero no termina.
*/

    capacidad = pow(2,30);
    tamanoMaximoInstancia = 30;
    std::ofstream tiempos07;
    tiempos07.open("experimento_7.csv",std::ios::out);
    tiempos07 << "instancias,n,v,backtracking,meet_in_the_middle,programacion_dinamica" << std::endl;
    for(int indiceCapacidad = 2; indiceCapacidad <= capacidad; indiceCapacidad = indiceCapacidad*2){

        originalSet = crearInstanciaConCostoYBeneficioAleatorio( tamanoMaximoInstancia,indiceCapacidad);

        tiempos07 << tamanoMaximoInstancia << "," << tamanoMaximoInstancia << "," << indiceCapacidad << ",";

        double mediana;

        mediana = calcularTiempos(backtracking, limpiarDatos, capacidad, &originalSet);
        tiempos07 << mediana << ",";

        mediana = calcularTiempos(meetInTheMiddle, limpiarDatos, capacidad, &originalSet);
        tiempos07 << mediana << ",";

        mediana = calcularTiempos(programacionDinamica, limpiarDatos, capacidad, &originalSet);
        tiempos07 << mediana << std::endl;
    }
    tiempos07.close();

    return 0;
}






std::vector<Request> crearInstanciaExperimento5(int cantidadDeElementos, double capacidad) {
    std::vector<Request> instancia;
    instancia.reserve(cantidadDeElementos);
    for(int index = 0; index < cantidadDeElementos; index++){
        instancia.push_back(Request(   std::fmod( (float) std::rand() , (capacidad*2) ) + capacidad+1, (float) std::rand()));
    }
    instancia.at(0) = Request(1, INT_MAX);
    assert(instancia.size() == cantidadDeElementos);
    return instancia;
}

std::vector<Request> crearInstanciaExperimento4(int cantidadDeElementos, double capacidad) {
    std::vector<Request> instancia;
    instancia.reserve(cantidadDeElementos);
    for(int index = 0; index < cantidadDeElementos; index++){
        instancia.push_back(Request(  std::fmod( (float) std::rand() , (capacidad*2) ) + capacidad+1, (float) std::rand()));
    }
    instancia.at(cantidadDeElementos-1) = Request(0,INT_MAX);
    assert(instancia.size() == cantidadDeElementos);
    return instancia;
}

/*
 * Instancia con costo entre 0 y la capacidad, y beneficio aleatorio.
 */
std::vector<Request> crearInstanciaConCostoYBeneficioAleatorio(int cantidadDeElementos, double capacidad){
    std::vector<Request> instancia;
    instancia.reserve(cantidadDeElementos);
    for(int index = 0; index < cantidadDeElementos; index++){
        instancia.push_back(   Request(  std::fmod( (float) std::rand() , capacidad )    , (float) std::rand()  )  );
    }
    assert(instancia.size() == cantidadDeElementos);
    return instancia;
}

/*
 * Corro el algoritmo "cantidadDeIteraciones" veces, saco los tiempos en milisegundos y saco la mediana.
 * OBS: La mediana es ordenar y elejir el del medio.
 */
double calcularTiempos(Knapsack *knapsack, int cantidadDeIteraciones, double capacity, std::vector<Request> *requests) {
    std::vector<double> tiemposALimpiar;
    tiemposALimpiar.resize(cantidadDeIteraciones);
    for(int nroDeIteracion = 0; nroDeIteracion < cantidadDeIteraciones; nroDeIteracion++){

            auto tiempo_inicio = std::__1::chrono::steady_clock::now();
            knapsack->maximumBenefit(capacity,requests);
            auto tiempo_final = std::__1::chrono::steady_clock::now();
            auto diferencia = tiempo_final - tiempo_inicio;
            tiemposALimpiar.at(nroDeIteracion) = std::__1::chrono::duration <double, std::__1::milli> (diferencia).count();

        }
    sort(tiemposALimpiar.begin(),tiemposALimpiar.end());
    return tiemposALimpiar.at(std::floor(tiemposALimpiar.size() / 2));
}
