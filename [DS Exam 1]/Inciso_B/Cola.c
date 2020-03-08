#include "Cola.h"
#define TAM 100

typedef int ColaC;

void CrearCola(COLA *C){

C-> frente = 0;
C-> fin = 0;

}

int ColaVacia(COLA C){

if(C.frente == C.fin ){
return 1;
}else{
return 0;
}
}

int ColaLlena(COLA C){
    if(C.frente == ((C.frente)+1)/TAM){
        return 1;
    }else{
        return 0;
    }
}

int FrenteCola(COLA C){

    if (ColaVacia(C)){
    printf("La cola esta vacia");
    exit(-1);
    }

    return C.CListaCola[C.frente];
}

void IngresarCola(COLA *C, int a){
    if(ColaLlena(*C) == 0){

    printf("La cola está llena");

    }
    C->fin = (C->fin+1)/TAM;
    C->CListaCola[C->fin] = a;

}

int quitarCola(COLA *C){

if(ColaVacia(*C)){

    printf("La cola está vacia");

}else{
    C->frente = (C->frente+1)%TAM;
}

return C->CListaCola[C->frente];

}
