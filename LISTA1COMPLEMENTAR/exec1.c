#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Ponto;

Ponto *criar_ponto(int x, int y) {
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

void destruir_ponto(Ponto *p) {
    free(p);
}

int main() {
    Ponto *p = criar_ponto(10, 20);
    if (p != NULL) {
        printf("Ponto criado com sucesso: (%d, %d)\n", p->x, p->y);
        destruir_ponto(p);
        printf("Memória do ponto liberada.\n");
    }
    return 0;
}
