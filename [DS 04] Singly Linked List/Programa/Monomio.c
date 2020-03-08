/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS: 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

FUNCIONES DE MONOMIO

FECHA: 5/4/17
*/


#include "monomio.h"
#include <stdlib.h>
#include <string.h>

//MOSTRAR MONOMIO
void imprimirMonomio(Monomio monomio){
	printf("%f*x^(%f)\n", monomio.coeficiente, monomio.exponente);
}
// OBTENER DERIVADA
Monomio obtDerivada(Monomio monomio){
	Monomio aux;
	if(aux.exponente != 0){	
	aux.coeficiente = monomio.coeficiente*monomio.exponente;
	aux.exponente = monomio.exponente-1;
	}else if(aux.exponente == 0 && aux.coeficiente == 0){
	aux.exponente = 0;
	aux.coeficiente =0;
	}else{
	aux.exponente = 0;
	aux.coeficiente =0;		
	}
	return aux;
}
//OBTENER INTEGRAL
Monomio obtIntegral(Monomio monomio){
	Monomio aux;
	if(monomio.exponente!=1){	
	aux.coeficiente = monomio.coeficiente/(monomio.exponente+1);
	aux.exponente = monomio.exponente+1;	
    }else{
    	aux.coeficiente = 0;
    	aux.exponente = 0;
	}
	return aux;
}



