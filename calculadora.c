
#include "operaciones.h"
#include "lista.h"

int format=2;
int memory=0;
Lista* lista;
int main(){
	print_menu();
	int operador;
	int operando1,operando2;
	int res;
	leer_operador(&operador);
	//Nodo* nodo= (Nodo *)malloc(sizeof(Nodo));
	lista =  (Lista *)malloc(sizeof(Lista));
	lista->cabeza=NULL;
	//printf("%d",operador);
	while(operador!=0){
		switch (operador)
		{
		case 1:
			leer_operandos(&operando1,&operando2);
			logic_or(operando1,operando2);
			break;
		case 2:
			leer_operandos(&operando1,&operando2);
			logic_and(operando1,operando2);
			break;
		case 3:
			leer_operandos(&operando1,&operando2);
			exclusive_or(operando1,operando2);
			break;
		case 4:
			leer_operandos(&operando1,&operando2);
			desplazamiento_izquierda(operando1,operando2);
			break;
		case 5:
			leer_operandos(&operando1,&operando2);
			desplazamiento_derecha(operando1,operando2);
			break;
		case 6:
			change_format(&format);
			printf("new format: %d\n",format);
			break;
		case 7://habilitar memoria
			if(memory==0){
				memory=1;
				//head = malloc(sizeof(node));
				printf("Memoria habilitada.\n");
			}else{
				printf("Memoria ya habilitada.\n");
			}
			break;
		case 8://deshabilitar memoria
			if(memory==0){
				printf("La memoria ya está desabilitada.\n");
			}else{
				if(memory==1){
				InsertarPrincipio_Operacion(lista,"memory");
				}
				memory=0;
			}
			break;
		case 9:
			EliminarLista(lista);
			break;
		case 10:
			imprimir_lista(lista);
			if(memory==1){
				//save_operacion("imprimir");
			}
			break;
		default:
		printf("Error, operador incorrecto.\n");
			break;
		}
		//print_menu();
		leer_operador(&operador);
	}
	EliminarLista(lista);
	return 0;
}
