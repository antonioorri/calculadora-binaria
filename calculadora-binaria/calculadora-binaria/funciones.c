#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"




int OR(int n1,int n2){
    return n1 | n2;
}

int AND(int n1,int n2){
    return n1 & n2;
}

int XOR(int n1,int n2){
    return n1 ^ n2;
}

int DESP_SHIFT(int n1, int n2){
    return n1 << n2;
}

int DES_RIGTH(int n1,int n2){
    return n1 << n2;
}
void mostrar_menu1(){
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("Seleccione una operacion.\n");
	printf("1.-OR l�gico\n");
	printf("2.-AND l�gico\n");
	printf("3.-XOR l�gico\n");
	printf("4.-<<(desplazamiento a la izquierda)\n");
	printf("5.->>(desplazamiento a la derecha)\n");
	printf("6.Cambio de formato (0->binario, 1->hexadecimal). Una vez seleccionado un formato determinado, los operandos se interpretar�n en ese nuevo formato, al igual que los resulatados.\n");
	printf("7.-Habilitar memoria.\n");
	printf("8.-Deshabilitar memoria.\n");
	printf("9.-Borrar memoria.\n");
	printf("10.-Mostrar el contenido de la memoria.\n");
	printf("0.-SALIR\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
}



void leer_operandos_hex(int *n1, int *n2){
    printf("Introduzca operando 1 en hexadecimal: \n");
    scanf("%x",n1);
  //  printf("%d\n",*n1);
    printf("Introduzca operando 2 en hexadecimal: \n");
    scanf("%x",n2);
  //  printf("%d\n",*n2);
}

void leer_operandos_bin(char *n1, char *n2){
    printf("Introduzca operando 1 en binario: ");
    scanf("%s",n1);
  //  printf("%d\n",*n1);
    printf("Introduzca operando 2 en binario: ");
    scanf("%s",n2);
  //  printf("%d\n",*n2);
}


/*

char * binario_decimal(int x){
    int i=0;
    char res[9];
    while(x>0){
        res[i]+=atoi((x%2) * pow(2,i));
        x=x/10;
        i++;
    }
    return *res;
}
*//*
int decimal_binario(int x){
    if(x==0)return x;
    else return decimal_binario(x/2) * 10 + x%2;
}
*/

void DecToBin(int num,char * res){
    //res2 era una prueba
    //char res2[20];
    //printf("Numero a transformar en binario: %d\n",num);
    int i=0;
    int x = num;
    //printf("DEBUG\n");
    while(x>0){
        x=x/2;
        i++;
    }
    //printf("%d\n",i);
    res[i]='\0';
    x=num;
    while(i>0){

        res[i-1]= (x%2) + '0';
        //printf("%c ",res[i]);
        x=x/2;
        i--;

    }
    //printf("\n");
    //printf("numero transformado en binario : %s\n",res);
    //strcpy(res,res2);
    //printf("DEBUG, ha terminado de pasar a binario.\n");
}


int binToDecima( char * num){
    char * t;
    //printf("numero a transformar en decimal : %s\n",num);
    return strtol(num,&t,2);
}




void calculadora_1(int seleccionado, int x, int y, int  res,int m,Lista * l){
    //printf("DEBUG, CALCULADORA HEXADECIMAL.\n");
    switch(seleccionado){
			case 1:
			  //  printf("%d\n",y);printf("%d\n",x);
			    res= (x | y);
                printf("%x OR %x = %x .\n",x,y,res);
			break;
			case 2:
                res= x & y;
                printf("%x AND %x = %x.\n",x,y,res);
            break;
			case 3:
			    res= x ^ y;
                printf("%x XOR %x = %x.\n",x,y,res);

			break;
			case 4:
                res= x << y;
                printf("%x << %x = %x.\n",x,y,res);
			break;
			case 5:
                res= x >> y;
                printf("%x >> %x = %x.\n",x,y,res);
			break;

			default:
				printf("Hasta pronto :).\n");
			break;
		}
        printf("DEBUGGING\n");
/*
        if(m){
            printf("DEBUGGING\n");
            Nodo * n = CrearNodo_1(res);
            Insertar_Nodo(l,n);
        }
        */
}


void calculadora_2(int seleccionado, int n1, int n2, char *  res,int m,Lista * l){
    char x[9];
    char y[9];
    //printf("DEBUG, CALCULADORA BINARIA.\n");
	DecToBin(n1,x);
    DecToBin(n2,y);
   // printf("LLEGARA HASTA AQUÍ?");
    switch(seleccionado){
			case 1:
			  //  printf("%d\n",y);printf("%d\n",x);
			    DecToBin((n1|n2),res);
                //printf("LLEGARA HASTA AQUÍ?");
                printf("0b%s OR 0b%s = 0b%s .\n",x,y,res);
               // printf("LLEGARA HASTA AQUÍ?");
			break;
			case 2:
			    DecToBin((n1 & n2),res);
                printf("0b%s AND 0b%s = 0b%s.\n",x,y,res);
            break;
			case 3:
			    DecToBin((n1 ^ n2),res);
                printf("0b%s XOR 0b%s = 0b%s.\n",x,y,res);

			break;
			case 4:
			    DecToBin((n1 << n2),res);
                printf("0b%s << 0b%s = 0b%s.\n",x,y,res);
			break;
			case 5:
			    DecToBin((n1 >> n2),res);
                printf("0b%s >> 0b%s = 0b%s.\n",x,y,res);
			break;
			default:
				seleccionado =  0;
				printf("Hasta pronto :).\n");
			break;
            //printf("LLEGARA HASTA AQUÍ?");
		}
       // printf("LLEGARA HASTA AQUÍ?");
        /*
    if(m && seleccionado){
        //Nodo * n = ;
        Insertar_Nodo(l,CrearNodo_2(res));
    }
        */
       if(m){
           Insertar_Nodo(l,CrearNodo_2(res));
       }
}
