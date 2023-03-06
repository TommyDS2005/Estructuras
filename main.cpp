#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <math.h>
#include <list>
#include "date.h"
#include "Curiosity.h"

int main()
{

    std::fstream file;
    bool bandera = true;
    file.open("Comandos.txt", std::ios::out);
    file << "";
    file.close();
    sCuriosity Curiosity;
    std::cout << "$Bienvenido a la consola de comandos" << std::endl;
    while(bandera)
    {
        std::string comando;
        std::string comando_aux = "";
        std::cout << "$Escriba el comando que desee o escriba ayuda|comando para ver los comandos disponibles" << std::endl;
        std::cout << "$";
        std::getline(std::cin, comando);
        std::stringstream ss(comando); // Turn the string into a stream.
        std::string tok;
        while (getline(ss, tok, '|')) {
            comando_aux = comando_aux + " _" + tok;
        }
        if(comando_aux == " ayuda_comando")
        {
            std::cout << "Los comandos disponibles son: " << std::endl;
            std::cout << "obtener|comandos" << std::endl;
            std::cout << "obtener|elementos" << std::endl;
            std::cout << "cargar|comandos" << std::endl;
            std::cout << "agregar|comandos" << std::endl;
            std::cout << "cargar|elementos" << std::endl;
            std::cout << "agregar|elementos" << std::endl;
            std::cout << "set|orientacion" << std::endl;
            std::cout << "simular|comandos" << std::endl;
            std::cout << "set|coordenadas" << std::endl;
            std::cout << "guardar" << std::endl;
            std::cout << "salir" << std::endl;
        }
        if(comando_aux == "obtener_comandos")
        {
            std::list<sComandos> lista_comandos = Curiosity.getComandos();
            std::list<sComandos>::iterator it;
            for (it = lista_comandos.begin(); it != lista_comandos.end(); it++)
            {
                std::cout << it->comando_movimiento.tipo_movimiento << " " << it->comando_movimiento.magnitud << " " << it->comando_movimiento.unidad_medida << std::endl;
            }
        }
        if(comando_aux == "obtener_elementos")
        {
            std::list<sElemento> lista_elementos = Curiosity.getlista_Elementos();
            std::list<sElemento>::iterator it;
            for (it = lista_elementos.begin(); it != lista_elementos.end(); it++)
            {
                std::cout << it->tipo_elemento << " " << it->tamaño << " " << it->unidad_medida << " " << it->coordenada_x << " " << it->coordenada_y << std::endl;
            }
        }
        if(comando_aux == "cargar_comandos")
        {
            std::string filename;
            std::cout << "Ingrese el nombre del archivo que desea cargar" << std::endl;
            std::getline(std::cin, filename);
            Curiosity.cargar_comandos(filename);
        }
        if(comando_aux == "agregar_comandos")
        {
            sComandos a = sComandos();
            std::cout << "Es de movimiento o de analisis?\n 0. Movimiento\n 1. Analisis" << std::endl;
            int tipo;
            std::cin >> tipo;
            std::cin.ignore();
            if(tipo == 0)
            {
                std::cout << "Ingrese el tipo de movimiento" << std::endl;
                std::string tipo_movimiento;
                std::getline(std::cin, tipo_movimiento);
                std::cout << "Ingrese la magnitud" << std::endl;
                int magnitud;
                std::cin >> magnitud;
                std::cin.ignore();
                std::cout << "Ingrese la unidad de medida" << std::endl;
                std::string unidad_medida;
                std::getline(std::cin, unidad_medida);
                a.comando_movimiento.tipo_movimiento = tipo_movimiento;
                a.comando_movimiento.magnitud = magnitud;
                a.comando_movimiento.unidad_medida = unidad_medida;
                Curiosity.agregar_comandos(a);
            }
            else
            {
                std::cout << "Ingrese el tipo de analisis" << std::endl;
                std::string tipo_analisis;
                std::getline(std::cin, tipo_analisis);
                std::cout << "Ingrese el objeto" << std::endl;
                int magnitud;
                std::cin >> magnitud;
                std::cin.ignore();
                std::cout << "Ingrese el comentario" << std::endl;
                std::string unidad_medida;
                std::getline(std::cin, unidad_medida);
                a.comando_analisis.tipo_analisis = tipo_analisis;
                a.comando_analisis.objeto = magnitud;
                a.comando_analisis.comentario = unidad_medida;
                Curiosity.agregar_comandos(a);
            }
        }
        if(comando_aux == "cargar_elementos")
        {
            std::string filename;
            std::cout << "Ingrese el nombre del archivo que desea cargar" << std::endl;
            std::getline(std::cin, filename);
            Curiosity.cargar_elementos(filename);
        }
        if(comando_aux == "agregar_elementos")
        {
            sElemento a = sElemento();
            std::cout << "Ingrese el tipo de elemento" << std::endl;
            std::string tipo_elemento;
            std::getline(std::cin, tipo_elemento);
            std::cout << "Ingrese el tamaño" << std::endl;
            int tamaño;
            std::cin >> tamaño;
            std::cin.ignore();
            std::cout << "Ingrese la unidad de medida" << std::endl;
            std::string unidad_medida;
            std::getline(std::cin, unidad_medida);
            std::cout << "Ingrese la coordenada x" << std::endl;
            int coordenada_x;
            std::cin >> coordenada_x;
            std::cin.ignore();
            std::cout << "Ingrese la coordenada y" << std::endl;
            int coordenada_y;
            std::cin >> coordenada_y;
            std::cin.ignore();
            a.tipo_elemento = tipo_elemento;
            a.tamaño = tamaño;
            a.unidad_medida = unidad_medida;
            a.coordenada_x = coordenada_x;
            a.coordenada_y = coordenada_y;
            Curiosity.agregar_elementos(a);
        }
        if(comando_aux == "set_orientacion")
        {
            std::cout << "Ingrese la orientacion" << std::endl;
            std::string orientacion;
            std::getline(std::cin, orientacion);
            Curiosity.setOrientacion(stoi(orientacion));
        }
        if(comando_aux == "simular_comandos")
        {
            Curiosity.simular_comandos();
        }
        if(comando_aux == "set_coordenadas")
        {
            std::cout << "Ingrese la coordenada x" << std::endl;
            int coordenada_x;
            std::cin >> coordenada_x;
            std::cin.ignore();
            std::cout << "Ingrese la coordenada y" << std::endl;
            int coordenada_y;
            std::cin >> coordenada_y;
            std::cin.ignore();
            Curiosity.setCoordenadas(coordenada_x, coordenada_y);
        }
        if(comando_aux == "guardar")
        {
            std::string filename;
            std::cout << "Ingrese el nombre del archivo que desea guardar" << std::endl;
            std::getline(std::cin, filename);
            std::cout << "Que tipo de archivo desea guardar?\nComandos\nElementos" << std::endl;
            std::string tipo;
            Curiosity.guardar(filename, tipo);
        }
        if(comando_aux == "salir")
        {
            Curiosity.salir(bandera);
        }
    }
    return 0;
}
