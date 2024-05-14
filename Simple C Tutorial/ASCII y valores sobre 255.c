#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Definir las variables
    char letra1, letra2, letra4;
    int numero;

    // Asignar variables
    letra1 = 's'; letra2 = 'i'; letra4 = '\0';
    numero = 's' * 'i';

    // Calcular valor ASCII
    letra4 = (letra1 * letra2) % 256;

    // Mostrar los resultados
    printf(" El código ASCII de \"s\" es: %d\n"
    " El código ASCII de \"i\" es: %d\n", letra1, letra2);
    printf( " El código ASCII de \"s\" * \"i\" es %d.\n", letra4);
    printf(" Simbolo ASCII de \"s\" * \"i\" es: %c\n", letra4);
    printf(" %i\n", numero);

    // Números dados
    int dividendo = 12075;
    int divisor = 255;

    // Calcular el cociente y el resto
    int cociente = dividendo / divisor;
    int resto = dividendo % divisor;

    // Mostrar el resultado
    printf("El cociente de %d entre %d es %d\n", dividendo, divisor, cociente);
    printf("El resto es %d\n", resto);


    char variableChar = 0;
    int a, b;
    a = -1; b = 1;

    printf("Presiona cualquier tecla para incrementar la variableChar.\n");

    for (int i = 0; i < 12076; i++) {

        // Incrementar número en 1
        a = a + b;

        // Mostrar los resultados
        printf("Nuevo valor: %i, Caracter: %c, Codigo ASCII: %d\n", a, variableChar, (int)variableChar);
        // Incrementar la variableChar en 1
        variableChar++;
        if ( a != 12074) {

        } else {
            getchar();
        }
    }

    char teclaPresionada;

    printf("Presiona 's' para salir.\n");

    // Leer un carácter
    scanf(" %c", &teclaPresionada);

    // Comprobar si la tecla es 's'
    if (teclaPresionada == 's') {
        printf("Saliendo...\n");
    } else {
        printf("Presionaste '%c' en lugar de 's'.\n", teclaPresionada);
    }

    return 0;
}
