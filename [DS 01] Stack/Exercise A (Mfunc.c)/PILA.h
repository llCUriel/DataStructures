/*
	INSTITUTO POLIT…CNICO NACIONAL
	ESCUELA SUPERIOR DE C”MPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (NO AUTORES DE ESTE CODIGO): 
		HERN¡NDEZ CASTELLANOS C…SAR URIEL
		MARTÕNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÕN LUNA BENOSO 
	FECHA: 18/2/17
*/

#include <stdio.h> 

#include <stdlib.h>

#define TAMMAX 100

//Definici√≥n del TAD PILA

typedef struct pila
{
	
	char listaPila[TAMMAX];
	
	int cima;
	
}PILA;

//Operaciones fundamentales del TAD PILA


void CrearPila(PILA *P);

void InsertarPila(PILA *P, char elemento);

char QuitarPila(PILA *P);

void LimpiarPila(PILA *P);

char CimaPila(PILA P);

int PilaLlena(PILA P);

int PilaVacia(PILA P);
 
