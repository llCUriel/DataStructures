/*
	INSTITUTO POLIT�CNICO NACIONAL
	ESCUELA SUPERIOR DE C�MPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERN�NDEZ CASTELLANOS C�SAR URIEL
		MART�NEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAM�N LUNA BENOSO 

	FUNCION PRINCIPAL DE PROBLEMA DE JOSEPHUS
	
	FECHA: 22/4/17
*/
#include "Josephus.c"

int main(){
	/*hay codigo en el main por que se quiso respetar la visualizaci�n del problema de josephus como una funci�n.
	El c�digo que est� aqu� simplemente es una manera general de ver c�mo se implementar�a.*/
	NODO* cab = NULL;
	printf("Cu%cntos soldados son?\n", 160);
	int ns = getSoldiers(); 
	cab = initList(ns);
	printf("Sobrevive %c", josephus(&cab, ns));
	return 0;
}
