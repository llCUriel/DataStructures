/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	IMPLEMENTACIÓN DE LAS FUNCIONES DE BICOLA
	FECHA: 1/3/17
*/
#include "Bicola.h"
//las funciones hacen practicamente lo que dice su nombre
void ingresarFrente(COLA* c, tipoDato a){
	if(ColaLlena(*c)){
		printf("La cola esta llena");
		exit(-1);
	}else{
		//para ingresar en frente cuando esta en indice 0
		c->frente = (c->frente==0) ? c->frente+(TAM-1) : (c->frente-1)%TAM;
    	c->CListaCola[c->frente] = a;	
	} 

}
void ingresarFinal(COLA* c, tipoDato a){
	if(ColaLlena(*c)){
		printf("La cola esta llena");
		exit(-1);
	}else{
		c->fin = (c->fin+1)%TAM;
    	c->CListaCola[c->fin] = a;	
	}
}
void eliminarFrente(COLA* c){
	if(ColaVacia(*c)){
		printf("cola vacia");
		exit(-1);
	}else{
		c->frente = (c->frente+1)%TAM;	
	}

}
void eliminarFinal(COLA* c){
	if(ColaVacia(*c)){
		printf("cola vacia");
		exit(-1);
	}else{
		//para quitar de final cuando esta en indice 0
		c->fin = (c->fin==0) ? c->fin+(TAM-1) : (c->fin-1)%TAM;
	}   	
}
tipoDato leerFrente(COLA* c){
	return c->CListaCola[c->frente];
}
tipoDato leerFinal(COLA* c){
	return c->CListaCola[c->fin];
}
void imprimir(COLA* c){
	int i=c->frente;
	printf("---------------\n");
	if(!ColaVacia(*c)){
		while (i!=c->fin){
			printf("ind %d ", i);
			printf("%d\n", c->CListaCola[i]);
			if(i>=TAM-1)
				i=0;
			else{
				i++;
			}
		}	//imprimir el ultimo elemento, que es cuando el argumento del while da falso
		printf("ind %d ", c->fin);
		printf("%d\n", leerFinal(c));
	}
	printf("---------------\n");
}
