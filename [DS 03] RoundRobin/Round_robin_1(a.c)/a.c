/*
        INSTITUTO POLITÉCNICO NACIONAL
        ESCUELA SUPERIOR DE CÓMPUTO
        ESTRUCTURAS DE DATOS
        GRUPO: 1CV7
        ALUMNOS:
                HERNÁNDEZ CASTELLANOS CÉSAR URIEL
                MARTÍNEZ ISLAS MAURICO JOEL
        PROFESOR: BENJAMÍN LUNA BENOSO 
        ROUND ROBIN
        FECHA: 05/03/17
 */


#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include "Cola.c"

void mostrar_conenter(COLA COLU);
void menu_conlee();
void mostrar_tab_proce();
void emular_p_a_p(COLA COLU);
void imp_tabla(COLA aux, int k);
void cont_func(int opc);
void cantidad_de_procesos();
void menu();

int num_procesos = 0, quantum = 0;
int *num_ale;
tipoDato datos;
COLA COL;

// FUNCION PRINCIPAL
int main() {
    CrearCola(&COL);
    menu_conlee();
}
// EMULACIÓN PASO A PASO (MEDIENTE MÚLTIPLES ENTER)
void mostrar_conenter(COLA COLU) {
    char c;
    COLA aux_2 = COLU;
    if (num_procesos != 0) {
        int k = num_procesos;
        int i = 0, cont = 7;
        system("cls");
        printf("\n QUANTUM = %d \n", quantum);
        Sleep(1000);
        system("cls");
        imp_tabla(aux_2, num_procesos);
        while (ColaVacia(&aux_2) == 0) {
            for (i = 0; i < k; i++) {
                TABLA * x = quitarCola(&aux_2);
                if (x->reque_cpu > 0) {
                    x->reque_cpu = (x->reque_cpu) - quantum;
                }
                if (x->reque_cpu > 0) {
                    IngresarCola(&aux_2, x);
                } else {
                    k--;
                    printf("\n\n\t\t\tEl proceso %c ha terminado\n\n", x->letra);
                }
                c = getch();
                if (c == 13) {
                    imp_tabla(aux_2, k);
                }
            }
        }
        printf("\n\n\t\t\tTodos los procesos han terminado. \n\n");
        /*	c = getch(); 
        if (c == 13)
        { 
        system("cls");
        menu_conlee();
        } 
         */
    } else {
        system("cls");
        printf("\n\n Ingresa el num de procesos primero, presiona ENTER para continuar... \n\n");
        c = getch();
        if (c == 13) {
            system("cls");
            menu_conlee();
        }
    }
}
// MENU PRINCIPAL
void menu_conlee() {
    int opc = 0;
    system("color 0E");
    menu();
    printf("\t\t\t ->");
    scanf("%d", &opc);
    cont_func(opc);
}
// VISUALIZAR LA TABLA GENERADA.
void mostrar_tab_proce() {
    char c;
    if (num_procesos != 0) {
        COLA sin_md = COL;
        system("cls");
        int i = 0, cont = 7;
        printf("\n\n\t\t\tTABLA DE PROCESOS\n\n");
        for (i = 0; i < num_procesos; i++) {
            TABLA * x = quitarCola(&sin_md);
            printf("\t\t\t%c \t%d \t%d \n", x->letra, x->tiem_lle, x->reque_cpu);
        }
        printf("\n\n Presione enter para retornar, por favor... \n\n");
        c = getch();
        if (c == 13) {
            system("cls");
            menu_conlee();
        }
    } else {
        system("cls");
        printf("\n\n Ingresa el num de procesos primero, presiona ENTER para continuar... \n\n");
        c = getch();
        if (c == 13) {
            system("cls");
            menu_conlee();
        }
    }
}
// EMULAR COMPLETO CON UN RETRASO DE UN SEGUNDO POR CADA TABLA.
void emular_p_a_p(COLA COLU) {
    COLA aux = COLU;
    char c;
    int k = num_procesos, i = 0;
    if (num_procesos != 0) {
        system("cls");
        printf("\n QUANTUM = %d \n", quantum);
        Sleep(1000);
        system("cls");
        imp_tabla(aux, num_procesos);
        while (ColaVacia(&aux) == 0) {
            for (i = 0; i < k; i++) {
                TABLA * x = quitarCola(&aux);
                if (x->reque_cpu > 0) {
                    x->reque_cpu = (x->reque_cpu) - quantum;
                }
                if (x->reque_cpu > 0) {
                    IngresarCola(&aux, x);
                } else {
                    k--;
                    printf("\n\n\t\t\tEl proceso %c ha terminado\n\n", x->letra);
                }
                Sleep(1000);
                imp_tabla(aux, k);
            }
        }

        printf("\n\n\t\t\tTodos los procesos han terminado. \n\n");
        /*
                c = getch(); 
                if (c == 13)
                { 
                system("cls");
                menu_conlee();
                } 
         */
    } else {
        system("cls");
        printf("\n\n Ingresa el num de procesos primero, presiona ENTER para continuar... \n\n");
        c = getch();
        if (c == 13) {
            system("cls");
            menu_conlee();
        }
    }
}
// IMPRIMIR TABLA EN LA EMULACION
void imp_tabla(COLA aux, int k) {
    int i = 0;
    COLA sin_md = aux;
    if (k != 0) {
        printf("\n\n\t\t\tTABLA DE PROCESOS\n\n");
        for (i = 0; i < k; i++) {
            TABLA * y = quitarCola(&sin_md);
            printf("\t\t\t%c \t%d \t%d \n", y->letra, y->tiem_lle, y->reque_cpu);
        }
    }
}
// LLAMAR A ALGUNA FUNCIÓN, DEPENDIENDO DEL NÚMERO INGRESADO POR EL USUARIO FINAL.
void cont_func(int opc) {
    switch (opc) {
        case 1:
            cantidad_de_procesos();
            break;
        case 2:
            mostrar_tab_proce();
            break;
        case 3:
            mostrar_conenter(COL);
            break;
        case 4:
            emular_p_a_p(COL);
            break;
        case 5:
            exit(-1);
            break;
        default:
            system("cls");
            menu_conlee();
    }
}
// ASIGNACIÓN DEL NÚMERO DE PROCESOS POR EL USUARIO FINAL
// INGRESO A LA COLA DE LOS DATOS GENERADOS
void cantidad_de_procesos() {
    system("cls");
    srand(time(NULL));
    int ca_p, i = 0, y = 0;
    printf("\n\t\t\t -> Ingresa la cantidad \n \t\t\t de procesos, por favor. \n");
    printf("\n\t\t\t n > 0 && n <27 \n");
    printf("\t\t\t ->");
    scanf("%d", &y);
    if (y > 0 && y < 27) {
        num_procesos = y;
    } else {
        cantidad_de_procesos();
    }
    printf("\n\n\t\t\t -> Num de procesos: %d \n\n", num_procesos);
    num_ale = (int *) malloc(sizeof (int)*num_procesos);
    datos = (tipoDato) malloc(sizeof (TABLA) * num_procesos);
    char letra = 'A';
    quantum = rand() % (5 - 3 + 1) + 3;
    for (i = 0; i < num_procesos; i++) {
        num_ale[i] = rand() % (20 - 1 + 1) + 1;
        datos[i].letra = letra;
        datos[i].reque_cpu = num_ale[i];
        datos[i].tiem_lle = i + 1;
        letra++;
        IngresarCola(&COL, &(datos[i]));
    }
    system("cls");
    menu_conlee();
}
// IMPRIMIR EL MODELO DEL MENÚ PRINCIPAL
void menu() {
    int i = 0;
    printf("\n\n\t\t\t ");
    for (i = 0; i < 33; i++) {
        if (i == 0)
            printf("%c", 201);
        else if (i == 32)
            printf("%c", 187);
        else
            printf("%c", 205);
    }
    printf("\n");
    printf("\t\t\t %c   P3 - METODO ROUND ROBIN     %c\n", 186, 186);
    printf("\t\t\t ");
    for (i = 0; i < 33; i++) {
        if (i == 0)
            printf("%c", 204);
        else if (i == 32)
            printf("%c", 185);
        else
            printf("%c", 205);
    }
    printf("\n");
    printf("\t\t\t %c [1] Cantidad de procesos      %c\n", 186, 186);
    printf("\t\t\t %c [2] Mostrar tabla de procesos %c\n", 186, 186);
    printf("\t\t\t %c [3] Emular paso a paso        %c\n", 186, 186);
    printf("\t\t\t %c [4] Emular completo           %c\n", 186, 186);
    printf("\t\t\t %c [5] Salir                     %c\n", 186, 186);
    printf("\t\t\t ");
    for (i = 0; i < 33; i++) {
        if (i == 0)
            printf("%c", 200);
        else if (i == 32)
            printf("%c", 188);
        else
            printf("%c", 205);
    }
    printf("\n");
}

