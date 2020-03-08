/*
        INSTITUTO POLITÉCNICO NACIONAL
        ESCUELA SUPERIOR DE CÓMPUTO
        ESTRUCTURAS DE DATOS
        GRUPO: 1CV7
        ALUMNO:
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL

        PROFESOR: BENJAMÍN LUNA BENOSO 
        EXAMEN PRIMER PARCIAL (INCISO B).
        FECHA: 10/03/17
 */

#include<stdio.h>
#include "PILA.c"
#include <string.h>
#define longitud 100
#include "Cola.c"

char* regresar(char *x);
void copiarPila(PILA * destino, PILA aCopiar);
void invertirPila(PILA * invertir);
void imprimirPILA(PILA P);
void insertarcadenaenPila(PILA * destino, char * cadena);
int compPilas(PILA A, PILA B);
int numElemPila(PILA A);
void palindromo();
void inciso_b();

// Main		

int main(void) {
    system("color 0E");
	inciso_b();
}
// Inciso A

void inciso_b() {
    char acept, dat;
    int n = 0;
    PILA A;
    CrearPila(&A);
    LimpiarPila(&A);
    while (dat != 13) {
        printf("%c", dat);
        dat = getch();
        if (dat != 13) {
            InsertarPila(&A, dat);
        }
    }
    printf("\n");
    while (PilaVacia(A) == 0) {
        invierte(QuitarPila(&A), n);
        n++;
    }
}
// Función recursiva que invierte un conjunto de caracteres.

void invierte(char d, int ele) {
    if (ele == 0) {
        printf("%c", d);
    } else {
        ele--;
        invierte(d, ele);
    }
}
// Función que compara dos pilas.

int compPilas(PILA A, PILA B) {
    int flag = 1;
    tipoDato a, b;
    if (numElemPila(A) == numElemPila(B) && CimaPila(A) == CimaPila(B)) {
        while (PilaVacia(A) == 0) {
            a = QuitarPila(&A);
            b = QuitarPila(&B);
            if (a != b) {
                flag = 0;
            }
        }
    } else {
        flag = 0;
    }
    return flag;
}
// Función que retorna el número de elementos de una PILA.

int numElemPila(PILA A) {
    int numero = 0;
    tipoDato aux;
    while (PilaVacia(A) == 0) {
        aux = QuitarPila(&A);
        numero++;
    }
    return numero;
}
// Función que inserta una cadena en una PILA.	

void insertarcadenaenPila(PILA * destino, char * cadena) {
    int i = 0;
    char a;
    for (i = 0; i < strlen(cadena) - 1; i++) {
        a = cadena[i];
        if (a != 32)
            InsertarPila(destino, cadena[i]);
    }
}
// Función que crea una copia de una PILA.

void copiarPila(PILA * destino, PILA aCopiar) {
    *destino = aCopiar;
}
// Función que invierte una PILA.

void invertirPila(PILA * invertir) {
    PILA aux;
    CrearPila(&aux);
    while (PilaVacia(*invertir) == 0) {
        InsertarPila(&aux, QuitarPila(invertir));
    }
    copiarPila(invertir, aux);
}
// Función que imprime una PILA.

void imprimirPILA(PILA P) {
    printf("\n > CIMA: %c\n", CimaPila(P));
    while (PilaVacia(P) != 1) {
        printf("%c \n", QuitarPila(&P));
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
// Función palindromo.

void palindromo() {
    while (1) {

        char * cadena = regresar(cadena);

        PILA PIL, PIL2, AUX;

        CrearPila(&PIL);

        insertarcadenaenPila(&PIL, cadena);

        copiarPila(&AUX, PIL);

        invertirPila(&PIL);

        copiarPila(&PIL2, PIL);

        imprimirPILA(PIL2);

        imprimirPILA(AUX);

        if (compPilas(PIL2, AUX) == 1) {

            printf("\n > Palindromo.\n");

        } else {
            printf("\n > No lo es.\n");
        }

    }

}

	


