/*
    INSTITUTO POLITÉCNICO NACIONAL.
    ESCUELA SUPERIOR DE CÓMPUTO.
    ESTRUCTURAS DE DATOS.
    GRUPO: 1CV7.
    ALUMNOS:    (NO AUTORES DE ESTE CODIGO)
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL.
                MARTÍNEZ ISLAS MAURICIO JOEL.

    PROFESOR: BENJAMÍN LUNA BENOSO.

    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	ARCHIVO DE CABECERA PARA LA DEFINICIÓM DEL TAD PILA.

    FECHA: 18/02/2017
    
*/

#include <stdio.h>
#include <stdlib.h>
#define TAMMAX 100

//Definición del TAD PILA
typedef struct pila {

    int listaPila[TAMMAX];

    int cima;

} PILA;

//Operaciones fundamentales del TAD PILA

void CrearPila(PILA *P);

void InsertarPila(PILA *P, int elemento);

int QuitarPila(PILA *P);

void LimpiarPila(PILA *P);

int CimaPila(PILA P);

int PilaLlena(PILA P);

int PilaVacia(PILA P);

void imprimirPILA(PILA *P);
