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


#include "lista.h"
#include <stdlib.h>
#include <string.h>

//CREAR NODO
Nodo * CrearNodo(Monomio* monomio) {
    Nodo* nodo = (Nodo *) malloc(sizeof (Nodo));
    nodo->monomio.coeficiente = monomio->coeficiente;
    nodo->monomio.exponente = monomio->exponente;
    nodo->siguiente = NULL;
    return nodo;
}


//MOSTRAR SEPARACIÓN EN LA IMPRESION DE LA LISTA
void separacion(){
    int i = 0;
    for (i = 0; i < 70; i++) {
            printf("%c", 205);
    }
	printf("\n");	
}

//MOSTRAR LISTA
void mostrarLista(Lista* lista) {
    Nodo * ptr;
    int contador = 0;
    
    for (ptr = lista->cabeza; ptr; ptr = ptr ->siguiente) {
		separacion();
        printf("\n\t\tInicio Nodo [%d]\n\n> Coeficiente: %f\n\n> Exponente: %f\n\n> Representaci%cn algebr%cica: %f*x^(%f)\n\n\t\tFin Nodo [%d]\n\n",contador, ptr->monomio.coeficiente,ptr->monomio.exponente,162,160, ptr->monomio.coeficiente, ptr->monomio.exponente, contador);
    	contador++;
	}
		separacion();
}

//DESTRUIR NODO
void DestruirNodo(Nodo * nodo) {
    free(nodo);
}
//INSERTAR AL PRINCIPIO
void InsertarPrincipio(Lista* lista, Monomio * monomio) {
    Nodo * nodo = CrearNodo(monomio);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}
//INSERTAR AL FINAL
void InsertarFinal(Lista* lista, Monomio* monomio) {
    Nodo* nodo = CrearNodo(monomio);
    if (lista->cabeza == NULL) {
        lista->cabeza = nodo;
    } else {
        Nodo * puntero = lista->cabeza;
        while (puntero->siguiente) {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}
//INSERTAR DESPUES
void InsertarDespues(int n, Lista* lista, Monomio* monomio) {
    Nodo* nodo = CrearNodo(monomio);
    if (lista->cabeza == NULL) {
        lista->cabeza = nodo;
    } else {
        Nodo * puntero = lista->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente) {
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}
//OBTENER MONOMIO
Monomio *Obtener(int n, Lista* lista) {
    if (lista->cabeza == NULL) {
        return NULL;
    } else {
        Nodo * puntero = lista->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente) {
            puntero = puntero->siguiente;
            posicion++;
        }
        if (posicion != n) {
            return NULL;
        } else {
            return &puntero->monomio;
        }
    }
}
//NUMERO DE ELEMENTOS
int Contar(Lista* lista) {
    return (lista->longitud) - 1;
}
// ESTA VACIA?
int EstaVacia(Lista* lista) {
    return lista->cabeza == NULL;
}
// ELIMINAR PRINCIPIO
void EliminarPrincipio(Lista* lista) {
    if (lista->cabeza) {
        Nodo* eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(eliminado);
        lista->longitud--;
    }
}
// ELIMINAR ULTIMO
void EliminarUltimo(Lista* lista) {
    if (lista->cabeza) {
        if (lista->cabeza->siguiente) {
            Nodo* puntero = lista->cabeza;
            while (puntero->siguiente->siguiente) {
                puntero = puntero->siguiente;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        } else {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
    }
}
// ELIMINAR ELEMENTO
void EliminarElemento(int n, Lista *lista) {
    if (lista->cabeza) {
        if (n == 0) {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        } else if (n < lista->longitud) {
            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while (posicion < (n - 1)) {
                puntero = puntero->siguiente;
                posicion++;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
    }
}



