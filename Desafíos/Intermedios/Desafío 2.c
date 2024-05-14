#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int valor;
    struct Nodo* siguiente;
};

// Stack (Pila)
struct Pila
{
    struct Nodo* top;
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

void push(struct Pila* pila, int nuevoValor) {

    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->valor = nuevoValor;
    nuevoNodo->siguiente = pila->top;
    pila->top = nuevoNodo;
}

int pop(struct Pila* pila) {
    if (pila->top == NULL)
    {
        printf("La Pila está vacía, no se puede hacer pop.\n");
        return -1;
    }

    int valorPop = pila->top->valor;
    struct Nodo* nodoPop;
    
}

int main() {

    struct Pila pila;
    pila.top = NULL;


    push(&pila, 10);
    push(&pila, 20);
    push(&pila, 30);
    push(&pila, 60);

    printf("Pila (stack) despues de Push: ");
    imprimirLista(pila.top);


    return 0;
}

