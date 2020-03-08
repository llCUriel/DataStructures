#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*nota importante antes de comenzar
 * si se topa con dos nombres iguales (o sea un juan lopez lopez y otro juan lopez lopez), va a 
 * crashear el programa por que el criterio del arbol avl es por nombre y no se cubre cuando el valor es igual,
 * si se incluye numero de boleta en el struct, pero no funciona como clave primaria, simplemente se maneja como campo*/

typedef struct nombre{
	char* primero;
	char* apMaterno;
	char* apPaterno;
}NOMBRE;

typedef struct alumno{
	NOMBRE* nom;
	int edad;
	int noBoleta;
}ALUMNO;


void altaAlumno(char* nombre, char*apMat, char*apPat, int edad, int noBoleta);
int biggerStr(char* s1, char* s2);
int comparaNom(NOMBRE *nom1, NOMBRE *nom2);



