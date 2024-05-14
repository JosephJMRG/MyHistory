#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 8  // Cambia N al tamaño del tablero que desees

bool esSeguro(int tablero[N][N], int fila, int columna) {
    // Verifica si no hay reinas en la misma columna
    for (int i = 0; i < fila; i++) {
        if (tablero[i][columna])
            return false;
    }

    // Verifica la diagonal superior izquierda
    for (int i = fila, j = columna; i >= 0 && j >= 0; i--, j--) {
        if (tablero[i][j])
            return false;
    }

    // Verifica la diagonal superior derecha
    for (int i = fila, j = columna; i >= 0 && j < N; i--, j++) {
        if (tablero[i][j])
            return false;
    }

    return true;
}

void imprimirTablero(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", tablero[i][j]);
        }
        printf("\n");
    }
}

bool resolverNReinasRecursivo(int tablero[N][N], int fila) {
    if (fila == N) {
        static int soluciones = 0;
        soluciones++;
        printf("Solucion %d:\n", soluciones);
        imprimirTablero(tablero);
        printf("\n");
        return true;
    }

    bool encontrada = false;

    for (int columna = 0; columna < N; columna++) {
        if (esSeguro(tablero, fila, columna)) {
            tablero[fila][columna] = 1;
            encontrada = resolverNReinasRecursivo(tablero, fila + 1) || encontrada;
            tablero[fila][columna] = 0;  // Retrocede
        }
    }

    return encontrada;
}

void encontrarSoluciones() {
    int tablero[N][N] = {0}; // Inicializa el tablero con ceros
    resolverNReinasRecursivo(tablero, 0);
}

int main() {
    encontrarSoluciones();
    system("pause");
    return 0;
}
