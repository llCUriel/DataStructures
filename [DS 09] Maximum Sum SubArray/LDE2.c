#include <stdio.h>
#include <stdlib.h>
#include "LDE2.h"



void mostrarSubListaMax(NODO *cabeza) {
    if (verificarSiTodosSonPositivos(cabeza)) {
        printf("\n\n > Los sumandos por los que se encuentra conformada la suma m%cxima, son todos los elementos contenidos en la lista doblemente enlazada, ya que todos son mayores que cero. \n\n", 160);
        ImprimirLista(cabeza);
    } else {
        printf("\n\nYa que, como su lista doblemente enlazada contiene al menos un elemento menor que cero, procederemos a aplicar el algoritmo pertinente. \n\n");
        printf("La suma es: %d", obtenerSumaMaxima(cabeza, obtenerTamanioDeLista(cabeza)));
    }
}



int obtenerSumaMaxima(NODO * cabeza, int n) {
    NODO * nAux_1 = cabeza, *nAux_2 = cabeza, *nAux_3 = cabeza;
    int ans = 0;
    int x = 0, y = 0;
    while (nAux_1 != NULL) {
        x++;
        nAux_1 = nAux_1->siguiente;
        while (nAux_2 != NULL) {
            y++;
            nAux_2 = nAux_2->siguiente;
            if (x + y > n) {
                break;
            }
            int sumaMaxima = 0;
            while (nAux_3 != NULL) {
                printf(" %d ", nAux_3->dato);
                sumaMaxima = sumaMaxima + nAux_3->dato;
                nAux_3 = nAux_3->siguiente;

            }
            ans = seleccionarNumeroMaximo(ans, sumaMaxima);
        }
    }
    return ans;
}

int seleccionarNumeroMaximo(int a, int b) {
    return (a > b) ? a : b;
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

void solicitarDatAlUsuario(NODO **destino) {
    int i = 0, n = 0, dato = 0;
    printf("> Ingrese el n%cmero de elementos a ingresar, por favor : \t", 163);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\n\n> Ingrese el elemento [%d / %d] : \t", i + 1, n);
        scanf("%d", &dato);
        InsertarInicio(destino, dato);
    }
}


