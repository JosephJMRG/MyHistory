/* Ahora ampliaremos conocimiento respecto a lo anteriormente visto. Aprenderemos más sobre sintaxis y otros
aspectos que pueden ayudar a comprender lo que sucede detrás de lo que se programa y simplificar la forma 
de escribir código */

// stdio.h, librería predeterminada de C, con ella se trabajará en el siguiente codigo.
#include <stdio.h>

/* mat.h es una librería que expande las operaciones matemáticas, esto permite tener muchas más operaciones 
que solo las 4 operaciones básicas */
#include <math.h>

// Función principal
int main() {

    /* En vez de escribir dos veces <tipo de variable> <nombre de variable>, podemos juntar las variables en 
    una sola linea de código. Esto aplica para todas las variables que queramos con su respectivo tipo. */
    int a, b, c, c2;
    float d, e, f, f2, potencia, raiz, resultado1, resultado2;
    double g, h, i, i2;
    char letra1, letra2, letra3, letra4;

    // Asignación de valores a las variables
    a = 2; b = 5; c = 0; c2 = 0; potencia = 2; raiz = 9; resultado1 = 0; resultado2 = 0;
    d = 3.5; e = 5.2; f = 0; f2 = 0;
    g =  2.159; h = 7.864; i = 0; i2 = 0;
    letra1 = 's'; letra2 = 'i'; letra3 = '\0'; letra4 = '\0'; // valor ASCII -> s = 115, i = 105, \0 = 0

    /* El motivo de agregar "c" y "c2" (al igual que con f, i) es para tener los resultados sin "concatenar" 
    las variables, puesto que si hacemos "a = a * b; b = b * a", lo que estamos haciendo es, al haber hecho
    una operación con "a" anteriormente, multiplicar el nuevo resultado de "a" con "b" (que no se le ha hecho
    ninguna operacion anterior), lo que daría lo siguiente: 
    a(2) = a(2) * b(5) (nuevo valor de "a" = 10);
    b(5) = b(5) * a(10) (nuevo valor de "b" = 50);
    en lugar de b(5) * a(2) -> b = 10) */

    // Imprimir variables sin operar
    printf(" Valor de variables sin operar\n"
        " Valor de \"a\" es: %i\n"
        " Valor de \"b\" es: %i\n"
        " Valor de \"c\" es: %i\n"
        " Valor de \"d\" es: %f\n"
        " Valor de \"e\" es: %f\n"
        " Valor de \"f\" es: %f\n"
        " Valor de \"Potencia\" es: %f\n"
        " Valor de \"raiz\" es: %f\n"
        " Valor de \"resultado1\" es: %f\n"
        " Valor de \"resultado2\" es: %f\n"
        " Valor de \"letra1\" es: %c\n"
        " Valor de \"letra2\" es: %c\n"
        " Valor de \"letra3\" es: %c\n"
        " Valor de \"letra4\" es: %c\n", a, b, c, d, e, f, potencia, 
        raiz, resultado1, resultado2, letra1, letra2, letra3, letra4);

    /* Operaciones Básicas son las mismas que en matemáticas:
    Suma (1+1), Resta (1-1), Multiplicación (1*1), Division (1/1). Y se pueden hacer con todas las variables 
    que quieran (con variables que ya hayan sido definidas) e incluso entre mismas variables 
    (a = a + a por ejemplo) */
    
    c = a + b; c2 = b - a; // "c" es el nuevo valor de "a", "c2" es el nuevo valor de "b" 
    f = d * e; f2 = e / d; // "f" es el nuevo valor de "c", "f2" es el nuevo valor de "d"
    i = g * h; i2 = h - g; // "i" es el nuevo valor de "e", "i2" es el nuevo valor de "f"
    resultado1 = pow(potencia,3); // "resultado1" tiene como resultado: potencia(2)^3
    resultado2 = sqrt(raiz); // "resultado2 tiene como resultado: raiz cuadrada de (raiz(9))
    
    /* La sección de arriba (Operaciones básicas) puede parecer confusa, pero para entenderla es mejor comparar
    con el output (compilar y ejecutar) para entender cómo se hizo la asignación a las variables "duplicadas"
    (c, c2, f, f2, i, i2) */

    /* Con "char" hay que tener cuidado, puesto que este no va a sumar/restar/multiplicar/dividir las letras, 
    en cambio, lo que hará sera tomar el valor en ASCII del caracter y hará la operación. En este caso, estamos
    sumando 's' + 'i', por lo que al hacer la operación el resultado no será "si", si no que será la suma de 
    los valores correspondientes a 's' e 'i' en ASCII, teniendo como resultado un número que será interpretado
    como una letra/símbolo en según el código ASCII */

    letra3 = letra1 + letra2; /* El nuevo valor de "letra1" será la suma de 
    "s (valor ASCII = 115)" + "i (valor de ASCII = 105)" = 220 (que representa el símbolo de multiplicación ×) */
    letra4 = letra2 * letra1; /* En este caso dará otro resultado (i = 105, s = 115) 105 * 115 = 12075. Como 
    este valor excede 255, este se loopea y continua (en el rango de 0 a 255) hasta llegar a 12075 el cual tiene 
    un valor asociado al codigo ASCII.
    Si quieres saber como funciona, abre el archivo "ASCII y valores sobre 255.c" de este repositorio */

    printf("\n"); // Separador entre "Valor" y "Nuevo valor"

    // Imprimir variables operadas
    printf(" Valor de variables operadas\n"
        " El nuevo valor de \"a\" es: %i\n"
        " El nuevo valor de \"b\" es: %i\n"
        " El nuevo valor de \"c\" es: %f\n"
        " El nuevo valor de \"d\" es: %f\n"
        " El nuevo valor de \"e\" es: %f\n"
        " El nuevo valor de \"f\" es: %f\n"
        " El valor de \"resultado1\" es: %f\n"
        " El valor de \"resultado2\" es: %f\n", c, c2, f, f2, i, i2, resultado1, resultado2);
    printf(" Nuevo valor de \"letra1\" es: %c\n"
        " Nuevo valor de \"letra2\" es: %c\n", letra3, letra4);

    printf("\n"); // Separador del siguiente ítem

    /* Existen tambien métodos para abreviar las operaciones básicas */
    int sumaResumida, restaResumida;
    float multiplicacionResumida, divisionResumida;

    sumaResumida = 5, restaResumida = 2;
    multiplicacionResumida = 10, divisionResumida = 15;

    sumaResumida += 15; // Esto es equivalente a sumaResumida = 5 + 15
    restaResumida -= 1; // Esto es equivalente a restaResumida = 2 - 2
    multiplicacionResumida *= 3; // Esto es equivalente a multiplicacionResumida = 10 * 3
    divisionResumida /= 5; // Esto es equivalente a divisionResumida = 15 / 5

    printf(" Operaciones basicas resumidas: \n"
    " Suma resumida +=: %i\n"
    " Resta resumida -=: %i\n"
    " Multiplicacion resumida *=: %f\n"
    " Division resumida /=: %f\n", sumaResumida, restaResumida, multiplicacionResumida, divisionResumida);

    printf("\n"); // Separador del siguiente ítem

    /* Existe un ultimo tipo de operadores, llamados "Operadores de Incremento", estos se caracterizan por
    tener su propia forma de expresarse, y funcionan para sumar o restar en 1 cualquier valor de cualquier 
    variable, ya sea int, float, double o char, cualquiera */
    
    int incrementar = 0, disminuir = 0; // Notar que se puede incializar una variable al mismo tiempo de crearla

    // Incremento
    incrementar++;

    // Disminución
    disminuir--;

    printf(" Valores usando operadores de incremento: \n"
    " Valor de incremento\"++\" : %i\n"
    " Valor de disminucion\"--\" : %i\n", incrementar, disminuir);    

    return 0;
}
