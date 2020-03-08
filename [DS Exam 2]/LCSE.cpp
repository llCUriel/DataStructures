/*  
	INSTITUTO POLITÉCNICO NACIONAL
    ESCUELA SUPERIOR DE CÓMPUTO
    ESTRUCTURAS DE DATOS
    GRUPO: __1CV7__ 
    ALUMNOS: 
            __Colin_Varela_Alejandro___ 
            __Romero_Ponce_Mauricio_Isaac__ 
    PROFESOR: BENJAMÍN LUNA BENOSO 

    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 

    ARCHIVO: IMPLEMENTACION DE LAS FUNCIONES DECLARADAS ENLSE.h
    
    FECHA: __21/04/2017__ */
/*#define item int
#include <stdio.h>
#include <stdlib.h>*/
#include "LCSE.h"

NODO *crearNODO(item x)
{
    NODO *nuevo=(NODO*)malloc(sizeof(NODO));
    nuevo->dato=x;
    return nuevo;
}

void insertarLCSE(NODO **cab,item x)
{
    NODO *nuevo=crearNODO(x);
    if(*cab)
    {
        nuevo->siguiente=(*cab)->siguiente;
        (*cab)->siguiente=nuevo;
    }
    (*cab)=nuevo;
}

void eliminarLCSE(NODO **cab, item x)
{
    NODO *actual=*cab;
    int encontrado=0;

    while((actual->siguiente!=(*cab))&& !encontrado)
    {
        encontrado=(actual->siguiente->dato== x);
        actual=actual->siguiente;
    }
    encontrado=(actual->siguiente->dato==x);

    if(encontrado)
    {
        NODO *aux=actual->siguiente;
        if(*cab==(*cab)->siguiente)
            *cab=NULL;
        else
        {
            if(aux==(*cab))
                *cab=actual;
            actual=aux->siguiente;
        }
        free(aux);
    }
}

NODO *copiarLCSE(NODO* cab)
{
    NODO *aux=cab,*cab2=NULL;
    while((aux->siguiente)!=cab)
    {
        insertarLCSE(&cab2, aux->siguiente->dato);
        aux=aux->siguiente;
    }
    insertarLCSE(&cab2,aux->siguiente->dato);
    return cab2;
}

int longitudLCSE(NODO *cab)
{
    NODO *aux=cab;
    int longitud=0;
    while((aux->siguiente)!=cab)
    {
        longitud++;
        aux=aux->siguiente;
    }
    longitud++;
    return longitud;
}

void compararLCSE(NODO *cab,NODO *cab2)
{
    NODO *aux=cab,*aux2=cab2;
    if(longitudLCSE(cab)!=longitudLCSE(cab2))
    {
        printf("las listas no son iguales");
        return;
    }
    else
    {
        while((aux->siguiente)!=cab)
        {
            if((aux->siguiente->dato)!=(aux2->siguiente->dato))
            {
                 printf("las listas no son iguales");
                 return;
            }
            aux=aux->siguiente;
            aux2=aux2->siguiente;
        }
    }
}