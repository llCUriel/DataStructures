/*
        INSTITUTO POLITÉCNICO NACIONAL
        ESCUELA SUPERIOR DE CÓMPUTO
        ESTRUCTURAS DE DATOS
        GRUPO: 1CV7
        ALUMNO:
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL

        PROFESOR: BENJAMÍN LUNA BENOSO 
        EXAMEN PRIMER PARCIAL (INCISO A).
        FECHA: 10/03/17
 */

#include<stdio.h>
#include "PILA.c"
#include <string.h>
#define longitud 100

	char* regresar(char *x);
	void copiarPila(PILA * destino, PILA aCopiar);
	void invertirPila(PILA * invertir);
	void imprimirPILA(PILA P);
	void insertarcadenaenPila(PILA * destino, char * cadena);
	int compPilas(PILA A, PILA B);
	int numElemPila(PILA A);
	void ordenarPilaEnteros(PILA * OR);
	PILA * conca(PILA A, PILA B);
	int existeenPila(int n, PILA A);
	void inciso_a();
	
	//Main
	int main(void){
    system("color 0E");
	inciso_a();
	}
	// Función que inserta elementos en dos pilas (De manera ordenada ambas).
	void inciso_a(){

	PILA H, N;
	CrearPila(&H);
	CrearPila(&N);
	LimpiarPila(&N);
	LimpiarPila(&H);

	InsertarPila(&H, 0);
	InsertarPila(&H, 1);
	InsertarPila(&H, 2);
	InsertarPila(&H, 3);
	InsertarPila(&H, 4);

	InsertarPila(&N, -4);
	InsertarPila(&N,  3);
	InsertarPila(&N, -2);
	InsertarPila(&N, -1);
	InsertarPila(&N,  0);


	PILA * b = conca(H, N);
	
	
	printf("CONCATENACION, MAYOR A MENOR.\n");
	imprimirPILA(*b);


	}
	// Función que regresa un apuntador a PILA, con la caracteristica de ser la concatenación de ambas, conservando su orden en la concatenación.
	PILA * conca(PILA A, PILA B){
		PILA M;
		CrearPila(&M);
		tipoDato aux;


			while(PilaVacia(A) == 0){
				aux = QuitarPila(&A);
				if(existeenPila(aux, B) == 0){
					InsertarPila(&B, aux);
				}

			}
			ordenarPilaEnteros(&B);
	}
	// Función que retorna 0 si el elemento n no se encuentra en la PILA, en caso contrario regresará uno.
	int existeenPila(int n, PILA A){
		tipoDato aux;
		int flag = 0;
		while(PilaVacia(A) == 0){
			aux =QuitarPila(&A);
			if(aux == n){
				flag = 1;
			}
		}

		return flag;

	}
	// Función que ordena una PILA.
	void ordenarPilaEnteros(PILA * OR){
		PILA A, B, C;
		int uno, dos, turno = 0, i = 0;
		CrearPila(&A);
		CrearPila(&B);
		CrearPila(&C);
		copiarPila(&A, *OR);
		for(i=0; i<numElemPila(*OR); i++){
			if(turno == 0){
				InsertarPila(&B, QuitarPila(&A));
				while(PilaVacia(A) == 0){
				uno = QuitarPila(&A);
				dos = CimaPila(B);

				if(uno <= dos){
					InsertarPila(&C, QuitarPila(&B));
					InsertarPila(&B, uno);
				}else{
					InsertarPila(&C, uno);
				}
				}
				turno = 1;
			}else if(turno == 1){
				InsertarPila(&B, QuitarPila(&C));
				while(PilaVacia(C) == 0){
					uno = QuitarPila(&C);
					dos = CimaPila(B);
					if(uno<=dos){
						InsertarPila(&A, QuitarPila(&B));
						InsertarPila(&B, uno);
					}else{
						InsertarPila(&A, uno);
					}
				}
				turno = 0;
			}
	}
			copiarPila(OR, B);
	}
	// Función que compara dos pilas.
	int compPilas(PILA A, PILA B){
		int flag = 1;
		tipoDato a, b;
		if(numElemPila(A) == numElemPila(B) && CimaPila(A) == CimaPila(B)){
			while(PilaVacia(A) == 0){
				a = QuitarPila(&A);
				b = QuitarPila(&B);
					if(a!=b){
						flag = 0;
					}
			}
		}else{
			flag = 0;
		}
		return flag;
	}
	// Función que retorna el número de elementos de una PILA.
	int numElemPila(PILA A){
		int numero=0;
		tipoDato aux;
		while(PilaVacia(A) == 0){
			aux = QuitarPila(&A);
			numero++;
		}
		return numero;
	}
	// Función que inserta una cadena en una PILA.
	void insertarcadenaenPila(PILA * destino, char * cadena){
		int i = 0;
		char a;
		for(i=0; i<strlen(cadena)-1; i++){
			a = cadena[i];
			if(a!=32)
			InsertarPila(destino, cadena[i]);
		}
	}
	// Función que hace una copia de una PILA.
	void copiarPila(PILA * destino, PILA aCopiar){
		*destino = aCopiar;
	}
	// Función que invierte el orden de una PILA.
	void invertirPila(PILA * invertir){
		PILA aux;
		CrearPila(&aux);
		while(PilaVacia(*invertir) == 0){
			InsertarPila(&aux, QuitarPila(invertir));
		}
		copiarPila(invertir, aux);
	}
	// Función que imprime una PILA.
	void imprimirPILA(PILA P){
	printf("\n > CIMA: %d\n", CimaPila(P));
	while(PilaVacia(P)!=1){
		printf("%d \n", QuitarPila(&P));
	}
	}
	// Función que captura una cadena ingresada por el usuario final.
	char* regresar(char *x) {

    char *cadena;

    int contador = 0;

    int i;

    cadena = (char*) calloc(longitud, sizeof (char));

    if (cadena == NULL) {

        exit(-1);

    }

    printf("\n > Ingresa una cadena: \n", 162, 160);

    fgets(cadena, longitud, stdin);

    return cadena;

	}






