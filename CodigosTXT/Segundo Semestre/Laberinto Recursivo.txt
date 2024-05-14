#include <stdio.h>
#include <stdbool.h>

#define N 11

char laberinto[N][N];
int visitado[N][N];
int pasos[N][N];

int mov_x[] = {0, 1, 0, -1};
int mov_y[] = {1, 0, -1, 0};


int inicio_x, inicio_y;
int final_x, final_y;

void leerLab() {
    FILE *archivo = fopen("laberinto.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    // Leer el laberinto desde el archivo y cargarlo en matrices.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(archivo, " %c", &laberinto[i][j]);
            visitado[i][j] = 0; // Inicialmente, ninguna celda ha sido visitada.
            pasos[i][j] = 0; // Inicializar todos los pasos como 0.
            if (laberinto[i][j] == 'I') {
                inicio_x = i;
                inicio_y = j;
            } else if (laberinto[i][j] == 'F') {
                final_x = i;
                final_y = j;
            }
        }
    }

    // Reemplazar los caracteres '1' por '#' en el laberinto.
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (laberinto[i][j] == '1') {
                laberinto[i][j] = '#';
            }
        }
    }

    fclose(archivo);
}

int resolverLab(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return 0;
    }

    if (laberinto[x][y] == 'F') {
        return 1;
    }

    if (laberinto[x][y] == '1' || visitado[x][y] == 1) {
        return 0;
    }

    visitado[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nuevo_x = x + mov_x[i];
        int nuevo_y = y + mov_y[i];

        if (resolverLab(nuevo_x, nuevo_y)) {
            return 1;
        }
    }

    visitado[x][y] = 0;
    return 0;
}

void mostrarLabResuelto() {
    printf("\nLaberinto resuelto:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (laberinto[i][j] == '0') {
                printf("%3c", visitado[i][j] ? '.' : laberinto[i][j]);
            } else {
                printf("%3c", laberinto[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Laberinto original:\n");
    leerLab();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", laberinto[i][j]);
        }
        printf("\n");
    }

    if (resolverLab(inicio_x, inicio_y)) {
        mostrarLabResuelto();
    } else {
        printf("No se encontró un camino\n");
    }

    getchar();
    return 0;
}
