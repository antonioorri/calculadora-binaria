#include <stdio.h>
#include <string.h>
#include <stdlib.h>





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


void leer_operandos_hex(int *n1, int *n2){
    printf("Introduzca operando 1 en hexadecimal: \n");
    scanf("%x",n1);
  //  printf("%d\n",*n1);
    printf("Introduzca operando 2 en hexadecimal: \n");
    scanf("%x",n2);
  //  printf("%d\n",*n2);
}

void leer_operandos_bin(char *n1, char *n2){
    printf("Introduzca operando 1 en binario: \n");
    sscanf("%s",n1);
  //  printf("%d\n",*n1);
    printf("Introduzca operando 2 en binario: \n");
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

    char res2[20];
    int i=0;
    int x = num;

    while(x>0){
        x=x/2;
        i++;
    }
    printf("%d\n",i);
    res2[i]='\0';
    while(i>0){

        res2[i-1]= (num%2) + '0';
        printf("%c",res2[i]);
        num=num/2;
        i--;

    }
    printf("%s\n",res2);
    strcpy(res,res2);
}


int binToDecima( char * num){
    char * t;
    return strtol(num,&t,2);
}




void calculadora_1(int seleccionado, int x, int y, int  res,int m,int base){

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
				seleccionado =  0;
				printf("Hasta pronto :).\n");
			break;
		}
}


void calculadora_2(int seleccionado, char * n1, char * n2, char *  res,int m){

    int x=binToDecima(n1);
    int y=binToDecima(n2);
    switch(seleccionado){
			case 1:
			  //  printf("%d\n",y);printf("%d\n",x);
			    DecToBin((x|y),res);
                printf("0b%s OR 0b%s = 0b%s .\n",n1,n2,res);
			break;
			case 2:
			    DecToBin((x & y),res);

                printf("0b%s AND 0b%s = 0b%s.\n",n1,n2,res);
            break;
			case 3:
			    DecToBin((x ^ y),res);
                printf("0b%s XOR 0b%s = 0b%s.\n",n1,n2,res);

			break;
			case 4:
			    DecToBin((x << y),res);
                printf("0b%s << 0b%s = 0b%s.\n",n1,n2,res);
			break;
			case 5:
			    DecToBin((x >> y),res);
                printf("0b%s >> 0b%s = 0b%s.\n",n1,n2,res);
			break;
			default:
				seleccionado =  0;
				printf("Hasta pronto :).\n");
			break;
		}
		/*
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
		*/
}
