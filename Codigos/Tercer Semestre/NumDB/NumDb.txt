#include <stdio.h>

void DecimalABinario(int NumDecimal) {
    int NumBinario[32];
    int i = 0;
    int contarCeros = 0;

    // Casos especiales
    if (NumDecimal == 0) {
        printf("El numero binario es: 0\n");
        printf("El Numero es diabolico\n");
        return;
    } else if (NumDecimal < 0) {
        printf("Los numeros negativos no estan soportados.\n");
        return;
    }

    // Convertir el número decimal a binario
    while (NumDecimal > 0) {
        NumBinario[i] = NumDecimal % 2;
        if (NumBinario[i] == 0) {
            contarCeros++;
        }
        NumDecimal = NumDecimal / 2;
        i++;
    }

    // Imprimir el número binario en orden invertido
    printf("El numero binario es: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", NumBinario[j]);
    }
    printf("\n");

    // Condicion si es o no diabólico
    if (contarCeros % 2 != 0) {
        printf("El Numero es diabolico\n");
    } else {
        printf("El Numero NO es diabolico\n");
    }
}

int main() {
    int NumDecimal;

    printf("Ingrese un numero decimal positivo: ");
    scanf("%d", &NumDecimal);

    DecimalABinario(NumDecimal);

    return 0;
}
