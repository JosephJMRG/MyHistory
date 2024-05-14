#include <stdio.h>

int esPrimo(int num) {
    if (num <= 1) {
        return 0;  // No se consideran números negativos ni 0 y 1 como primos
    }

    int i = 2;
    while (i * i <= num) {
        if (num % i == 0) {
            return 0;  // Si se encuentra un divisor, el número no es primo
        }
        i++;
    }

    return 1;  // Si no se encontraron divisores, el número es primo
}

int main() {
    int numero;
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &numero);

    if (esPrimo(numero)) {
        printf("%d es un número primo.\n", numero);
    } else {
        printf("%d no es un número primo.\n", numero);
    }

    return 0;
}
