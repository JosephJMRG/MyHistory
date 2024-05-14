#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DIGITOS 4
#define MAX_INTENTOS 5

void generarNumeroSecreto(int numeroSecreto[]) {
    srand(time(NULL));

    numeroSecreto[0] = rand() % 10;
    numeroSecreto[1] = rand() % 10;
    numeroSecreto[2] = rand() % 10;
    numeroSecreto[3] = rand() % 10;
}

void obtenerSuposicionUsuario(int suposicion[]) {
    printf("Ingresa tu suposicion de %d digitos (0-9): ", NUM_DIGITOS);

    scanf("%d", &suposicion[0]);
    scanf("%d", &suposicion[1]);
    scanf("%d", &suposicion[2]);
    scanf("%d", &suposicion[3]);
}

void calcularPuntuacion(int numeroSecreto[], int suposicion[], int* toques, int* famas) {
    *toques = 0;
    *famas = 0;
    int intentos = 0;

    if (numeroSecreto[0] == suposicion[0]) {
        (*famas)++;
        intentos++;

    } else if (numeroSecreto[0] == suposicion[1] || numeroSecreto[0] == suposicion[2] || numeroSecreto[0] == suposicion[3]) {
        (*toques)++;
        intentos++;
    }

    if (numeroSecreto[1] == suposicion[1]) {
        (*famas)++;
        intentos++;

    } else if (numeroSecreto[1] == suposicion[0] || numeroSecreto[1] == suposicion[2] || numeroSecreto[1] == suposicion[3]) {
        (*toques)++;
        intentos++;
    }

    if (numeroSecreto[2] == suposicion[2]) {
        (*famas)++;
        intentos++;

    } else if (numeroSecreto[2] == suposicion[0] || numeroSecreto[2] == suposicion[1] || numeroSecreto[2] == suposicion[3]) {
        (*toques)++;
        intentos++;
    }

    if (numeroSecreto[3] == suposicion[3]) {
        (*famas)++;
        intentos++;

    } else if (numeroSecreto[3] == suposicion[0] || numeroSecreto[3] == suposicion[1] || numeroSecreto[3] == suposicion[2]) {
        (*toques)++;
        intentos++;
    }
}

int main() {
    int numeroSecreto[NUM_DIGITOS];
    int suposicion[NUM_DIGITOS];
    int toques, famas;
    int intentos = 0;

    generarNumeroSecreto(numeroSecreto);

    printf("Esto es Toque y Fama!\n");
    printf("Adivina el numero de %d digitos.\n", NUM_DIGITOS);
    printf("Cada vez que propongas un numero, recibiras pistas de Toques y Famas.\n");

    while (intentos <= MAX_INTENTOS) {
        obtenerSuposicionUsuario(suposicion);
        calcularPuntuacion(numeroSecreto, suposicion, &toques, &famas);

        printf("Toques: %d, Famas: %d\n", toques, famas);

        if (intentos >= MAX_INTENTOS){
            printf("\n GAME OVER\n Numero de intentos superado.\n Gracias por jugar!");
        }

        intentos++;

    }

    return 0;
}
