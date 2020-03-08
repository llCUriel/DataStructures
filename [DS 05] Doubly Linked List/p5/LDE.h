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
#include <stdio.h>
#include <stdlib.h>
//structs son las clases (bueno sin metodos
typedef struct fecha{
	int dia, mes, ano;
}FECHA;

typedef struct hora{
	int hr, min;
}HORA;

typedef struct regTemp{
	FECHA* f;
	HORA* h;
	double temp;
	int id; //hora nada mas se va a manejar literalmente como hora, (o sea de 0 a 23) 
}REGTEMP;

typedef REGTEMP* item;

typedef struct nodo{
	item dato; //o sea se tiene que checar el ultimo id antes de ingresar, tambien, se elimina por id
	struct nodo* sig;
	struct nodo* prev;
} NODO;

NODO* crearNodo(item x);
void insertarCabLDE(item x, NODO **cab);
void insertarLDE(NODO* ant, item x);
void intercambiarLDE(NODO *A);
