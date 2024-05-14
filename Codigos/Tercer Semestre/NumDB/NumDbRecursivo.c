#include <stdio.h>

int contarCeros(int NumBinario[], int posicion) {

    if (posicion < 0)
    {
        return 0;
    }
    
    int cerosRestantes = contarCeros(NumBinario, posicion - 1);

    if (NumBinario[posicion] == 0)
    {
        return cerosRestantes + 1;
    }
    
    return cerosRestantes;

}

void esDiabolico(int NumBinario[], int posicion) {

    int cerosTotales = contarCeros(NumBinario, posicion);

    if (cerosTotales % 2 != 0)
    {
        printf("El Numero es diabolico");
    } else {
        printf("El Numero No es diabolico");
    }
}

void DecimalABinario(int NumDecimal) {
    int NumBinario[32]; 
    int i = 0;

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
        NumDecimal = NumDecimal / 2;
        i++;
    }

    // Imprimir el número binario en orden invertido
    printf("El numero binario es: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", NumBinario[j]);
    }
    printf("\n");

    // Llamada para saber si es o no Diabólico
    esDiabolico(NumBinario, i - 1);
    // (i - 1) representa el último dígito en la representación binaria del número
    
}

int main() {
    int NumDecimal;

    printf("Ingrese un numero decimal positivo: ");
    scanf("%d", &NumDecimal);

    DecimalABinario(NumDecimal);

    return 0;
}

// int contarCeros = 0;

/*
if (NumBinario[i] == 0) {
            contarCeros++;
        }
// Condicion si es o no diabólico
    if (contarCeros % 2 != 0) {
        printf("El Numero es diabolico\n");
    } else {
        printf("El Numero NO es diabolico\n");
    }
*/
