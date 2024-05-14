#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Definir el tamaño del arreglo
#define FILAS 51
#define COLUMNAS 11

void generarNotasAleatorias(int arreglo[FILAS][COLUMNAS]);
void calcularPromedioFinal(int arreglo[FILAS][COLUMNAS]);
void calcularPromedioCurso(int arreglo[FILAS][COLUMNAS]);
int obtenerMejorAlumno(int arreglo[FILAS][COLUMNAS]);
int obtenerPeorAlumno(int arreglo[FILAS][COLUMNAS]);
void determinarEstadisticasCurso(int arreglo[FILAS][COLUMNAS]);
int main();

// Procedimiento para llenar el arreglo con notas aleatorias
void generarNotasAleatorias(int arreglo[FILAS][COLUMNAS]) {
    srand(time(NULL)); // Inicializar la semilla para generar números aleatorios

    int fila = 0;
    while (fila < FILAS) {
        int columna = 0;
        while (columna < COLUMNAS - 1) {
            arreglo[fila][columna] = rand() % 70 + 10; // Generar un número aleatorio entre 10 y 79

            // Convertir el número aleatorio a un valor de nota entre 1.0 y 7.0
            float nota = arreglo[fila][columna] / 10.0;
            arreglo[fila][columna] = nota;

            columna++;
        }
        fila++;
    }
}

// Procedimiento para calcular el promedio final de cada alumno
void calcularPromedioFinal(int arreglo[FILAS][COLUMNAS]) {
    int fila, columna;

    // Recorrer cada fila del arreglo
    fila = 0;
    while (fila < FILAS - 1) {
        int suma = 0;

        // Sumar las notas de las columnas 1 a 10 (índices 0 a 9)
        columna = 0;
        while (columna < COLUMNAS - 1) {
            suma += arreglo[fila][columna];
            columna++;
        }

        // Calcular el promedio y almacenarlo en la columna 11 (índice 10)
        arreglo[fila][10] = suma / 10;

        fila++;
    }
}

// Procedimiento para calcular el promedio de nota del curso para cada evaluación
void calcularPromedioCurso(int arreglo[FILAS][COLUMNAS]) {
    int fila, columna;

    // Recorrer cada columna del arreglo
    columna = 0;
    while (columna < COLUMNAS - 1) {
        int suma = 0;

        // Sumar las notas de las filas 1 a 50 (índices 0 a 49)
        fila = 0;
        while (fila < FILAS - 1) {
            suma += arreglo[fila][columna];
            fila++;
        }

        // Calcular el promedio y almacenarlo en la fila 51 (índice 50)
        arreglo[50][columna] = suma / 50;

        columna++;
    }
}

// Función para determinar el mejor alumno del curso
int obtenerMejorAlumno(int arreglo[FILAS][COLUMNAS]) {
    int fila = 0;
    float mejorPromedio = 0.0;
    int mejorAlumno = 0;

    // Recorrer cada fila del arreglo
    while (fila < FILAS - 1) {
        if (arreglo[fila][10] > mejorPromedio) {
            mejorPromedio = arreglo[fila][10];
            mejorAlumno = fila;
        }

        fila++;
    }

    return mejorAlumno;
}

// Función para determinar el peor alumno del curso
int obtenerPeorAlumno(int arreglo[FILAS][COLUMNAS]) {
    int fila = 0;
    float peorPromedio = 8.0;
    int peorAlumno = 0;

    // Recorrer cada fila del arreglo
    while (fila < FILAS - 1) {
        if (arreglo[fila][10] < peorPromedio) {
            peorPromedio = arreglo[fila][10];
            peorAlumno = fila;
        }

        fila++;
    }

    return peorAlumno;
}

// Procedimiento para determinar el porcentaje de aprobados, reprobados y el promedio del curso
void determinarEstadisticasCurso(int arreglo[FILAS][COLUMNAS]) {
    int aprobados = 0;
    int reprobados = 0;
    float suma = 0.0;
    int fila = 0;

    // Recorrer cada fila del arreglo
    while (fila < FILAS - 1) {
        suma += arreglo[fila][10];

        if (arreglo[fila][10] >= 4.0) {
            aprobados++;
        } else {
            reprobados++;
        }

        fila++;
    }

    float promedioCurso = suma / (FILAS - 1);

    printf("Porcentaje de aprobados: %.2f%%\n", (float)aprobados * 100.0 / (FILAS - 1));
    printf("Porcentaje de reprobados: %.2f%%\n", (float)reprobados * 100.0 / (FILAS - 1));
    printf("Promedio del curso: %.1f\n", promedioCurso);
}

int main() {

    int notas[FILAS][COLUMNAS];
    // Generar notas aleatorias
    generarNotasAleatorias(notas);

    // Aquí se insertaría código para llenar el arreglo con las notas de los alumnos
    calcularPromedioFinal(notas);
    calcularPromedioCurso(notas);

    int mejorAlumno = obtenerMejorAlumno(notas);
    printf("El mejor alumno obtuvo: %.1f\n", (float)notas[mejorAlumno][10]);
    int peorAlumno = obtenerPeorAlumno(notas);
    printf("El peor alumno obtuvo: %.1f\n", (float)notas[peorAlumno][10]);

    determinarEstadisticasCurso(notas);

    return 0;
}

