/*
INSTITUTO POLIT�CNICO NACIONAL
ESCUELA SUPERIOR DE C�MPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS (NO AUTORES DE ESTE CODIGO): 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAM�N LUNA BENOSO

ARCHIVO DE CABECERA DE TEMPERATURAS

FECHA: 20/4/17
*/
#include "LDE.c"

item getRecInput();
int calcId(NODO* cab);
void insertByDate(item x, NODO** cab);
int gtDetermine(item one, item two);
NODO* copyRecords(NODO* cab);
void viewByTemp(NODO* cab);
void printTemps(NODO* cab);
void bubbleSortTemp(NODO** cab);
void viewMaxTByHour(NODO* cab);
void viewMinTByHour(NODO* cab);
void delRec(NODO** cab, int idDel);
void printMenu();
