#ifndef OPERACIONES_H
#define OPERACIONES_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"
void print_menu();
void print_line();
void leer_operador(int *operador);
void leer_operandos(int *o1, int *o2);
void logic_or(int o1,int o2);
void logic_and(int o1,int o2);
void exclusive_or(int o1,int o2);
void desplazamiento_izquierda(int o1,int o2);
void desplazamiento_derecha(int o1,int o2);
void change_format(int *format);
char* entero_a_binario(int numero);
char* or_binario(const char* binario1, const char* binario2);
char* and_binario(const char* binario1, const char* binario2);
char* xor_binario(const char* binario1, const char* binario2);


//----------------------------------------------------------------------
//variables globales
//-----------------------------------------------------------------------
extern int format;// varible global para controlar el formato por defecto
extern int memory;
extern Lista* lista;
//-----------------------------------------------------------------------

#endif