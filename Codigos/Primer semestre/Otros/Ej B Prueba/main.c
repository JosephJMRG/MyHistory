#include <stdio.h>

// Función para determinar si un número es primo o no
int es_primo(int num) {
    if (num < 2) {
        return 0;
    }
    int i = 2;
    while (i <= (int)(num / 2)) {
        if (num % i == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    // Contador de números primos
    int cantidad_primos = 0;

    int num = 3;
    while (num <= 100) {
        if (es_primo(num)) {
            cantidad_primos++;
        }
        num++;
    }

    // Imprimir el resultado
    printf("La cantidad de números primos entre 3 y 100 es: %d\n", cantidad_primos);

    return 0;
}
