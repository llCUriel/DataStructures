/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS: 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

IMPLEMENTACION DE FUNCIONES DE TEMPERATURA

FECHA: 20/4/17
*/
#include "Temperaturas.h"

//manejar el input
item getRecInput(){
	/*esta fea esta funcion por que nada mas es una secuencia de input.
	es mejor si no se cuenta con las funciones requeridas, por que es mas
	como de front end esto*/
	item nItem = (item)malloc(sizeof(REGTEMP));
	nItem->f = (FECHA*)malloc(sizeof(FECHA));
	nItem->h = (HORA*)malloc(sizeof(HORA));
	int inInt;
	double inDoub;
	printf("primero va la fecha\n");
	printf("mete el dia\n");
	scanf("%d", &inInt);
	nItem->f->dia=inInt;
	printf("mete el mes\n");
	scanf("%d", &inInt);
	nItem->f->mes=inInt;
	printf("mete el anio\n");
	scanf("%d", &inInt);
	nItem->f->ano=inInt;
	printf("ahora va la hora\n");
	printf("mete la hora\n");
	scanf("%d", &inInt);
	nItem->h->hr=inInt;
	printf("mete los mins de la hora\n");
	scanf("%d", &inInt);
	nItem->h->min=inInt;
	printf("ahora va la temp\n");
	printf("mete la temp\n");
	scanf("%lf", &inDoub);
	nItem->temp=inDoub;
	//es que es pura instruccion nada mas
	return nItem;
}
/*pueden haber campos repetidos, y aparte se ve como de malas practicas referenciar 
a un registro por un dato (aqui seria el de hora el que no se tendria que repetir),
asi que mejor se le puso un campo de id a cada registro de temperatura*/
//o sea que se tiene que calcular un id nuevo (como se hace a veces en las bases)
int calcId(NODO* cab){
	NODO *ptr = NULL;
    int newID = 0;
    //nada mas busca cual es el id mayor y le suma uno para obtener el nuevo
    if(cab!=NULL){
	    for(ptr = cab; ptr; ptr = ptr->sig){
	    	if(ptr->dato->id >= newID)
	    		newID = ptr->dato->id;
	    }
		newID++;
	}
	return newID;	
}

void insertByDate(item x, NODO** cab){
	//quedo medio feo
	NODO* aux=(*cab); 
	NODO* n;
	int gt=0, nLvl, cLvl=0;
	int stop=0;
	if(aux!=NULL){
		while(stop==0){//primero se recorre la lista y se ve en donde el elemento es mayor (o si siquiera es mayor que alguno)
			if(gtDetermine(x, aux->dato)!=0){
				gt=1;
				stop=1;
			}//bueno tambien hay que mencionar que se detiene cuando es mayor
			if(stop!=1){
				if(aux->sig==NULL)
					stop=1;
				else if(aux->sig&&stop==0)
					aux=aux->sig;	
			}
		}
		//ya despues se acciona, si es mayor que un elemento...
		if(gt==1){
			//se agarra al auxiliar que se tenia y se inserta ahi
			if(aux->prev)
				insertarLDE(aux->prev, x);
			else
				insertarCabLDE(x, cab);	
		}else{ //o si no es mayor que ninguno, pues se va hasta atras
			insertarLDE(aux, x);
		}
	}else{
		insertarCabLDE(x, cab);
	}
}

//determinar sin un elemento es mayor en fecha que el otro
int gtDetermine(item one, item two){ 
	//va checando capa por capa de la fecha si es mayor o no
	int gt=0;
	if(one->f->ano > two->f->ano){
		gt=1;	
	}else if(one->f->ano == two->f->ano){
		if(one->f->mes > two->f->mes){
			gt=1;
		}else if(one->f->mes == two->f->mes){
			if(one->f->dia > two->f->dia){
				gt=1;
			}else if(one->f->dia == two->f->dia){
				if(one->h->hr > two->h->hr){
					gt=1;
				}else if(one->h->hr == two->h->hr){
					if(one->h->min > two->h->min){
						gt=1;
					}else if(one->h->min == two->h->min){
						gt=1;
					}
				}
			}
		}
	}
	return gt;
}

/*para el de ordenar de menor a moyor y mostrar, se tiene un conflicto
si se ordena con la misma memoria, pues es rapido y ya, pero pues ya se arruino el orden
por fecha. Mejor se va uno por las buenas practicas y se hace como vista*/
/*o sea que hace falta uno de copiar (francamente no se si sea necesario que una copia no sea generica, 
pero como hay que reservar memoria para cada cosa, mejor se hace conforme al caso)*/
NODO* copyRecords(NODO* cab){
	NODO* aux = cab;
	NODO* copy=NULL;
	item auxItem, memItem;
	for(aux=cab;aux;aux=aux->sig){
		auxItem =(item)malloc(sizeof(REGTEMP));
		auxItem->f = (FECHA*)malloc(sizeof(FECHA));
		auxItem->h = (HORA*)malloc(sizeof(HORA));
		memItem = aux->dato;
		auxItem->id = memItem->id; 
		auxItem->temp = memItem->temp; 
		auxItem->f->ano = memItem->f->ano;
		auxItem->f->mes = memItem->f->mes;
		auxItem->f->dia = memItem->f->dia;
		auxItem->h->hr = memItem->h->hr;
		auxItem->h->min = memItem->h->min;
		printf("COPY id no.: %d, %.2fdeg, %d/%d/%d, %d:%d\n", auxItem->id, auxItem->temp, auxItem->f->dia, auxItem->f->mes, auxItem->f->ano, auxItem->h->hr, auxItem->h->min);
		insertarCabLDE(auxItem, &copy);
	}
	return copy;
}
//ahora ya va el de la vista por temperatura
void viewByTemp(NODO* cab){
	NODO* copy = copyRecords(cab);
	bubbleSortTemp(&copy);
	printTemps(copy);
}

//uno para imprimir
void printTemps(NODO* cab){
	NODO* aux; 
	printf("\n");
	for(aux=cab;aux;aux=aux->sig){
		printf("id no.: %d, %.2fdeg, %d/%d/%d, %d:%d\n", aux->dato->id, aux->dato->temp, aux->dato->f->dia, aux->dato->f->mes, aux->dato->f->ano, aux->dato->h->hr, aux->dato->h->min);
	}
	printf("\n");
}

//se sigue usando bubblesort
void bubbleSortTemp(NODO** cab){
	int sorted=0;
	NODO* aux=(*cab);
	NODO* next=NULL;
	while(sorted==0){
		aux=(*cab);
		next=aux->sig;
		sorted=1; 
		/*
		nota importante:
		si, fue cuando se estuvieron metiendo valores de prueba en el bubblesort que se
		dio cuenta que estaba mal.
		¿Por que se aclara?
		por que este es el bubblesort que se uso en el de polinomio
		>o sea que el de polinomio esta mal
		pero ya aqui se corrigio.
		nada mas era mover esa linea que dice "sorted=1" al while de arriba
		*/
		while(next){//ahora es por temperatura
			if((aux->dato->temp) > (next->dato->temp)){
				intercambiarLDE(aux);
				sorted=0;
			}
				aux=aux->sig;
				next=aux->sig;
		}		
	}
}
//ahora van los de maxima y minima temperatura por un dia y hora
//no se sabe si guiarse por buen diseño y separar todo, o manejar input en la vista tambien, mejor nada mas que se separe el input, sino se va a repetir codigo
//mejor no, por que si se hace, se va a tener que pasar un pointer o una nueva estructura a las vistas
//tambien se deberia de aclarar que no estan validadas las vistas para cuando no se encuentra ninguna temperatura
void viewMaxTByHour(NODO* cab){
	//input (este codigo se va a repetir y se ve mal estando en esta funcion, pero por cuestion de tiempo se dejo aqui)
	NODO* aux;
	int a, m, d, h;
	double maxTemp;
	printf("mete el anio\n");
	scanf("%d", &a);
	printf("mete el mes\n");
	scanf("%d", &m);
	printf("mete el dia\n");
	scanf("%d", &d);
	printf("mete la hora\n");
	scanf("%d", &h);
	//y ya aqui es buscar en los registros donde dia sea igual a d y mes sea igual a m, etc, etc....
	//de hecho este deberia de ser el unico pedazo de codigo en la funcion, que solamente es la peticion al registro
	
	for(aux=cab;aux;aux=aux->sig){
		if(aux->dato->f->ano==a&&aux->dato->f->mes==m&&aux->dato->f->dia==d&&aux->dato->h->hr==h){
				maxTemp = aux->dato->temp;
		}
	}
	for(aux=cab;aux;aux=aux->sig){
		if(aux->dato->f->ano==a&&aux->dato->f->mes==m&&aux->dato->f->dia==d&&aux->dato->h->hr==h){
			if(aux->dato->temp>=maxTemp)
				maxTemp = aux->dato->temp;
		}
	}
	
	printf("temperatura maxima: %.3f\n", maxTemp);
}
void viewMinTByHour(NODO* cab){
	//y aqui esta el codigo repetido.
	NODO* aux;
	int a, m, d, h;
	double minTemp;
	printf("mete el anio\n");
	scanf("%d", &a);
	printf("mete el mes\n");
	scanf("%d", &m);
	printf("mete el dia\n");
	scanf("%d", &d);
	printf("mete la hora\n");
	scanf("%d", &h);
	//es lo mismo que lo anterior pero con menor
	
	for(aux=cab;aux;aux=aux->sig){
		if(aux->dato->f->ano==a&&aux->dato->f->mes==m&&aux->dato->f->dia==d&&aux->dato->h->hr==h){
				minTemp = aux->dato->temp;
		}
	}
	for(aux=cab;aux;aux=aux->sig){
		if(aux->dato->f->ano==a&&aux->dato->f->mes==m&&aux->dato->f->dia==d&&aux->dato->h->hr==h){
			if(aux->dato->temp<=minTemp)
				minTemp = aux->dato->temp;
		}
	}
	printf("temperatura minima: %.3f\n", minTemp);
}
//este es el de borrar registro
void delRec(NODO** cab, int idDel){
	//es nadamas borrar en donde el id sea el indicado
	NODO* aux = NULL;
	//primero se recorre todo hasta llegar (se ve feo, pero funciona)
	for(aux=*cab;aux;aux=aux->sig){
		if(aux->dato->id == idDel){
			if(aux->prev&&aux->sig){
				aux->prev->sig = aux->sig;
				aux->sig->prev = aux->prev;
			}else if(aux->prev&&!aux->sig){
				aux->prev->sig = NULL;
				aux->prev = NULL;
			}else if(aux==*cab&&aux->sig){
				*cab = aux->sig;
				aux->sig->prev = NULL;
				aux->sig = NULL;
			}else if(aux==*cab&&!aux->sig)
				*cab = NULL;
		}
	}
}

void printMenu(){
	printf("1. ingresar temp\n");
	printf("2. imprimir temps\n");
	printf("3. temp mas alta de cierto dia y hora\n");
	printf("4. temp mas baja de cierto dia y hora\n");
	printf("5. eliminar temp por id\n");
	printf("6. ver por temperatura\n");
	printf("7. terminar\n");
}



