#include <stdio.h>
#include <stdbool.h>

#define N 5

int movX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int movY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool esMovimientoValido(int x, int y, int tablero[N][N]) {
    return (x >= 0 && y >= 0 && x < N && y < N && tablero[x][y] == 0);
}

void imprimirTablero(int tablero[N][N]) {
    static int contadorSoluciones = 1;  // Variable estática para rastrear el número de soluciones
    printf("Solución %d:\n", contadorSoluciones++);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void encontrarSoluciones() {
    int tablero[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    tablero[x][y] = 0;
                }
            }

            int x = 0;
            int y = 0;
            int movimientos = 1;

            while (movimientos <= N * N) {
                tablero[x][y] = movimientos;

                bool movimientoEncontrado = false;

                for (int k = 0; k < 8; k++) {
                    int nuevoX = x + movX[k];
                    int nuevoY = y + movY[k];

                    if (esMovimientoValido(nuevoX, nuevoY, tablero)) {
                        x = nuevoX;
                        y = nuevoY;
                        movimientoEncontrado = true;
                        break;
                    }
                }

                if (!movimientoEncontrado) {
                    break;  // No hay movimientos válidos, terminar
                }

                movimientos++;
            }

            // Imprimir la solución encontrada
            imprimirTablero(tablero);
        }
    }
}

int main() {
    encontrarSoluciones();
    getchar();
    return 0;
}
