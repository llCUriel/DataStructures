/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (NO AUTORES DE ESTE CODIGO): 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	IMPLEMENTACIÓN DE LAS FUNCIONES DE COLA
	FECHA: 6/3/17
*/
#include "Cola.h"

void CrearCola(COLA *C){
	C-> frente = -1;
	C-> fin = -1;
}

int ColaVacia(COLA *C){
	if(C->frente == -1 && C->fin==-1){
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
    if (ColaVacia(&C)){
	    printf("La cola esta vacia");
		exit(-1);
    }
    return C.CListaCola[C.frente];
}

void IngresarCola(COLA *C, tipoDato a){
    if(ColaLlena(*C)){
    	printf("La cola esta llena");
    }else if(ColaVacia(C)){
    	C->fin=0; 
    	C->frente=0;
	    C->CListaCola[C->fin] = a;
	}else{
	    C->fin = (C->fin+1)%TAM;
	    C->CListaCola[C->fin] = a;	
	}
}

tipoDato quitarCola(COLA *C){
	int aux=C->frente;
	if(C->frente==C->fin){
	    C->frente=-1;
	    C->fin=-1;
	    return C->CListaCola[aux];
	}else{
	    C->frente = (C->frente+1)%TAM;
	    return C->CListaCola[aux];
	}
	
}

