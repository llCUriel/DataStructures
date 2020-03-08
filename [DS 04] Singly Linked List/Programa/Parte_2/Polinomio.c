/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS: 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

IMPLEMENTACION DE FUNCIONES DE POLINOMIO

FECHA: 5/4/17
*/
#include "Polinomio.h"
void runMenu(){ //esta medio mal por que no corre el menu, sino el la funcion principal
	int x;
	NODO* cab1=NULL;
	NODO* cab2=NULL;
	printf("\t\t\tIngrese los miembros del polinomio, de la siguiente manera: ax^n, aunque n=0, y a=1, por favor.\n");
	printf("\n\t\t\t[1] Derivar polinomio. \n");
	printf("\t\t\t[2] Integrar polinomio.\n");
	printf("\t\t\t[3] Sumar dos polinomios. \n");
	printf("\t\t\t[4] Multiplicar dos polinomios.\n");
	printf("\n\t\t\t>");
	scanf("%d", &x);
	switch(x){
		case 1: //era mejor manejar funcion por operacion ingresada de usuario
			inputPoly(&cab1);
			cab1 = simpPoly(cab1);
			printPoly(cab1);
			cab1 = polyDeriv(cab1);
			printPoly(cab1);
			bubbleSortPoly(&cab1); //se le hace bubble hasta el final, ya cuando se opero
			printf("//res:\n"); //codigo repetido
			printPoly(cab1);
			break;
		case 2:
			inputPoly(&cab1);
			cab1=simpPoly(cab1);
			cab1 = polyInt(cab1);
			bubbleSortPoly(&cab1);
			printf("//res:\n");
			printPoly(cab1);
			break;
		case  3:
			inputPoly(&cab1);
			inputPoly(&cab2);
			cab1=simpPoly(cab1);
			cab2=simpPoly(cab2);
			NODO* sum = addPoly(cab1, cab2);
			sum=simpPoly(sum);
			bubbleSortPoly(&sum);
			printf("//res:\n");
			printPoly(sum);
			break;
		case 4:
			inputPoly(&cab1);
			inputPoly(&cab2);
			cab1=simpPoly(cab1);
			cab2=simpPoly(cab2);
			NODO* prod = multPoli(cab1, cab2);
			prod=simpPoly(prod);
			bubbleSortPoly(&prod);
			printf("//res:\n");
			printPoly(prod);
			break;
	}
}

void inputPoly(NODO** cab){
	//manejar el input con una cadena de largo fijo, con codigo duro 
	char inString[100];
	char act, cString[10], eString[10];
	int exp;
	double coef;
	item aux;
	int i=0, j=0,k=0,l;
	printf("\t\t\tIngrese el polinomio, por favor.\n\t\t\t");
	scanf("%s", inString);	
	//empezar a dividir la cadena en monomios
	if(inString[i]=='-'){
		cString[j]=inString[i];
		j++;
		i++;
	}else if(inString[i]=='+'){
		i++;
	}
	act=inString[i];
	while (act!='\0'){
		while(act!='x'){
			cString[j]=act;
			i++;
			j++;
			act=inString[i];
		}
		j=0;
		if(act=='x'){
			i+=2;
			act=inString[i];
		}
		while(act!='+'&&act!='-'&&act!='\0'){
			eString[k]=act;
			k++;
			i++;
			act=inString[i];
		}
		k=0; //creo que no se necesitaban dos indices separados
		//convertir los strings al tipo de dato corresp
		coef = strtod(cString, (char**)NULL);
		exp = (int)strtol(eString, (char**)NULL, 10);
		
		aux=(item)malloc(sizeof(Mono));
		aux->coef = coef;
		aux->exp = exp;
		//limpiar los strings
		for(l=0;l<10;l++){
			eString[l]='\0';
			cString[l]='\0';
		}
		insertarCabLSE(aux, cab);
	}
}
void printPoly(NODO* cab){
	NODO* aux; 
	item auxItem;
	printf("//beg print poly\n");
	for(aux=cab;aux;aux=aux->siguiente){
		auxItem = aux->dato;
		if(auxItem->coef > 0)
			printf("+%.2fx^%d", auxItem->coef, auxItem->exp);
		else
			printf("%.2fx^%d", auxItem->coef, auxItem->exp);
	}
	printf("\n//end print poly\n");
}

NODO* polyInt(NODO* cab){
	NODO* aux=cab; 
	NODO* newcab=NULL;
	item auxItem, memItem;
	for(aux=cab;aux;aux=aux->siguiente){
		memItem = aux->dato;
		auxItem =(item)malloc(sizeof(Mono));
		auxItem->exp = memItem->exp;
		auxItem->coef = memItem->coef;
		auxItem->exp++;
		auxItem->coef/=auxItem->exp;
		insertarCabLSE(auxItem, &newcab);
	}
	return newcab;
}
NODO* polyDeriv(NODO* cab){
	NODO* aux=cab; 
	NODO* newcab=NULL;
	item auxItem,memItem;
	for(aux=cab;aux;aux=aux->siguiente){
		memItem = aux->dato;
		//si es constante mejor se lo salta
		if(auxItem->exp>0){
			auxItem =(item)malloc(sizeof(Mono));
			auxItem->exp = memItem->exp;
			auxItem->coef = memItem->coef;
			auxItem->coef*=auxItem->exp;
			auxItem->exp--;
			insertarCabLSE(auxItem, &newcab);
		}
	}
	return newcab;
}

NODO* addPoly(NODO* cab1, NODO* cab2){
	NODO* cCab1 = copyPoly(cab1);
	NODO* cCab2 = copyPoly(cab2);
	NODO* sumPoly=NULL;
	NODO* aux;
	NODO* aux2;
	item auxItem, memItem, auxItem2;
	for(aux=cCab1;aux;aux=aux->siguiente){
		auxItem =(item)malloc(sizeof(Mono)); //este aux es el que se va a ir a la lista suma
		memItem = aux->dato;
		auxItem->exp = memItem->exp;
		auxItem->coef = memItem->coef;
		//buscar a el exponente en la otra lista y si esta, sumarlo
		aux2=cCab2;
		for(aux2=cCab2;aux2;aux2=aux2->siguiente){	
			auxItem2 = aux2->dato;
			if((auxItem2->exp)==(auxItem->exp)){
				(auxItem->coef)+=(auxItem2->coef);
				eliminarLSE(auxItem2, &cCab2);
			}
		}
		//insertar el aux a la lista suma
		
		insertarCabLSE(auxItem, &sumPoly);
	}
	if(cCab2){
		for(aux2=cCab2;aux2;aux2=aux2->siguiente){	
			auxItem2 = aux2->dato;
			insertarCabLSE(auxItem2, &sumPoly);
		}
	}
	return sumPoly;
}
//para simplificar un polinomio
NODO* simpPoly(NODO* cab){
	NODO* cCab = copyPoly(cab);
	NODO* aux; 
	NODO* newcab=NULL;
	NODO* aux2;
	item auxItem,memItem,auxItem2;
	aux=cCab;
	while(aux){
		if(aux){
			memItem = aux->dato;
			auxItem =(item)malloc(sizeof(Mono));
			auxItem->exp = memItem->exp;
			auxItem->coef = memItem->coef;
			for(aux2=aux->siguiente;aux2;aux2=aux2->siguiente){
				if(aux2){	
					auxItem2=aux2->dato;
					if(auxItem2->exp==auxItem->exp){
						auxItem->coef+=auxItem2->coef;
						eliminarLSE(auxItem2, &cCab);
					}
					
				}	
			}
			insertarCabLSE(auxItem, &newcab);	
			if(aux!=NULL)
				aux=aux->siguiente;
		}
	}
	return newcab;
}

NODO* multPoli(NODO* cab1, NODO* cab2){
	//multiplica por distributiva, despues se manda a llamar el de simplificar
	NODO* aux1;
	NODO* aux2;
	NODO* newcab=NULL;
	item auxItem, memItem1, memItem2;
	for(aux1=cab1;aux1;aux1=aux1->siguiente){
		for(aux2=cab2;aux2;aux2=aux2->siguiente){
			memItem1 = aux1->dato;
			memItem2 = aux2->dato;
			auxItem =(item)malloc(sizeof(Mono));
			auxItem->coef = (memItem1->coef)*(memItem2->coef);
			auxItem->exp = (memItem1->exp)+(memItem2->exp);
			insertarCabLSE(auxItem, &newcab);
		}	
	}
	return newcab;
}
 //para copiar un polinomio (conservar datos para operaciones)
NODO* copyPoly(NODO* cab){
	NODO* aux = cab;
	NODO* copy=NULL;
	item auxItem, memItem;
	for(aux=cab;aux;aux=aux->siguiente){
		auxItem =(item)malloc(sizeof(Mono));
		memItem = aux->dato;
		auxItem->exp = memItem->exp; 
		auxItem->coef = memItem->coef;
		insertarCabLSE(auxItem, &copy);
	}
	return copy;
}

void bubbleSortPoly(NODO** cab){
	int sorted=0;
	NODO* aux=(*cab);
	NODO* next=NULL;
	while(sorted==0){
		aux=(*cab);
		if(aux->siguiente)
			next=aux->siguiente;
		while(next){
			sorted=1;//este es bubble sort poly por que si depende de la estructura
			if((aux->dato->exp) < (next->dato->exp)){
				intercambiarLSE(aux);
				sorted=0;
			}
			if(aux->siguiente){
				aux=aux->siguiente;
				next=aux->siguiente;
			}
		}		
	}
}


