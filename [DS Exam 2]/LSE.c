#include <stdio.h>
#include <stdlib.h>
#include "LSE.h"

int retornarTamanioDeLSE(NODO * cabeza) {
    NODO *nAux = cabeza;
    int tamanio = 0;
    while (nAux != NULL) {
        tamanio++;
        nAux = nAux->siguiente;
    }
    return tamanio;
}

NODO* retornarListaPositiva(NODO* lista, NODO*lista2) {
    NODO* aux = lista;
    NODO*aux2 = lista2;
    NODO* nuevo = NULL;
    int tam1 = retornarTamanioDeLSE(aux), tam2 = retornarTamanioDeLSE(aux2);
    int n = 0, i = 0;
    n = obtenerMin(tam1, tam2);
    for (i = 0; i < n; i++) {
        if (aux->dato > 0) {
            InsertarInicio(&nuevo, aux->dato);
        }
        if (aux2->dato > 0) {
            InsertarInicio(&nuevo, aux2->dato);
        }
        aux = aux->siguiente;
        aux2 = aux2->siguiente;
    }
    return nuevo;
}

NODO* retornarListaNegativa(NODO* lista, NODO*lista2) {
    NODO* aux = lista;
    NODO*aux2 = lista2;
    NODO* nuevo = NULL;
    int tam1 = retornarTamanioDeLSE(aux), tam2 = retornarTamanioDeLSE(aux2);
    int n = 0, i = 0, list_mayor = 0, dif = 0;
    n = obtenerMin(tam1, tam2);
    if (n == tam1) {
        list_mayor = tam2;
    } else if (n == tam2) {
        list_mayor = tam1;
    }
    for (i = 0; i < n; i++) {
        if (aux->dato < 0) {
            InsertarInicio(&nuevo, aux->dato);
        }
        if (aux2->dato < 0) {
            InsertarInicio(&nuevo, aux2->dato);
        }
        aux = aux->siguiente;
        aux2 = aux2->siguiente;
    }
    for (i = 0; i < list_mayor - n; i++) {
        if (list_mayor == tam2) {
            InsertarInicio(&nuevo, aux2->dato);
            aux2 = aux2->siguiente;

        } else if (list_mayor == tam1) {
            InsertarInicio(&nuevo, aux->dato);
            aux = aux->siguiente;
        }
    }
    return nuevo;
}

int obtenerMin(int a, int b) {
    return (a < b) ? a : b;
}

NODO* ordenarDeMenorAMayor(NODO* cabe) {
    NODO *nuevo = NULL;
    int n, i, j, temp;
    n = retornarTamanioDeLSE(cabe);
    int *puntero;
    puntero = (int *) malloc(n);
    for (i = 0; i < n; ++i) {
        puntero[i] = cabe->dato;
        cabe = cabe->siguiente;
    }
    for (i = 1; i < n; ++i)
        for (j = 0; j < (n - i); ++j)
            if (puntero[j] > puntero[j + 1]) {
                temp = puntero[j];
                puntero[j] = puntero[j + 1];
                puntero[j + 1] = temp;
            }
    for (i = n - 1; i != -1; --i) {
        InsertarInicio(&nuevo, puntero[i]);
    }
    return nuevo;
}

NODO* ordenarDeMayorAMenor(NODO* cabe) {
    NODO *nuevo = NULL;
    int n, i, j, temp;
    n = retornarTamanioDeLSE(cabe);
    int *puntero;
    puntero = (int *) malloc(n);
    for (i = 0; i < n; ++i) {
        puntero[i] = cabe->dato;
        cabe = cabe->siguiente;
    }
    for (i = 1; i < n; ++i)
        for (j = 0; j < (n - i); ++j)
            if (puntero[j] > puntero[j + 1]) {
                temp = puntero[j];
                puntero[j] = puntero[j + 1];
                puntero[j + 1] = temp;
            }
    for (i = 0; i < n; ++i) {
        InsertarInicio(&nuevo, puntero[i]);
    }
    return nuevo;
}

//Función para crear un nuevo nodo de la lista

NODO* CrearNodo(int dato) {
    NODO *nuevo = NULL;

    nuevo = (NODO*) malloc(sizeof (NODO));
    if (nuevo != NULL) {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
    }

    return nuevo;
}

//Función para insertar un nodo al principio de la lista

int InsertarInicio(NODO **cabeza, int dato) {
    NODO* nuevo = NULL;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL) {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        return 1;
    }

    return 0;
}

//Función para imprimir todos los datos de la lista

void ImprimirLista(NODO *cabeza) {
    NODO *nAux = cabeza;

    while (nAux != NULL) {
        printf("%d ", nAux->dato);
        nAux = nAux->siguiente;
    }
}

//Función para insertar un nodo al final de la lista

int InsertarFinal(NODO **cabeza, int dato) {
    NODO* nuevo = NULL, *nAux = *cabeza;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL) {
        while (nAux->siguiente != NULL) {
            nAux = nAux->siguiente;
        }
        nAux->siguiente = nuevo;
        return 1;
    }
    return 0;
}

//Función para verificar si una lista está vacía

int EstaVacia(NODO *cabeza) {
    if (cabeza == NULL)
        return 1;
    else
        return 0;
}

//Función para verificar si existe un elemento en la lista

int ExisteElemento(NODO *cabeza, int dato) {
    NODO *nAux = cabeza;

    while (nAux != NULL) {
        if (nAux->dato == dato)
            return 1;
        nAux = nAux->siguiente;
    }
    return 0;
}
