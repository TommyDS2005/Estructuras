#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <set>
#include <map>
#include "functions.h"
#include <filesystem>



int main() {

    std::vector<JaveMusic> javeMusic;
    guardar_datos("example1.txt", javeMusic);
    guardar_datos("example2.txt", javeMusic);
    guardar_datos("example3.txt", javeMusic);
    guardar_datos("example4.txt", javeMusic);
    guardar_datos("example5.txt", javeMusic);

    while(true) {
        int condition;
        std::cout << "Ingrese: " << std::endl;
        std::cout << "1. --Listar todos los autores presentes, ordenados alfabeticamente" << std::endl;
        std::cout << "2. --Dado un autor, listar todas sus canciones ordenadas alfabeticamente." << std::endl;
        std::cout << "3. --Listar todos los albumes presentes, ordenados cronologicamente." << std::endl;
        std::cout << "4. --Dado un album, listar todas las canciones que componen un album, ordenadas alfabeticamente por el nombre de la cancion." << std::endl;
        std::cout << "5. --Listar todas las canciones y su album, ordenadas alfabeticamente primero por el album y despues por el nombre de la cancion." << std::endl;
        std::cout << "6. --Salir" << std::endl;
        std::cin >> condition;
        switch (condition) {
            case 1: {
                imprimir_por_autor_alfabeticamente(javeMusic);
            }
            break;
            case 2: {
                imprimir_las_canciones_de_un_autor_alfabeticamente(javeMusic);
            }
            break;
            case 3:
            {
                imprimir_albumes_cronologicamente(javeMusic);
            }
            break;
            case 4:
            {
                imprimir_canciones_de_un_album_alfabeticamente(javeMusic);
            }
            break;
            case 5:
            {
                imprimir_las_canciones_alfabeticamente_por_album_y_por_cancion(javeMusic);
            }
            break;
            case 6:
            {
                return 0;
            }
        }
    }
}
