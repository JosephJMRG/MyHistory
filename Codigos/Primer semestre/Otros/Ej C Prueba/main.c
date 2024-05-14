#include <stdio.h>

int main() {
    int N;
    int contador = 0;
    int i = 1;

    printf("Ingrese un número N: ");
    scanf("%d", &N);

    while (i <= 1000) {
        if (i % N == 0) {
            contador++;
        }
        i++;
    }

    printf("La cantidad de números divisibles por %d entre 1 y 1000 es: %d\n", N, contador);

    return 0;
}
