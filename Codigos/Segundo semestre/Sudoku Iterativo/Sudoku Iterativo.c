#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TAB 9

// Función para mostrar el tablero en la consola
void mostrarTablero(int tablero[TAB][TAB])
{
    for (int i = 0; i < TAB; i++)
    {
        for (int j = 0; j < TAB; j++)
        {
            printf("%2d", tablero[i][j]);
        }
        printf("\n");
    }
}

// Función para limpiar el tablero, estableciendo todos los elementos a cero
void limpiarTablero(int tablero[TAB][TAB])
{
    for (int i = 0; i < TAB; i++)
    {
        for (int j = 0; j < TAB; j++)
        {
            tablero[i][j] = 0;
        }
    }
}

// Funciones para verificar la existencia de un número en una fila, columna o cuadrante
int existeEnFila(int tablero[TAB][TAB], int fila, int num)
{
    for (int j = 0; j < TAB; j++)
    {
        if (tablero[fila][j] == num)
        {
            return 1; // Devuelve 1 si el número existe en la fila
        }
    }
    return 0; // Devuelve 0 si el número no existe en la fila
}

int existeEnColumna(int tablero[TAB][TAB], int columna, int num)
{
    for (int i = 0; i < TAB; i++)
    {
        if (tablero[i][columna] == num)
        {
            return 1; // Devuelve 1 si el número existe en la columna
        }
    }
    return 0; // Devuelve 0 si el número no existe en la columna
}

int existeEnCuadrante(int tablero[TAB][TAB], int fila, int columna, int num)
{
    int inicioFila = fila - (fila % 3);
    int inicioColumna = columna - (columna % 3);

    for (int i = inicioFila; i < inicioFila + 3; i++)
    {
        for (int j = inicioColumna; j < inicioColumna + 3; j++)
        {
            if (tablero[i][j] == num)
            {
                return 1; // Devuelve 1 si el número existe en el cuadrante
            }
        }
    }
    return 0; // Devuelve 0 si el número no existe en el cuadrante
}

// Genera números aleatorios en el tablero
void genNumsTablero(int tablero[TAB][TAB])
{
    srand(time(NULL));
    int cantNum = rand() % 36 + 1;

    for (int i = 0; i < cantNum; i++)
    {
        int fila = rand() % TAB;
        int columna = rand() % TAB;
        int num = 0;

        // Evita repetir números en filas, columnas o cuadrantes
        while (existeEnFila(tablero, fila, num) || existeEnColumna(tablero, columna, num) || existeEnCuadrante(tablero, fila, columna, num))
        {
            num = rand() % 9 + 1;
        }

        tablero[fila][columna] = num;
    }
}

// Resuelve el Sudoku utilizando recursión
int resolverSudoku(int tablero[TAB][TAB])
{
    int fila, columna;
    int tableroCopia[TAB][TAB];
    
    // Copia el tablero original para usarlo en la visualización
    for (fila = 0; fila < TAB; fila++)
    {
        for (columna = 0; columna < TAB; columna++)
        {
            tableroCopia[fila][columna] = tablero[fila][columna];
        }
    }

    // Recorre el tablero en busca de celdas vacías
    for (fila = 0; fila < TAB; fila++)
    {
        for (columna = 0; columna < TAB; columna++)
        {
            if (tablero[fila][columna] == 0) // Si encuentra una celda vacía
            {
                for (int num = 1; num <= 9; num++) // Intenta colocar números del 1 al 9
                {
                    // Verifica si el número es válido en la fila, columna y cuadrante
                    if (!existeEnFila(tablero, fila, num) && !existeEnColumna(tablero, columna, num) && !existeEnCuadrante(tablero, fila, columna, num))
                    {
                        tablero[fila][columna] = num; // Coloca el número

                        mostrarTablero(tableroCopia); // Muestra el tablero en cada paso

                        usleep(10000); // Pausa para visualización
                        
                        if (resolverSudoku(tablero))
                            return 1; // Si la recursión es exitosa, retorna 1

                        tablero[fila][columna] = 0; // Si la recursión falla, retrocede y prueba otro número
                    }
                }
                return 0; // Si no se encuentra solución, retorna 0
            }
        }
    }
    return 1; // Si el tablero está completo, retorna 1 (solución encontrada)
}

// Función principal
int main()
{
    int tablero[TAB][TAB];

    limpiarTablero(tablero); // Inicializa el tablero con ceros
    genNumsTablero(tablero); // Genera números aleatorios en el tablero
    mostrarTablero(tablero); // Muestra el tablero inicial

    printf("\n\nSudoku resuelto:\n");

    if (resolverSudoku(tablero))
        mostrarTablero(tablero); // Si se encuentra solución, muestra el tablero resuelto
    else
        printf("No se encontró solución.\n"); // Si no se encuentra solución, muestra un mensaje

    return 0;
}
