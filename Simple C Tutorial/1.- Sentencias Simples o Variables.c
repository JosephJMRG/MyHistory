/* En este código se abarca la creacion de variables, inicializacion de variables y la impresión en
consola de las mismas. Explicado con comentarios de manera simple y detallada. */

// stdio.h es la librería predeterminada de C, con ella se trabajará en el siguiente codigo.
#include <stdio.h>

/* main() Corresponde a la "Función" (que retorna un número ENTERO) principal del codigo, aqui es donde 
se ejecuta lo que vayamos a programar. */
int main() {

    /* Sección de creación/definicion de variables */
    int a; // "int" es un número entero (cualquiera, su tamaño es de 16 bits)
    float b; // "float" es un número racional (cualquiera, su tamaño es de 32 bits)
    double b2; // "double" = "float", es un número racional (cualquiera, su tamaño es de 64 bits)
    char A; // "char" corresponde a caracteres (letras, no números), basado en ASCII
    
    /* Sección de inicialización/asignación de variables */
    a = 25; // se le ha asignado un valor a la variable "a"
    b = 56.5; // se le ha asignado un valor a la variable "b"
    b2 = 56.64615; // se le ha asignado un valor a la variable "b2"
    A = 'r'; // se le ha asignado un caracter/valor a la variable "A"

    /* Sección de impresión de variables, aquí se imprime en consola con "printf(" "\n)" por separado. */
    printf(" Impresion con \"printf(\"\")\" por separado.");
    printf("\n El valor de la variable a es: %i\n", a);
    printf("\n El valor de la variable b es: %f\n", b);
    printf("\n El valor de la variable b2 es: %f\n", b2);
    printf("\n El valor de la variable caracter A es: %c\n", A);

    /* Sección de impresión de variables, aquí se imprime en consola con "printf(" "\n)" todo junto. 
    Según el orden de variables que se quiera imprimir, se asigna el lugar de la variable, todo en un mismo
    "printf(" "\n)" (con \" puedes usar comillas sin que falle el printf("")).
    Uso correcto de "" y \"
    ESTO: printf("\nEl valor de la variable \"a\" es: %i\n", a); Forma correcta.
    NO ES LO MISMO QUE ESTO: printf("\nEl valor de la variable "a" es: %i\n", a); Forma incorrecta*/
    printf("\n Impresion con \"printf(\"\")\" en uno solo.");
    printf("\n El valor de la variable \"a\" es: %i\n"
    " El valor de la variable \"b\" es: %f\n"
    " El valor de la variable \"b2\" es: %f\n"
    " El valor de la cadena de caracteres A es: %c\n", a, b, b2, A);

    return 0;
}
 