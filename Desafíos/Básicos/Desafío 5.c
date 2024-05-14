#include <stdio.h>

int main()
{

    int primo;

    printf("Ingrese un numero: ");
    scanf("%i", &primo);

    int i = 2;
    int verificarPrimo = 0;

    while (i * i <= primo)
    {
        if (primo % i == 0)
        {
            verificarPrimo = 1;
        }
        i++;
    }
    
    if (verificarPrimo == 1)
    {
        printf("El numero no es Primo\n");
    } else
    {
        printf("El numero es Primo\n");
    }
    
    return 0;
}
