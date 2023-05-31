//
// Created by Usuario on 16/05/2023.
//

#include "Nodo.h"

Nodo::Nodo() {
    this->elemento = sElemento();
}

Nodo::Nodo(sElemento elemento) {
    this->elemento = elemento;
}

Arista::Arista(Nodo *adyacente1, Nodo *adyacente2, float peso) {
    this->adyacente.push_back(adyacente1);
    this->adyacente.push_back(adyacente2);
    this->peso = peso;
}
