/* En este código se abarca la creacion de Macros (variables accesibles en todo el codigo), operaciones con 
variables y la impresión en consola de las mismas, ademas de aprender a pedir al usuario valores y asignarles 
esos valores a variables. Explicado con comentarios de manera simple y detallada. */

// stdio.h, librería predeterminada de C, con ella se trabajará en el siguiente codigo.
#include <stdio.h>

/* Aquí se crea la Macro (variable numerica), con "#define <nombre variable> <valor>, dependiendo si asignamos 
un valor int, float, double, debemos especificarlo luego en la funcion para que imprima correctamente */
#define lmao 25 //tipo int
#define lmao2 3.1415 // tipo float
#define lmao3 3.14159 // tipo double

// Funcion principal del código
int main() {

    // Definiciones de variables (numéricas)
    int a;
    float b;
    double b2;

    // Asignación de variables con la Macro (numéricas)
    a = lmao;
    b = lmao2;
    b2 = lmao3;

    // Impresión en consola
    printf(" El valor de \"a\" es: %i\n"
        " El valor de \"b\" es: %f\n"
        " El valor de \"b2 es: %f\n", a, b, b2);
    
    // Definicion de variables (input del usuario)
    int abc;

    // Consulta al usuario por un valor
    printf("\n Ingrese un valor (entero) para variable \"abc\": ");
    /* scanf("") será el input del usuario asignado a una variable, y se debe usa "&" (ampersand) para
    asignarle el valor (el input) a la variable */
    scanf("%i", &abc);

    // Imprimir en consola
    printf(" Valor de variable \"abc\" es: %i\n", abc);

    /* Operar con las variables anteriores, aquí se le asigna una operación a la variable abc (ya definida, 
    no se puede asignar operaciones a variables no definidas anteriormente).
    Operaciones Básicas, son las mismas que en matemáticas:
    Suma (1+1), Resta (1-1), Multiplicación (1*1), Division (1/1). Además tambien puedes hacer operaciones con
    numeros sin la necesidad de hacerlo entre variables. Por ejemplo: a = a * 15. Esto es válido para toda
    operación con números (int, float, double), sin embargo con char funciona de manera diferente. */
    a = abc * a;
    b = abc * b;
    b2 = abc * b2;

    // Imprimir las operaciones realizadas
    printf(" Nuevo valor de \"a\" es: %i\n"
        " Nuevo valor de \"b\" es: %f\n"
        " Nuevo valor de \"b2\" es: %f\n", a, b, b2);

    return 0;
}
