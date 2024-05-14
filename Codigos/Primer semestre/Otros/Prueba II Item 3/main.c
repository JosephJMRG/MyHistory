#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 5

void llenarArreglos(char arreglo1[M][N], char arreglo2[M][N]);
void ordenarArreglos(char arreglo1[M][N], char arreglo2[M][N]);
void imprimirArreglos(char arreglo1[M][N], char arreglo2[M][N]);
int main();

// Procedimiento para llenar los arreglos al azar
void llenarArreglos(char arreglo1[M][N], char arreglo2[M][N]) {
    srand(time(NULL)); // Inicializar la semilla de generación de números aleatorios

    int i = 0;
    int j = 0;

    while (i < M) {
        j = 0;

        while (j < N) {
            // Generar un número aleatorio entre 0 y 25 para las letras
            int num = rand() % 26;
            char letra = 'A' + num;

            // Generar un número aleatorio entre 0 y 9 para los dígitos
            int digito = rand() % 10;

            // Asignar el valor al arreglo1 y al arreglo2
            arreglo1[i][j] = letra;
            arreglo2[i][j] = digito + '0'; // Convertir el dígito a su representación como caracter

            j++;
        }

        i++;
    }
}

// Función para ordenar los arreglos de mayor a menor
void ordenarArreglos(char arreglo1[M][N], char arreglo2[M][N]) {
    int i = 0;
    int j = 0;

    while (i < M) {
        j = 0;

        while (j < N) {
            int k = 0;
            int l = 0;

            while (k < M) {
                l = 0;

                while (l < N) {
                    // Comparar los elementos actuales con los elementos restantes y realizar intercambios si es necesario
                    if (arreglo1[i][j] < arreglo1[k][l] || (arreglo1[i][j] == arreglo1[k][l] && arreglo2[i][j] < arreglo2[k][l])) {
                        char temp1 = arreglo1[i][j];
                        char temp2 = arreglo2[i][j];

                        arreglo1[i][j] = arreglo1[k][l];
                        arreglo2[i][j] = arreglo2[k][l];

                        arreglo1[k][l] = temp1;
                        arreglo2[k][l] = temp2;
                    }

                    l++;
                }

                k++;
            }

            j++;
        }

        i++;
    }
}

// Función para imprimir los arreglos
void imprimirArreglos(char arreglo1[M][N], char arreglo2[M][N]) {
    int i = 0;
    int j = 0;

    while (i < M) {
        j = 0;

        while (j < N) {
            printf("%c ", arreglo1[i][j]);
            printf("%c ", arreglo2[i][j]);

            j++;
        }

        printf("\n");
        i++;
    }
}

int main() {
    char arreglo1[M][N];
    char arreglo2[M][N];

    llenarArreglos(arreglo1, arreglo2);

    printf("Arreglo 1:\n");
    imprimirArreglos(arreglo1, arreglo2);

    printf("\nArreglo 2:\n");
    imprimirArreglos(arreglo1, arreglo2);

    ordenarArreglos(arreglo1, arreglo2);

    printf("\nArreglo 1 ordenado de mayor a menor:\n");
    imprimirArreglos(arreglo1, arreglo2);

    printf("\nArreglo 2 ordenado de mayor a menor:\n");
    imprimirArreglos(arreglo1, arreglo2);

    getchar();
    return 0;
}
