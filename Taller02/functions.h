//
// Created by TOMAS on 20/02/2023.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <set>
#include <map>
#include <filesystem>


#ifndef functions_h
#define functions_h

struct JaveMusic{
    std::string nombre_artista;
    std::string nombre_album;
    std::string nombre_cancion;
    std::string genero;
    std::string lanzamiento;
};

void guardar_datos(std::string example, std::vector<JaveMusic> &javeMusic);

void imprimir_por_autor_alfabeticamente(std::vector<JaveMusic> &javeMusic);

void imprimir_las_canciones_de_un_autor_alfabeticamente(std::vector<JaveMusic> &javeMusic);

void imprimir_albumes_cronologicamente(std::vector<JaveMusic> &javeMusic);

void imprimir_canciones_de_un_album_alfabeticamente(std::vector<JaveMusic> &javeMusic);

void imprimir_las_canciones_alfabeticamente_por_album_y_por_cancion(std::vector<JaveMusic> &javeMusic);

#endif
