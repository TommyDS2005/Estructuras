//
// Created by Usuario on 27/04/2023.
//

#include "Curiosity.h"
#include "Point.h"
#include <vector>

#ifndef PROYECTO_ESTRUCTURAS_QUADTREE_H
#define PROYECTO_ESTRUCTURAS_QUADTREE_H

class Quadtree {
public:
    const int MAX_POINTS = 1; // Máximo número de puntos que se pueden almacenar en un nodo
    const int MAX_LEVELS = 30; // Máxima profundidad del árbol
    int level; // Nivel del árbol
    vector<sElemento> points; // Vector de puntos almacenados en el nodo
    Quadtree* nodes[4]; // Cuatro hijos del nodo (noroeste, noreste, suroeste, sureste)
    Point topLeft; // Coordenadas del punto superior izquierdo del área que abarca el nodo
    Point bottomRight; // Coordenadas del punto inferior derecho del área que abarca el nodo

    // Método privado para dividir el nodo en cuatro hijos
    void split(){
        float subWidth = (bottomRight.x - topLeft.x) / 2;
        float subHeight = (bottomRight.y - topLeft.y) / 2;
        float x = topLeft.x;
        float y = topLeft.y;

        nodes[0] = new Quadtree(level+1, Point(x, y), Point(x+subWidth, y+subHeight));
        nodes[1] = new Quadtree(level+1, Point(x+subWidth, y), Point(bottomRight.x, y+subHeight));
        nodes[2] = new Quadtree(level+1, Point(x, y+subHeight), Point(x+subWidth, bottomRight.y));
        nodes[3] = new Quadtree(level+1, Point(x+subWidth, y+subHeight), bottomRight);
    }

    // Constructor del nodo
    Quadtree(int level, Point topLeft, Point bottomRight)
    {
        this->level = level;
        this->topLeft = topLeft;
        this->bottomRight = bottomRight;
        for (int i = 0; i < 4; i++)
        {
            this->nodes[i] = nullptr;
        }
    }

    // Método para insertar un punto en el árbol
    void insert(sElemento point)
    {
        if (nodes[0] != nullptr)
        {
            int index = getIndex(point);
            if (index != -1)
            {
                nodes[index]->insert(point);
                return;
            }
        }
        points.push_back(point);

        if (points.size() > MAX_POINTS && level < MAX_LEVELS)
        {
            if (nodes[0] == nullptr) {
                split();
            }
            int i = 0;
            while (i < points.size())
            {
                int index = getIndex(points[i]);
                if (index != -1)
                {
                    nodes[index]->insert(points[i]);
                    points.erase(points.begin() + i);
                }
                else
                {
                    i++;
                }
            }
        }
    }

    /*
     if (pQuadtree == nullptr) {
                    return;
                }
                if (!pQuadtree->points.empty()) {
                    for (auto &t: pQuadtree->points)
                    {
                        std::cout << t.tipo_elemento << " " << t.tamaño << " " << t.unidad_medida << " " << t.coordenada_x << " " << t.coordenada_y << std::endl;
                    }
                }
                if (pQuadtree->nodes[0] != nullptr) {
                    for (auto & node : pQuadtree->nodes) {
                        imprimirQuadtree(node);
                    }
                }
     */

    // Función para buscar los elementos dentro de un área específica
    vector<sElemento> query(float x1, float y1, float x2, float y2, Quadtree* pQuadtree) {
        vector<sElemento> result;

        // Caso base: si el área de búsqueda está completamente fuera del área del nodo actual, retorna el resultado vacío
        if (x2 < pQuadtree->topLeft.x || x1 > pQuadtree->bottomRight.x || y2 < pQuadtree->topLeft.y || y1 > pQuadtree->bottomRight.y) {
            return result;
        }

        // Verificar si los puntos del pQuadtree están dentro del área de búsqueda y agregarlos al resultado
        for (auto& element : pQuadtree->points) {
            if (element.coordenada_x >= x1 && element.coordenada_x <= x2 &&
                    element.coordenada_y >= y1 && element.coordenada_y <= y2) {
                result.push_back(element);
            }
        }

        // Si el nodo actual tiene hijos, realiza la búsqueda recursiva en cada uno de ellos
        if (pQuadtree->nodes[0] != nullptr) {
            for (auto& node : pQuadtree->nodes) {
                vector<sElemento> childResult = query(x1, y1, x2, y2, node);
                for (const auto& point : childResult) {
                    result.push_back(point);
                }
            }
        }

        return result;
    }




    bool esQuadTreeVacio(Quadtree* nodo) {
        // Comprobamos si el nodo es nulo
        if (nodo == nullptr) {
            return true;
        }

        // Comprobamos si el nodo tiene hijos y no son nulos
        for (auto & node : nodo->nodes) {
            if (node != nullptr) {
                return false;
            }
        }

        // Si todos los hijos son nulos, el nodo es una hoja
        return true;
    }
// Método privado para determinar en qué hijo se encuentra un punto
    int getIndex(sElemento point)
    {
        int index = -1;
        double verticalMidpoint = (topLeft.x + bottomRight.x) / 2;
        double horizontalMidpoint = (topLeft.y + bottomRight.y) / 2;
        // Verificar en qué cuadrante se encuentra el punto
        bool topQuadrant = (point.coordenada_x < horizontalMidpoint && point.coordenada_y >= topLeft.y);
        bool bottomQuadrant = (point.coordenada_y >= horizontalMidpoint && point.coordenada_x <= bottomRight.y);
        if (point.coordenada_x < verticalMidpoint && point.coordenada_y >= topLeft.x)
        {
            if (topQuadrant)
            {
                index = 0;
            }
            else if (bottomQuadrant)
            {
                index = 2;
            }
        } else if (point.coordenada_x >= verticalMidpoint && point.coordenada_y <= bottomRight.x)
        {
            if (topQuadrant)
            {
                index = 1;
            }
            else if (bottomQuadrant)
            {
                index = 3;
            }
        }

        return index;
    }

    void imprimirQuadtree(Quadtree* pQuadtree)
            {
                if (pQuadtree == nullptr) {
                    return;
                }
                if (!pQuadtree->points.empty()) {
                    for (auto &t: pQuadtree->points)
                    {
                        std::cout << t.tipo_elemento << " " << t.tamaño << " " << t.unidad_medida << " " << t.coordenada_x << " " << t.coordenada_y << std::endl;
                    }
                }
                if (pQuadtree->nodes[0] != nullptr) {
                    for (auto & node : pQuadtree->nodes) {
                        imprimirQuadtree(node);
                    }
                }
            }
};

#endif //PROYECTO_ESTRUCTURAS_QUADTREE_H
