/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS (NO AUTORES DE ESTE CODIGO): 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

IMPLEMENTACION DE FUNCIONES DEL TDA LSE

FECHA: 5/4/17
*/

#include "LSE.h"
#include<stdlib.h>

NODO * CrearNodo(item x, NODO *enlace) {
    NODO *nuevo = (NODO *) malloc(sizeof (NODO));
    nuevo -> dato = x;
    nuevo -> siguiente = enlace;
    return nuevo;
}

void intercambiarLSE(NODO *A){
    item aux = A->dato;
    A->dato = A->siguiente->dato;
    A->siguiente->dato = aux;
}

int longitudLista(NODO *cab){
    NODO *ptr = NULL;
    int cont = 0;
    for(ptr= cab; ptr; ptr= ptr->siguiente){
        cont ++;
    }
    return cont;
}

void mostrarLSE(NODO * cab) {
    NODO * ptr;
    for (ptr = cab; ptr; ptr = ptr ->siguiente) {
        printf("%d -> ", ptr -> dato);
    }
}

void insertarCabLSE(item x, NODO **cab){
    NODO *nuevo = CrearNodo(x, NULL);
    nuevo ->siguiente=*cab;
    *cab = nuevo;
}

void insertarLSE(item x, NODO *anterior){
    NODO *nuevo = CrearNodo(x, NULL);
    nuevo ->siguiente = anterior->siguiente;
    anterior ->siguiente = nuevo;
}

NODO *buscarLSE(item x, NODO *cab){
    NODO *ptr;
    for(ptr = cab; ptr; ptr = ptr->siguiente){

        if(ptr ->dato == x){
            return ptr;
        }
    }
    return NULL;
}

NODO * buscarant(item x, NODO*cab){
NODO *ptr1, *ptr2 = NULL;
    for(ptr1 = cab; ptr1; ptr1 = ptr1 -> siguiente){
        if(ptr1 -> dato < x){
            ptr2 = ptr1;
        }else{
            return ptr2;
        }
    }
    return ptr2;
}

void eliminarLSE(item x, NODO **cab){
    NODO *ant = NULL;
    NODO *act = *cab;
    int encontrado = 0;
    while((act) && (!encontrado)){
        encontrado = (act->dato == x);
        if(!encontrado){
                ant = act;
                act = act->siguiente;
        }
        if(act!= NULL){
            if(act == *cab)
                *cab = (*cab)->siguiente;
            else
                ant->siguiente = act ->siguiente;
        }
    }
}






