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
#define TAM 100


typedef struct proceso{
	char nombre; 
	int tiempo; 
	int req;
} PROCESO;
typedef PROCESO* tipoDato;
typedef struct cola{
    tipoDato CListaCola[TAM];
    int frente;
    int fin;
}COLA;
void CrearCola(COLA*C);
void IngresarCola(COLA *C, tipoDato a);
tipoDato sacarCola(COLA *C);
int Colallena(COLA C);
int ColaVacia(COLA *C);
tipoDato FrenteCola(COLA C);

