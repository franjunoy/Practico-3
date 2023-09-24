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
int desencola (cola **inicio, cola **fin){
    int valor = NULL ;
    cola *nodoauxiliar;
    if(estaVacia(inicio)==0){
        return 0;
    }
    else if(*inicio==*fin){
        valor=(*inicio)->dato;
        nodoauxiliar=*inicio;
        *inicio=NULL;
        *fin=NULL;
        free(nodoauxiliar);
    }else{
        valor=(*inicio)->dato;
        nodoauxiliar=*inicio;
        *inicio=(*inicio)->sgte;
        free(nodoauxiliar);
    }

    return valor;
}
int estaVacia(cola **inicio){
    if(*inicio==NULL){
        return 0;
    }else{
    return 1;
    }
}
