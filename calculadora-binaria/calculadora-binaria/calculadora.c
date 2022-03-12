#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>


#include "funciones.h"
#include "lista.h"

#define MAX 10
#define MIN 0

#define BIN 2
#define HEX 3




int main(){
    Lista * l=(Lista * )malloc(sizeof(Lista));


	int seleccionado=1;
	char num1[9];
	char num2[9];
	int x,y,res=0,base=1,memoria=1;
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
		if(seleccionado && base==1 && seleccionado<6 ){//por si es 0 y quiere salir del programa
           leer_operandos_hex(&x,&y);
          // printf("%d\n",y);printf("%d\n",x);
          printf("---------------------------------------------------------------------------------");
          calculadora_1(seleccionado,x,y,res,memoria);
          printf("---------------------------------------------------------------------------------");
        }else if(seleccionado && base==0 && seleccionado<6){
            leer_operandos_bin(num1,num2);
            x=binToDecima(num1);
            y=binToDecima(num2);
            calculadora_2(seleccionado,x,y,res1,memoria);
        }//
        if(seleccionado==6){
            do{
                    printf("Seleccione el nuevo formato(0-> binario, 1-> hexadecimal: \n");
                    scanf("%d",&base);
                    if(base==0)printf("Nuevo formato binario.\n");
                    if(base == 1 )printf("Nuevo formato hexadecimal.\n");
                    if(!(base ==0 || base ==1)){printf("ERROR. Formato no valido");}
                    if(base==0)Insertar_Nodo(l,CrearNodo_3("form bin"));
                    if(base==1)Insertar_Nodo(l,CrearNodo_3("form hex"));
			    }while(!(base==0 || base==1));
        }

            
            switch(seleccionado){
                case 7:
                    memoria=1;
                    printf("Se ha habilitado la memoria.\n");
                    if(memoria){
                        Nodo *n = CrearNodo_2("mem on");
                        Insertar_Nodo(l,n);
                    }
                break;
                case 8:
                    memoria=0;
                    printf("Se ha deshabilitado la memoria.\n");
                    if(memoria){
                        Nodo *n = CrearNodo_2("mem off");
                        Insertar_Nodo(l,n);
                    }
                break;
                case 9:
                    borrar_lista(l);
                    if(memoria){
                        Nodo *n = CrearNodo_2("borrar.");
                        Insertar_Nodo(l,n);
                    }
                break;
                case 10:
                    mostrar_lista(l);
                    if(memoria){
                        Nodo *n = CrearNodo_2("mostrar.");
                        Insertar_Nodo(l,n);
                    }
                break;
            }
    }
    borrar_lista(l);
    free(l);
    return 0;
}
