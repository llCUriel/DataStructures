/*
    INSTITUTO POLITÉCNICO NACIONAL.
    ESCUELA SUPERIOR DE CÓMPUTO.
    ESTRUCTURAS DE DATOS.
    GRUPO: 1CV7.
    ALUMNOS:    (NO AUTORES DE ESTE CODIGO)
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL.
                MARTÍNEZ ISLAS MAURICIO JOEL.

    PROFESOR: BENJAMÍN LUNA BENOSO.

    ARCHIVO: IMPLEMENTACIÓN DE LAS FUNCIONES FUNDAMENTALES DE LA TAD PILA.

    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    FECHA: 18/02/2017
*/

#include "pila.h"


// Función que inicializa el valor de cima en -1.

void CrearPila(PILA *P) {

    P->cima = -1;

}

// Función que imprime los elementos de la pila.


void imprimirPILA(PILA *P){

	while(PilaVacia(*P)!=1){

		printf("%c \n", QuitarPila(P));

	}

}

// Función para ingresar elementos en una pila.

void InsertarPila(PILA *P, int elemento) {

    if (PilaLlena(*P) == 1) {

        puts("Error, Pila Llena");

        system("PAUSE");

        exit(-1);

    }

    P->cima++;

    P->listaPila[P->cima] = elemento;

}

// Función para sacar los elementos de una pila.

int QuitarPila(PILA *P) {

    int aux;

    if (PilaVacia(*P) == 1) {

        system("PAUSE");

        exit(-1);

    }

    aux = P->listaPila[P->cima];

    P->cima--;

    return aux;

}

// Función que devuelve el valor de cima a -1.

void LimpiarPila(PILA *P) {

    P->cima = -1;

}

// Función que lee el elemento de la cima de la pila.

int CimaPila(PILA P) {

    return (P.listaPila[P.cima]);

}

//Función que comprueba si una pila se encuentra llena.

int PilaLlena(PILA P) {

    if (P.cima == TAMMAX - 1)

        return 1;

    return 0;

}

// Función que comprueba si una pila se encuentra vacia.

int PilaVacia(PILA P) {

    if (P.cima == -1)

        return 1;

    return 0;

}
