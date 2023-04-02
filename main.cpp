#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;


/* TALLER-03

Nombre: Tomas De Aza Marquez, Mauricio Rodriguez Cordoba
Fecha: 02/04/2023
Solucion: Se hace la lectura del archivo que contiene los procesos a realizar, se crea un arbol AVL que permite tener ejecutar los procesos del .TXT, manteniendo sus especificaciones como arbol balanceado.

*/

// Definimos la estructura "Lectura" con dos miembros: "accion" de tipo string y "valor" de tipo entero
struct Lectura
{
  string accion;
  int valor;
};

// Función para tokenizar un archivo de texto y almacenar los tokens en una lista de tipo "Lectura"
void tokenizarArchivo(string nombreArchivo, list<Lectura> & aux) {
  ifstream archivo(nombreArchivo);
  string linea;
  int auxiliar=0;
  bool bandera = false;
  Lectura e;
  while (getline(archivo, linea)) {
    istringstream iss(linea);
    string token;
    while (iss >> token) {
      if(auxiliar == 0)
      {
        e.accion= token;
        bandera=false;
      }
      if(auxiliar == 1)
      {
        e.valor = stoi(token);
        aux.push_back(e);
        auxiliar=0;
        bandera = true;
      }
      if(bandera == false)
      {
        auxiliar++;
      }
        
    }
  }
}

// Clase "Node" que define un nodo de un árbol AVL
class Node {
  public:
    int data;
    Node *left, *right;
    int height;

Node(){}

// Función que devuelve la altura de un arbol
int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return node->height;
    }
}

// Función que devuelve el factor de balance de un nodo
int getBalanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return getHeight(node->left) - getHeight(node->right);
    }
}

// Función que realiza una rotación a la derecha sobre un nodo
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Función que realiza una rotación a la izquierda sobre un nodo
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

//Se encarga de insertar un nodo en el árbol AVL
Node* insertNode(Node* node, int data) {
    if (node == NULL) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    } else if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && data < node->left->data) {
        return rightRotate(node);
    } else if (balanceFactor > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    } else if (balanceFactor < -1 && data > node->right->data) {
        return leftRotate(node);
    } else if (balanceFactor < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

//Que se encarga de eliminar un nodo del árbol AVL. Ambos métodos(Delete e Insert) utilizan las rotaciones y la función getBalanceFactor para mantener el balance del árbol.
Node* deleteNode(Node* node, int data) {
    if (node == NULL) {
        return node;
    } else if (data < node->data) {
        node->left = deleteNode(node->left, data);
    } else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    } else {
        if (node->left == NULL || node->right == NULL) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            Node* temp = minValueNode(node->right);

            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
        }
    }

    if (node == NULL) {
        return node;
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
        return rightRotate(node);
    } else if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    } else if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
        return leftRotate(node);
    } else if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

//Recorre el árbol AVL en orden ascendente y muestra el valor de cada nodo.
void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}
};

int main() 
{
  list<Lectura> aux;
  Node* node = new Node();
  tokenizarArchivo("entrada.txt", aux);
  for (auto x : aux)
    {
      if(x.accion == "A")
      {
        node->insertNode(node, x.valor);
      }
      if(x.accion == "E")
      {
        node->deleteNode(node, x.valor);
      }
    }
  node->inorderTraversal(node);
}
