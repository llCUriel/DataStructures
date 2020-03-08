#include <stdio.h>
#include <stdlib.h>
#include "LDE2.c"


int main() {
    system("color 0E");
    NODO *cabeza = NULL;
    solicitarDatAlUsuario(&cabeza);
    printf("\n\n > Su lista doblemente enlazada es la siguiente: \n\n");
    ImprimirLista(cabeza);
    mostrarSubListaMax(cabeza);
    return 0;
}




