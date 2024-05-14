#include <stdio.h>

int main() {
    int n;
    int suma = 0;
    int i = 1;

    printf("Ingrese un valor para n: ");
    scanf("%d", &n);

    while (i <= 100) {
        int termino = 3 * i * n;
        suma += termino;
        i++;
    }

    printf("La suma de los primeros 100 terminos de la serie es: %d\n", suma);

    return 0;
}
