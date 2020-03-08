/*
	INSTITUTO POLIT�CNICO NACIONAL
	ESCUELA SUPERIOR DE C�MPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (NO AUTORES DE ESTE CODIGO): 
		HERN�NDEZ CASTELLANOS C�SAR URIEL
		MART�NEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAM�N LUNA BENOSO 

	IMPLEMENTACION DE FUNCIONES DEL TDA LCSE
	
	FECHA: 22/4/17
*/
#include "LCSE.h"

NODO* crearNodo(ITEM x){
	NODO* nuevo = (NODO*)malloc(sizeof(NODO));
	nuevo->dato = x;
	nuevo->sig = nuevo;
	return nuevo;
}
void ingresarCabLCSE(NODO** cab, ITEM x){
	NODO* nuevo = crearNodo(x);
	if(*cab){
		nuevo->sig = (*cab)->sig;
		(*cab)->sig = nuevo;
	}else{	
		(*cab) = nuevo;
	}	 
}
void eliminarLCSE(NODO** cab, ITEM x){
	NODO* act = *cab;
	int encontrado = 0;
	while(act->sig != *cab && !encontrado){
		encontrado = (act->sig->dato==x);
		if(!encontrado)
			act = act->sig;
	}
	encontrado = (act->sig->dato==x);
	if(encontrado){
		NODO* aux = act->sig;
		if(*cab==(*cab)->sig)
			(*cab) = NULL;
		else{
			if(aux==(*cab))
				*cab = act;
		
			act->sig = aux->sig;
		}
	}
}

