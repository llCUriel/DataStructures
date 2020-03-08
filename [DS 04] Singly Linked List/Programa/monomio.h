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


#ifndef MONOMIO_H
#define MONOMIO_H
#include <stdio.h>


//DEFINICION DEL TAD MONOMIO
typedef struct mono {
    double coeficiente;
    double exponente;
}Monomio;
//PROTOTIPOS
double *retornarCoeficientes(char *polinomio);
double *retornarExponentes(char *polinomio);
char* regresarCadena(char *x);
void obtenerDerivadaDePolinomio();
void obtenerIntegralDePolinomio();
int obtnumeroDeMonomios(char* cadena);
void obtMultiplicacionDePolinomios();
void imprimirMonomio(Monomio monomio);


#endif 

