//
// Created by TOMAS on 20/02/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <list>
#include <sstream>
#include <set>
#include <map>
#include "functions.h"
#include <vector>
#include <algorithm>


void guardar_datos(std::string a, std::vector<JaveMusic> &javeMusic)
{
    JaveMusic javeMusic1;
    int aux=0;
    std::string line;
    std::ifstream myfile (a);
    std::string aa;
    if (myfile.is_open()) {
        std::getline(myfile, aa);
        while ( getline (myfile,line) ) {
            std::string delim = "|";
            std::vector<std::string> words{};
            size_t pos = 0;
            while ((pos = line.find(delim)) != std::string::npos) {
                words.push_back(line.substr(0, pos));
                line.erase(0, pos + delim.length());
            }
            if (!line.empty())
                words.push_back(line.substr(0, pos));
            for (const auto &str : words) {
                if(aux==0)
                {
                    javeMusic1.nombre_cancion=str;
                }
                if(aux==2)
                {
                    javeMusic1.genero=str;
                }
                if(aux==1)
                {
                    javeMusic1.nombre_artista=str;
                }
                if(aux==3)
                {
                    javeMusic1.nombre_album=str;
                }
                if(aux==4)
                {
                    javeMusic1.lanzamiento=str;
                    javeMusic.push_back(javeMusic1);
                }
                aux++;
                if(aux==5)
                {
                    aux=0;
                }
            }
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
}

void imprimir_por_autor_alfabeticamente(std::vector<JaveMusic> &javeMusic)
{
    std::set<std::string> autores;
    for (auto &javeMusic1 : javeMusic) {
        autores.insert(javeMusic1.nombre_artista);
    }
    for (auto &autor : autores) {
        std::cout << autor << std::endl;
    }
}

void imprimir_las_canciones_de_un_autor_alfabeticamente(std::vector<JaveMusic> &javeMusic)
{
    std::string autor;
    std::cout << "Ingrese el autor: ";
    std::cin >> autor;
    std::cout << std::endl;
    std::set<std::string> canciones;
    for (auto &javeMusic1 : javeMusic) {
        if(javeMusic1.nombre_artista==autor)
        {
            canciones.insert(javeMusic1.nombre_cancion);
        }
    }
    for (auto &cancion : canciones) {
        std::cout << cancion << std::endl;
    }
}

void imprimir_albumes_cronologicamente(std::vector<JaveMusic> &javeMusic)
{
    std::cout << std::endl;
    std::map<std::string, std::string> albumes;
    for (auto &javeMusic1 : javeMusic) {
            albumes.insert(std::pair<std::string, std::string>(javeMusic1.lanzamiento, javeMusic1.nombre_album));
    }
    for (auto &album : albumes) {
        std::cout << album.first << " " << album.second << std::endl;
    }
}

void imprimir_canciones_de_un_album_alfabeticamente(std::vector<JaveMusic> &javeMusic)
{
    std::string album;
    std::cout << "Ingrese el album: ";
    std::cin >> album;
    std::cout << std::endl;
    std::set<std::string> canciones;
    for (auto &javeMusic1 : javeMusic) {
        if(javeMusic1.nombre_album==album)
        {
            canciones.insert(javeMusic1.nombre_cancion);
        }
    }
    for (auto &cancion : canciones) {
        std::cout << cancion << std::endl;
    }
}

void imprimir_las_canciones_alfabeticamente_por_album_y_por_cancion(std::vector<JaveMusic> &javeMusic)
{
    std::cout << std::endl;
    std::map<std::string, std::string> albumes;
    for (auto &javeMusic1 : javeMusic) {
        albumes.insert(std::pair<std::string, std::string>(javeMusic1.nombre_album, javeMusic1.nombre_cancion));
    }
    for (auto &album : albumes) {
        std::cout << album.first << " " << album.second << std::endl;
    }
}