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

bool hasMoreTokens(std::stringstream& ss, char delimiter) {
    // Si el siguiente carácter es el delimitador, no hay más tokens.
    if (ss.peek() == delimiter) {
        return false;
    }

    // Si no hay más caracteres, no hay más tokens.
    if (ss.eof()) {
        return false;
    }

    // Si no se cumplen las condiciones anteriores, hay más tokens.
    return true;
}

int countLines(std::string fileName) {
    std::ifstream file(fileName);
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
    std::string aux1, aux2, aux3, aux4;
    int aux = 0;
    bool bandera = true;
    std::stringstream ss(str); // Turn the string into a stream.
    std::string tok;
    while (getline(ss, tok, delimiter)) {
        if (aux == 0) {
            aux1 = tok;
        }
        if(aux1 == "0")
        {
            if(aux == 1)
            {
                aux2 = tok;
            }
            if(aux == 2)
            {
                aux3 = tok;
            }
            if(aux == 3)
            {
                aux4 = tok;
            }
        }
        if(aux1 == "1")
        {
            if(aux == 1)
            {
                aux2 = tok;
            }
            if(aux == 2)
            {
                aux3 = tok;
            }
            if(hasMoreTokens(ss, delimiter))
            {
                aux4 = tok;
            }
        }
        aux++;
    }
    if(aux1 == "0")
    {
        if(aux2 == "avanzar" || aux2 == "girar")
        {
            for(auto& c: aux3)
            {
                if (!isdigit(c))
                {
                    std::cout << "El formato es invalido" << std::endl;
                    bandera = false;
                }
            }
            if(bandera)
            {
                if(aux4 == "metros")
                {
                    internal.push_back({aux2, stof(aux3), aux4});
                }
                else if(aux4 == "grados")
                {
                    internal.push_back({aux2, stof(aux3), aux4});
                }
            } 
        }
    }
    else if(aux1 == "1")
    {
        if(aux2 == "fotografiar" || aux2 == "composicion" || aux2 == "perforar")
        {
            for(auto& c: aux2)
            {
                if (isdigit(c))
                {
                    bandera = false;
                }
            }
            if(bandera)
            {
                if(aux4 == "")
                {
                    internal.push_back({aux2, aux3, ""});
                }
                else
                {
                    internal.push_back({aux2, aux3, aux4});
                }
            }    
        }
    }
    return internal;
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

    std::vector<std::string> TokenizarEntradaUsuario (std::string entrada)
    {
        std::string aux;
        std::vector<std::string> instrucciones;
        std::stringstream ss(entrada); // Turn the string into a stream.
        std::string tok;
        while (getline(ss, tok, ' ')) {
            instrucciones.push_back(tok);
        }
        return instrucciones;
    }

