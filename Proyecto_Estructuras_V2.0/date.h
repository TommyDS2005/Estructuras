//
// Created by TOMAS on 3/03/2023.
//

#ifndef PROYECTO_ESTRUCTURAS_DATE_H
#define PROYECTO_ESTRUCTURAS_DATE_H
#include "Curiosity.h"
#include <iostream>
#include <fstream>

bool hasMoreTokens(std::stringstream& ss, char delimiter = '|');

int countLines(std::string fileName);

std::list <sComandos> split(std::string str, char delimiter);

void escribir_archivo_comandos(std::string filename, std::list<std::string> internal);

void escribir_archivo_elementos(std::string filename, std::list<std::string> internal);

std::vector<std::string> TokenizarEntradaUsuario(std::string entrada);

#endif //PROYECTO_ESTRUCTURAS_DATE_H
