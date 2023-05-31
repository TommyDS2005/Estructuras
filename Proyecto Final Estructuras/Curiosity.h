//
// Created by TOMAS on 5/03/2023.
//
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <list>
#include <cstring>
#include "Date.h"
#define PI 3.14159265359
#ifndef PROYECTO_ESTRUCTURAS_CURIOSITY_H
#define PROYECTO_ESTRUCTURAS_CURIOSITY_H
struct sComandos
{
    sComandos();
    struct sComando_movimientos {
        std::string tipo_movimiento;
        float magnitud;
        std::string unidad_medida;
        bool operator != (const sComando_movimientos &comandoMovimientos) const {
            return (tipo_movimiento != comandoMovimientos.tipo_movimiento) || (magnitud != comandoMovimientos.magnitud) || (unidad_medida != comandoMovimientos.unidad_medida);
        }
    };
    sComando_movimientos comando_movimiento;
    sComandos(std::string tipo_movimiento, float magnitud, std::string unidad_medida);
    struct sComando_analisis {
        std::string tipo_analisis;
        std::string objeto;
        std::string comentario;
        bool operator != (const sComando_analisis &comandoAnalisis) const {
            return (tipo_analisis != comandoAnalisis.tipo_analisis) || (objeto != comandoAnalisis.objeto) || (comentario != comandoAnalisis.comentario);
        }
    };
    sComando_analisis comando_analisis;
    sComandos(std::string tipo_analisis, std::string objeto, std::string comentario);
    bool operator != (const sComandos &comando) const {
        return (comando_movimiento != comando.comando_movimiento) || (comando_analisis != comando.comando_analisis);
    }
};
struct sElemento {
    std::string tipo_elemento;
    float tamaño;
    std::string unidad_medida;
    float coordenada_x;
    float coordenada_y;

    bool operator != (const sElemento &elemento) const {
        return (tipo_elemento != elemento.tipo_elemento) || (tamaño != elemento.tamaño) || (unidad_medida != elemento.unidad_medida) || (coordenada_x != elemento.coordenada_x) || (coordenada_y != elemento.coordenada_y);
    }
};

class sCuriosity {
public:
    std::list<sComandos> comandos;
    std::list<sElemento> lista_elementos;
    float orientacion;
    float coordenadas[2] = {0,0};
    sCuriosity();
    sCuriosity(std::list<sComandos> comandos, std::list<sElemento> lista_elementos);
    std::list<sComandos> getComandos();
    std::list<sElemento> getlista_Elementos();
    void cargar_comandos(std::string fileName);
    void agregar_comandos(sComandos &comandos);
    void cargar_elementos(std::string fileName);
    void agregar_elementos(sElemento &lista_elementos);
    [[maybe_unused]] void setOrientacion(float orientacion);
    void simular_comandos(float coordenada_x, float coordenada_y);
    [[maybe_unused]] void setCoordenadas(float coordenada_x, float coordenada_y);
    void guardar(std::string fileName, std::string tipo_archivo);
    void salir(bool &bandera);
};



#endif //PROYECTO_ESTRUCTURAS_CURIOSITY_H
