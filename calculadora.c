#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
#define MIN 0




typedef struct Nodo{

    int op1,op2,res;
    char operacion[5];
    struct Nodo * siguiente;
}Nodo;

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
        printf("%d %s %d = %d\n",aux->op1,*aux->operacion,aux->op2,aux->res);
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



void mostrar_menu1(){
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Seleccione una operacion.\n");
	printf("1.-OR lógico\n");
	printf("2.-AND lógico\n");
	printf("3.-XOR lógico\n");
	printf("4.-<<(desplazamiento a la izquierda)\n");
	printf("5.->>(desplazamiento a la derecha)\n");
}
void mostrar_menu2(){
	printf("6.Cambio de formato (0->binario, 1->hexadecimal). Una vez seleccionado un formato determinado, los operandos se interpretarán en ese nuevo formato, al igual que los resulatados.\n");
	printf("7.-Habilitar memoria.\n");
	printf("8.-Deshabilitar memoria.\n");
	printf("9.-Borrar memoria.\n");
	printf("10.-Mostrar el contenido de la memoria.\n");
	printf("0.-SALIR\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
}

int binario_decimal(int x){
    int i=0;
    int res=0;
    while(x>0){
        res+=(x%2) * pow(2,i);
        x=x/10;
        i++;
    }
    return res;
}

int decimal_binario(int x){
    if(x==0)return x;
    else return decimal_binario(x/2) * 10 + x%2;
}

void leer_operandos(int *n1, int *n2){
    printf("Introduzca operando 1: \n");
    scanf("%d",n1);
  //  printf("%d\n",*n1);
    printf("Introduzca operando 2: \n");
    scanf("%d",n2);
  //  printf("%d\n",*n2);
}

void leer_operandos_x(int *n1, int *n2){
    printf("Introduzca operando 1: \n");
    scanf("%x",n1);
  //  printf("%d\n",*n1);
    printf("Introduzca operando 2: \n");
    scanf("%x",n2);
  //  printf("%d\n",*n2);
}


void calculadora_1(int seleccionado, int x, int y, int  res,Lista * l,int m){

    switch(seleccionado){
			case 1:
			  //  printf("%d\n",y);printf("%d\n",x);
			    res= (x | y);
                printf("%d OR %d = %d .\n",x,y,res);
			break;
			case 2:
                res= x & y;
                printf("%d AND %d = %d.\n",x,y,res);
            break;
			case 3:
			    res= x ^ y;
                printf("%d XOR %d = %d.\n",x,y,res);

			break;
			case 4:
                res= x << y;
                printf("%d << %d = %d.\n",x,y,res);
			break;
			case 5:
                res= x >> y;
                printf("%d >> %d = %d.\n",x,y,res);
			break;

			default:
				seleccionado =  0;
				printf("Hasta pronto :).\n");
			break;
		}
		if(m && seleccionado){
                Nodo *n;
                n->op1=x;
                n->op2=y;
                n->res=res;
                if(seleccionado==1)
                    strcpy(n->operacion,"OR");
                if(seleccionado==2)
                    strcpy(n->operacion,"AND");
                if(seleccionado==3)
                    strcpy(n->operacion,"XOR");
                if(seleccionado==4)
                    strcpy(n->operacion,"<<");
                else strcpy(n->operacion,">>");

                Insertar_Nodo(l,n);
		}
}


void calculadora_2(int seleccionado, int x, int y, int  res,Lista * l,int m){

    int n1=binario_decimal(x);
    int n2=binario_decimal(y);
    switch(seleccionado){
			case 1:
			  //  printf("%d\n",y);printf("%d\n",x);
			    res= (n1 | n2);
			    res=decimal_binario(res);
                printf("0b%d OR 0b%d = 0b%d .\n",x,y,res);
			break;
			case 2:
                res= n1 & n2;
                res=decimal_binario(res);
                printf("0b%d AND 0b%d = 0b%d.\n",x,y,res);
            break;
			case 3:
			    res= n1 ^ n2;
			    res=decimal_binario(res);
                printf("0b%d XOR 0b%d = 0b%d.\n",x,y,res);

			break;
			case 4:
                res= n1 << n2;
                res=decimal_binario(res);
                printf("0b%d << 0b%d = 0b%d.\n",x,y,res);
			break;
			case 5:
                res= n1 >> n2;
                res=decimal_binario(res);
                printf("0b%d >> 0b%d = 0b%d.\n",x,y,res);
			break;
			default:
				seleccionado =  0;
				printf("Hasta pronto :).\n");
			break;
		}
		if(m && seleccionado){
                Nodo *n;
                n->op1=n1;
                n->op2=n2;
                n->res=res;
                if(seleccionado==1)
                    strcpy(n->operacion,"OR");
                if(seleccionado==2)
                    strcpy(n->operacion,"AND");
                if(seleccionado==3)
                    strcpy(n->operacion,"XOR");
                if(seleccionado==4)
                    strcpy(n->operacion,"<<");
                else strcpy(n->operacion,">>");

                Insertar_Nodo(l,n);
		}
}

void calculadora_3(int seleccionado, int x, int y, int  res,Lista * l,int m){

    switch(seleccionado){
			case 1:
			  //  printf("%d\n",y);printf("%d\n",x);
			    res= (x | y);
                printf("0x%x OR 0x%x = 0x%x .\n",x,y,res);
			break;
			case 2:
                res= x & y;
                printf("0x%x AND 0x%x = 0x%x.\n",x,y,res);
            break;
			case 3:
			    res= x ^ y;
                printf("0x%x XOR 0x%x = 0x%x.\n",x,y,res);

			break;
			case 4:
                res= x << y;
                printf("0x%x << 0x%x = 0x%x.\n",x,y,res);
			break;
			case 5:
                res= x >> y;
                printf("0x%x >> 0x%x = 0x%x.\n",x,y,res);
			break;
		}
		if(m && seleccionado){
                Nodo *n;
                n->op1=x;
                n->op2=y;
                n->res=res;
                if(seleccionado==1)
                    strcpy(n->operacion,"OR");
                if(seleccionado==2)
                    strcpy(n->operacion,"AND");
                if(seleccionado==3)
                    strcpy(n->operacion,"XOR");
                if(seleccionado==4)
                    strcpy(n->operacion,"<<");
                else strcpy(n->operacion,">>");

                Insertar_Nodo(l,n);
		}
}

int main(){
    Lista * l=NULL;


	int seleccionado=1;
	int x,y,res,base,memoria=0;
	//mostrar_menu();
	while(seleccionado){

		mostrar_menu1();
		mostrar_menu2();
		do{
            printf("Introduzca operacion: ");
			scanf("%d",&seleccionado);
			if(seleccionado<MIN || seleccionado >MAX){
                printf("ERROR. Vuelva a introducir la opercacion.\n");
			}
		}while(seleccionado<MIN || seleccionado >MAX);
		if(seleccionado && seleccionado<6){//por si es 0
           leer_operandos(&x,&y);
          // printf("%d\n",y);printf("%d\n",x);
          calculadora_1(seleccionado,x,y,res,l,memoria);
        }

        if(seleccionado==6){
            do{
                    printf("Seleccione el nuevo formato(0-> binario, 1-> hexadecimal: \n");
                    scanf("%d",&base);
                    if(!(base ==0 || base ==1)){printf("ERROR. Formato no valido");}
			    }while(!(base==0 || base==1));
            if(base==0){
                leer_operandos(&x,&y);
                do{

                    mostrar_menu1();
                    scanf("%d",&seleccionado);
                    if(seleccionado<MIN || seleccionado >5){
                        printf("ERROR. Vuelva a introducir la opercacion.\n");
                    }
                }while(seleccionado<MIN || seleccionado >5);
                calculadora_2(seleccionado,x,y,res,l,memoria);
            }else{
                leer_operandos_x(&x,&y);
                mostrar_menu1();
                scanf("%d",&seleccionado);
                calculadora_3(seleccionado,x,y,res,l,memoria);
            }
        }else{
            switch(seleccionado){
                case 7:
                    memoria=1;
                    printf("Se ha habilitado la memoria.\n");
                break;
                case 8:
                    memoria=0;
                    printf("Se ha deshabilitado la memoria.\n");
                break;
                case 9:
                    borrar_lista(l);
                break;
                case 10:
                    mostrar_lista(l);
                break;
            }
        }
	}
	return 0;
}
