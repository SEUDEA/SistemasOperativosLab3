// fragmentation.c
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main() {
    void *ptrs[N];
    int sizes[] = {16, 32, 64, 128, 256, 512, 1024, 512, 256, 128};

    for (int i = 0; i < N; i++) {
        ptrs[i] = malloc(sizes[i]);
        printf("malloc(%4d)  ->  %p\n", sizes[i], ptrs[i]);
    }

    printf("\nLiberando bloques en indices pares...\n");
    for (int i = 0; i < N; i += 2) {
        free(ptrs[i]);
        ptrs[i] = NULL;
    }

    void *big = malloc(1500);
    printf("\nmalloc(1500)  ->  %p  [%s]\n", big, big ? "exito" : "FALLO");
    if (big) free(big);

    for (int i = 1; i < N; i += 2) free(ptrs[i]);
    return 0;
}
