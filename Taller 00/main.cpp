#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar números aleatorios entre 0 y 25
int generarAleatorio() {
    return rand() % 26;
}

int main() {
    // Crear un array con 10 elementos
    int array[10];

    // Semilla para la función rand()
    srand(time(0));

    // Llenar el array con 10 números aleatorios
    for (int i = 0; i < 10; i++) {
        array[i] = generarAleatorio();
    }

    // Crear un puntero
    int *puntero = array;

    // Imprimir el contenido del array usando el puntero
    cout << "Contenido del array:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << *(puntero + i) << " ";
    }
    cout << endl;

    // Imprimir las direcciones del contenido del array usando el puntero
    cout << "Direcciones del contenido del array:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << puntero + i << " ";
    }
    cout << endl;

    return 0;
}