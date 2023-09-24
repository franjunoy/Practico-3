#include <stdio.h>
#include <stdlib.h>
#include "colaLista.h"

void encola(cola **inicio, cola **fin, int elem){
    cola *nuevo=(cola*)malloc(sizeof(cola));
    nuevo->dato=elem;
    if (estaVacia(inicio)==0){
        *inicio=nuevo;
        *fin=nuevo;
        nuevo->sgte=NULL;
    }else{
    nuevo->sgte=NULL;
    (*fin)->sgte=nuevo;
    *fin=nuevo;
    }
}
