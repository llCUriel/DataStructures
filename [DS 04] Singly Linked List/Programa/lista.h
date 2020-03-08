/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS: 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

FUNCIONES DE LISTA

FECHA: 5/4/17
*/


#ifndef LISTA_H
#define LISTA_H
#include "monomio.h"

//DEFINICION DE LA ESTRUCTURA NODO

typedef struct Nodo {
    Monomio monomio;
    struct Nodo*siguiente;

} Nodo;

//DEFINICION DE LA ESTRUCTURA LISTA
typedef struct Lista {
    Nodo *cabeza;
    int longitud;
} Lista;
//PROTOTIPOS
void EliminarElemento(int n, Lista *lista);
void EliminarUltimo(Lista* lista);
void EliminarPrincipio(Lista* lista);
int EstaVacia(Lista* lista);
int Contar(Lista* lista);
Monomio *Obtener(int n, Lista* lista);
void InsertarDespues(int n, Lista* lista, Monomio* monomio);
void InsertarFinal(Lista* lista, Monomio* monomio);
void InsertarPrincipio(Lista* lista, Monomio * monomio);
void DestruirNodo(Nodo * nodo);
Nodo * CrearNodo(Monomio* monomio);
void mostrarLista(Lista* lista);



#endif /* LISTA_H */

