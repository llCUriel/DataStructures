/*
	INSTITUTO POLIT�CNICO NACIONAL
	ESCUELA SUPERIOR DE C�MPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERN�NDEZ CASTELLANOS C�SAR URIEL
		MART�NEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAM�N LUNA BENOSO 
	FUNCI�N PRINCIPAL DE ROUND ROBIN
	FECHA: 6/3/17
*/
#include "rRobin.c"
int main(){
	COLA c;
	CrearCola(&c);
	//asigna la memoria y datos de cada proceso
	assignMem(&c, readInput());
	//imprimir para confirmar
	print(c);
	//este se puede decir que es el mainloop
	run(&c, assignQuantum());
	return 0;
}

