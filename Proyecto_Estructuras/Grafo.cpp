//
// Created by Usuario on 16/05/2023.
//

#include "Nodo.h"
#include "Grafo.h"
#include <algorithm>

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
        std::cout << "Nodo: " << i->elemento.tipo_elemento << std::endl;
        std::cout << "Adyacentes: " << std::endl;
        for(auto &j: i->adyacente){
            std::cout << "Inicial: " << j->adyacente[0]->elemento.tipo_elemento << " Final: " << j->adyacente[1]->elemento.tipo_elemento << " Peso: " << j->peso << std::endl;
        }
        std::cout << std::endl;
    }
}

Nodo* Grafo::CaminoMasLargo(Nodo* aux) {
    std::vector<Nodo*> CopyInsertados = this->insertados;
    for(int i=0; i<insertados.size(); i++)
    {
        if(insertados[i] == aux)
        {
            for (int j = 0; j < insertados.size() - 1; j++) {
                if (DistanciaEuclidiana(this->insertados[i], insertados[j]) < DistanciaEuclidiana(this->insertados[i], insertados[j + 1])) {
                    Nodo *temp = CopyInsertados[j];
                    CopyInsertados[j] = CopyInsertados[j + 1];
                    CopyInsertados[j + 1] = temp;
                }
            }
        }
    }

    for(int i=0; i<insertados.size(); i++)
    {
        if(insertados[i] == CopyInsertados[0])
        {
            return insertados[i];
        }
    }
    return nullptr;
}

Arista* Grafo::AristaMayorPeso(Nodo* aux) {
    for(int i=0; i<aux->adyacente.size(); i++)
    {
        for(int j=0; j<aux->adyacente.size()-1; j++)
        {
            if(aux->adyacente[j]->peso < aux->adyacente[j+1]->peso)
            {
                Arista *temp = aux->adyacente[j];
                aux->adyacente[j] = aux->adyacente[j+1];
                aux->adyacente[j+1] = temp;
            }
        }
    }
    return aux->adyacente[0];
}

void Grafo::ruta_mas_larga() {
    Nodo* origen = nullptr;
    Nodo* destino = nullptr;
    float maxDistancia = 0.0;

    // Buscar los puntos más alejados entre sí en el grafo
    for (auto iter1 = insertados.begin(); iter1 != insertados.end(); ++iter1) {
        for (auto iter2 = iter1 + 1; iter2 != insertados.end(); ++iter2) {
            float distancia = DistanciaEuclidiana(*iter1, *iter2);
            if (distancia > maxDistancia) {
                maxDistancia = distancia;
                origen = *iter1;
                destino = *iter2;
            }
        }
    }

    std::cout << "(Resultado exitoso) Los puntos de interes mas alejados entre si son (" << origen->elemento.coordenada_x
              << ", " << origen->elemento.coordenada_y << ") y (" << destino->elemento.coordenada_x << ", "
              << destino->elemento.coordenada_y << ")." << std::endl;

    std::vector<Nodo*> ruta;
    ruta.push_back(origen);
    Nodo* nodoActual = origen;
    float longitudTotal = 0.0;

    while (nodoActual != destino) {
        float maxDistanciaLocal = 0.0;
        Nodo* siguienteNodo = nullptr;

        for (const auto& arista : nodoActual->adyacente) {
            Nodo* nodoAdyacente = (arista->adyacente[0] != nodoActual) ? arista->adyacente[0] : arista->adyacente[1];
            float distancia = DistanciaEuclidiana(nodoActual, nodoAdyacente);
            if (distancia > maxDistanciaLocal && std::find(ruta.begin(), ruta.end(), nodoAdyacente) == ruta.end()) {
                maxDistanciaLocal = distancia;
                siguienteNodo = nodoAdyacente;
            }
        }

        if (siguienteNodo == nullptr) {
            std::cout << "(No hay informacion) No se puede encontrar una ruta que pase por todos los nodos." << std::endl;
            return;
        }

        ruta.push_back(siguienteNodo);
        longitudTotal += maxDistanciaLocal;
        nodoActual = siguienteNodo;
    }

    std::cout << "La ruta que los conecta tiene una longitud total de " << longitudTotal << " y pasa por los siguientes elementos:" << std::endl;
    for (const auto& nodo : ruta) {
        std::cout << "(" << nodo->elemento.coordenada_x << ", " << nodo->elemento.coordenada_y << ") ";
    }
    std::cout << std::endl;
}



Nodo* Grafo::NodoMasIzq() {
    Nodo* aux = this->insertados[0];
    for(auto & insertado : this->insertados)
    {
        if((insertado->elemento.coordenada_x + insertado->elemento.coordenada_y) < (aux->elemento.coordenada_x + aux->elemento.coordenada_y))
        {
            aux = insertado;
        }
    }
    return aux;
}