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


#include <stdio.h>
#include <conio.h>
#define longitud 100

// prototipos de funciones.
void ingresar_a_txt(char *cadena, int resul);

// Función que ingresa la cadena postfija y el resultado en "postfija.txt"

void ingresar_a_txt(char *cadena, int resul) {

    FILE *doc;

    char *salto;

    salto = (char*) calloc(10, sizeof (char));

    salto = "\n";

    doc = fopen("postfija.txt", "a+");

    fputs(salto, doc);

    fputs(cadena, doc);

    fprintf(doc, "%d", resul);

    fputs(salto, doc);

    fclose(doc);


}
