/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (AUTORES DE SOLAMENTE LAS FUNCIONES AÑADIDAS): 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	CABECERA DEL TDA ARBOL
	FECHA: 24/5/17
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Pila.c"

typedef char Item;

typedef struct nodo {
    Item valor;
    struct nodo* izq;
    struct nodo* der;
    struct nodo* padre;
} Nodo;

typedef Nodo Arbol;

Nodo* CrearNodo(Item valor, Nodo* padre);
void DestruirNodo(Nodo* nodo);
static void InsertarConPadre(Nodo** arbol, Nodo*padre, Item valor);
void Insertar(Nodo** arbol, Item valor);
int ExisteNodo(Nodo* arbol, Item valor);
Nodo* ObtenerNodo(Nodo* arbol, Item valor);
void DeterminarExistencia(Nodo* arbol, Item valor);
static void Reemplazar(Nodo* arbol, Nodo* nuevoNodo);
void Preorden(Nodo* arbol);
void Inorden(Nodo* arbol);
static void EliminarNodo(Nodo* nodoEliminar);
void Eliminar(Nodo* arbol, Item valor);
void PostOrden(Nodo* arbol);
//funciones añadidas:
void rootLeafPaths(Nodo* arbol, PILA p);
Arbol* inputExprTree(char *inString);
