#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <math.h>
#include <list>
#include <typeinfo>
#include <ctype.h>
#include "date.h"
#include "Curiosity.h"

int main()
{

    std::fstream file;
    bool bandera = true;
    sCuriosity Curiosity;
    while(bandera)
    {
        std::string comando_aux;
        std::cout << "$";
        std::getline(std::cin, comando_aux);
        std::vector<std::string> comandos = TokenizarEntradaUsuario(comando_aux);

        if(comandos.size() == 1)
        {
            if(comandos[0] == "ayuda_comando")
            {
                std::cout << "Los comandos disponibles son: " << std::endl;
                std::cout << "obtener_comandos" << std::endl;
                std::cout << "obtener_elementos" << std::endl;
                std::cout << "cargar_comandos" << std::endl;
                std::cout << "agregar_movimiento" << std::endl;
                std::cout << "agregar_analisis" << std::endl;
                std::cout << "cargar_elementos" << std::endl;
                std::cout << "agregar_elementos" << std::endl;
                std::cout << "simular_comandos" << std::endl;
                std::cout << "guardar" << std::endl;
                std::cout << "salir" << std::endl;
            }
            else if(comandos[0] == "salir")
            {
                Curiosity.salir(bandera);
            }
            else if(comandos[0] == "obtener_comandos")
            {
                std::list<sComandos> lista_comandos = Curiosity.getComandos();
                std::list<sComandos>::iterator it;
                for (it = lista_comandos.begin(); it != lista_comandos.end(); it++)
                {
                    std::cout << it->comando_movimiento.tipo_movimiento << " " << it->comando_movimiento.magnitud << " " << it->comando_movimiento.unidad_medida << std::endl;
                }
            }
            else if(comandos[0] == "obtener_elementos")
            {
                std::list<sElemento> lista_elementos = Curiosity.getlista_Elementos();
                std::list<sElemento>::iterator it;
                for (it = lista_elementos.begin(); it != lista_elementos.end(); it++)
                {
                    std::cout << it->tipo_elemento << " " << it->tamaño << " " << it->unidad_medida << " " << it->coordenada_x << " " << it->coordenada_y << std::endl;
                }
            }
            else{
                std::cout << "Comando no reconocido" << std::endl;
                std::cout << "Pruebe con ayuda_comando para ver los comandos disponibles" << std::endl;
            }
        }

        else if(comandos.size() == 2)
        {
            if(comandos[0] == "cargar_comandos")
            {
                Curiosity.cargar_comandos(comandos[1]);
            }
            else if(comandos[0] == "cargar_elementos")
            {
                Curiosity.cargar_elementos(comandos[1]);
            }
            else{
                std::cout << "Comando no reconocido" << std::endl;
                std::cout << "Pruebe con ayuda_comando para ver los comandos disponibles" << std::endl;
            }
        }

        else if(comandos.size() == 3)
        {
            if(comandos[0] == "agregar_analisis")
            {
                sComandos a = sComandos();
                if(comandos[1] == "fotografiar" || comandos[1] == "composicion" || comandos[1] == "perforar")
                {
                    a.comando_analisis.tipo_analisis = comandos[1];
                }
                else
                {
                    std::cout << "El tipo de analisis no es valido" << std::endl;
                    continue;
                }
                a.comando_analisis.objeto = comandos[2];
                a.comando_analisis.comentario = "";
                Curiosity.agregar_comandos(a);
            }
            else if(comandos[0] == "guardar")
            {
                size_t pos = comandos[2].find(".txt");
                if(pos == std::string::npos)
                {
                    comandos[2] += ".txt";
                }
                Curiosity.guardar(comandos[2], comandos[1]);
            }
            else if(comandos[0] == "simular_comandos")
            {
                
                Curiosity.setCoordenadas(std::stoi(comandos[1]), std::stoi(comandos[2]));
                Curiosity.simular_comandos();
            }
            else{
                std::cout << "Comando no reconocido" << std::endl;
                std::cout << "Pruebe con ayuda_comando para ver los comandos disponibles" << std::endl;
            }
        }

        else if(comandos.size() == 4)
        {
            if(comandos[0] == "agregar_movimiento")
            {
                sComandos a = sComandos();
                if(comandos[1] == "avanzar" || comandos[1] == "girar")
                {
                    a.comando_movimiento.tipo_movimiento = comandos[1];
                }
                else
                {
                    std::cout << "El tipo de movimiento no es valido" << std::endl;
                    continue;
                }
                for (auto& c: comandos[2])
                {
                    if (!isdigit(c))
                    {
                        std::cout << "La magnitud no es valida" << std::endl;
                        continue;
                    }
                }
                a.comando_movimiento.magnitud = std::stoi(comandos[2]);
                if((comandos[3] == "grados" && comandos[1] == "girar") || (comandos[3] == "metros" && comandos[1] == "avanzar"))
                {
                    a.comando_movimiento.unidad_medida = comandos[3];
                }
                else
                {
                    std::cout << "La unidad de medida no es valida" << std::endl;
                    continue;
                }
                Curiosity.agregar_comandos(a);
            }
            else if(comandos[0] == "agregar_analisis")
            {
                sComandos a = sComandos();
                if(comandos[1] == "fotografiar" || comandos[1] == "composicion" || comandos[1] == "perforar")
                {
                    a.comando_analisis.tipo_analisis = comandos[1];
                }
                else
                {
                    std::cout << "El tipo de analisis no es valido" << std::endl;
                    continue;
                }
                a.comando_analisis.objeto = comandos[2];
                a.comando_analisis.comentario = comandos[3];
                Curiosity.agregar_comandos(a);
            }
            else{
                std::cout << "Comando no reconocido" << std::endl;
                std::cout << "Pruebe con ayuda_comando para ver los comandos disponibles" << std::endl;
            }
        }

        else if(comandos.size() == 6)
        {
            if(comandos[0] == "agregar_elementos")
            {
                sElemento a = sElemento();
                // El tipo de componente puede ser uno entre roca, crater, monticulo o duna.
                if(comandos[1] == "roca" || comandos[1] == "crater" || comandos[1] == "monticulo" || comandos[1] == "duna")
                {
                    a.tipo_elemento = comandos[1];
                }
                else
                {
                    std::cout << "El tipo de elemento no es valido" << std::endl;
                    continue;
                }
                for (auto& c: comandos[2])
                {
                    if (!isdigit(c))
                    {
                        std::cout << "El tamaño no es valido" << std::endl;
                        continue;
                    }
                }
                a.tamaño = std::stoi(comandos[2]);
                if(comandos[3] == "metros")
                {
                    a.unidad_medida = comandos[3];
                }
                else
                {
                    std::cout << "La unidad de medida no es valida" << std::endl;
                    continue;
                }
                for (auto& c: comandos[4])
                {
                    if (!isdigit(c))
                    {
                        std::cout << "La coordenada x no es valida" << std::endl;
                        continue;
                    }
                }
                a.coordenada_x = std::stoi(comandos[4]);
                for (auto& c: comandos[5])
                {
                    if (!isdigit(c))
                    {
                        std::cout << "La coordenada y no es valida" << std::endl;
                        continue;
                    }
                }
                a.coordenada_y = std::stoi(comandos[5]);
                Curiosity.agregar_elementos(a);
            }
            else{
                std::cout << "Comando no reconocido" << std::endl;
                std::cout << "Pruebe con ayuda_comando para ver los comandos disponibles" << std::endl;
            }
        }

        else
        {
            std::cout << "Comando no reconocido" << std::endl;
            std::cout << "Pruebe con ayuda_comando para ver los comandos disponibles" << std::endl;
        }
    }
    return 0;
}
