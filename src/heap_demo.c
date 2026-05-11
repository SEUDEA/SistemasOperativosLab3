// heap_demo.c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) { perror("malloc"); return 1; }

    for (int i = 0; i < n; i++) arr[i] = i * i;
    printf("Arreglo original:  ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    arr = (int *) realloc(arr, 20 * sizeof(int));
    if (arr == NULL) { perror("realloc"); return 1; }
    for (int i = n; i < 20; i++) arr[i] = i * i;

    printf("Arreglo ampliado:  ");
    for (int i = 0; i < 20; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
