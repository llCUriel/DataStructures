#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"

NODO*  ordenarDeMenorAMayor(NODO* cabe){
	NODO *nuevo = NULL;
	int n,i,j,temp;
	n = obtenerTamanioDeLista(cabe);
	int *puntero;
	puntero=(int *)malloc(n);    
    for(i=0;i<n;++i){
    puntero[i] = cabe->dato;
	cabe = cabe->siguiente;	
	}
    for(i=1;i<n;++i)
        for(j=0;j<(n-i);++j)
            if(puntero[j]>puntero[j+1])
            {
                temp=puntero[j];
                puntero[j]=puntero[j+1];
                puntero[j+1]=temp;
            }          
    for(i=n-1;i!=-1;--i){
		InsertarInicio(&nuevo, puntero[i]);
	}
    return nuevo;
}

NODO*  ordenarDeMayorAMenor(NODO* cabe)
{
	NODO *nuevo = NULL;
	int n,i,j,temp;
	n = obtenerTamanioDeLista(cabe);
	int *puntero;
	puntero=(int *)malloc(n);    
    for(i=0;i<n;++i){
    puntero[i] = cabe->dato;
	cabe = cabe->siguiente;	
	}
    for(i=1;i<n;++i)
        for(j=0;j<(n-i);++j)
            if(puntero[j]>puntero[j+1])
            {
                temp=puntero[j];
                puntero[j]=puntero[j+1];
                puntero[j+1]=temp;
            }          
    for(i=0;i<n;++i){
    	InsertarInicio(&nuevo, puntero[i]);    	
	}
    return nuevo;
}

int verificarSiTodosSonPositivos(NODO *cabeza) {
    NODO *nAux = cabeza;
    int band = 1;
    if (verificarSiEstaVaciaLaLista(cabeza)) {
        while (nAux != NULL) {
            if ((nAux->dato) < 0) {
                band = 0;
            }
            nAux = nAux->siguiente;
        }
    } else {
        band = 0;
        printf("> La lista se encuentra vac%ca.", 161);
    }
    return band;
}
int verificarSiEstaVaciaLaLista(NODO * cabeza) {
    return (cabeza == NULL) ? 0 : 1;
}
int EliminarNodo(NODO **cabeza, int dato) {
    NODO *actual = *cabeza, *ant = NULL, *sig = NULL;
    while (actual != NULL) {
        if (actual->dato == dato) {
            if (actual == *cabeza) {
                *cabeza = actual->siguiente;
                if (actual->siguiente != NULL)
                    actual->siguiente->anterior = NULL;
            } else if (actual->siguiente == NULL) {
                ant = actual->anterior;
                actual->anterior = NULL;
                ant->siguiente = NULL;
            } else {
                ant = actual->anterior;
                actual->anterior = NULL;
                sig = actual->siguiente;
                actual->siguiente = NULL;
                ant->siguiente = sig;
                sig->anterior = ant;
            }
            free(actual);
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}
int InsertarFinal(NODO **cabeza, int dato) {
    NODO *nuevo = NULL, *nAux = *cabeza;
    nuevo = CrearNodo(dato);
    if (nuevo != NULL) {
        while (nAux->siguiente != NULL) {
            nAux = nAux->siguiente;
        }
        nuevo->anterior = nAux;
        nAux->siguiente = nuevo;
        return 1;
    }
    return 0;
}
int obtenerTamanioDeLista(NODO* cabeza) {
    NODO *nAux = cabeza;
    int tam = 0;
    if (cabeza != NULL) {
        while (nAux != NULL) {
            tam++;
            nAux = nAux->siguiente;
        }
    } else {
        printf("> La lista se encuentra vac%ca.", 161);
        tam = 0;
    }
    return tam;
}
void ImprimirLista(NODO *cabeza) {
    NODO *nAux = cabeza;
    if (cabeza != NULL) {
        printf("Cabecera <-");
        while (nAux != NULL) {
            if (nAux != cabeza) {
                printf("-><-[ %d ]", nAux->dato);
            } else {
                printf("[ %d ]", nAux->dato);
            }
            nAux = nAux->siguiente;
        }
        if (nAux == NULL) {
            printf("->NULL");
        }
    } else {
        printf("> La lista se encuentra vac%ca.", 161);
    }
}
int InsertarInicio(NODO **cabeza, int dato) {
    NODO *nuevo = NULL;
    nuevo = CrearNodo(dato);
    if (nuevo != NULL) {
        nuevo->siguiente = *cabeza;
        nuevo->anterior = NULL;
        if (*cabeza != NULL)
            (*cabeza)->anterior = nuevo;
        *cabeza = nuevo;
        return 1;
    }
    return 0;
}
NODO *CrearNodo(int dato) {
    NODO* nuevo = NULL;
    nuevo = (NODO*) malloc(sizeof (NODO));
    if (nuevo != NULL) {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    return nuevo;
}




