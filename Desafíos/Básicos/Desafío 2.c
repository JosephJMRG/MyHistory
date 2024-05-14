#include <stdio.h>

int main()
{

    char nombre[20];
    int edad;

    printf("Cual es tu Primer Nombre: ");
    scanf("%s", &nombre);
    printf("Cual es tu Edad: ");
    scanf("%i", &edad);

    printf("Hola, %s! Tienes %i anios.", nombre, edad);

    return 0;
}