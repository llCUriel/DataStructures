/*
    INSTITUTO POLITÉCNICO NACIONAL.
    ESCUELA SUPERIOR DE CÓMPUTO.
    ESTRUCTURAS DE DATOS.
    GRUPO: 1CV7.
    ALUMNOS:
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL.
                MARTÍNEZ ISLAS MAURICIO JOEL.

    PROFESOR: BENJAMÍN LUNA BENOSO.

    INGRESO AL TXT

    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    FECHA: 01/03/2017
 */


#include <stdio.h>
#include <conio.h>
#define longitud 100
#include <string.h>

// prototipos de funciones.
void ingresar_a_txt(char *cadena);

// Función que ingresa la cadena postfija y el resultado en "postfija.txt"

void ingresar_a_txt(char *cadena) {

    FILE *doc;
    
    doc = fopen("postfija.txt", "a+");

    fputs(strcat(cadena, "\n\n"), doc);

    fclose(doc);


}
