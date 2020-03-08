#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} NODO;

NODO* CrearNodo(int dato);
int InsertarInicio(NODO **cabeza, int dato);
int InsertarFinal(NODO **cabeza, int dato);
void ImprimirLista(NODO *cabeza);
int EstaVacia(NODO *cabeza);
int ExisteElemento(NODO *cabeza, int dato);
NODO* retornarListaPositiva(NODO* lista, NODO*lista2);
