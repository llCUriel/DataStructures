/*
	INSTITUTO POLIT�CNICO NACIONAL
	ESCUELA SUPERIOR DE C�MPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (NO AUTORES DE ESTE CODIGO): 
		HERN�NDEZ CASTELLANOS C�SAR URIEL
		MART�NEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAM�N LUNA BENOSO 
	IMPLEMENTACI�N DE LAS FUNCIONES DE COLA
	FECHA: 1/3/17
*/
#include "Cola.h"

void CrearCola(COLA *C){
	C-> frente = 0;
	C-> fin = 0;
}

tipoDato ColaVacia(COLA C){
	if(C.frente == C.fin){
		return 1;
	}else{
		return 0;
	}
}

int ColaLlena(COLA C){
	
    if(C.frente == ((C.fin)+1)%TAM)
        return 1;
    else
        return 0;
}

tipoDato FrenteCola(COLA C){
    if (ColaVacia(C)){
	    printf("La cola esta vacia");
		exit(-1);
    }
    return C.CListaCola[C.frente];
}

void IngresarCola(COLA *C, tipoDato a){
    if(ColaLlena(*C) == 0){
    	printf("La cola est� llena");
    }else if(ColaVacia(*C)){
    	C->CListaCola[C->fin] = a;
	}else{
	    C->fin = (C->fin+1)%TAM;
	    C->CListaCola[C->fin] = a;	
	}
}

tipoDato quitarCola(COLA *C){
	if(ColaVacia(*C))
	    printf("La cola est� vacia");
	else
	    C->frente = (C->frente+1)%TAM;
	return C->CListaCola[(C->frente+1)%TAM-1];
}

