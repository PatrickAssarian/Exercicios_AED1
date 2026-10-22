#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto *criar_estoque(int n) {
    Produto *estoque = (Produto *)malloc(n * sizeof(Produto));
    if (estoque != NULL) {
        Produto *ptr = estoque;
        for (int i = 0; i < n; i++) {
            printf("--- Produto %d ---\n", i + 1);
            printf("Nome: ");
            scanf(" %49[^\n]", ptr->nome);
            printf("Preco: ");
            scanf("%f", &ptr->preco);
            printf("Quantidade: ");
            scanf("%d", &ptr->quantidade);
            ptr++;
        }
    }
    return estoque;
}

int main() {
    int n;
    printf("Digite a quantidade de produtos para o estoque: ");
    scanf("%d", &n);
    
    Produto *estoque = criar_estoque(n);
    
    if (estoque != NULL) {
        printf("\n=== Estoque Cadastrado ===\n");
        Produto *ptr = estoque;
        for (int i = 0; i < n; i++) {
            printf("%d: %s | R$ %.2f | Qtd: %d\n", i + 1, ptr->nome, ptr->preco, ptr->quantidade);
            ptr++;
        }
        free(estoque);
        printf("\nMemória do estoque liberada.\n");
    }
    return 0;
}
