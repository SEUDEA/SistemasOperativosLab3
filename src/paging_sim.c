// paging_sim.c
#include <stdio.h>

#define PAGE_BITS  4
#define PAGE_SIZE  (1 << PAGE_BITS)       /* 16 bytes/pagina */
#define VA_BITS    8                       /* VA de 8 bits    */
#define NUM_PAGES  (1 << (VA_BITS - PAGE_BITS))  /* 16 paginas */

/* Tabla de paginas: -1 = pagina no presente (PAGE FAULT) */
int page_table[NUM_PAGES] = {
    3, -1,  7,  2, -1,  1, -1,  5,
   -1, -1,  4, -1,  6, -1,  0, -1
};

void traducir(int va) {
    int vpn    = va >> PAGE_BITS;
    int offset = va & (PAGE_SIZE - 1);
    printf("VA=0x%02X  VPN=%2d  Offset=%2d  ", va, vpn, offset);
    if (page_table[vpn] == -1) {
        printf("-> PAGE FAULT (pagina no presente)\n");
    } else {
        int pfn = page_table[vpn];
        int pa  = (pfn << PAGE_BITS) | offset;
        printf("-> PFN=%2d  PA=0x%02X\n", pfn, pa);
    }
}

int main() {
    int vas[] = {0x00, 0x0F, 0x20, 0x35, 0x10, 0xA3, 0xC8, 0xF0};
    int n = sizeof(vas) / sizeof(vas[0]);
    printf("%-22s %-6s %-8s %-6s %s\n", "VA", "VPN", "Offset", "PFN", "PA");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < n; i++) traducir(vas[i]);
    return 0;
}
