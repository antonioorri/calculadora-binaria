#include "lista.h"
Nodo* CrearNodo(int t){
	Nodo* nodo= (Nodo *)malloc(sizeof(Nodo));
	nodo->tipo= t;
	nodo->siguiente = NULL;
	return nodo;
}
void DestruirNodo(Nodo* nodo){
	free(nodo);
}
void InsertarPrincipio(Lista* lista, int res,int format){
	Nodo* nodo= CrearNodo(format);
	nodo->siguiente = lista->cabeza;
	lista->cabeza = nodo;
	
	if(format==2 || format == 1){
		nodo->contenido.dato = res; // Asignamos un valor entero
		nodo->tipo=0;
	}else if (format==0){
		char * n_binary = entero_a_binario(res);
		strcpy(nodo->contenido.dato_binario, n_binary); // Asignamos un valor binario
		nodo->tipo=1;
	}
}
void InsertarPrincipio_Operacion(Lista* lista,char *operacion){
	Nodo* nodo= CrearNodo(2);	
	nodo->siguiente= lista->cabeza;
	lista->cabeza = nodo;
	nodo->tipo = 2; // Establecemos el tipo como operacion	
	strcpy(nodo->contenido.operacion, operacion); // Asignamos un valor binario
}

int EstaVacia(Lista* lista){
	return lista->cabeza== NULL;
}
void EliminarLista(Lista* lista){
	while(!EstaVacia(lista)){
		Nodo* eliminado= lista->cabeza;
		lista->cabeza=lista->cabeza->siguiente;
		DestruirNodo(eliminado);
	}
}
void imprimir_lista(Lista* lista) {
	if(!EstaVacia(lista)){
		Nodo *tmp = lista->cabeza;
    	while (tmp != NULL) {
        // Dependiendo del tipo de contenido, imprimimos de manera adecuada
        if (tmp->tipo == 0) {
            printf("%d \n", tmp->contenido.dato); // Imprimimos el dato como entero
        } else if (tmp->tipo == 1) {
            printf("%s \n", tmp->contenido.dato_binario); // Imprimimos el dato como cadena binaria
        } else if (tmp->tipo == 2) {
            printf("%s \n",tmp->contenido.operacion); // Imprimimos el dato como cadena de operación
        }
        tmp = tmp->siguiente;
    }
    printf("\n");
	}else{
		printf("Esta vacia\n");
	}
	
}

