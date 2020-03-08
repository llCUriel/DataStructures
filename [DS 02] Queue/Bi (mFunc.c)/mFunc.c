/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	FUNCIÓN PRINCIPAL PARA ILUSTRAR LA IMPLEMENTACIÓN DE LA BICOLA
	FECHA: 1/3/17
*/
#include "Bicola.c"
void printMenu();
int main(){
	COLA c;
	CrearCola(&c);
	int cont;
	do{
		printMenu();
		cont = getValue();
		switch(cont){
			case 1:
				ingresarFrente(&c, getValue());
				break;
			case 2:
				ingresarFinal(&c, getValue());
				break;
			case 3:
				eliminarFrente(&c);
				break;
			case 4:
				eliminarFinal(&c);
				break;
			case 5:
				printf("frente: %d\n",leerFrente(&c));
				break;
			case 6:
				printf("final: %d\n",leerFinal(&c));
				break;
			case 7:
				imprimir(&c);
				break;
		}
	}while(cont!=8);
	imprimir(&c);
	return 0;
}
tipoDato getValue(){
	//devuelve un valor ingresado por el usuario
	tipoDato n;
	printf("mete el valor\n");
	scanf("%d", &n);
	return n;
}
void printMenu(){
	//imprime un menu con las funciones
	printf("1.ingresar frente\n");
	printf("2.ingresar final\n");
	printf("3.eliminar frente\n");
	printf("4.eliminar final\n");
	printf("5.leer elemento del frente\n");
	printf("6.leer elemento del final\n");
	printf("7.imprimir\n");
	printf("8.salir\n");
}
