#include <stdio.h>
#include <math.h>

int OctalADecimal(int NumOctal) {
    int NumDecimal = 0, i = 0, remainder;

    while (NumOctal != 0) {
        remainder = NumOctal % 10;
        NumOctal /= 10;
        NumDecimal += remainder * pow(8, i);
        ++i;
    }

    return NumDecimal;
}

int main() {
    int NumOctal;

    printf("Ingrese un numero octal: ");
    scanf("%d", &NumOctal);

    printf("El numero decimal es: %d\n", OctalADecimal(NumOctal));

    return 0;
}
