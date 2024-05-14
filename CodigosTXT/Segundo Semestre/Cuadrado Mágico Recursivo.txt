#include <stdio.h>
#include <stdlib.h>
#define TAMANO 3

void inicializarTablero(int tablero[TAMANO][TAMANO]);
void mostrarTablero(int tablero[TAMANO][TAMANO]);
int buscarSolucion(int tablero[TAMANO][TAMANO], int fila, int columna);
void retroceder(int tablero[TAMANO][TAMANO], int *fila, int *columna, int *candidato);
int esValido(int tablero[TAMANO][TAMANO], int numero);
int esCuadradoMagico(int tablero[TAMANO][TAMANO]);
int esTableroCompleto(int tablero[TAMANO][TAMANO]);

int main()
{
    int tablero[TAMANO][TAMANO];
    inicializarTablero(tablero);
    if (buscarSolucion(tablero, 0, 0) == 1)
    {
        mostrarTablero(tablero);
    }
    else
    {
        printf("\nNo hay solucion\n");
    }
    return 0;
}

int buscarSolucion(int tablero[TAMANO][TAMANO], int fila, int columna)
{
    int solucion = 0, candidato = 1;

    while (candidato <= (TAMANO * TAMANO) && !solucion)
    {
        if (esValido(tablero, candidato))
        {
            tablero[fila][columna] = candidato;

            if (esTableroCompleto(tablero) == 1)
            {
                if (esCuadradoMagico(tablero))
                {
                    solucion = 1;
                }
                else
                {
                    candidato = tablero[fila][columna] + 1;
                    tablero[fila][columna] = 0;
                    while (candidato > (TAMANO * TAMANO) && !(fila == 0 && columna == 0))
                    {
                        retroceder(tablero, &fila, &columna, &candidato);
                    }
                }
            }
            else
            {
                columna++;
                candidato = 1;
                if (columna == TAMANO)
                {
                    columna = 0;
                    fila++;
                }
                solucion = buscarSolucion(tablero, fila, columna);
            }
        }
        else
        {
            candidato++;
            while (candidato > (TAMANO * TAMANO) && !(fila == 0 && columna == 0))
            {
                retroceder(tablero, &fila, &columna, &candidato);
            }
        }
    }
    return solucion;
}

void retroceder(int tablero[TAMANO][TAMANO], int *fila, int *columna, int *candidato)
{
    (*columna)--;
    if (*columna < 0)
    {
        *columna = TAMANO - 1;
        (*fila)--;
    }
    *candidato = tablero[*fila][*columna] + 1;
    tablero[*fila][*columna] = 0;
}

int esValido(int tablero[TAMANO][TAMANO], int numero)
{
    for (int i = 0; i < TAMANO; i++)
    {
        for (int j = 0; j < TAMANO; j++)
        {
            if (tablero[i][j] == numero)
            {
                return 0; // El número ya está en el tablero
            }
        }
    }
    return 1; // El número es válido
}

int esCuadradoMagico(int tablero[TAMANO][TAMANO])
{
    int sumaObjetivo = (TAMANO * (TAMANO * TAMANO + 1)) / 2;
    int sumaFila, sumaColumna;
    for (int i = 0; i < TAMANO; i++)
    {
        sumaFila = 0;
        sumaColumna = 0;
        for (int j = 0; j < TAMANO; j++)
        {
            sumaFila += tablero[i][j];
            sumaColumna += tablero[j][i];
        }
        if (sumaColumna != sumaObjetivo || sumaFila != sumaObjetivo)
        {
            return 0; // no es un cuadrado mágico
        }
    }
    int sumaDiagonalPrincipal = 0, sumaDiagonalSecundaria = 0;
    for (int i = 0; i < TAMANO; i++)
    {
        sumaDiagonalPrincipal += tablero[i][i];
        sumaDiagonalSecundaria += tablero[i][TAMANO - 1 - i];
    }
    if (sumaDiagonalPrincipal != sumaObjetivo || sumaDiagonalSecundaria != sumaObjetivo)
    {
        return 0; // no es un cuadrado mágico
    }

    return 1; // es un cuadrado mágico
}

int esTableroCompleto(int tablero[TAMANO][TAMANO])
{
    for (int i = 0; i < TAMANO; i++)
    {
        for (int j = 0; j < TAMANO; j++)
        {
            if (tablero[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void inicializarTablero(int tablero[TAMANO][TAMANO])
{
    for (int i = 0; i < TAMANO; i++)
    {
        for (int j = 0; j < TAMANO; j++)
        {
            tablero[i][j] = 0;
        }
    }
}

void mostrarTablero(int tablero[TAMANO][TAMANO])
{
    for (int i = 0; i < TAMANO; i++)
    {
        for (int j = 0; j < TAMANO; j++)
        {
            printf("%2d", tablero[i][j]);
        }
        printf("\n");
    }
}