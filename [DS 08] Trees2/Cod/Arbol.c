/*
	INSTITUTO POLITÉCNICO NACIONAL
	ESCUELA SUPERIOR DE CÓMPUTO
	ESTRUCTURAS DE DATOS
	GRUPO: 1CV7
	ALUMNOS (AUTORES DE SOLAMENTE LAS FUNCIONES AÑADIDAS): 
		HERNÁNDEZ CASTELLANOS CÉSAR URIEL
		MARTÍNEZ ISLAS MAURICO JOEL
	PROFESOR: BENJAMÍN LUNA BENOSO 
	IMPLEMENTACIÓN DE LAS FUNCIONES DE ARBOL
	FECHA: 24/5/17
*/

#include "Arbol.h"

Nodo* CrearNodo(Item valor, Nodo* padre) {
    Nodo* nuevoNodo = (Nodo *) malloc(sizeof (Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izq = nuevoNodo->der = NULL;
    nuevoNodo->padre = padre;
    return nuevoNodo;
}

void DestruirNodo(Nodo* nodo) {
    nodo->izq = nodo->der = NULL;
    free(nodo);
}

static void InsertarConPadre(Nodo** arbol, Nodo*padre, Item valor) {
    if (*arbol == NULL) {
        *arbol = CrearNodo(valor, padre);
    } else {
        int valorRaiz = (*arbol)->valor;
        if (valor < valorRaiz) {
            InsertarConPadre(&(*arbol)->izq, *arbol, valor);
        } else {
            InsertarConPadre(&(*arbol)->der, *arbol, valor);
        }
    }
}

void Insertar(Nodo** arbol, Item valor) {
    InsertarConPadre(arbol, NULL, valor);
}

int ExisteNodo(Nodo* arbol, Item valor) {
    if (arbol == NULL) {
        return 0;
    } else if (arbol->valor == valor) {
        return 1;
    } else if (valor < arbol->valor) {
        return ExisteNodo(arbol->izq, valor);
    } else {
        return ExisteNodo(arbol->der, valor);
    }
}

Nodo* ObtenerNodo(Nodo* arbol, Item valor) {
    if (arbol == NULL) {
        return NULL;
    } else if (arbol->valor == valor) {
        return arbol;
    } else if (valor < arbol->valor) {
        return ObtenerNodo(arbol->izq, valor);
    } else {
        return ObtenerNodo(arbol->der, valor);
    }
}

void DeterminarExistencia(Nodo* arbol, Item valor) {
    if (ExisteNodo(arbol, valor)) {
        printf("El nodo %d existe en el arbol. \n", valor);
    } else {
        printf("El nodo %d NO existe en el arbol.\n", valor);
    }
}

static void Reemplazar(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->padre) {
        if (arbol->valor == arbol->padre->izq->valor) {
            arbol->padre->izq = nuevoNodo;
        } else if (arbol->valor == arbol->padre->der->valor) {
            arbol->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
}

void Preorden(Nodo* arbol) {
    if (arbol == NULL) {
    } else {
        printf("(%c", arbol->valor);
        Preorden(arbol->izq);
        Preorden(arbol->der);
        printf(")");
    }
}

void Inorden(Nodo* arbol) {
    if (arbol != NULL) {
        printf("(");
        Inorden(arbol->izq);
        printf("%c", arbol->valor);
        Inorden(arbol->der);
        printf(")");
    }
}

static void EliminarNodo(Nodo* nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		
	}else if(nodoEliminar->izq){
		Reemplazar(nodoEliminar, nodoEliminar->izq);
		DestruirNodo(nodoEliminar);
	}else if(nodoEliminar->der){
		Reemplazar(nodoEliminar, nodoEliminar->der);
		DestruirNodo(nodoEliminar);		
	}else{
	Reemplazar(nodoEliminar, NULL);
	DestruirNodo(nodoEliminar);
	}
}

void Eliminar(Nodo* arbol, Item valor){
	if(arbol == NULL){
		return;
	}else if(valor < arbol->valor){
		Eliminar(arbol->izq, valor);
	}else if(valor > arbol->valor){
		Eliminar(arbol->der, valor);
	}else{
		EliminarNodo(arbol);
	}
}

void PostOrden(Nodo* arbol) {
    if (arbol == NULL) {
    } else {
        printf("(");
        PostOrden(arbol->izq);
        PostOrden(arbol->der);
        printf("%c", arbol->valor);
        printf(")");
    }
}

//las dos funciones de los dos incisos de la practica:

//caminos de raiz-hoja

void rootLeafPaths(Nodo* arbol, PILA p) {
	//es recorrer el arbol en orden pero se lleva una pila
	/*surgieron problemas aqui cuando se intento poner la pila como
	variable global, simplemente no tenian efecto las funciones sobre la pila global,
	asi que se puso como una local que se fuera copiando durante todo el camino*/
	if (arbol != NULL) {
		InsertarPila(&p, arbol->valor);
        rootLeafPaths(arbol->izq, p);
        if(arbol->der == NULL && arbol->izq == NULL){
        	reverseStackPrint(p);
		}
        rootLeafPaths(arbol->der, p);
    }
    //como las pilas son locales, pues no se le quita nada a la pila (por que se crean un monton)
}

//meter arbol de expresion

Arbol* inputExprTree(char *inString){
	int i=0;
	Arbol *arbol = NULL, *raiz = NULL;
	for(i=0;i<strlen(inString);i++){
		if(inString[i]=='('){
			if(!arbol){
				arbol = CrearNodo(' ', arbol); //si es el primero, conviertelo en la raiz
				raiz = arbol;	
			}else{
				if (!arbol->izq)
					arbol = arbol->izq = CrearNodo(' ', arbol);
				else
					arbol = arbol->der = CrearNodo(' ', arbol);
			}
		}else if(inString[i]==')'){
			arbol = arbol->padre; //ya se cierra una operacion
		}else if(inString[i]=='+' || inString[i]=='-' || inString[i]=='*' || inString[i]=='/' || inString[i]=='*' || inString[i]=='^'){
			arbol->valor = inString[i]; //no se desplaza de su posicion si es operador
		}else{//si ya es una constante
			if (!arbol->izq)
				arbol->izq = CrearNodo(inString[i], arbol);
			else
				arbol->der = CrearNodo(inString[i], arbol);
		}
	}
	return raiz; //regresa la raiz que se asigno al primer parentesis
}

//begin avl tree functions
 	
int max(int a, int b){
	if (a>=b){
		return a
	}else if (a>=b){
		return b
	}
}
 	
int depth(node* n){
	if(n==NULL)
		return 0;
	else
		return max(depth(n->left), depth(n->right)) + 1
}

int balFactor(node* n){
	return (depth(n->left) - depth(n->right))	
}

