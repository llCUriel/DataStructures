/*
	INSTITUTO POLIT�CNICO NACIONAL
	ESCUELA SUPERIOR DE C�MPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERN�NDEZ CASTELLANOS C�SAR URIEL
		MART�NEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAM�N LUNA BENOSO 
	CABECERA DE BICOLA (DEFINICI�N DE FUNCIONES DE BICOLA)
	FECHA: 1/3/17
*/
#include<stdio.h>
#include "Cola.c"
void ingresarFrente(COLA* c, tipoDato a);
void ingresarFinal(COLA* c, tipoDato a);
void eliminarFrente(COLA* c);
void eliminarFinal(COLA* c);
tipoDato leerFrente(COLA* c);
tipoDato leerFinal(COLA* c); 
void imprimir(COLA* c);
