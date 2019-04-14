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
#include "../scr/dynamic_programming/DynamicProgrammingAlgorithm.h"
#include <chrono>
#include <thread>
#include<time.h>

double calcularTiempos(Knapsack *knapsack, int cantidadDeIteraciones, double capacity, std::vector<Request> *requests);

std::vector<Request> crearInstanciaConCostoYBeneficioAleatorio(int elementos, int capacidad);

std::vector<Request> crearInstanciaExperimento4(int elementos, int capacidad);

std::vector<Request> crearInstanciaExperimento5(int elementos, int capacidad);

int randomEnRangoInt(int minimo, int maximo); // implementacion abajo de todo, es un metodo auxiliar

double randomEnRangoDouble(double minimo, double maximo); // implementacion abajo de todo, es un metodo auxiliar

std::vector<Request> requestsRandom(double maxPesoItem, double maxBeneficioItem, int maxCantidadElementos); // implementacion abajo de todo, es un metodo auxiliar

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
    Knapsack *programacionDinamica = new DynamicProgrammingAlgorithm();

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

    std::cout << " ---- INICIO EXPERIMENTO 1 ----" << std::endl;

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
        std::cout << "mediana" << mediana << std::endl;
        tiempos1 << mediana << std::endl;
    }
    tiempos1.close();

    std::cout << " ---- FIN EXPERIMENTO 1 ----" << std::endl;

    ////////////////////////////////// EXPERIMENTO 2 /////////////////////////////////////////
/*
     * Experimento 2
     * Compiten BT y PD
     * V fijo y N ordenado de menor a mayor. Esto va a ayudar a BT ya que este va a cortar muchas más ramas por sus podas
*/

    std::cout << " ---- COMIENZO EXPERIMENTO 2 ----" << std::endl;

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

    std::cout << " ---- FIN EXPERIMENTO 2 ----" << std::endl;

    ////////////////////////////////// EXPERIMENTO 3 /////////////////////////////////////////
    /*
     * Experimento 3
     * Compiten BT y PD
     * V fijo y N ordenado de mayor a menor. Esto va a perjudicar a BT porque va a podar mucho menos.
    */

    std::cout << " ---- COMIENZO EXPERIMENTO 3 ----" << std::endl;

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

    std::cout << " ---- FIN EXPERIMENTO 3 ----" << std::endl;

    ////////////////////////////////// EXPERIMENTO 4 /////////////////////////////////////////
    /*
     * Experimento 4
     * Compiten BT, MITM y PD
     * V fijo y N con los elementos entre [0,n-1) mayores que V y el elemento n-1 tiene costo 0.
     * Por esto se perjudica a BT porque tiene que ver el arbol de completo.
     */

    std::cout << " ---- COMIENZO EXPERIMENTO 4 ----" << std::endl;

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

    std::cout << " ---- FIN EXPERIMENTO 4 ----" << std::endl;

    ////////////////////////////////// EXPERIMENTO 5 /////////////////////////////////////////
    /*
     * Experimento 5
     * Compiten BT , MITM y PD
     * V fijo y N con los elementos entre [1,n) mayores que V y el elemento 0 tiene a V.
     * Por esto se beneficia a BT porque va a podar mucho. MITM va a tener un arbol que poda y el otro no poda nada.
     */

    std::cout << " ---- COMIENZO EXPERIMENTO 5 ----" << std::endl;

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

    std::cout << " ---- FIN EXPERIMENTO 5 ----" << std::endl;

    ////////////////////////////////// EXPERIMENTO 6 /////////////////////////////////////////
/*
     * Experimento 6
     * Compiten MITM y PD
     * La idea es perjudicar a PD teniendo un V muy grande.
     * OBS: Intenté con INT_MAX/2 pero no termina.
*/

    std::cout << " ---- COMIENZO EXPERIMENTO 6 ----" << std::endl;

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

    std::cout << " ---- COMIENZO EXPERIMENTO 6 ----" << std::endl;

    ////////////////////////////////// EXPERIMENTO 7 /////////////////////////////////////////
/*
     * Experimento 7
     * Compiten BT, MITM y PD
     * Dejar instancias de tamaño fijo y mover la capacidad.
     * La idea es perjudicar a PD teniendo un V muy grande.
     * OBS: Intenté con INT_MAX/2 pero no termina.
*/

    std::cout << " ---- COMIENZO EXPERIMENTO 7 ----" << std::endl;

    capacidad = pow(2,30);
    tamanoMaximoInstancia = 30;
    std::ofstream tiempos07;
    tiempos07.open("experimento_7.csv",std::ios::out);
    tiempos07 << "instancias,n,v,backtracking,meet_in_the_middle,programacion_dinamica" << std::endl;
    for(int indiceCapacidad = 2; indiceCapacidad <= capacidad; indiceCapacidad = indiceCapacidad*2){

        originalSet = crearInstanciaConCostoYBeneficioAleatorio( tamanoMaximoInstancia,indiceCapacidad);

        tiempos07 << indiceCapacidad << "," << indiceCapacidad << "," << capacidad << ",";

        double mediana;

        mediana = calcularTiempos(backtracking, limpiarDatos, capacidad, &originalSet);
        tiempos07 << mediana << ",";

        mediana = calcularTiempos(meetInTheMiddle, limpiarDatos, capacidad, &originalSet);
        tiempos07 << mediana << ",";

        mediana = calcularTiempos(programacionDinamica, limpiarDatos, capacidad, &originalSet);
        tiempos07 << mediana << std::endl;
    }
    tiempos07.close();

    std::cout << " ---- FIN EXPERIMENTO 7 ----" << std::endl;

    ////////////////////////////////// EXPERIMENTO 8 /////////////////////////////////////////

    /*
     * el siguiente experimento consta en generar mochilas randoms (los requests siempre tienen peso >0)
     * sus valores son randoms al igual que la cantidad de requests
     * la capacidad maxima tambien es aleatoria
     * con esas dos variables anteriores (capacidad maxima y requests)
     * ejecutamos los 4 algoritmos, mismos parametros por experimento, se realizarán 100 experimentos
     * (la cantidad de experimentos es configurable)
     * */
    std::cout << " ---- COMIENZO EXPERIMENTO 8 ----" << std::endl;

    srand(time(NULL)); // semilla random

    double maxCapacidad = 20; // tamaño mochila  entre 1 y 30

    double maxPesoItem = 10; // entre 1 y 33
    double maxBeneficioItem = 30; // entre 0 y 100 - beneficio items

    // fuerza bruta prueba todos los casos, asi que no tiene que ser mayor a 30, (2^30)
    int maxCantidadRequest = 24;// entre 0 y 30 (asi puede estar el caso de entrar todos)

    int cantidadExperimentos = 100;// mismas situaciones para cada algoritmo en cada experimento

    std::ofstream fileExperimento8;
    fileExperimento8.open("experimento_8.csv",std::ios::out);
    for(int numeroExperimento=1; numeroExperimento < cantidadExperimentos+1; numeroExperimento ++) {
        std::cout << "experimento numero:" << numeroExperimento << "\n";
        std::chrono::duration<double> tiempoFuerzaBruta;
        std::chrono::duration<double> tiempoBacktracking;
        std::chrono::duration<double> tiempoMeetInTheMiddle;
        std::chrono::duration<double> tiempoDinamica;

        std::vector<Request> requests = requestsRandom(maxPesoItem,maxBeneficioItem,maxCantidadRequest);
        double capacidadMochilaActualExperimento = randomEnRangoDouble(1,maxCapacidad);
        std::cout << requests.size() << std::endl;
        std::cout << capacidadMochilaActualExperimento << std::endl;

        Knapsack* fuerzaBruta_algoritmo = new KnapsackDesitionTree(new BruteForce());
        Knapsack* backtracking_algoritmo = new KnapsackDesitionTree(new Backtracking());
        Knapsack* meetInTheMiddle_algoritmo = new MeetInTheMiddle();
        Knapsack* programacionDinamica_algoritmo = new DynamicProgrammingAlgorithm();

        std::chrono::steady_clock::time_point tmp_fuerza_bruta_start = std::chrono::steady_clock::now();
        double benefitFB = fuerzaBruta_algoritmo->maximumBenefit(capacidadMochilaActualExperimento , &requests);
        std::chrono::steady_clock::time_point tmp_fuerza_bruta_end = std::chrono::steady_clock::now();
        std::chrono::duration<double> tmp_fuerza_bruta = std::chrono::duration_cast<std::chrono::duration<double > >(tmp_fuerza_bruta_end - tmp_fuerza_bruta_start); // diferencia tiempos
        delete fuerzaBruta_algoritmo;

        std::chrono::steady_clock::time_point tmp_backtracking_start = std::chrono::steady_clock::now();
        double benefitBT = backtracking_algoritmo->maximumBenefit(capacidadMochilaActualExperimento , &requests);
        std::chrono::steady_clock::time_point tmp_backtracking_end = std::chrono::steady_clock::now();
        std::chrono::duration<double> tmp_backtracking = std::chrono::duration_cast<std::chrono::duration<double > >(tmp_backtracking_end - tmp_backtracking_start); // diferencia tiempos
        delete backtracking_algoritmo;

        std::chrono::steady_clock::time_point tmp_meet_middle_start = std::chrono::steady_clock::now();
        double benefitMM = meetInTheMiddle_algoritmo->maximumBenefit(capacidadMochilaActualExperimento , &requests);
        std::chrono::steady_clock::time_point tmp_meet_middle_end = std::chrono::steady_clock::now();
        std::chrono::duration<double> tmp_meet_middle = std::chrono::duration_cast<std::chrono::duration<double > >(tmp_meet_middle_end - tmp_meet_middle_start); // diferencia tiempos
        delete meetInTheMiddle_algoritmo;

        std::chrono::steady_clock::time_point tmp_dinamica_start = std::chrono::steady_clock::now();
        double benefitPD = programacionDinamica_algoritmo->maximumBenefit(capacidadMochilaActualExperimento , &requests);
        std::chrono::steady_clock::time_point tmp_dinamica_end = std::chrono::steady_clock::now();
        std::chrono::duration<double> tmp_dinamica = std::chrono::duration_cast<std::chrono::duration<double > >(tmp_dinamica_end - tmp_dinamica_start); // diferencia tiempos
        delete programacionDinamica_algoritmo;

        bool sonIguales = (benefitFB == benefitPD) && (benefitBT == benefitMM);
        fileExperimento8 << std::fixed << numeroExperimento << "," << tmp_fuerza_bruta.count()  << "," << tmp_backtracking.count() << "," << tmp_meet_middle.count() << "," << tmp_dinamica.count() << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    fileExperimento8.close();
    std::cout << " ---- FIN EXPERIMENTO 8 ----" << std::endl;

    ////////////////////////////////// EXPERIMENTO N /////////////////////////////////////////

    return 0;
}






std::vector<Request> crearInstanciaExperimento5(int cantidadDeElementos, int capacidad) {
    std::vector<Request> instancia;
    instancia.reserve(cantidadDeElementos);
    for(int index = 1; index < cantidadDeElementos; index++){
        instancia.push_back(Request(std::rand() % (capacidad*2) + capacidad+1,std::rand()));
    }
    instancia.at(0) = Request(1, INT_MAX);
    assert(instancia.size() == cantidadDeElementos);
    return instancia;
}

std::vector<Request> crearInstanciaExperimento4(int cantidadDeElementos, int capacidad) {
    std::vector<Request> instancia;
    instancia.reserve(cantidadDeElementos);
    for(int index = 0; index < cantidadDeElementos; index++){
        instancia.push_back(Request(std::rand() % (capacidad*2) + capacidad+1, std::rand()));
    }
    instancia.at(cantidadDeElementos-1) = Request(0,INT_MAX);
    assert(instancia.size() == cantidadDeElementos);
    return instancia;
}

/*
 * Instancia con costo entre 0 y la capacidad, y beneficio aleatorio.
 */
std::vector<Request> crearInstanciaConCostoYBeneficioAleatorio(int cantidadDeElementos, int capacidad){
    std::vector<Request> instancia;
    instancia.reserve(cantidadDeElementos);
    for(int index = 0; index < cantidadDeElementos; index++){
        instancia.push_back(Request(std::rand() % capacidad,std::rand()));
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

// devolver un random entero entre dos numeros.
int randomEnRangoInt(int minimo, int maximo) {
    int random = std::rand() % (maximo+1);
    if(random < minimo ) {
        random = minimo;
    }
    return random;
}

// devolver un random double entre dos numeros.
double randomEnRangoDouble(double minimo, double maximo) {
    double random =  std::fmod( (float) std::rand() , (maximo+1));
    if(random < minimo ) {
        random = minimo;
    }
    return random;
}

std::vector<Request> requestsRandom(double maxPesoItem, double maxBeneficioItem, int maxCantidadElementos) {
    std::vector<Request> requests;
    int cantidad = randomEnRangoInt(0, maxCantidadElementos);
    for(int j=0; j<cantidad; j++){
        Request request = Request( randomEnRangoDouble(1,maxPesoItem),  randomEnRangoDouble(0,maxBeneficioItem)  ) ;
        requests.push_back(request);
    }
    return requests;
}
