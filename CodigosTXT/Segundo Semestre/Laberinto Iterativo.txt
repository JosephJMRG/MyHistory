#include <stdio.h>
#include <stdbool.h>

#define N 11 // Define N con valor 11 para el tamaño del laberinto

char laberinto[N][N]; // Declara una matriz para el laberinto.
int visitado[N][N]; // Declara una matriz para rastrear celdas visitadas.
int pasos[N][N]; // Declara una matriz para rastrear el número de pasos.

// Matrices para definir la dirección de los movimientos (arriba, derecha, abajo, izquierda)
int mov_x[] = {0, 1, 0, -1};
int mov_y[] = {1, 0, -1, 0};

// Declaración de variables globales para el inicio y final del laberinto
int inicio_x, inicio_y;
int final_x, final_y;

/* Este módulo se encarga de leer el archivo .txt con el laberinto para cargarlo al programa
   además de hacerlo un poco más legible, convirtiendo los '1' en '#', para interpretar que son
   paredes
*/
void leerLab() {
    // Apertura del archivo .txt
    FILE *archivo = fopen("laberinto.txt", "r");
    // Verificación si se ha abierto correctamente el archivo
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

    fclose(archivo); // Cerrar el archivo después de leer los datos.
}

// Función para resolver un laberinto.
int resolverLab() {
    leerLab();  // Lee el laberinto desde alguna fuente, no se proporciona en el código.

    int x = inicio_x;  // Inicializa la posición actual en 'x' con la coordenada de inicio.
    int y = inicio_y;  // Inicializa la posición actual en 'y' con la coordenada de inicio.
    int paso = 0;      // Inicializa el contador de pasos a 0.

    // Comienza un bucle principal que continuará hasta encontrar la solución o no haya camino.
    while (true) {
        pasos[x][y] = paso;  // Asigna el número de paso a la celda actual.

        bool encontrado = false;  // Indica si hemos llegado al final del laberinto.
        bool retroceder = true;  // Indica si debemos retroceder en caso de no encontrar movimiento válido.

        // Bucle para explorar las cuatro direcciones posibles desde la posición actual.
        for (int i = 0; i < 4; i++) {
            int nuevo_x = x + mov_x[i];  // Calcula la nueva posición en x.
            int nuevo_y = y + mov_y[i];  // Calcula la nueva posición en y.

            if (nuevo_x == final_x && nuevo_y == final_y) {
                // Hemos llegado al final del laberinto.
                visitado[nuevo_x][nuevo_y] = 1;
                encontrado = true;
                break;
            }

            // Comprueba si las coordenadas (nuevo_x, nuevo_y) están dentro de los límites del laberinto,
            // si la celda no es una pared (representada por '0') y si la celda no ha sido visitada previamente.
            if (nuevo_x >= 0 && nuevo_x < N && nuevo_y >= 0 && nuevo_y < N &&
                laberinto[nuevo_x][nuevo_y] == '0' && visitado[nuevo_x][nuevo_y] == 0) {

                visitado[nuevo_x][nuevo_y] = 1;  // Marca la celda como visitada.
                x = nuevo_x;  // Actualiza la posición actual en x.
                y = nuevo_y;  // Actualiza la posición actual en y.
                paso++;        // Incrementa el número de paso.
                retroceder = false;  // Indica que se encontró un movimiento válido y no es necesario retroceder.
                break;
            }
        }

        if (encontrado) {
            break;  // Si hemos encontrado el final, salimos del bucle principal.
        }

        if (retroceder) {
            visitado[x][y] = 1;  // Marca la celda actual como visitada.

            if (x == inicio_x && y == inicio_y) {
                // Hemos vuelto a la posición de inicio y no se ha encontrado un camino válido.
                break;  // Salimos del bucle principal porque no hay camino válido.
            }

            // Retrocede a la celda anterior si no hay movimientos válidos desde la posición actual.
            for (int i = 0; i < 4; i++) {
                int anterior_x = x - mov_x[i];
                int anterior_y = y - mov_y[i];

                if (anterior_x >= 0 && anterior_x < N && anterior_y >= 0 && anterior_y < N &&
                    visitado[anterior_x][anterior_y] == 0) {
                    x = anterior_x;  // Actualiza la posición actual en x.
                    y = anterior_y;  // Actualiza la posición actual en y.
                    break;  // Salimos del bucle de retroceso.
                }
            }
        }
    }

    return paso;  // Devuelve el número total de pasos realizados para resolver el laberinto.
}

// Función para mostrar el laberinto resuelto.
void mostrarLabResuelto() {
    printf("\nLaberinto resuelto:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (laberinto[i][j] == '0') {
                if (pasos[i][j] > 0) {
                    printf("%3d", pasos[i][j]); // Mostrar el número de pasos si es mayor que 0.
                } else {
                    printf("%3c", laberinto[i][j]); // Mostrar '0' si no se ha resuelto esta celda.
                }
            } else {
                printf("%3c", laberinto[i][j]); // Mostrar otros caracteres como '1', '#', 'I', 'F', etc.
            }
        }
        printf("\n"); // Salto de línea al final de cada fila del laberinto.
    }
}

int main() {
    printf("Laberinto original:\n"); // Muestra un encabezado indicando el laberinto original.
    leerLab(); // Llama a la función leerLab() para cargar el laberinto.

    // Itera a través de la matriz del laberinto y la muestra en la consola.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", laberinto[i][j]); // Muestra cada celda del laberinto.
        }
        printf("\n"); // Salto de línea al final de cada fila del laberinto.
    }

    int totalPasos = resolverLab(); // Llama a la función resolverLab() para resolver el laberinto.

    if (totalPasos > 0) {
        mostrarLabResuelto(); // Si se encontró un camino, llama a la función mostrarLabResuelto() para mostrar el laberinto resuelto.
    } else {
        printf("No se encontro un camino\n"); // Si no se encontró un camino, muestra un mensaje de error.
    }

    getchar(); // Espera a que el usuario presione Enter antes de salir del programa.
    return 0; // Devuelve 0 para indicar una ejecución exitosa del programa.
}
