#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Nodo {
    union {
        int dato;
        char dato_binario[9];
        char operacion[10];
    } contenido;
    int tipo; // Para indicar el tipo de contenido: 0 = entero, 1 = binario, 2 = operación
    struct Nodo *siguiente;
} Nodo;

typedef struct Lista{
	Nodo* cabeza;
}Lista;

//----------------------------------------------------------------------
//variables globales
int memory=0;
int format=2;// varible global para controlar el formato por defecto
Lista* lista;
//-----------------------------------------------------------------------
char* entero_a_binario(int numero);

Nodo* CrearNodo(int t){
	Nodo* nodo= (Nodo *)malloc(sizeof(Nodo));
	nodo->tipo= t;
	nodo->siguiente = NULL;
	return nodo;
}
void DestruirNodo(Nodo* nodo){
	free(nodo);
}
void InsertarPrincipio(Lista* lista, int res){
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

//int convertToBinary();
void print_line();
char* entero_a_binario(int numero);
char* or_binario(const char* binario1, const char* binario2);
char* and_binario(const char* binario1, const char* binario2);
char* xor_binario(const char* binario1, const char* binario2);
void print_menu(){
	print_line();
	printf("1.-OR logico\n");
	printf("2.-AND logico\n");
	printf("3.-XOR logico\n");
	printf("4.-<< (desplazamiento a la izquierda)\n");
	printf("5.->> (desplazamiento a la derecha)\n");
	printf("6.-Cambio de formato(0-> binario, 1-> hexadecimal). Una vez seleccionado un formato\n   determinado, los operandos se intepretaran en ese nuevo formato, al igual que los resultados.\n");
	printf("7.- Habilitar memoria\n");
	printf("8.- Deshabilitar memoria\n");
	printf("9.- Borrar memoria\n");
	printf("10.- Mostrar el contenido de la memoria\n");
	printf("0.- Salir\n");
	printf("Seleccione un operando: ");
}
void print_line(){
	for(int i =0; i<50;i++){
		printf("-");
	}
	printf("\n");
}
void leer_operador(int *operador){
	scanf("%d", operador);
}
void leer_operandos(int *o1, int *o2){
	printf("Introduce 2 numeros: ");
	if(format==2){//entero
		scanf("%d%d",o1,o2);
	}else if(format ==1){//hexadecimal
		scanf("%x%x",o1,o2);
	}else{//binario
		scanf("%d%d",o1,o2);
	}
}
void logic_or(int o1,int o2){
	int res=o1 | o2;
	if(format==2){
		printf("%d or %d = %d\n\n",o1,o2,res);
	}else if(format ==1){
		printf("%x or %x = %x\n\n",o1,o2,res);
	}else{
		char * res = or_binario(entero_a_binario(o1),entero_a_binario(o2));
		printf("%s or %s = %s\n\n",entero_a_binario(o1),entero_a_binario(o2),res);
	}
	if(memory==1){
		InsertarPrincipio(lista,res);
	}
}
void logic_and(int o1,int o2){
		int res=o1 & o2;
		if(format==2){
		printf("%d and %d = %d\n\n",o1,o2,res);
		}else if(format ==1){
			printf("%x and %x = %x\n\n",o1,o2,res);
		}else{
			char * res = and_binario(entero_a_binario(o1),entero_a_binario(o2));
			printf("%s and %s = %s\n\n",entero_a_binario(o1),entero_a_binario(o2),res);
		}
	if(memory==1){
		InsertarPrincipio(lista,res);
	}
}
void exclusive_or(int o1,int o2){
	int res=o1 ^ o2;
	if(format==2){
		printf("%d xor %d = %d\n\n",o1,o2,res);		
	}else if(format ==1){
		printf("%x xor %x = %x\n\n",o1,o2,res);
	}else{
		char * res = xor_binario(entero_a_binario(o1),entero_a_binario(o2));
		printf("%s xor %s = %s\n\n",entero_a_binario(o1),entero_a_binario(o2),res);
	}
	if(memory==1){
		InsertarPrincipio(lista,res);
	}
}

void desplazamiento_izquierda(int o1,int o2){
	int res=o1 << o2;
	//printf("%d << %d = %d\n\n",o1,o2,res);
		if(format==2){
		printf("%d << %d = %d\n\n",o1,o2,res);
		}else if(format ==1){
			printf("%x << %x = %x\n\n",o1,o2,res);
		}else{
			printf("%s << %s = %s\n\n",entero_a_binario(o1),entero_a_binario(o2),entero_a_binario(res));
		}
	if(memory==1){
		InsertarPrincipio(lista,res);
	}
}
void desplazamiento_derecha(int o1,int o2){
	int res=o1 >> o2;
	if(format==2){
		printf("%d >> %d = %d\n\n",o1,o2,res);
	}else if(format ==1){
		printf("%x >> %x = %x\n\n",o1,o2,res);
	}else{
		printf("%s >> %s = %s\n\n",entero_a_binario(o1),entero_a_binario(o2),entero_a_binario(res));
	}
	if(memory==1){
		InsertarPrincipio(lista,res);
	}
}
void change_format(int *format){
	printf("introduzca el nuevo formato (0->binary, 1->hexadecimal, 2-> decimal): ");
	scanf("%d",format);
	if(memory==1){
		InsertarPrincipio_Operacion(lista,"Format");
	}
}
char* entero_a_binario(int numero) {
    // Crear un arreglo de caracteres para almacenar el número binario
    char *binario = (char*)malloc(9 * sizeof(char)); // 8 bits + '\0'
    binario[8] = '\0'; // Añadir el caracter nulo al final de la cadena
    // Convertir el número entero a binario
    int indice = 7; // Empezamos desde el bit más significativo
    while (indice >= 0) {
        binario[indice] = (numero & 1) ? '1' : '0'; // Obtener el bit menos significativo
        numero >>= 1; // Desplazar el número hacia la derecha
        indice--;
    }
    return binario;
}
char* or_binario(const char* binario1, const char* binario2) {
    // Crear un arreglo de caracteres para almacenar el resultado
    char *resultado = (char*)malloc(9 * sizeof(char)); // 8 bits + '\0'
    resultado[8] = '\0'; // Añadir el caracter nulo al final de la cadena

    // Realizar la operación OR bit a bit
    for (int i = 0; i < 8; i++) {
        // Si al menos uno de los bits es '1', el resultado es '1', de lo contrario es '0'
        resultado[i] = (binario1[i] | binario2[i] );
    }
    return resultado;
}
char* and_binario(const char* binario1, const char* binario2) {
    // Crear un arreglo de caracteres para almacenar el resultado
    char *resultado = (char*)malloc(9 * sizeof(char)); // 8 bits + '\0'
    resultado[8] = '\0'; // Añadir el caracter nulo al final de la cadena
    // Realizar la operación OR bit a bit
    for (int i = 0; i < 8; i++) {
        // Si al menos uno de los bits es '1', el resultado es '1', de lo contrario es '0'
        resultado[i] = (binario1[i] & binario2[i] );
    }
    return resultado;
}
char* xor_binario(const char* binario1, const char* binario2) {
    // Crear un arreglo de caracteres para almacenar el resultado
    char *resultado = (char*)malloc(9 * sizeof(char)); // 8 bits + '\0'
    resultado[8] = '\0'; // Añadir el caracter nulo al final de la cadena
    // Realizar la operación OR bit a bit
    for (int i = 0; i < 8; i++) {
        // Si al menos uno de los bits es '1', el resultado es '1', de lo contrario es '0'
        resultado[i] = (binario1[i] ^ binario2[i] );
    }
    return resultado;
}
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