/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 

	IMPLEMENTACION DE FUNCIONES DE PROBLEMA DE JOSEPHUS
	
	FECHA: 22/4/17
*/
#include "Josephus.h"
//regresa int por que los soldados son numeros
char josephus(NODO** cab, int ns){ //no esta validado si n = 0 o cosas asi, eso se validaria afuera
	int n = getN(ns);
	printf("n = %d\n", n);
	int i=0, j=1;      
	NODO* aux = *cab;
	NODO* delAux;
	printf("inicial:\n");
	printSoldiers(*cab);
	int stop=0;
	while(stop==0){
		printf("pasada %d:\n", j);
		if(!(*cab==aux&&*cab==aux->sig)){
			for(i=0;i<n;i++){
				printf("->%d\n", i+1);
				printSoldiers(aux);
				if(i!=n-1)
					aux = aux->sig;
			}
			if(!(*cab==aux&&*cab==aux->sig)){
				delAux = aux->sig;
				printf("=>sale %c\n", aux->dato);
				eliminarLCSE(cab, aux->dato);
				aux = delAux;
			}
		}
		if((*cab==aux&&*cab==aux->sig))
			stop=1;
		j++;
	}
	char c = aux->dato;
	return c;
}
void printSoldiers(NODO* aux){
	//esta funcion imprime desde un nodo dado, toda la lista
	NODO* act = aux;
	char s = act->dato;
	printf("%c ", act->dato);
	if(act->sig!=act){
		act=act->sig; 
		while(act->dato!=s){//o sea se detiene cuando se encuentra a si mismo
			printf("%c ", act->dato);
			act=act->sig;
		}
	}
	printf("\n");
}
NODO* initList(int ns){ //crear la lista de soldados dado el numero
	NODO* cab=NULL;
	char name = 97;
	int i;
	for(i=0;i<ns;i++){
		ingresarCabLCSE(&cab, name);
		name++;
	}
	return cab;
}
int getSoldiers(){ //recibir el input de soldados
	int x;
	scanf("%d", &x);
	return x;
}
int getN(int ns){ //realmente esto es una linea pero pues, por diseño nada mas se deja como funcion
	srand(time(NULL));
	int n = (rand() % ns) + 1; //no es la mejor manera de generar numeros random
	return n;
}


