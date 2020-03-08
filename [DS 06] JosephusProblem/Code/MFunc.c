/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 

	FUNCION PRINCIPAL DE PROBLEMA DE JOSEPHUS
	
	FECHA: 22/4/17
*/
#include "Josephus.c"

int main(){
	/*hay codigo en el main por que se quiso respetar la visualización del problema de josephus como una función.
	El código que está aquí simplemente es una manera general de ver cómo se implementaría.*/
	NODO* cab = NULL;
	printf("Cu%cntos soldados son?\n", 160);
	int ns = getSoldiers(); 
	cab = initList(ns);
	printf("Sobrevive %c", josephus(&cab, ns));
	return 0;
}
