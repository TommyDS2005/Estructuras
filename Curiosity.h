//
// Created by TOMAS on 5/03/2023.
//
#include "date.h"
#ifndef PROYECTO_ESTRUCTURAS_CURIOSITY_H
#define PROYECTO_ESTRUCTURAS_CURIOSITY_H
struct sComandos
{
    sComandos();
    struct sComando_movimientos {
        std::string tipo_movimiento;
        float magnitud;
        std::string unidad_medida;
        bool operator != (const sComando_movimientos &comando_movimiento) const {
            return (tipo_movimiento != comando_movimiento.tipo_movimiento) || (magnitud != comando_movimiento.magnitud) || (unidad_medida != comando_movimiento.unidad_medida);
        }
    };
    sComando_movimientos comando_movimiento;
    sComandos(std::string tipo_movimiento, float magnitud, std::string unidad_medida);
    struct sComando_analisis {
        std::string tipo_analisis;
        std::string objeto;
        std::string comentario;
        bool operator != (const sComando_analisis &comando_analisis) const {
            return (tipo_analisis != comando_analisis.tipo_analisis) || (objeto != comando_analisis.objeto) || (comentario != comando_analisis.comentario);
        }
    };
    sComando_analisis comando_analisis;
    sComandos(std::string tipo_analisis, std::string objeto, std::string comentario);
};
struct sElemento {
    std::string tipo_elemento;
    float tamaño;
    std::string unidad_medida;
    float coordenada_x;
    float coordenada_y;
};

class sCuriosity {
private:
    std::list<sComandos> comandos;
    std::list<sElemento> lista_elementos;
    float orientacion;
    float coordenadas[2] = {0,0};
public:
    sCuriosity();
    sCuriosity(std::list<sComandos> comandos, std::list<sElemento> lista_elementos);
    std::list<sComandos> getComandos();
    std::list<sElemento> getlista_Elementos();
    void cargar_comandos(std::string fileName);
    void agregar_comandos(sComandos &comandos);
    void cargar_elementos(std::string fileName);
    void agregar_elementos(sElemento &lista_elementos);
    void setOrientacion(float orientacion);
    void simular_comandos();
    void setComandos(std::list<sComandos> comandos);
    void setlista_Elementos(std::list<sElemento> lista_elementos);
    void setCoordenadas(float coordenada_x, float coordenada_y);
    void guardar(std::string fileName, std::string tipo_archivo);
    void salir(bool &bandera);
};



#endif //PROYECTO_ESTRUCTURAS_CURIOSITY_H
