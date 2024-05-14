

// Método de variables auxiliares

/*

#include <stdio.h>

int main() {

    int A = 0; int B = 0; int a = 0; int b = 0;

    printf("Ingresa un valor para A: ");
    scanf("%i", &A);
    printf("Ingresa un valor para B: ");
    scanf("%i", &B);

    a = B; b = A;

    printf( "Los Numeros han sido intercambiado!\n"
            "A ahora es %i. B ahora es %i", a, b);

    return 0;
}
*/


// Esta metodología puede ser util cuando se trata de optimizar codigo en materia de Referencia


/*
#include <stdio.h>

int main() {
    int A, B;

    printf("Ingresa un valor para A: ");
    scanf("%i", &A);

    printf("Ingresa un valor para B: ");
    scanf("%i", &B);

    // Intercambio de valores sin usar variables adicionales
    printf("Valor de A: %i\n", A); getchar();
    printf("Valor de B: %i\n", B); getchar();
    A = A + B;
    printf("A = A + B: %i\n", A); getchar();
    B = A - B;
    printf("B = A - B: %i\n", B); getchar();
    A = A - B;
    printf("A = A - B: %i\n", A); getchar();

    printf("Los numeros han sido intercambiados!\n"
           "A ahora es %i. B ahora es %i", A, B);

    return 0;
}
*/