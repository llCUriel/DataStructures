/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (QUE SOLAMENTE MODIFICARON ESTE CÓDIGO): 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	CABECERA DE COLA (DEFINICIÓN DE FUNCIONES DE COLA)
	FECHA: 1/3/17
*/
#include<stdio.h>
#include<stdlib.h>
#define TAM 4

typedef int tipoDato;
typedef struct cola{
    tipoDato CListaCola[TAM];
    int frente;
    int fin;
}COLA;
void CrearCola(COLA*);
void IngresarCola(COLA *, tipoDato C);
tipoDato sacarCola(COLA *);
int Colallena(COLA);
int ColaVacia(COLA);
tipoDato FrenteCola(COLA);

