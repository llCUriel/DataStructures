/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS: 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	IMPLEMENTACIÓN DE RUTAS RAIZ-HOJA DE ARBOL
	FECHA: 24/5/17
*/
#include "Arbol.c"
 
int main() {
	PILA p;
	CrearPila(&p);
    Arbol* arbol = NULL;
    
    //se lleno asi solamente por probar el programa
    arbol = CrearNodo('a', arbol);
    arbol->izq = CrearNodo('b', arbol);
    arbol->izq->izq = CrearNodo('d', arbol->izq);
    arbol->izq->izq->izq = CrearNodo('f', arbol->izq->izq);
    arbol->izq->der = CrearNodo('e', arbol->izq);
    arbol->der = CrearNodo('c', arbol);
	arbol->der->der = CrearNodo('g', arbol->der);
	arbol->der->der->der = CrearNodo('h', arbol->der->der);
	arbol->der->der->izq = CrearNodo('i', arbol->der->der);
	//hasta aqui es el codigo duro de llenado
	
    printf("rutas (vease arbol usado en documentacion)\n");
    rootLeafPaths(arbol, p);
    return 0;
}



