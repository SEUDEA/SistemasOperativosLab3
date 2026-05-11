// buggy_mem.c  -- NO ejecutar sin Valgrind
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* ERROR 1: buffer overflow */
    int *p = malloc(5 * sizeof(int));
    for (int i = 0; i <= 5; i++)   /* <= en vez de < */
        p[i] = i;

    /* ERROR 2: memory leak (nunca se llama free(q)) */
    char *q = malloc(100);
    strcpy(q, "hola mundo");
    printf("%s\n", q);

    /* ERROR 3: use-after-free */
    free(p);
    printf("p[0] = %d\n", p[0]);   /* acceso ilegal */

    return 0;
}
