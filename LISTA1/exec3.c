#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto **criar_estoque_ptrs(int n) {
    Produto **estoque = (Produto **)malloc(n * sizeof(Produto *));
    if (estoque != NULL) {
        for (int i = 0; i < n; i++) {
            estoque[i] = (Produto *)malloc(sizeof(Produto));
            if (estoque[i] != NULL) {
                printf("--- Produto %d ---\n", i + 1);
                printf("Nome: ");
                scanf(" %49[^\n]", estoque[i]->nome);
                printf("Preco: ");
                scanf("%f", &estoque[i]->preco);
                printf("Quantidade: ");
                scanf("%d", &estoque[i]->quantidade);
            }
        }
    }
    return estoque;
}

void liberar_estoque_ptrs(Produto **estoque, int n) {
    if (estoque != NULL) {
        for (int i = 0; i < n; i++) {
            free(estoque[i]);
        }
        free(estoque);
    }
}

int main() {
    int n;
    printf("Digite a quantidade de produtos (ponteiros): ");
    scanf("%d", &n);
    
    Produto **estoque = criar_estoque_ptrs(n);
    
    if (estoque != NULL) {
        printf("\n=== Estoque de Ponteiros Cadastrado ===\n");
        for (int i = 0; i < n; i++) {
            printf("%d: %s | R$ %.2f | Qtd: %d\n", i + 1, estoque[i]->nome, estoque[i]->preco, estoque[i]->quantidade);
        }
        liberar_estoque_ptrs(estoque, n);
        printf("\nMemória do estoque liberada.\n");
    }
    return 0;
}
