/*
    INSTITUTO POLIT�CNICO NACIONAL.
    ESCUELA SUPERIOR DE C�MPUTO.
    ESTRUCTURAS DE DATOS.
    GRUPO: 1CV7.
    ALUMNOS:
                HERN�NDEZ CASTELLANOS C�SAR URIEL.
                MART�NEZ ISLAS MAURICIO JOEL.

    PROFESOR: BENJAM�N LUNA BENOSO.

    PROGRAMA QUE EVAL�A UNA CADENA EN NOTACI�N POSTFIJA (SUPONIENDO QUE ES CORRECTA).

    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    FECHA: 18/02/2017
 */


#include <stdio.h>
#include <conio.h>
#define longitud 100

// prototipos de funciones.
void ingresar_a_txt(char *cadena, int resul);

// Funci�n que ingresa la cadena postfija y el resultado en "postfija.txt"

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
