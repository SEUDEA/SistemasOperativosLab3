// buggy_mem_fixed.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* FIX 1: cambiar <= por < para no escribir fuera del bloque */
    int *p = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
        p[i] = i;

    /* FIX 3: leer p[0] antes de liberar */
    printf("p[0] = %d\n", p[0]);
    free(p);

    /* FIX 2: liberar q al terminar de usarlo */
    char *q = malloc(100);
    strcpy(q, "hola mundo");
    printf("%s\n", q);
    free(q);

    return 0;
}
