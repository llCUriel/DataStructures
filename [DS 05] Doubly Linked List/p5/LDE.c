/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS (NO AUTORES DE ESTE CODIGO): 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

ARCHIVO DE CABECERA DE TDA LDE

FECHA: 20/4/17
*/
#include "LDE.h"

void insertarCabLDE(item x, NODO **cab){
    NODO *nuevo = crearNodo(x);
    nuevo->sig=(*cab);
    (*cab) = nuevo;
    if(nuevo->sig)
    	nuevo->sig->prev=nuevo;	
    
}

NODO* crearNodo(item x){
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
    nuevo->dato = x;
    nuevo->prev=nuevo->sig=NULL;
    return nuevo;
}

void insertarLDE(NODO* ant, item x){
	
	NODO* nuevo = crearNodo(x);
	printf("\nid no.: %d, %.2fdeg, %d/%d/%d, %d:%d\n", x->id, x->temp, x->f->dia, x->f->mes, x->f->ano, x->h->hr, x->h->min);
	if(ant->sig){	
		nuevo->sig = ant->sig;
		nuevo->prev = ant;
		ant->sig = nuevo;
		nuevo->sig->prev = nuevo;
	}else{
		printf("INSERT END");
		ant->sig = nuevo;
		nuevo->prev = ant;
		nuevo->sig=NULL;
	}
}

void intercambiarLDE(NODO *A){
    item aux = A->dato;
    A->dato = A->sig->dato;
    A->sig->dato = aux;
}

