#include <stdio.h>
#include <string.h>
#include<stdlib.h>


typedef struct node{

    union {
    int dato; // operando o resultado para hexadecimal
    char dato_binario[9];
     //cadena para almacenar el operando/resultado  //binario
    char operacion[10]; // cadena descriptiva de la operacion  } contenido;
    }op;
    void * siguiente;
}Nodo;

typedef struct Lista{
    Nodo * cabeza;
    int n_nodos;
}Lista;

Nodo * CrearNodo_1(int d);
Nodo * CrearNodo_2(char * binario);
Nodo * CrearNodo_3(char * operacion);
int EstaVacia(Lista *lista);
void DestruirNodo(Nodo* nodo);
void Insertar_Nodo(Lista * lista,Nodo * new_node);
void mostrar_lista(Lista * lista);
void borrar_lista(Lista *lista);



