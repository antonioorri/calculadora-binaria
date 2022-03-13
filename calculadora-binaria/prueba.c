#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{

    union un{
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
Nodo * CrearNodo_1(int  d){
    Nodo* nodo= (Nodo *)malloc(sizeof(Nodo));
    printf("-------------------------\n");
    nodo->op.dato=5;
    nodo->siguiente=NULL;
    //printf("---SE HA INSERTADO UN NODO CON DATO %s\n",nodo->op.dato);
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
    
    if(lista->cabeza== NULL){
        lista->cabeza= new_node;
        lista->n_nodos=1;
    }else{
        Nodo* puntero = lista->cabeza;
        while(puntero->siguiente){
            puntero=puntero->siguiente;
        }
        puntero->siguiente=new_node;
        lista->n_nodos++;
    }
    
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

void DecToBin(int num,char * res){

    //char res2[20];
    int i=0;
    int x = num;

    while(x>0){
        x=x/2;
        i++;
    }
    printf("%d\n",i);
    res[i]='\0';
    while(i>0){

        res[i-1]= (num%2) + '0';
        printf("%c",res[i]);
        num=num/2;
        i--;
    }
    //printf("%s\n",res2);
    //strcpy(res,res2);
}
int binToDecima( char * num){
    char * t;
    return strtol(num,&t,2);
}



int main(){

/* PRUEBA DE BINARIO  A DECIMAL
    char xy[32]="";
    DecToBin(1234,xy);
    printf("res: %s",xy);
*/

//PRUEBA DE LISTA

Lista * l=NULL;
l=(Lista * )malloc(sizeof(Lista));
char x[10];
char pr[9]="hola";
int n=10;
Nodo * n1;
Nodo* n2;
DecToBin(n,x);
n1 = CrearNodo_2(pr);
n2= CrearNodo_1(n);
if(n2->op.dato)printf("Prueba\n");
if(n1->op.dato)printf("Prueba\n");
Insertar_Nodo(l,n1);
//Insertar_Nodo(l,n2);
//Insertar_Nodo(l,n3);
mostrar_lista(l);
Insertar_Nodo(l,n2);
mostrar_lista(l);


}
