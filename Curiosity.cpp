//Curiosity.cpp
// Created by TOMAS on 5/03/2023.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <math.h>
#include <list>
#include "Curiosity.h"
#define PI 3.14159265359

sComandos::sComandos(std::string tipo_movimiento, float magnitud, std::string unidad_medida) {
comando_movimiento.tipo_movimiento = tipo_movimiento;
comando_movimiento.magnitud = magnitud;
comando_movimiento.unidad_medida = unidad_medida;
}

sComandos::sComandos(std::string tipo_analisis, std::string objeto, std::string comentario) {
comando_analisis.tipo_analisis = tipo_analisis;
comando_analisis.objeto = objeto;
comando_analisis.comentario = comentario;
}

sComandos::sComandos(){

}

sCuriosity::sCuriosity()
{
    this->orientacion=0;
}

sCuriosity::sCuriosity(std::list<sComandos> comandos, std::list <sElemento> lista_elementos) {
    this->comandos = comandos;
    this->lista_elementos = lista_elementos;
}

std::list<sComandos> sCuriosity::getComandos()
{
    return this->comandos;
}

std::list<sElemento> sCuriosity::getlista_Elementos()
{
    return this->lista_elementos;
}

void sCuriosity::agregar_comandos(sComandos &comandos) {
    this->comandos.push_back(comandos);
}

void sCuriosity::agregar_elementos(sElemento &lista_elementos) {
    this->lista_elementos.push_back(lista_elementos);
}

void sCuriosity::cargar_comandos(std::string fileName) {
    int aux = countLines();
    int a=0;
    if (aux == 0) {
        std::cout << "No hay comandos en la lista" << std::endl;
    }
    if (aux == -1) {
        std::cout << "Error el archivo no se encuetra o no existe" << std::endl;
    } else {
        std::cout << "Se han cargado " << aux << " comandos desde " << fileName << std::endl;
        std::list<sComandos> lista_comandos = split(fileName, '|');
        for(sComandos t: lista_comandos)
        {
                agregar_comandos(t);
        }
    }
}

void sCuriosity::cargar_elementos(std::string fileName) {
    int aux = countLines();
    int a=0;
    std::string aux1;
    std::string aux2;
    std::string aux3;
    if (aux == 0) {
        std::cout << "No hay comandos en la lista" << std::endl;
    }
    if (aux == -1) {
        std::cout << "Error el archivo no se encuetra o no existe" << std::endl;
    } else {
        std::cout << "Se han cargado " << aux << " elemntos desde " << fileName << std::endl;
        std::list<sComandos> lista_elementos = split(fileName, '|');
        for(sComandos t: lista_elementos)
        {
            agregar_comandos(t);
        }
    }
}

void sCuriosity::guardar(std::string fileName, std::string tipo_archivo)
{
    std::string aux = fileName;
    std::fstream file;
    if (tipo_archivo == "comandos") {
        if (!comandos.empty()) {
            file.open(aux, std::ios::out | std::ios::app);
            if (file.is_open()) {
                file << "Movimientos" << std::endl;
                for (sComandos t: comandos) {
                    file << t.comando_movimiento.tipo_movimiento << " " << t.comando_movimiento.magnitud << " " << t.comando_movimiento.unidad_medida << std::endl;
                }
                file << "Analisis" << std::endl;
                for (sComandos t: comandos) {
                    file << t.comando_analisis.tipo_analisis << " " << t.comando_analisis.objeto << " " << t.comando_analisis.comentario << std::endl;
                }
                file.close();
                std::cout << "La informacion ha sido guardada exitosamente en " << aux << std::endl;
            } else {
                std::cout << "No se pudo abrir el archivo" << std::endl;
            }
        } else {
            std::cout << "No hay comandos para guardar" << std::endl;
        }
    }
    if (tipo_archivo == "elementos") {
        if (!lista_elementos.empty()) {
            file.open(aux, std::ios::out);
            if (file.is_open()) {
                for (sElemento t: lista_elementos) {
                    file << t.tipo_elemento << " " << t.tamaño << " " << t.unidad_medida << " " << t.coordenada_x << " " << t.coordenada_y << std::endl;
                }
                file.close();
                std::cout << "La informacion ha sido guardada exitosamente en " << aux << std::endl;
            } else {
                std::cout << "No se pudo abrir el archivo" << std::endl;
            }
        } else {
            std::cout << "No hay elementos para guardar" << std::endl;
        }
    }
}

void sCuriosity::setCoordenadas(float coordenada_x, float coordenada_y)
{
    this->coordenadas[0] = coordenada_x;
    this->coordenadas[1] = coordenada_y;
}

void sCuriosity::simular_comandos()
{
    for(auto it = this->comandos.begin();it!=this->comandos.end();it++){
        if(it->comando_movimiento != sComandos::sComando_movimientos()){
            if(it->comando_movimiento.tipo_movimiento == "avanzar"){
                if(it->comando_movimiento.unidad_medida == "metros"){
                    this->coordenadas[0] += it->comando_movimiento.magnitud * cos((this->orientacion*PI)/180);
                    this->coordenadas[0] = round(this->coordenadas[0] * 100) / 100;
                    this->coordenadas[1] += it->comando_movimiento.magnitud * sin(this->orientacion*PI/180);
                    this->coordenadas[1] = round(this->coordenadas[1] * 100) / 100;
                    std::cout << "Coordenadas actuales: " << this->coordenadas[0] << " " << this->coordenadas[1] << std::endl;
                }
            }
            else if(it->comando_movimiento.tipo_movimiento == "girar"){
                if(it->comando_movimiento.unidad_medida == "grados"){
                    this->orientacion += it->comando_movimiento.magnitud;
                    if(orientacion>360){
                        orientacion = orientacion - 360;
                    }
                    else if(orientacion<0){
                        orientacion = orientacion + 360;
                    }
                    this->orientacion = round(this->orientacion * 100) / 100;
                    std::cout << "Orientacion actual: " << this->orientacion << std::endl;
                }
            }
        }
        if(it->comando_analisis != sComandos::sComando_analisis()){
            if(it->comando_analisis.tipo_analisis == "tomar foto"){
                if(it->comando_analisis.objeto == "roca"){
                    for(auto it2 = this->lista_elementos.begin();it2!=this->lista_elementos.end();it2++){
                        if(it2->coordenada_x == this->coordenadas[0] && it2->coordenada_y == this->coordenadas[1]){
                            std::cout << "Elemento encontrado: " << it2->tipo_elemento << " " << it2->tamaño << " " << it2->unidad_medida << std::endl;
                        }
                    }
                }
            }
            if(it->comando_analisis.tipo_analisis == "perforar"){
                if(it->comando_analisis.objeto == "roca"){
                    for(auto it2 = this->lista_elementos.begin();it2!=this->lista_elementos.end();it2++){
                        if(it2->coordenada_x == this->coordenadas[0] && it2->coordenada_y == this->coordenadas[1]){
                            std::cout << "Elemento encontrado: " << it2->tipo_elemento << " " << it2->tamaño << " " << it2->unidad_medida << std::endl;
                        }
                    }
                }
            }
        }
    }
}

void sCuriosity::salir(bool &bandera) {
    bandera = false;
    std::cout << "Gracias por usar el programa" << std::endl;
}