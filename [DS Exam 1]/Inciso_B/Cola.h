#include<stdio.h>
#define TAM 100


typedef struct cola{

    int CListaCola[TAM];
    int frente;
    int fin;

}COLA;

void CrearCola(COLA*);
void IngresarCola(COLA *, int C);
int sacarCola(COLA *);
int Colallena(COLA);
int ColaVacia(COLA);
int FrenteCola(COLA);
