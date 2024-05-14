#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int valor;
    struct Nodo* siguiente;
};

void agregarElemento(struct Nodo** inicio, int nuevoValor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->valor = nuevoValor;
    nuevoNodo->siguiente = NULL;

    if (*inicio == NULL) {
        *inicio = nuevoNodo;
    } else {
        struct Nodo* ultimo = *inicio;
        while (ultimo->siguiente != NULL)
        {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = nuevoNodo;        
    }
}

void imprimirLista(struct Nodo* inicio) {
    struct Nodo* actual = inicio;
    while (actual != NULL)
    {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


void invertirLista(struct Nodo** inicio){

    struct Nodo* actual = *inicio;
    struct Nodo* siguiente = NULL;
    struct Nodo* anterior = NULL;

    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }
    *inicio = anterior;

}


int main() {

    struct Nodo* listaEnlazada = NULL;
    agregarElemento(&listaEnlazada, 10);
    agregarElemento(&listaEnlazada, 20);
    agregarElemento(&listaEnlazada, 30);
    agregarElemento(&listaEnlazada, 40);
    agregarElemento(&listaEnlazada, 50);
    agregarElemento(&listaEnlazada, 60);

    printf("Lista Original: ");
    imprimirLista(listaEnlazada);

    invertirLista(&listaEnlazada);
    printf("Lista Invertida ");
    imprimirLista(listaEnlazada);
}