#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>


#include "funciones.h"

#define MAX 10
#define MIN 0

#define BIN 2
#define HEX 3

typedef struct node{

    union {
    int dato; // operando o resultado para hexadecimal
    char dato_binario[9];
     //cadena para almacenar el operando/resultado  //binario
    char operacion[10]; // cadena descriptiva de la operacion  } contenido;
    }op;
    void * siguiente;
} nodo;


int main(){
//    Lista * l=NULL;


	int seleccionado=1;
	char num1[9];
	char num2[9];
	int x,y,res=0,base=1,memoria=0;
    char res1[9];
	//mostrar_menu();
	while(seleccionado){

		mostrar_menu1();
		do{
            printf("Introduzca operacion: ");
			scanf("%d",&seleccionado);
			if(seleccionado<MIN || seleccionado >MAX){
                printf("ERROR. Vuelva a introducir la opercacion.\n");
			}
		}while(seleccionado<MIN || seleccionado >MAX);
		if(seleccionado && base==1 && seleccionado<6 ){//por si es 0
           leer_operandos_hex(&x,&y);
          // printf("%d\n",y);printf("%d\n",x);
          calculadora_1(seleccionado,x,y,res,memoria);
        }else if(seleccionado && base==0 && seleccionado<6 ){
            leer_operandos_bin(num1,num2);
            x=binToDecima(num1);
            y=binToDecima(num2);
            calculadora_2(seleccionado,x,y,res1,memoria);
        }
        if(seleccionado==6){
            do{
                    printf("Seleccione el nuevo formato(0-> binario, 1-> hexadecimal: \n");
                    scanf("%d",&base);
                    if(!(base ==0 || base ==1)){printf("ERROR. Formato no valido");}
			    }while(!(base==0 || base==1));
        }


        if(seleccionado==6){
            do{
                printf("Seleccione el nuevo formato(0-> binario, 1-> hexadecimal: \n");
                scanf("%d",&base);
                if(!(base ==0 || base ==1)){printf("ERROR. Formato no valido");}
			    }while(!(base==0 || base==1));
        }

            /*
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
            */



    }
    return 0;
}
