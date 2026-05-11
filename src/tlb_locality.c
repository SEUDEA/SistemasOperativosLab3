// tlb_locality.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N (1 << 22)   /* 4M enteros = 16 MB */

double ms(struct timespec a, struct timespec b) {
    return (b.tv_sec - a.tv_sec) * 1000.0
         + (b.tv_nsec - a.tv_nsec) / 1e6;
}

int main() {
    int *arr = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) arr[i] = i;

    struct timespec t0, t1;
    long sum = 0;

    /* Acceso SECUENCIAL — alta localidad espacial */
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < N; i++) sum += arr[i];
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("Secuencial : %8.2f ms  (sum=%ld)\n", ms(t0, t1), sum);

    /* Acceso ALEATORIO — baja localidad (Fisher-Yates) */
    int *idx = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) idx[i] = i;
    srand(42);
    for (int i = N - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int t = idx[i]; idx[i] = idx[j]; idx[j] = t;
    }

    sum = 0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int i = 0; i < N; i++) sum += arr[idx[i]];
    clock_gettime(CLOCK_MONOTONIC, &t1);
    printf("Aleatorio  : %8.2f ms  (sum=%ld)\n", ms(t0, t1), sum);

    free(arr);
    free(idx);
    return 0;
}
