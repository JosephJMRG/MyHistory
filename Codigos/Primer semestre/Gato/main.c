#include <stdio.h>

char espacio1 = ' ';
char espacio2 = ' ';
char espacio3 = ' ';
char espacio4 = ' ';
char espacio5 = ' ';
char espacio6 = ' ';
char espacio7 = ' ';
char espacio8 = ' ';
char espacio9 = ' ';

char jugador1 = 'X';
char jugador2 = 'O';

void mostrarTablero() {
    printf(" %c | %c | %c \n", espacio1, espacio2, espacio3);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", espacio4, espacio5, espacio6);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", espacio7, espacio8, espacio9);
}

int verificarVictoria(char jugador) {
    if ((espacio1 == jugador && espacio2 == jugador && espacio3 == jugador) ||
        (espacio4 == jugador && espacio5 == jugador && espacio6 == jugador) ||
        (espacio7 == jugador && espacio8 == jugador && espacio9 == jugador) ||
        (espacio1 == jugador && espacio4 == jugador && espacio7 == jugador) ||
        (espacio2 == jugador && espacio5 == jugador && espacio8 == jugador) ||
        (espacio3 == jugador && espacio6 == jugador && espacio9 == jugador) ||
        (espacio1 == jugador && espacio5 == jugador && espacio9 == jugador) ||
        (espacio3 == jugador && espacio5 == jugador && espacio7 == jugador)) {
        return 1; // El jugador ha ganado
    }
    return 0; // El juego continúa
}

int main() {
    int volverAJugar = 1;

    while (volverAJugar) {
        int turno = 1;
        int posicion;

        // Reiniciar los espacios del tablero
        espacio1 = ' ';
        espacio2 = ' ';
        espacio3 = ' ';
        espacio4 = ' ';
        espacio5 = ' ';
        espacio6 = ' ';
        espacio7 = ' ';
        espacio8 = ' ';
        espacio9 = ' ';

        while (1) {
            mostrarTablero();

            if (turno % 2 == 1) {
                printf("Turno del Jugador 1 (%c). Elija una posición (1-9): ", jugador1);
                scanf("%d", &posicion);

                if (posicion >= 1 && posicion <= 9) {
                    // Aquí se agrega la validación del rango
                    if ((posicion == 1 && espacio1 == ' ') ||
                        (posicion == 2 && espacio2 == ' ') ||
                        (posicion == 3 && espacio3 == ' ') ||
                        (posicion == 4 && espacio4 == ' ') ||
                        (posicion == 5 && espacio5 == ' ') ||
                        (posicion == 6 && espacio6 == ' ') ||
                        (posicion == 7 && espacio7 == ' ') ||
                        (posicion == 8 && espacio8 == ' ') ||
                        (posicion == 9 && espacio9 == ' ')) {
                        // Movimiento válido
                        // Realiza la asignación
                        if (posicion == 1) {
                            espacio1 = jugador1;
                        } else if (posicion == 2) {
                            espacio2 = jugador1;
                        } else if (posicion == 3) {
                            espacio3 = jugador1;
                        } else if (posicion == 4) {
                            espacio4 = jugador1;
                        } else if (posicion == 5) {
                            espacio5 = jugador1;
                        } else if (posicion == 6) {
                            espacio6 = jugador1;
                        } else if (posicion == 7) {
                            espacio7 = jugador1;
                        } else if (posicion == 8) {
                            espacio8 = jugador1;
                        } else if (posicion == 9) {
                            espacio9 = jugador1;
                        }
                    } else {
                        printf("Movimiento inválido. Inténtalo de nuevo.\n");
                        continue; // Continuar al siguiente ciclo de juego sin cambiar de turno
                    }
                }

                if (verificarVictoria(jugador1)) {
                    mostrarTablero();
                    printf("¡Jugador 1 (%c) ha ganado!\n", jugador1);
                    break; // Terminar el juego
                } else if (turno == 9) {
                    mostrarTablero();
                    printf("¡Empate!\n");
                    break; // Terminar el juego en caso de empate
                }
            } else {
                printf("Turno del Jugador 2 (%c). Elija una posición (1-9): ", jugador2);
                scanf("%d", &posicion);

                // Verifica si la posición está disponible
                if (posicion == 1 && espacio1 == ' ') {
                    espacio1 = jugador2;
                } else if (posicion == 2 && espacio2 == ' ') {
                    espacio2 = jugador2;
                } else if (posicion == 3 && espacio3 == ' ') {
                    espacio3 = jugador2;
                } else if (posicion == 4 && espacio4 == ' ') {
                    espacio4 = jugador2;
                } else if (posicion == 5 && espacio5 == ' ') {
                    espacio5 = jugador2;
                } else if (posicion == 6 && espacio6 == ' ') {
                    espacio6 = jugador2;
                } else if (posicion == 7 && espacio7 == ' ') {
                    espacio7 = jugador2;
                } else if (posicion == 8 && espacio8 == ' ') {
                    espacio8 = jugador2;
                } else if (posicion == 9 && espacio9 == ' ') {
                    espacio9 = jugador2;
                } else {
                    printf("Movimiento inválido. Inténtalo de nuevo.\n");
                    continue; // Continuar al siguiente ciclo de juego sin cambiar de turno
                }

                if (verificarVictoria(jugador2)) {
                    mostrarTablero();
                    printf("¡Jugador 2 (%c) ha ganado!\n", jugador2);
                    break; // Terminar el juego
                } else if (turno == 9) {
                    mostrarTablero();
                    printf("¡Empate!\n");
                    break; // Terminar el juego en caso de empate
                }
            }

            turno++;
        }

        // Pregunta si los jugadores quieren volver a jugar
        printf("¿Desean volver a jugar? (1: Sí, 0: No): ");
        scanf("%d", &volverAJugar);

        if(volverAJugar == 2) {
            return 0;
        }

    }

    return 0;
}
