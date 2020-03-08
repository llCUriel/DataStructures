/*
        INSTITUTO POLIT蒀NICO NACIONAL
        ESCUELA SUPERIOR DE C覯PUTO
        ESTRUCTURAS DE DATOS
        GRUPO: 1CV7
        ALUMNOS (NO AUTORES DE ESTE CODIGO): 
                HERN罭DEZ CASTELLANOS C蒘AR URIEL
                MART蚇EZ ISLAS MAURICO JOEL
        PROFESOR: BENJAM蚇 LUNA BENOSO 
        FECHA: 18/2/17
 */
#include "PILA.h"
// Funci贸n que inicializa el valor de cima en -1.



void CrearPila(PILA *P) {
	
    P->cima = -1;
    LimpiarPila(P);
}
// Funci贸n para ingresar elementos en una pila.

void InsertarPila(PILA *P, tipoDato elemento) {
	
    if (PilaLlena(*P) == 1) {
    	
        puts("Error, Pila Llena");
        
        system("PAUSE");
        
        exit(-1);
        
    }
    
    P->cima++;
    
    P->listaPila[P->cima] = elemento;
    
}
// Funci贸n para sacar los elementos de una pila.

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
// Funci贸n que devuelve el valor de cima a -1.

void LimpiarPila(PILA *P) {
	
    P->cima = -1;
    
}
// Funci贸n que lee el elemento de la cima de la pila.

tipoDato CimaPila(PILA P) {
	
    return (P.listaPila[P.cima]);
    
}
//Funci贸n que comprueba si una pila se encuentra llena.

int PilaLlena(PILA P) {
	
    if (P.cima == TAMMAX - 1)
    
        return 1;
        
    return 0;
    
}
// Funci贸n que comprueba si una pila se encuentra vacia.

int PilaVacia(PILA P) {
	
    if (P.cima == -1)
    
        return 1;
        
    return 0;
    
}

