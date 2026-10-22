#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int inserir_produto(Produto **estoque, int *n, Produto novo) {
    Produto *temp = (Produto *)realloc(*estoque, (*n + 1) * sizeof(Produto));
    if (temp == NULL) {
        return 0; // Falha na alocação
    }
    *estoque = temp;
    (*estoque)[*n] = novo;
    (*n)++;
    return 1; // Sucesso
}

int main() {
    Produto *estoque = NULL;
    int n = 0;
    int opcao;
    
    do {
        printf("\n1. Inserir novo produto\n2. Sair\nOpcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 1) {
            Produto novo;
            printf("Nome: ");
            scanf(" %49[^\n]", novo.nome);
            printf("Preco: ");
            scanf("%f", &novo.preco);
            printf("Quantidade: ");
            scanf("%d", &novo.quantidade);
            
            if (inserir_produto(&estoque, &n, novo)) {
                printf("\n=== Estoque Atual (%d produtos) ===\n", n);
                for (int i = 0; i < n; i++) {
                    printf("%d: %s | R$ %.2f | Qtd: %d\n", i + 1, estoque[i].nome, estoque[i].preco, estoque[i].quantidade);
                }
            } else {
                printf("Erro ao alocar memoria para o novo produto!\n");
            }
        }
    } while (opcao != 2);
    
    if (estoque != NULL) {
        free(estoque);
        printf("Memória liberada.\n");
    }
    return 0;
}
