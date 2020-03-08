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


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define longitu 500
#include "monomio.h"
#include "lista.h"

//RETORNAR COEFICIENTES
double *retornarCoeficientes(char *polinomio) {
    int i = 0, c = 0, d = 0, r = 0, h = 0;
    char *temporal, *polinomio1 = polinomio, *mas;
    mas = (char*) calloc(longitu, sizeof (char));
    mas[0] = '+';
    if (polinomio[0] != '+') {
        if (polinomio[0] != '-') {
            strcat(mas, polinomio1);
            polinomio = mas;
        }
    }
    temporal = (char*) calloc(longitu, sizeof (char));
    double *coeficientes, coeficientes2;
    coeficientes = (double*) calloc(obtnumeroDeMonomios(polinomio), sizeof (double));
    double val = 0;
    for (i = 0; i < strlen(polinomio); i++) {
        if (polinomio[i] == '+' || polinomio[i] == '-') {
            c = i;
            if (polinomio[i] == '-') {
                r++;
                temporal[r - 1] = polinomio[i];
            }
            while (polinomio[c] != '*') {
                c++;
                if (polinomio[c] != '*' && polinomio[c] != '-' && polinomio[c] != '+') {
                    r++;
                    temporal[r - 1] = polinomio[c];

                }
            }
            val = atof(temporal);
            coeficientes[h] = val;
            h++;
            r = 0;
            temporal = (char*) calloc(longitu, sizeof (char));
        }
    }
    return coeficientes;
}
//RETORNAR EXPONENTES
double *retornarExponentes(char *polinomio) {
    int i = 0, c = 0, d = 0, r = 0, h = 0;
    char *temporal;
    temporal = (char*) calloc(longitu, sizeof (char));
    double *coeficientes;
    coeficientes = (double*) calloc(obtnumeroDeMonomios(polinomio), sizeof (double));
    double val = 0;
    for (i = 0; i < strlen(polinomio); i++) {
        if (polinomio[i] == '^') {
            c = i;
            if (polinomio[i + 1] == '-') {
                r++;
                temporal[r - 1] = polinomio[i + 1];
            }
            while (polinomio[c] != '+' && c != strlen(polinomio) - 1) {
                c++;
                if (polinomio[c] != '*' && polinomio[c] != '-' && polinomio[c] != '+') {
                    r++;
                    temporal[r - 1] = polinomio[c];
                }
                if (polinomio[c + 1] == '-') {
                    break;
                }
            }

            val = atof(temporal);
            coeficientes[h] = val;
            h++;
            r = 0;
            temporal = (char*) calloc(longitu, sizeof (char));
        }
    }
    return coeficientes;
}
//RETORNAR CADENA
char* regresarCadena(char *x) {
    char *cadena;
    int contador = 0;
    int i;
    cadena = (char*) calloc(longitu, sizeof (char));
    if (cadena == NULL) {
        exit(-1);
    }
    fgets(cadena, longitu, stdin);
    return cadena;
}
// OBTENCION DE LA DERIVADA DE UN POLINOMIO CON EL USO DE LISTAS
void obtenerDerivadaDePolinomio() {
    Lista lista;
    char *polinomio;
    int num = 0, i = 0;
    printf("\n\n> Ingrese un polinomio de la forma a*x^n +- b*x^n-1 +- c*x^n-2 +- ... +- z*x^0, donde a,b,c . . . z son ctes y n es el grado de su polinomio. \n\n");
    polinomio = regresarCadena(polinomio);
    polinomio = regresarCadena(polinomio);
    printf("\n\n> El polinomio que ingres%c es %s \n\n", 162, polinomio);
    double *exponentes, *coeficientes;
    exponentes = (double*) calloc(num, sizeof (double));
    coeficientes = (double*) calloc(num, sizeof (double));
    exponentes = retornarExponentes(polinomio);
    coeficientes = retornarCoeficientes(polinomio);
    num = obtnumeroDeMonomios(polinomio);
    Monomio me;
    for (i = 0; i < num; i++) {
        me.exponente = exponentes[i];
        me.coeficiente = coeficientes[i];
        if(exponentes[i]!=0 && coeficientes[i]!=0){
        	me = obtDerivada(me);
	        InsertarFinal(&lista, &me);
		}
    }
    for (i = 0; i < num; i++) {
		me = (*Obtener(i, &lista));
		if((int)me.coeficiente==0 && (int)me.exponente==0){
			EliminarElemento(i,&lista);
		}
	}
    mostrarLista(&lista);     
}

//OBTENER INTEGRAL DE POLINOMIO
void obtenerIntegralDePolinomio(){
	Lista lista;
    char *polinomio;
    int num = 0, i = 0;
    printf("\n\n> Ingrese un polinomio de la forma a*x^n +- b*x^n-1 +- c*x^n-2 +- ... +- z*x^0, donde a,b,c . . . z son ctes y n es el grado de su polinomio. \n\n");
    polinomio = regresarCadena(polinomio);
    polinomio = regresarCadena(polinomio);
    printf("\n\n> El polinomio que ingres%c es %s \n\n", 162, polinomio);
    double *exponentes, *coeficientes;
    exponentes = (double*) calloc(num, sizeof (double));
    coeficientes = (double*) calloc(num, sizeof (double));
    exponentes = retornarExponentes(polinomio);
    coeficientes = retornarCoeficientes(polinomio);
    num = obtnumeroDeMonomios(polinomio);
    Monomio me;
    for (i = 0; i < num; i++) {
        me.exponente = exponentes[i];
        me.coeficiente = coeficientes[i];
        if(exponentes[i]!=0 && coeficientes[i]!=0){
        	me = obtIntegral(me);
	        InsertarFinal(&lista, &me);
		}
    }
    
     for (i = 0; i < num; i++) {
		me = (*Obtener(i, &lista));
		if((int)me.coeficiente==0 || (int)me.exponente==0){
			EliminarElemento(i,&lista);
		}
	}
    
    mostrarLista(&lista);   
}

//OBTENER NUMERO DE MONOMIOS
int obtnumeroDeMonomios(char* cadena) {
    int i = 0, contador = 0;
    for (i = 0; i < strlen(cadena); i++) {
        if (cadena[i] == '+' || cadena[i] == '-' && cadena[i - 1] != '^') {
            contador++;
        }
    }
    return contador + 1;
}










