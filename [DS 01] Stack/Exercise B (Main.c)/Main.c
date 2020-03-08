
/*
    INSTITUTO POLITÉCNICO NACIONAL.
    ESCUELA SUPERIOR DE CÓMPUTO.
    ESTRUCTURAS DE DATOS.
    GRUPO: 1CV7.
    ALUMNOS:
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL.
                MARTÍNEZ ISLAS MAURICIO JOEL.

    PROFESOR: BENJAMÍN LUNA BENOSO.

    PROGRAMA QUE EVALÚA UNA CADENA EN NOTACIÓN POSTFIJA (SUPONIENDO QUE ES CORRECTA).

    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    FECHA: 18/02/2017
 */


#include "PILA.c"

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define longitud 100

#include <ctype.h>

#include<math.h>

#include "Ana_elemento.c"

// prototipos de funciones.


char* regresar(char *x);

int validar(char o, int op1, int op2);

int convertir_caracter_a_entero(char caracter);


// función main.

int main() {

    PILA pil;

    char *cadena;

    char o;

    int op1, op2, final = 0;

    int i = 0, count = 0, resultado;


    CrearPila(&pil);


    cadena = regresar(cadena);

    for (i = 0; i < strlen(cadena) - 1; i++) {

        if (isdigit(cadena[i])) {

            InsertarPila(&pil, convertir_caracter_a_entero(cadena[i]));

        } else {

            o = cadena[i];

            op2 = QuitarPila(&pil);

            op1 = QuitarPila(&pil);

            final = validar(o, op1, op2);

            printf("\n%d %c %d  = %d", op1, o, op2, final);

            InsertarPila(&pil, final);

        }

    }

    printf("\n\n\n> El resultado de la evaluaci%cn de la cadena %s es %d \n\n\n", 162, cadena, final);

    ingresar_a_txt(cadena, final);

    printf("> El dato ha sido guardado en el fichero 'postfija.txt'\n\n\n");

    return 0;

}

// función que evalúa a pares los operandos de la pila.

int validar(char o, int op1, int op2) {

    int resultado = 0;

    switch (o) {

        case '+':

            resultado = op1 + op2;

            break;

        case '-':

            resultado = op1 - op2;

            break;

        case '*':

            resultado = op1 * op2;

            break;

        case '/':

            resultado = op1 / op2;

            break;

        case '^':

            resultado = pow((double) op1, (double) op2);

            break;

    }

    return (int) resultado;

}

// función que convierte un tipo de dato carácter a un entero.

int convertir_caracter_a_entero(char caracter) {

    int vari = 0;

    vari = caracter - 48;

    return vari;

}
// función que captura una cadena de texto.

char* regresar(char *x) {

    char *cadena;

    int contador = 0;

    int i;

    cadena = (char*) calloc(longitud, sizeof (char));

    if (cadena == NULL) {

        exit(-1);

    }

    printf("> Ingresa una cadena en notaci%cn  postfija, por favor: ", 162, 160);

    fgets(cadena, longitud, stdin);

    return cadena;

}
