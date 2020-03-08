
/*
    INSTITUTO POLITÉCNICO NACIONAL.
    ESCUELA SUPERIOR DE CÓMPUTO.
    ESTRUCTURAS DE DATOS.
    GRUPO: 1CV7.
    ALUMNOS:
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL.
                MARTÍNEZ ISLAS MAURICIO JOEL.

				(NO AUTORES DE ESTE CÓDIGO)
				
    PROFESOR: BENJAMÍN LUNA BENOSO.

    PILA

    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    FECHA: 01/03/2017
 */


#include <stdio.h>
#include <stdlib.h>
#define TAMMAX 100

//DEFINICIÓN DEL TDA

typedef struct pila {
    char listaPila[TAMMAX];
    int cima;
} PILA;

void CrearPila(PILA *P);
void InsertarPila(PILA *P, char elemento);
char QuitarPila(PILA *P);
void LimpiarPila(PILA *P);
char CimaPila(PILA P);
int PilaLlena(PILA P);
int PilaVacia(PILA P);
void imprimirPILA(PILA *P);
void voltear_pila(PILA *P);
int n_elemento_p(PILA p);

