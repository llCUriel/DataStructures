/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS (NO AUTORES DE ESTE CODIGO): 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

IMPLEMENTACION DE FUNCIONES DEL TDA LSE

FECHA: 5/4/17
*/


#include<stdio.h>
//TAD MONO
typedef struct mono {
	double coef;
	int exp;
} Mono;

typedef Mono* item;
//LSE
typedef struct nodo {
    item dato;
    struct nodo* siguiente;
} NODO;
//PROTOTIPOS
void burbuja(NODO *cab);
NODO* CrearNodo(item x, NODO* enlace);
void mostrarLSE(NODO * cab);
void insertarCabLSE(item x, NODO **cab);
void insertarLSE(item x, NODO *anterior);
NODO *buscarLSE(item x, NODO *cab);
NODO * buscarant(item x, NODO*cab);
void eliminarLSE(item x, NODO **cab);
void intercalarSignos(NODO * cab);
void intercambiarLSE(NODO *A);
//invertirLSE(NODO ** cab);
