//
// Created by Usuario on 16/05/2023.
//

#include "Nodo.h"

#ifndef PROYECTO_ESTRUCTURAS_GRAFO_H
#define PROYECTO_ESTRUCTURAS_GRAFO_H


class Grafo {
public:
    std::vector<Nodo*> insertados;
    float coeficiente;
    explicit Grafo(float coeficiente);
    void insertarNodo(std::vector<sElemento> elemento);
    float DistanciaEuclidiana(Nodo* elemento1, Nodo* elemento2);
    void Conectar();
    void imprimir();
    Nodo* CaminoMasLargo(Nodo* aux);
    Arista* AristaMayorPeso(Nodo* aux);
    void ruta_mas_larga();
    Nodo* NodoMasIzq();
};


#endif //PROYECTO_ESTRUCTURAS_GRAFO_H
