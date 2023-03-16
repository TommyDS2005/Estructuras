#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estructura de datos para los clientes
struct Cliente {
    string nombre;
    string direccion;
    string ciudad;
    string estado;
    string codigoPostal;
    string numeroTelefono;
};

// Función para imprimir la factura de un cliente en un fichero de texto
void imprimirFactura(Cliente* cliente, float total) {
    ofstream fichero;
    fichero.open("factura.txt");
    fichero << "Factura para " << cliente->nombre << endl;
    fichero << "Dirección: " << cliente->direccion << ", " << cliente->ciudad << ", " << cliente->estado << ", " << cliente->codigoPostal << endl;
    fichero << "Número de teléfono: " << cliente->numeroTelefono << endl;
    fichero << "Total a pagar: $" << total << endl;
    fichero.close();
}

int main() {
    // Crear un cliente y asignarle valores
    Cliente cliente1;
    cliente1.nombre = "Juan Pérez";
    cliente1.direccion = "Calle 1 #123";
    cliente1.ciudad = "Ciudad de México";
    cliente1.estado = "Ciudad de México";
    cliente1.codigoPostal = "01234";
    cliente1.numeroTelefono = "555-1234";

    // Calcular el total de la factura
    float total = 100.50;

    // Imprimir la factura del cliente1
    imprimirFactura(&cliente1, total);

    return 0;
}