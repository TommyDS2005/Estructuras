//
// Created by TOMAS on 3/03/2023.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <math.h>
#include <list>
#include "Curiosity.h"
#include "date.h"


int countLines() {
    std::ifstream file("Comandos.txt");
    std::string line;
    int count = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
        }
        file.close();
    }
    else
    {
        return -1;
    }

    return count;
}
std::list <sComandos> split(std::string str, char delimiter) {
    std::list<sComandos> internal;
    std::string aux1, aux2;
    int aux3, aux4 = 0;
    std::stringstream ss(str); // Turn the string into a stream.
    std::string tok;

    while (getline(ss, tok, delimiter)) {
        if (aux4 == 0) {
            aux1 = tok;
            aux4++;
        }
        if (aux4 == 1) {
            aux3 = stoi(tok);
            aux4++;
        }
        if (aux4 == 2) {
            aux2 = tok;
            aux4 = 0;
            sComandos comandos = sComandos(aux1, aux3, aux2);
            internal.push_back(comandos);
        }
        return internal;
    }
}

    void escribir_archivo_comandos(std::string filename, std::list<std::string> internal) {
        std::fstream file;
        int i = 0;
        file.open(filename, std::ios::out | std::ios::app);
        for (std::string t: internal) {
            if (i == 0) {
                file << t << "|";
                i++;
            }
            if (i == 1) {
                file << t;
                file << std::endl;
                i = 0;
            }
        }
        file.close();
    }

    void escribir_archivo_elementos(std::string filename, std::list<std::string> internal) {
        std::fstream file;
        int i = 0;
        file.open(filename, std::ios::out | std::ios::app);
        for (std::string t: internal) {
            if (i == 0) {
                file << t << "|";
            }
            if (i == 1) {
                file << t << "|";
            }
            if (i == 2) {
                file << t << "|";
            }
            if (i == 3) {
                file << t << "|";
            }
            if (i == 4) {
                file << t;
                file << std::endl;
                i = 0;
            }
            i++;
        }
        file.close();
    }

