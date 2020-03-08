/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	FUNCIÓN PRINCIPAL DE ROUND ROBIN
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

