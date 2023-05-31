//
// Created by Usuario on 16/05/2023.
//

#include "Nodo.h"
#include "Grafo.h"
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
#include <unordered_map>


Grafo::Grafo(float coeficiente) {
    this->coeficiente = coeficiente;
    this->insertados = {};
}

void Grafo::insertarNodo(std::vector<sElemento> elemento) {
    for(auto &t: elemento){
        Nodo *nodo = new Nodo(t);
        this->insertados.push_back(nodo);
    }
}

float Grafo::DistanciaEuclidiana(Nodo* elemento1, Nodo* elemento2) {
    return sqrt(pow(elemento1->elemento.coordenada_x - elemento2->elemento.coordenada_x, 2) + pow(elemento1->elemento.coordenada_y - elemento2->elemento.coordenada_y, 2));
}

void Grafo::Conectar()
{
    float conectividad = round(this->coeficiente * this->insertados.size());
    for(int z = 0; z < this->insertados.size(); z++){
        std::vector<Nodo*> adyacentes;
        for(auto &i: this->insertados){
            if(this->insertados[z] != i){
                adyacentes.push_back(i);
            }
        }
        //bubble sort
        for(int i=0; i<adyacentes.size(); i++){
            for(int j=0; j<adyacentes.size()-1; j++){
                if(DistanciaEuclidiana(this->insertados[z], adyacentes[j]) > DistanciaEuclidiana(this->insertados[z], adyacentes[j+1])){
                    Nodo *temp = adyacentes[j];
                    adyacentes[j] = adyacentes[j+1];
                    adyacentes[j+1] = temp;
                }
            }
        }
        for(int i=0; i<conectividad; i++){
            this->insertados[z]->adyacente.push_back(new Arista(this->insertados[z], adyacentes[i], DistanciaEuclidiana(this->insertados[z], adyacentes[i])));
        }
    }
}

void Grafo::imprimir() {
    for(auto &i: this->insertados){
        std::cout << "Nodo: " << i->elemento.tipo_elemento << "Coordenada x: " << i->elemento.coordenada_x << " Coordenada y: " << i->elemento.coordenada_y << std::endl;
        std::cout << "Adyacentes: " << std::endl;
        for(auto &j: i->adyacente){
            std::cout << "Inicial: " << j->adyacente[0]->elemento.tipo_elemento << " Final: " << j->adyacente[1]->elemento.tipo_elemento << " Peso: " << j->peso << std::endl;
        }
        std::cout << std::endl;
    }
}

void Grafo::DFS(Nodo* nodoActual, std::unordered_map<Nodo*, bool>& visitado, std::vector<Nodo*>& rutaActual, float pesoTotal, float& pesoMaximo, std::vector<Nodo*>& rutaMasLarga) {
    visitado[nodoActual] = true;
    rutaActual.push_back(nodoActual);

    // Verificar si se ha encontrado una ruta mas larga
    if (pesoTotal > pesoMaximo) {
        pesoMaximo = pesoTotal;
        rutaMasLarga = rutaActual;
    }

    // Recorrer los nodos adyacentes no visitados
    for (const auto& arista : nodoActual->adyacente) {
        Nodo* nodoAdyacente = (arista->adyacente[0] != nodoActual) ? arista->adyacente[0] : arista->adyacente[1];

        if (!visitado[nodoAdyacente]) {
            pesoTotal += arista->peso;
            DFS(nodoAdyacente, visitado, rutaActual, pesoTotal, pesoMaximo, rutaMasLarga);
            pesoTotal -= arista->peso;
        }
    }

    // Retroceder y marcar el nodo actual como no visitado
    rutaActual.pop_back();
    visitado[nodoActual] = false;
}


void Grafo::ruta_mas_larga() {
    std::vector<Nodo*> rutaActual;
    std::vector<Nodo*> rutaMasLarga;
    float pesoTotal = 0.0;
    float pesoMaximo = 0.0;

    // Inicializar el estado de visita de los nodos
    std::unordered_map<Nodo*, bool> visitado;
    for (const auto& nodo : insertados) {
        visitado[nodo] = false;
    }

    // Realizar DFS modificado desde cada nodo
    for (const auto& nodo : insertados) {
        DFS(nodo, visitado, rutaActual, pesoTotal, pesoMaximo, rutaMasLarga);
    }

    std::cout << "(Resultado exitoso) Los puntos de interes mas alejados entre si en terminos de aristas son (" << rutaMasLarga.front()->elemento.coordenada_x
              << ", " << rutaMasLarga.front()->elemento.coordenada_y << ") y (" << rutaMasLarga.back()->elemento.coordenada_x << ", "
              << rutaMasLarga.back()->elemento.coordenada_y << ")." << std::endl;

    std::cout << "La ruta que los conecta tiene una longitud total de " << rutaMasLarga.size() - 1 << " aristas y pasa por los siguientes elementos:" << std::endl;
    for (const auto& nodo : rutaMasLarga) {
        std::cout << "(" << nodo->elemento.coordenada_x << ", " << nodo->elemento.coordenada_y << ") ";
    }
    std::cout << std::endl;
}