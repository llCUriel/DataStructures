
/*
    INSTITUTO POLITÉCNICO NACIONAL.
    ESCUELA SUPERIOR DE CÓMPUTO.
    ESTRUCTURAS DE DATOS.
    GRUPO: 1CV7.
    ALUMNOS:
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL.
                MARTÍNEZ ISLAS MAURICIO JOEL.

    PROFESOR: BENJAMÍN LUNA BENOSO.

    PROGRAMA QUE CONVIERTE UNA EXPRESIÓN EN NOTACIÓN INFIJA A NOTACIÓN POSTFIJA.

    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    FECHA: 01/03/2017
 */


#include "PILA.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define longitud 100
#include <ctype.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include "Ana_elemento.c"


int prioridad(char operador);
char* regresar(char *x);
void concatenar_cadena_con_caracter(char *cadena, char chr);


// FUNCION MAIN

int main() {



    system("color 0E");

    PILA pil, postfija, aux;

    int i = 0;

    CrearPila(&pil);
    CrearPila(&postfija);
	CrearPila(&aux);

    char *cadenita = "";

    char *cadena;
    cadena = regresar(cadena);


    for (i = 0; i < strlen(cadena) - 1; i++) {

        if (cadena[i] == '+' || cadena[i] == '-' || cadena[i] == '*' || cadena[i] == '/' || cadena[i] == '^' || cadena[i] == '(' || cadena[i] == ')') {


            if (PilaVacia(pil) == 0 && (prioridad(cadena[i]) <= prioridad(CimaPila(pil)))) {


                while (PilaVacia(pil) == 0 || prioridad(cadena[i]) <= prioridad(CimaPila(pil))) {


                    InsertarPila(&postfija, QuitarPila(&pil));
                }

                InsertarPila(&pil, cadena[i]);



            } else {
                printf("\n\nIngresamos a la pila auxiliar : %c\n\n", cadena[i]);

                InsertarPila(&pil, cadena[i]);
            }

        } else {

            printf("\n\n Ingresamos a la pila postfija : %c\n\n", cadena[i]);

            InsertarPila(&postfija, cadena[i]);

        }


    }

    while (PilaVacia(pil) == 0) {
        InsertarPila(&postfija, QuitarPila(&pil));
    }
		


		while(PilaVacia(postfija) == 0){
			
			InsertarPila(&aux, QuitarPila(&postfija));
			
		}
		
		
		
		
		
		
	if ((cadenita = malloc(strlen("") + 2)) == NULL)
      return EXIT_FAILURE;
   
   strcpy(cadenita, "");
   
   while(PilaVacia(aux) == 0){
   	
   concatenar_cadena_con_caracter(cadenita, QuitarPila(&aux));
   	
   }
   
	printf("      \n\n\n\n  POSTFIJA:  %s \n\n Se ha guardado el resultado en postfija.txt \n\n ", cadenita); 


		
	strcat(cadena, " , ");
	strcat(cadena, cadenita);
	
	ingresar_a_txt(cadena);

    return 0;

}


// FUNCIONA QUE ASIGNA CIERTA PRIORIDAD DEPENDIENDO DEL OPERADOR

int prioridad(char operador) {

    int prioridad = 0;

    if (operador == '*' || operador == '/') {

        prioridad = 2;

    } else if (operador == '-' || operador == '+') {

        prioridad = 1;

    } else if (operador == '^') {

        prioridad = 3;

    } else if (operador == '(' || operador == ')') {

        prioridad = 0;

    } else {
        prioridad = 0;
    }


    return prioridad;

}


// FUNCION QUE CONCATENA UNA CADENA CON UN CARACTER.

void concatenar_cadena_con_caracter(char *cadena, char chr)
{
   size_t dim = strlen(cadena);

   *(cadena + dim) = chr;
   *(cadena + dim + 1) = '\0';
}

// FUNCION QUE SOLICITA LA EXPRESIÓN EN NOTACIÓN INFIJA.

char* regresar(char *x) {

    char *cadena;

    int contador = 0;

    int i;

    cadena = (char*) calloc(longitud, sizeof (char));

    if (cadena == NULL) {

        exit(-1);

    }

    printf("> Ingresa una cadena en notaci%cn  interfija, por favor: \n\n", 162, 160);

    fgets(cadena, longitud, stdin);

    return cadena;

}
