//
// Created by Usuario on 16/05/2023.
//

#include "Nodo.h"
#include <unordered_map>
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
    void ruta_mas_larga();
    void DFS(Nodo* nodoActual, std::unordered_map<Nodo*, bool>& visitado, std::vector<Nodo*>& rutaActual, float pesoTotal, float& pesoMaximo, std::vector<Nodo*>& rutaMasLarga);
};


#endif //PROYECTO_ESTRUCTURAS_GRAFO_H
