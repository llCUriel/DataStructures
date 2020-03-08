/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV7
ALUMNOS: 
	HERNANDEZ CASTELLANOS CESAR URIEL
	MARTINEZ ISLAS MAURICIO JOEL
PROFESOR: BENJAMÍN LUNA BENOSO

FUNCIONES DE MENU

FECHA: 5/4/17
*/



#include<stdio.h>
#include<windows.h>
#include "Polinomio.h"


//FUNCION QUE INICIA TODO
void probarApp(){
	system("cls");
	setTitulo();
    system("color 0E");
	impMenu();
	solicitarDato();
}


// ASIGNAR TITULO A LA VENTANA
void setTitulo(){
	SetConsoleTitle("ESCOM - EDD.");
}

//SOLICITAR DATO
void solicitarDato() {
    int opc = 0;
    scanf("%d", &opc);
        ingresarOpc(opc);
    
}
//INGRESO A LA OPCION
void ingresarOpc(int opc) {
    if (opc >= 1 && opc <= 5) {
        switch (opc) {
            case 1:
            	system("cls");
				obtenerDerivadaDePolinomio();
                break;

            case 2:
            	system("cls");
				obtenerIntegralDePolinomio();
                break;

            case 3:
            printf("\n\n");
			system("MFunc.exe");

                break;
            case 4:
                system("cls");
                printf("Hasta luego.");
                Sleep(1000);
                system("cls");
                exit(1);
                break;
        }
    } else {
        system("cls");
        printf("Opci%cn no v%clida, por favor ingresa un valor entre 1 y 5.", 162, 160);
        Sleep(1000);
        system("cls");
        impMenu();
        solicitarDato();
    }
}

// IMPRIMIR CABECERA SUPERIOR
void impCabeceraSup() {
    int i = 0;
    printf("\n\n\t\t\t ");
    for (i = 0; i < 55; i++) {
        if (i == 0)
            printf("%c", 201);
        else if (i == 54)
            printf("%c", 187);
        else
            printf("%c", 205);
    }
    impCabeceraSupDos();
}

// IMPRIMIR CABECERA SUPERIOR DOS
void impCabeceraSupDos() {
    int i = 0;
    printf("\n");
    printf("\t\t\t %c                P4 - LSE Polinomios.                 %c\n", 186, 186);
    printf("\t\t\t ");
    for (i = 0; i < 55; i++) {
        if (i == 0)
            printf("%c", 204);
        else if (i == 54)
            printf("%c", 185);
        else
            printf("%c", 205);
    }
}

//IMPRIMIR CABECERA
void impCabecera(int n) {
    int i = 0;
    if (n == 0) {
        impCabeceraSup();
    } else {
        impCabeceraInf();
    }
}
//IMPRIMIR CAB INFERIOR
void impCabeceraInf() {
    int i = 0;
    for (i = 0; i < 55; i++) {
        if (i == 0)
            printf("%c", 200);
        else if (i == 54)
            printf("%c", 188);
        else
            printf("%c", 205);
    }
    printf("\n");
}
// IMPRIMIR MENU
void impMenu() {
    int i = 0;
    impCabecera(0);
    printf("\n");
    printf("\t\t\t %c [1] Obtener la derivada de un polinomio.            %c\n", 186, 186);
    printf("\t\t\t %c [2] Obtener la integral de un polinomio.            %c\n", 186, 186);
    printf("\t\t\t %c [3] Derivada/Integral/Suma/Producto.                %c\n", 186, 186);
    printf("\t\t\t %c [4] Salir                                           %c\n", 186, 186);
    printf("\t\t\t ");
    impCabecera(1);
    printf("\t\t\t > Opci%cn: ", 162);

}
