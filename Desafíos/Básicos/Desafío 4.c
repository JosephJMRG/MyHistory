#include <stdio.h>

int main() {

    int A, B;
    int a, b, c, d;

    printf("Ingrese un valor para A: ");
    scanf("%i", &A);
    printf("Ingrese un valor para B: ");
    scanf("%i", &B);

    a = A + B;
    b = A - B;
    c = A * B;
    d = A / B;

    printf("La suma de \"A\" y \"B\" es: %i\n"
        "La resta de \"A\" y \"B\" es: %i\n"
        "La multiplicacion de \"A\" y \"B\" es: %i\n"
        "La division de \"A\" y \"B\" es: %i\n", a, b, c, d);
        

    return 0;
}