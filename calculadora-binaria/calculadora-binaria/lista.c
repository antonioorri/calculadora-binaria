
#include "lista.h"

Nodo * CrearNodo_1(int d){
    Nodo* nodo= (Nodo *)malloc(sizeof(Nodo));
    nodo->op.dato=d;
    nodo->siguiente=NULL;
    printf("---SE HA INSERTADO UN NODO CON DATO %s\n",nodo->op.dato);
    return nodo;
}
Nodo * CrearNodo_2(char * binario){
    Nodo* nodo= (Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->op.dato_binario,binario);
    nodo->siguiente=NULL;
    return nodo;
}
Nodo * CrearNodo_3(char * operacion){
    Nodo* nodo= (Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->op.operacion,operacion);
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
    
    if(lista->cabeza== NULL)
        lista->cabeza= new_node;
    else{
        Nodo* puntero = lista->cabeza;
        while(puntero->siguiente){
            puntero=puntero->siguiente;
        }
        puntero->siguiente=new_node;
    }
    lista->n_nodos++;
    printf("Se ha insertado el nodo %d\n",lista->n_nodos);
    printf("hay %d Nodos\n",lista->n_nodos);
}

void mostrar_lista(Lista * lista){
    if(!EstaVacia(lista)){
        Nodo *aux=lista->cabeza;
        int nodos= lista->n_nodos;

        for(int i = 0;i<nodos;i++){
            printf("------------------------------\n");
            printf("elemento %d : %s\n",i+1,aux->op.dato_binario);
            aux= aux->siguiente;
        }
        printf("------------------------------\n");
        DestruirNodo(aux);
    }else{
        printf("------------------------------\n");
        printf("Esta vacia\n");
        printf("------------------------------\n");
    }
    
}

void borrar_lista(Lista *lista){
    Nodo * aux=NULL;
    while(lista->cabeza){
         aux= lista->cabeza;
        lista->cabeza=lista->cabeza->siguiente;
        DestruirNodo(aux);
    }
}

