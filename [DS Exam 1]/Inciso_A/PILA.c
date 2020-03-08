/*
        INSTITUTO POLIT�CNICO NACIONAL
        ESCUELA SUPERIOR DE C�MPUTO
        ESTRUCTURAS DE DATOS
        GRUPO: 1CV7
        ALUMNOS (NO AUTORES DE ESTE CODIGO): 
                HERN�NDEZ CASTELLANOS C�SAR URIEL
                MART�NEZ ISLAS MAURICO JOEL
        PROFESOR: BENJAM�N LUNA BENOSO 
        FECHA: 18/2/17
 */
#include "PILA.h"
// Función que inicializa el valor de cima en -1.



void CrearPila(PILA *P) {
	
    P->cima = -1;
    LimpiarPila(P);
}
// Función para ingresar elementos en una pila.

void InsertarPila(PILA *P, tipoDato elemento) {
	
    if (PilaLlena(*P) == 1) {
    	
        puts("Error, Pila Llena");
        
        system("PAUSE");
        
        exit(-1);
        
    }
    
    P->cima++;
    
    P->listaPila[P->cima] = elemento;
    
}
// Función para sacar los elementos de una pila.

tipoDato QuitarPila(PILA *P) {
	
    tipoDato aux;
    
    if (PilaVacia(*P) == 1) {
    	
        puts("Error, Pila Vacia");
        
        system("PAUSE");
        
        exit(-1);
        
    }
    
    aux = P->listaPila[P->cima];
    
    P->cima--;
    
    return aux;
    
}
// Función que devuelve el valor de cima a -1.

void LimpiarPila(PILA *P) {
	
    P->cima = -1;
    
}
// Función que lee el elemento de la cima de la pila.

tipoDato CimaPila(PILA P) {
	
    return (P.listaPila[P.cima]);
    
}
//Función que comprueba si una pila se encuentra llena.

int PilaLlena(PILA P) {
	
    if (P.cima == TAMMAX - 1)
    
        return 1;
        
    return 0;
    
}
// Función que comprueba si una pila se encuentra vacia.

int PilaVacia(PILA P) {
	
    if (P.cima == -1)
    
        return 1;
        
    return 0;
    
}

