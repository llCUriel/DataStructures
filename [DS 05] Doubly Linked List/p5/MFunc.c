/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS: 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

FUNCION PRINCIPAL DE TEMPERATURAS

FECHA: 20/4/17
*/
#include "Temperaturas.c"
/*el main trae mucho codigo, pero realmente ese codigo si es la funcion principal.
bueno, si se quisiera, se podria separar el do while y mandar el interior a otra funcion,
tratando esa funcion como el loop principal, pero realmente no ayudaria mucho*/
int main(){
	imprimirMenu();
	return 0;
}

void imprimirMenu(){
	NODO* cab = NULL;
	int idDel, opt;
	do{
		item varItem = (item)malloc(sizeof(REGTEMP));
		varItem->f = (FECHA*)malloc(sizeof(FECHA));
		varItem->h = (HORA*)malloc(sizeof(HORA));
		printMenu();
		scanf("%i", &opt);
		switch(opt){
			case 1:
				varItem = getRecInput();
				varItem->id = calcId(cab);
				insertByDate(varItem, &cab);
				break;
			case 2:
				printTemps(cab);
				break;
			case 3:
				viewMaxTByHour(cab);
				break;
			case 4:
				viewMinTByHour(cab);
				break;
			case 5:
				printf("mete el id que vas a borrar\n"); //malas practicas pero ya que
				scanf("%d", &idDel);
				delRec(&cab, idDel);
				break;
			case 6:
				viewByTemp(cab);
				break;
			case 7:
				printf("ok.");
				break;
			default:
				printf("no.\n");
				break;
		}
	}while(opt!=7);
	
}
