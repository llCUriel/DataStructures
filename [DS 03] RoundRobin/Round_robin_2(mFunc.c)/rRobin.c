/*
	INSTITUTO POLIT�CNICO NACIONAL
	ESCUELA SUPERIOR DE C�MPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERN�NDEZ CASTELLANOS C�SAR URIEL
		MART�NEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAM�N LUNA BENOSO 
	IMPLEMENTACI�N DE FUNCIONES DE ROUND ROBIN
	FECHA: 6/3/17
*/
#include "rRobin.h"

int assignQuantum(){
	srand(time(NULL));
	return rand() % (2) + 3;
}
//funci�n para leer entrada de usuario(o sea el numero de procesos)
int readInput(){
	int size;
	printf("mete el numero de procesos\n");
	scanf("%d", &size);
	return size;
}

void assignMem(COLA* c, int size){
	int i;
	tipoDato dato;
	for(i=0;i<size;i++){
		//esto nada mas es "agarrar un tipoDato, asignarle sus cosas y pasarlo a la cola"
		dato = (PROCESO*)malloc(sizeof(PROCESO));
		dato->nombre = 65+i;
		dato->tiempo = i;
		dato->req = rand() % 21;
		//ya metiendo el tipoDato a la cola
		IngresarCola(c, dato);
	}
}

void run(COLA* c, int quant){
	//esta es la funci�n que emula el round robin, se puede decir que este es el algoritmo que se busca
	tipoDato dato;
	printf("quantum: %d \n", quant);
	while(!ColaVacia(c)){
		dato=quitarCola(c);
		//si la resta del requerimiento del proceso menos el quantum es mayor a cero, va de nuevo a la cola
		if((dato->req-quant)>0){
			dato->req-=quant;
			IngresarCola(c, dato);
		}else{ //si no, pues se va definitivamente
			printf("proceso %c terminado\n", dato->nombre);
		}
		//imprimir la cola despues de correr una iteraci�n
		print(*c);
		printf("end\n");
	}
}
//esta funci�n nada mas imprime la cola
void print(COLA c){
	int i=0;
	tipoDato dato;
	if(!ColaVacia(&c)){
		//si la cola no esta vac�a, que mientras el indice activo(partiendo desde el frente) sea diferente al fin, que lo imprima
		while((c.frente+i)%TAM!=c.fin%TAM){
			dato=c.CListaCola[(c.frente+i)%TAM];
			printf("%c %d %d\n", dato->nombre, dato->tiempo, dato->req);
			i++;				
		}
		//y pues aqui imprime el fin, creo que se puede imprimir una cola de manera m�s limpia, por que pues esto ya es codigo repetido, pero no se
		dato=c.CListaCola[(c.fin)%TAM];
		printf("%c %d %d\n", dato->nombre, dato->tiempo, dato->req);
	}
}
