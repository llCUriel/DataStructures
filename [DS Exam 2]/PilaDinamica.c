#include <stdio.h>
#include <stdlib.h>
 
/* estructura auto-referenciada */
struct nodoPila {   
   int dato;                  /* define un dato como int */
   struct nodoPila *ptrSiguiente; /* apuntador a nodoPila */
}; /* fin de la estructura nodoPila */
 
typedef struct nodoPila NodoPila; /* sinÃ³nimo de la estructura nodoPila */
typedef NodoPila *ptrNodoPila; /* sinÃ³nimo para NodoPila* */
 
/* prototipos */
void empujar( ptrNodoPila *ptrCima, int info );
int sacar( ptrNodoPila *ptrCima );
int estaVacia( ptrNodoPila ptrCima );
void imprimePila( ptrNodoPila ptrActual );
void instrucciones( void );
 
/* la funciÃ³n main comienza la ejecuciÃ³n del programa */
int main()
{ 
   ptrNodoPila ptrPila = NULL; /* apunta al tope de la pila */
   int eleccion; /* elecciÃ³n de menÃº del usuario */
   int valor;  /* entrada int del usuario */
 
   instrucciones(); /* despliega el menÃº */
   printf( "? " );
   scanf( "%d", &eleccion );
 
   /* mientras el usuario no introduzca 3 */
   while ( eleccion != 3 ) { 
 
      switch ( eleccion ) { 
 
         /* empuja el valor dentro de la pila */
         case 1:      
            printf( "Introduzca un entero: " );
            scanf( "%d", &valor );
            empujar( &ptrPila, valor );
            imprimePila( ptrPila );
            break;
 
         /* saca el valor de la pila */
         case 2:      
 
            /* si la pila no esta vacÃ­a */
            if ( !estaVacia( ptrPila ) ) {
               printf( "El valor sacsdo es %d.n", sacar( &ptrPila ) );
            } /* fin de if */
 
            imprimePila( ptrPila );
            break;
 
         default:
            printf( "Eleccion no valida.nn" );
            instrucciones();
            break;
 
      } /* fin de switch */
 
      printf( "? " );
      scanf( "%d", &eleccion );
   } /* fin de while */
 
   printf( "Fin del programa.n" );
 
   return 0; /* indica terminaciÃ³n exitosa */
 
} /* fin de main */
 
/* despliega las instrucciones del programa para el usuario */
void instrucciones( void )
{ 
   printf( "Introduzca su eleccion:n"
      "1 para empujar un valor dentro de la pilan"
      "2 para sacar un valor dwe la pilan"
      "3 para terminar el programan" );
} /* fin de la funciÃ³n instrucciones */
 
/* Inserta un nodo en la cima de la pila */
void empujar( ptrNodoPila *ptrCima, int info )
{ 
   ptrNodoPila ptrNuevo; /* apuntador al nuevo nodo */
 
   ptrNuevo = malloc( sizeof( NodoPila ) );
 
   /* inserta el nodo en la cima de la pila */
   if ( ptrNuevo != NULL ) {   
      ptrNuevo->dato = info;
      ptrNuevo->ptrSiguiente = *ptrCima;
      *ptrCima = ptrNuevo;
   } /* fin de if */
   else { /* no queda espacio disponible */
      printf( "%d no se inserto. Memoria insuficiente.n", info );
   } /* fin de else */
 
} /* fin de la funciÃ³n empujar */
 
/* Elimina un nodo de la cima de la pila */
int sacar( ptrNodoPila *ptrCima )
{ 
   ptrNodoPila ptrTemp; /* apuntador a un nodo temporal */
   int valorElim; /* valor del nodo */
 
   ptrTemp = *ptrCima;
   valorElim = ( *ptrCima )->dato;
   *ptrCima = ( *ptrCima )->ptrSiguiente;
   free( ptrTemp );
 
   return valorElim;
 
} /* fin de la funciÃ³n sacar */
 
/* Imprime la pila */
void imprimePila( ptrNodoPila ptrActual )
{ 
 
   /* si la pila esta vacÃ­a */
   if ( ptrActual == NULL ) {
      printf( "La pila esta vacia.nn" );
   } /* fin de if */
   else { 
      printf( "La pila es:n" );
 
      /* mientras no sea el final de la pila */
      while ( ptrActual != NULL ) { 
         printf( "%d --> ", ptrActual->dato );
         ptrActual = ptrActual->ptrSiguiente;
      } /* fin de while */
 
      printf( "NULLnn" );
   } /* fin de else */
 
} /* fin de la funciÃ³n imprimePila */
 
/* Devuelve 1 si la pila estÃ¡ vacÃ­a, de lo contrario 0 */
int estaVacia( ptrNodoPila ptrCima )
{ 
   return ptrCima == NULL;
 
} /* fin de la funciÃ³n estaVacia */
