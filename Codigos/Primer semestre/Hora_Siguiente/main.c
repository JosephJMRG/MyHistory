#include <stdio.h>

int main() {
    int h, m, s;

    printf("Ingrese Hora hh:mm:ss\n");
    scanf("%d:%d:%d", &h, &m, &s);

    if (h > 23) {
        printf("Ha excedido la cantidad de horas\n");
    } else {
        if (s < 59) {
            printf("Son las %d:%d:%d\n", h, m, s + 1);
        } else {
            if (m < 59) {
                printf("Son las %d:%d:00\n", h, m + 1);
            } else {
                if (h < 23) {
                    printf("Son las %d:00:00\n", h + 1);
                } else {
                    printf("Son las 00:00:00\n");
                }
            }
        }
    }
    return 0;
}
