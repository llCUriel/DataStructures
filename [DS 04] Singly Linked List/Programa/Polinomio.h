/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS: 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

FUNCIONES DE POLINOMIO

FECHA: 5/4/17
*/

#include<stdio.h>
#include "Polinomio.c"

//PROTOTIPOS
void obtenerDerivadaDePolinomio();
char* regresarCadena(char *x);
int obtnumeroDeMonomios(char* cadena);
double *retornarCoeficientes(char *polinomio);
double *retornarExponentes(char *polinomio);
double* asignarMemoriayCoeficientes(double *coeficientes_1, char* polinomio_1);
void obtMultiplicacionDePolinomios();
void obtenerIntegralDePolinomio();
