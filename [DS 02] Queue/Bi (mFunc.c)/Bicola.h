/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	CABECERA DE BICOLA (DEFINICIÓN DE FUNCIONES DE BICOLA)
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
