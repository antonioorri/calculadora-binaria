#include "operaciones.h"

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
		InsertarPrincipio(lista,res,format);
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
		InsertarPrincipio(lista,res,format);
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
		InsertarPrincipio(lista,res,format);
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
		InsertarPrincipio(lista,res,format);
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
		InsertarPrincipio(lista,res,format);
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