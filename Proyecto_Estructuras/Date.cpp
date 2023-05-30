#include <sstream>
#include "Date.h"

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

std::vector<Point> puntoMaxyMin(std::list<sElemento> internal)
{
    std::vector<Point> puntos;
    std::vector<float> x;
    std::vector<float> y;
    for (auto& t: internal)
    {
        x.push_back(t.coordenada_x);
        y.push_back(t.coordenada_y);
    }
    float max_x = x[0];
    float max_y = y[0];
    float min_x = x[0];
    float min_y = y[0];
    for(int i = 1; i < x.size(); i++)
    {
        if(x[i] > max_x)
        {
            max_x = x[i]; // actualizar el valor máximo si encontramos un elemento más grande
        }
        if(y[i] > max_y)
        {
            max_y = y[i]; // actualizar el valor máximo si encontramos un elemento más grande
        }
        if(x[i] < min_x)
        {
            min_x = x[i]; // actualizar el valor máximo si encontramos un elemento más grande
        }
        if(y[i] < min_y)
        {
            min_y = y[i]; // actualizar el valor máximo si encontramos un elemento más grande
        }
    }
    puntos.push_back(Point(min_x, max_y));
    puntos.push_back(Point(max_x, min_y));
    return puntos;
}

