#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void llenarVector(int vector[], int tamano);
int calcularPromedioPares(const int vector[], int tamano);
int calcularPromedioImpares(const int vector[], int tamano);
void calcularSumaPosicionesPares(const int vector[], int tamano);
void calcularSumaPosicionesImpares(const int vector[], int tamano);
int main();


// Procedimiento para llenar el vector con números aleatorios entre 1001 y 9999
void llenarVector(int vector[], int tamano) {
    int i = 0;
    srand(time(NULL));  // Iniciar generación de números aleatorios

    while (i < tamano) {
        vector[i] = rand() % 9000 + 1001;  // Generar un número aleatorio entre 1001 y 9999
        i++;
    }
}

// Función para calcular el promedio de los números pares en el vector
int calcularPromedioPares(const int vector[], int tamano) {
    int suma = 0;
    int contador = 0;
    int i = 0;

    while (i < tamano) {
        if (vector[i] % 2 == 0) {  // Si el número es par
            suma += vector[i];
            contador++;
        }
        i++;
    }

    if (contador == 0) {
        return 0;  // Para evitar división por cero si no hay números pares
    }

    return suma / contador;
}

// Función para calcular el promedio de los números impares en el vector
int calcularPromedioImpares(const int vector[], int tamano) {
    int suma = 0;
    int contador = 0;
    int i = 0;

    while (i < tamano) {
        if (vector[i] % 2 != 0) {  // Si el número es impar
            suma += vector[i];
            contador++;
        }
        i++;
    }

    if (contador == 0) {
        return 0;  // Para evitar división por cero si no hay números impares
    }

    return suma / contador;
}

// Procedimiento para calcular la suma de los elementos en posiciones pares del vector
void calcularSumaPosicionesPares(const int vector[], int tamano) {
    int suma = 0;
    int i = 0;

    while (i < tamano) {
        if (i % 2 == 0) {  // Si la posición es par
            suma += vector[i];
        }
        i++;
    }

    printf("La suma de los elementos en posiciones pares es: %d\n", suma);
}

// Procedimiento para calcular la suma de los elementos en posiciones impares del vector
void calcularSumaPosicionesImpares(const int vector[], int tamano) {
    int suma = 0;
    int i = 0;

    while (i < tamano) {
        if (i % 2 != 0) {  // Si la posición es impar
            suma += vector[i];
        }
        i++;
    }

    printf("La suma de los elementos en posiciones impares es: %d\n", suma);
}

int main() {
    int vector[100];
    int tamano = 100;

    llenarVector(vector, tamano);  // Llenar el vector con números aleatorios

    int promedioPares = calcularPromedioPares(vector, tamano);  // Calcular el promedio de los números pares en el vector
    printf("El promedio de los numeros pares es: %d\n", promedioPares);  // Imprimir el resultado del promedio de números pares

    int promedioImpares = calcularPromedioImpares(vector, tamano);  // Calcular el promedio de los números impares en el vector
    printf("El promedio de los numeros impares es: %d\n", promedioImpares);  // Imprimir el resultado del promedio de números impares

    calcularSumaPosicionesPares(vector, tamano);  // Calcular la suma de los elementos en posiciones pares del vector
    calcularSumaPosicionesImpares(vector, tamano);  // Calcular la suma de los elementos en posiciones impares del vector
    printf("Presione ENTER para cerrar...\n");
    getchar(); // Esperar a que el usuario presione Enter
    return 0;
}
