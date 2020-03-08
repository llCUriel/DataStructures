#include <stdio.h>
#include <stdlib.h>
//#include "LDE.c"
#include "LSE.c"
//#include "LCSE.c"


void probarApp(){
NODO *lista = NULL;
	NODO* lista2 = NULL;
	NODO* positivos, *negativos;
	
	InsertarInicio(&lista, 4);
	InsertarInicio(&lista, -6);
	InsertarInicio(&lista, 2);
	InsertarInicio(&lista, -8);
	InsertarInicio(&lista, 3);
	InsertarInicio(&lista, -10);
	
	ImprimirLista(lista);
	printf("\n");
	
	InsertarInicio(&lista2, -9);
	InsertarInicio(&lista2, 2);
	InsertarInicio(&lista2, -8);
	InsertarInicio(&lista2, 3);
	InsertarInicio(&lista2, 3);
	InsertarInicio(&lista2, -2);
	InsertarInicio(&lista2, 1);
	
	ImprimirLista(lista2);
	printf("\n\n\n\nLISTA DE NUM POSITIVOS\n\n");	
	positivos =  retornarListaPositiva(lista, lista2);
	ImprimirLista(positivos);
	printf("\nLISTA DE NUM NEGATIVOS\n\n");
	negativos = retornarListaNegativa(lista, lista2);
	ImprimirLista(negativos);	
}
int main() {
	
	probarApp();

	/* LSE
    system("color 0E");
    NODO *cabeza = NULL;
    NODO *mi = NULL;
    int res;
    InsertarInicio(&cabeza, 5);
    InsertarInicio(&cabeza, 2);
    InsertarInicio(&cabeza, 9);
    InsertarInicio(&cabeza, 7);
    ImprimirLista(cabeza);
    res = ExisteElemento(cabeza, 4);

    if(res == 1)
        printf("\nEl elemento esta en la lista...");
    else
        printf("\nEl elemento no se encuentra en la lista...");

	mi = ordenarDeMayorAMenor(cabeza);
	ImprimirLista(mi);
	printf("%d", retornarTamanioDeLSE(cabeza));

	*/
    return 0;
}






