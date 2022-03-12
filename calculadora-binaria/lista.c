#include <stdio.h>


typedef struct Lista{
    Nodo * cabeza;
    int n_nodos;
}Lista;

Nodo * CrearNodo(Nodo * new_node){
    Nodo* nodo= (Nodo *)malloc(sizeof(Nodo));
    nodo->op1 =new_node->op1;
    nodo->op2 =new_node->op2;
    nodo->res =new_node->res;
    strcpy(nodo->operacion,new_node->operacion);
    nodo->siguiente=NULL;
    return nodo;
}
int EstaVacia(Lista *lista){
    return lista->cabeza ==NULL;
}

void DestruirNodo(Nodo* nodo){
    free(nodo);
}

void Insertar_Nodo(Lista * lista,Nodo * new_node){
    Nodo * nodo=CrearNodo(new_node);
    if(lista->cabeza== NULL)
        lista->cabeza=nodo;
    else{
        Nodo* puntero = lista->cabeza;
        while(puntero->siguiente){
            puntero=puntero->siguiente;
        }
        puntero->siguiente=nodo;
    }
    lista->n_nodos++;
    printf("Se ha insertado el nodo\n");
}

void mostrar_lista(Lista * lista){
    Nodo *aux=lista->cabeza;
    while(aux->siguiente){
        printf("%d %s %d = %d\n",aux->op1,aux->operacion,aux->op2,aux->res);
        aux= aux->siguiente;
    }
    DestruirNodo(aux);
}

void borrar_lista(Lista *lista){
    Nodo * aux=NULL;
    while(lista->cabeza){
         aux= lista->cabeza;
        lista->cabeza=lista->cabeza->siguiente;
        DestruirNodo(aux);
    }
}
