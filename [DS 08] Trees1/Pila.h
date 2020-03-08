/*
	INSTITUTO POLIT�CNICO NACIONAL
	ESCUELA SUPERIOR DE C�MPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (AUTORES DE SOLAMENTE LAS FUNCIONES A�ADIDAS): 
		HERN�NDEZ CASTELLANOS C�SAR URIEL
		MART�NEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAM�N LUNA BENOSO 
	CABECERA DE TDA PILA
	FECHA: 24/5/17
*/
#include <stdio.h>
#include <stdlib.h>
#define TAMMAX 100

typedef char tipoDato;
typedef struct pila {
    tipoDato listaPila[TAMMAX];
    int cima;
} PILA;

void CrearPila(PILA *P);
void InsertarPila(PILA *P, tipoDato elemento);
tipoDato QuitarPila(PILA *P);
void LimpiarPila(PILA *P);
tipoDato CimaPila(PILA P);
int PilaLlena(PILA P);
int PilaVacia(PILA P);
//funciones a�adidas para la practica
void cStackPrint(PILA P);
void reverseStackPrint(PILA P);
