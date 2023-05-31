//
// Created by Usuario on 16/05/2023.
//

#include "Curiosity.h"
#include <vector>

#ifndef PROYECTO_ESTRUCTURAS_NODO_H
#define PROYECTO_ESTRUCTURAS_NODO_H

class Arista;

class Nodo {
public:
    sElemento elemento;
    std::vector<Arista*> adyacente;
    Nodo(sElemento elemento);
    bool operator != (const Nodo* &nodo) const {
        return (elemento != nodo->elemento);
    }
    Nodo();
};

class Arista {
public:
    std::vector<Nodo*> adyacente;
    float peso;
    Arista(Nodo *adyacente1, Nodo* adyacente2, float peso);
};


#endif //PROYECTO_ESTRUCTURAS_NODO_H
