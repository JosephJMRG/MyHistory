#include <stdio.h>

int esAnioBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int esFechaValida(int dia, int mes, int anio) {
    if (mes < 1 || mes > 12)
        return 0;

    if (dia < 1)
        return 0;

    if (mes == 2) {
        if (esAnioBisiesto(anio)) {
            if (dia > 29)
                return 0;
        } else {
            if (dia > 28)
                return 0;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30)
            return 0;
    } else {
        if (dia > 31)
            return 0;
    }

    return 1;
}

void obtenerFechaSiguiente(int dia, int mes, int anio, int *nuevoDia, int *nuevoMes, int *nuevoAnio) {
    *nuevoDia = dia;
    *nuevoMes = mes;
    *nuevoAnio = anio;

    if (mes == 2) {
        if (esAnioBisiesto(anio)) {
            if (dia == 29) {
                *nuevoDia = 1;
                *nuevoMes = mes + 1;
            } else {
                *nuevoDia = dia + 1;
            }
        } else {
            if (dia == 28) {
                *nuevoDia = 1;
                *nuevoMes = mes + 1;
            } else {
                *nuevoDia = dia + 1;
            }
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia == 30) {
            *nuevoDia = 1;
            *nuevoMes = mes + 1;
        } else {
            *nuevoDia = dia + 1;
        }
    } else {
        if (dia == 31) {
            if (mes == 12) {
                *nuevoDia = 1;
                *nuevoMes = 1;
                *nuevoAnio = anio + 1;
            } else {
                *nuevoDia = 1;
                *nuevoMes = mes + 1;
            }
        } else {
            *nuevoDia = dia + 1;
        }
    }
}

int main() {
    int dia, mes, anio;
    printf("Ingrese fecha dd/mm/aaaa: ");
    scanf("%d/%d/%d", &dia, &mes, &anio);

    if (!esFechaValida(dia, mes, anio)) {
        printf("Fecha ingresada no válida.\n");
        return 1;
    }

    int nuevoDia, nuevoMes, nuevoAnio;
    obtenerFechaSiguiente(dia, mes, anio, &nuevoDia, &nuevoMes, &nuevoAnio);

    printf("Fecha siguiente: %d/%d/%d\n", nuevoDia, nuevoMes, nuevoAnio);

    return 0;
}
