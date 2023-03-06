//
// Created by TOMAS on 3/03/2023.
//

#ifndef PROYECTO_ESTRUCTURAS_DATE_H
#define PROYECTO_ESTRUCTURAS_DATE_H
#include "Curiosity.h"
#include <iostream>
#include <fstream>

int countLines();

std::list <sComandos> split(std::string str, char delimiter);

void escribir_archivo(std::string filename, std::list<std::string> lista_comandos);

void menu(sCuriosity &Curiosity);

#endif //PROYECTO_ESTRUCTURAS_DATE_H
