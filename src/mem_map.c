// mem_map.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_var = 42;

int main() {
    int  local_var = 10;
    int *heap_var  = malloc(sizeof(int) * 100);
    *heap_var = 99;

    printf("PID del proceso    : %d\n",  getpid());
    printf("Dir. codigo (main) : %p\n",  (void*)main);
    printf("Dir. global_var    : %p\n",  (void*)&global_var);
    printf("Dir. local_var     : %p\n",  (void*)&local_var);
    printf("Dir. heap_var      : %p\n",  (void*)heap_var);

    printf("\nPresione ENTER para continuar...\n");
    getchar();
    free(heap_var);
    return 0;
}
