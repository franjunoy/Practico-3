#include <stdio.h>
#include <stdlib.h>
#include "colaLista.h"

void encola(cola **inicio, cola **fin, int elem)
{
    cola *nuevo = (cola *)malloc(sizeof(cola));
    nuevo->dato = elem;
    if (estaVacia(inicio) == 0)
    {
        *inicio = nuevo;
        *fin = nuevo;
        nuevo->sgte = NULL;
    }
    else
    {
        nuevo->sgte = NULL;
        (*fin)->sgte = nuevo;
        *fin = nuevo;
    }
}
int desencola(cola **inicio, cola **fin)
{
    int valor = NULL;
    cola *nodoauxiliar;
    if (estaVacia(inicio) == 0)
    {
        return 0;
    }
    else if (*inicio == *fin)
    {
        valor = (*inicio)->dato;
        nodoauxiliar = *inicio;
        *inicio = NULL;
        *fin = NULL;
        free(nodoauxiliar);
    }
    else
    {
        valor = (*inicio)->dato;
        nodoauxiliar = *inicio;
        *inicio = (*inicio)->sgte;
        free(nodoauxiliar);
    }

    return valor;
}
int estaVacia(cola **inicio)
{
    if (*inicio == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void vaciaCola(cola **inicio)
{
    cola *nodoauxiliar = *inicio;
    while (nodoauxiliar != NULL)
    {
        *inicio = (*inicio)->sgte;
        free(nodoauxiliar);
        nodoauxiliar = *inicio;
    }
}

int ntamao(cola *inicio)
{
    int contador = 0;
    cola *nodoauxiliar = inicio;
    while (nodoauxiliar != NULL)
    {
        nodoauxiliar = nodoauxiliar->sgte;
        contador++;
    }
}
int frente(cola *inicio)
{
    return inicio->dato;
}
int main()
{
    cola *inicio;
    cola *fin;
    inicio = NULL;
    fin = NULL;
    do
    {
        printf("Menu\n");
        printf("1) Agregar un elemento\n");
        printf("2) Eliminar y retornar el primer elemento\n");
        printf("3) Retornar el primer elemento sin eliminarlo\n");
        printf("4) Vaciar la cola\n");
        printf("5) Cantidad de elementos\n");
        printf("6) Saber si hay o no elementos\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese un elemento\n");
            scanf("%d", &a);
            encola(&inicio, &fin, a);
            break;
        case 2:
            b = desencola(&inicio, &fin);
            if (b == 0)
            {
                printf("La cola no tiene elementos\n");
            }
            else
            {
                printf("Se elimino el elemento: %d\n", b);
            }
            break;
        case 3:
            printf("El primer valor es: %d\n", frente(inicio));
            break;
        case 4:
            vaciaCola(&inicio);
            fin = NULL;
            break;
        case 5:
            printf("La cantidad de elementos que posee la pila es: %d\n", ntamao(inicio));
            break;
        case 6:
            c = estaVacia(&fin);
            if (c == 0)
            {
                printf("La cola esta vacia\n");
            }
            else
            {
                printf("La cola posee elementos\n");
            }
            break;
        default:
            printf("Opcion incorrecta\n");
        }

    } while (opcion != 0);
    return 0;
}
