#include <stdio.h>

// Función para verificar si un número es perfecto
int es_perfecto(int num) {
    int suma = 0;
    int i = 1;
    while (i < num) {
        if (num % i == 0) {
            suma += i;
        }
        i++;
    }
    return suma == num;
}

int main() {
    int n;
    printf("Introduce un número: ");
    scanf("%d", &n);

    printf("Números perfectos hasta %d:\n", n);

    int i = 1;
    while (i <= n) {
        if (es_perfecto(i)) {
            printf("%d\n", i);
        }
        i++;
    }

    return 0;
}
