
/*
    INSTITUTO POLITÉCNICO NACIONAL.
    ESCUELA SUPERIOR DE CÓMPUTO.
    ESTRUCTURAS DE DATOS.
    GRUPO: 1CV7.
    ALUMNOS:
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL.
                MARTÍNEZ ISLAS MAURICIO JOEL.
                
                (NO AUTORES DE ESTE CÓDIGO)

    PROFESOR: BENJAMÍN LUNA BENOSO.

    OPERACIONES FUNDAMENTALES DE LA PILA.

    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    FECHA: 01/03/2017
 */





#include "pila.h"


// CREAR PILA
void CrearPila(PILA *P) {
    P->cima = -1;
}

// VOLTEAR PILA E IMPRIMIR

void voltear_pila(PILA *P){
	
		PILA aux;

		CrearPila(&aux);

		while(PilaVacia(*P) == 0){
			InsertarPila(&aux, QuitarPila(P));
		}
		
	
  		P = &aux;	

	imprimirPILA(P);
}



//NUMERO DE ELEMENTOS DE UNA PILA

int n_elemento_p(PILA p){
	int contador = 0;
	
	while(PilaVacia(p)== 0){
		QuitarPila(&p);
		contador ++;	
	}
	
	return contador;
	
	
}


// IMPRIMIR PILA

void imprimirPILA(PILA *P){
	while(PilaVacia(*P)!=1){
		printf("%c", QuitarPila(P));
	}
}

// INSERTAR ELEMENTOS EN UNA PILA


void InsertarPila(PILA *P, char elemento) {
    if (PilaLlena(*P) == 1) {
        puts("Error, Pila Llena");
        system("PAUSE");
        exit(-1);
    }
    P->cima++;
    P->listaPila[P->cima] = elemento;
}

// EXTRAER ELEMENTOS DE UNA PILA

char QuitarPila(PILA *P) {
    char aux;
    if (PilaVacia(*P) == 1) {
        puts("Error, Pila Vacia");
        system("PAUSE");
        exit(-1);
    }
    aux = P->listaPila[P->cima];
    P->cima--;
    return aux;
}

// LIMPIAR PILA

void LimpiarPila(PILA *P) {
    P->cima = -1;
}

// CONSULTAR LA CIMA DE LA PILA

char CimaPila(PILA P) {
    return (P.listaPila[P.cima]);
}

 // SABER SI LA PILA SE ENCUENTRA LLENA

int PilaLlena(PILA P) {
    if (P.cima == TAMMAX - 1)
        return 1;
    return 0;
}
 
// SABER SI LA PILA SE ENCUENTRA VACIA 
 
 
int PilaVacia(PILA P) {
    if (P.cima == -1)
        return 1;
    return 0;
}
