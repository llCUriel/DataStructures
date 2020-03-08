/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (NO AUTORES DE ESTE CODIGO): 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 

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

