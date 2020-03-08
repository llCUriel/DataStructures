#include <stdio.h>
#include <stdlib.h>



typedef struct nodo {
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
} NODO;

NODO *CrearNodo(int dato);
int InsertarInicio(NODO **cabeza, int dato);
int InsertarFinal(NODO **cabeza, int dato);
void ImprimirLista(NODO *cabeza);
int EliminarNodo(NODO **cabeza, int dato);
int obtenerTamanioDeLista(NODO* cabeza);
int verificarSiEstaVaciaLaLista(NODO * cabeza);
int verificarSiTodosSonPositivos(NODO *cabeza);

