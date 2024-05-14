#include <stdio.h>

int main() {
    int lado1, lado2, lado3;

    printf("Ingrese la longitud del primer lado: ");
    scanf("%f", &lado1);

    printf("Ingrese la longitud del segundo lado: ");
    scanf("%f", &lado2);

    printf("Ingrese la longitud del tercer lado: ");
    scanf("%f", &lado3);

    if (lado1 == lado2 && lado2 == lado3) {
        printf("El triángulo es equilátero");
    } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
        printf("El triángulo es isósceles");
    } else {
        printf("El triángulo es escaleno");
    }

    return 0;
}
