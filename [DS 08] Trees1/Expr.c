/*
	INSTITUTO POLIT�CNICO NACIONAL
	ESCUELA SUPERIOR DE C�MPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERN�NDEZ CASTELLANOS C�SAR URIEL
		MART�NEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAM�N LUNA BENOSO 
	IMPLEMENTACI�N DE ARBOL DE EXPRESION
	FECHA: 24/5/17
*/

#include "Arbol.c"

int main(){
	Arbol* arbol = NULL;
	char *inString= "(((a*b)^d)+(f*(g/h))"; //aqui puede ser lo que sea
	printf("entrada: %s\n", inString);
	arbol = inputExprTree(inString);
	printf("\nin:\n");
	Inorden(arbol);
	printf("\npost:\n");
	PostOrden(arbol);
	printf("\npre:\n");
	Preorden(arbol);
	return 0;
}
