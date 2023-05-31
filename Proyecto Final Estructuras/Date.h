//
// Created by TOMAS on 3/03/2023.
//

#ifndef PROYECTO_ESTRUCTURAS_DATE_H
#define PROYECTO_ESTRUCTURAS_DATE_H
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "Quadtree.h"
bool hasMoreTokens(std::stringstream& ss, char delimiter = '|');

int countLines(std::string fileName);

void escribir_archivo_comandos(std::string filename, std::list<std::string> internal);

void escribir_archivo_elementos(std::string filename, std::list<std::string> internal);

std::vector<std::string> TokenizarEntradaUsuario(std::string entrada);

std::vector<Point> puntoMaxyMin(std::list<sElemento> internal);

#endif //PROYECTO_ESTRUCTURAS_DATE_H
