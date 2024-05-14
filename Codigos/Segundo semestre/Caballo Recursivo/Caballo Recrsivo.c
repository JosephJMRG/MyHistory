#include <stdio.h>
#include <stdbool.h>

#define N 5  // Cambia N al tamaño del tablero que desees


int movX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int movY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool esMovimientoValido(int x, int y, int tablero[N][N]) {
    return (x >= 0 && y >= 0 && x < N && y < N && tablero[x][y] == 0);
}

void imprimirTablero(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool recorrerTablero(int tablero[N][N], int x, int y, int movimientos,int *soluciones) {
    if (movimientos == N * N) {
        (*soluciones)++;
        printf("Solución %d:\n", *soluciones);
        imprimirTablero(tablero);
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int nuevoX = x + movX[i];
        int nuevoY = y + movY[i];

        if (esMovimientoValido(nuevoX, nuevoY, tablero)) {
            tablero[nuevoX][nuevoY] = movimientos + 1;

            if (recorrerTablero(tablero, nuevoX, nuevoY, movimientos + 1, soluciones)) {
                // Continuar buscando más soluciones
                tablero[nuevoX][nuevoY] = 0; // Retroceder
            } else {
                tablero[nuevoX][nuevoY] = 0; // Retroceder
            }
        }
    }

    return false;
}

void encontrarSoluciones() {
    int tablero[N][N] = {0};
    tablero[0][0] = 1;
    int soluciones = 0;
    recorrerTablero(tablero, 0, 0, 1,&soluciones);
}

int main() {
    encontrarSoluciones();
    return 0;
}
