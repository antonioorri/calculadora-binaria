#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct Nodo {
    union {
        int dato;
        char dato_binario[9];
        char operacion[10];
    } contenido;
    int tipo; // Para indicar el tipo de contenido: 0 = entero, 1 = binario, 2 = operación
    struct Nodo *siguiente;
} Nodo;

typedef struct Lista{
	Nodo* cabeza;
}Lista;

#include "operaciones.h"


Nodo* CrearNodo(int t);
void DestruirNodo(Nodo* nodo);
void InsertarPrincipio(Lista* lista, int res,int format);
void InsertarPrincipio_Operacion(Lista* lista,char *operacion);
int EstaVacia(Lista* lista);
void EliminarLista(Lista* lista);
void imprimir_lista(Lista* lista);

#endif // LISTA_H
