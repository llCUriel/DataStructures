/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (AUTORES DE SOLAMENTE LAS FUNCIONES AÑADIDAS): 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	IMPLEMENTACIÓN DE LAS FUNCIONES DE PILA
	FECHA: 24/5/17
*/
#include "Pila.h"

void CrearPila(PILA *P) {
    P->cima = -1;
}

void InsertarPila(PILA *P, tipoDato elemento) {
    if (PilaLlena(*P) == 1) {
        puts("Error, Pila Llena");
        system("PAUSE");
        exit(-1);
    }
    P->cima++;
    P->listaPila[P->cima] = elemento;
}

tipoDato QuitarPila(PILA *P) {
    int aux;
    if (PilaVacia(*P) == 1) {
        system("PAUSE");
        exit(-1);
    }
    aux = P->listaPila[P->cima];
    P->cima--;
    return aux;
}

void LimpiarPila(PILA *P) {
    P->cima = -1;
}

tipoDato CimaPila(PILA P) {
    return (P.listaPila[P.cima]);
}

int PilaLlena(PILA P) {
    if (P.cima == TAMMAX - 1)
        return 1;
    else
    	return 0;
}

int PilaVacia(PILA P) {
    if (P.cima == -1)
        return 1;
    else
    	return 0;
}

//char stack print 
void cStackPrint(PILA P){
	while(P.cima!=-1){
		printf("%c", QuitarPila(&P));
	}
	printf("\n");
}
//imprimir stack al reves
void reverseStackPrint(PILA P){
	PILA R;
	CrearPila(&R);
	while(P.cima!=-1){
		InsertarPila(&R, QuitarPila(&P));
	}
	cStackPrint(R); 
}
