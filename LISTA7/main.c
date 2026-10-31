#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    Arv *d = arv_cria(4, inicializa(), inicializa());
    Arv *e = arv_cria(5, inicializa(), inicializa());
    Arv *b = arv_cria(2, d, e);

    Arv *f = arv_cria(6, inicializa(), inicializa());
    Arv *g = arv_cria(7, inicializa(), inicializa());
    Arv *c = arv_cria(3, f, g);

    Arv *raiz = arv_cria(1, b, c);

    printf("Percursos da arvore:\n");
    printf("Preorder: ");
    preOrder(raiz);
    printf("\nInorder: ");
    inOrder(raiz);
    printf("\nPostorder: ");
    postOrder(raiz);
    printf("\n");

    printf("\n--- Exercicio 1 ---\n");
    printf("Quantidade total de nos: %d\n", quantidade_nos(raiz));

    printf("\n--- Exercicio 2 ---\n");
    printf("Soma dos valores dos nos: %d\n", soma_valores(raiz));

    printf("\n--- Exercicio 3 ---\n");
    printf("Maior elemento: %d\n", maior_elemento(raiz));

    printf("\n--- Exercicio 4 ---\n");
    printf("Altura da arvore: %d\n", altura(raiz));

    printf("\n--- Exercicio 5 ---\n");
    printf("Nos com exatamente dois filhos: %d\n", nos_dois_filhos(raiz));

    printf("\n--- Exercicio 6 ---\n");
    imprimir_internos_externos(raiz);

    printf("\n--- Exercicio 7 ---\n");
    int alvo1 = 8;
    int alvo2 = 20;
    printf("Existe caminho com soma %d: %s\n", alvo1, existe_caminho_soma(raiz, alvo1) ? "Sim" : "Nao");
    printf("Existe caminho com soma %d: %s\n", alvo2, existe_caminho_soma(raiz, alvo2) ? "Sim" : "Nao");

    printf("\n--- Exercicio 8 ---\n");
    printf("A arvore e cheia? %s\n", eh_cheia(raiz) ? "Sim" : "Nao");

    printf("\n--- Exercicio 9 ---\n");
    printf("A arvore e perfeita? %s\n", eh_perfeita(raiz) ? "Sim" : "Nao");

    printf("\n--- Exercicio 10 ---\n");
    printf("A arvore e completa? %s\n", eh_completa(raiz) ? "Sim" : "Nao");

    printf("\n--- Exercicio 11 ---\n");
    Arv *copia = arv_cria(1,
                    arv_cria(2, arv_cria(4, NULL, NULL), arv_cria(5, NULL, NULL)),
                    arv_cria(3, arv_cria(6, NULL, NULL), arv_cria(7, NULL, NULL)));
    Arv *diferente = arv_cria(1, arv_cria(2, NULL, NULL), NULL);
    printf("Comparando com arvore igual: %s\n", sao_identicas(raiz, copia) ? "Identicas" : "Diferentes");
    printf("Comparando com arvore diferente: %s\n", sao_identicas(raiz, diferente) ? "Identicas" : "Diferentes");
    arv_libera(copia);
    arv_libera(diferente);

    printf("\n--- Exercicio 12 ---\n");
    printf("Soma por nivel:\n");
    soma_por_nivel(raiz);

    printf("\n--- Exercicio 13 ---\n");
    imprimir_caminho_alvo(raiz, 5);
    imprimir_caminho_alvo(raiz, 7);
    imprimir_caminho_alvo(raiz, 99);

    printf("\n--- Exercicio 14 ---\n");
    Arv *anc1 = lca(raiz, 4, 5);
    if (anc1) printf("LCA de 4 e 5: %d\n", anc1->info);
    Arv *anc2 = lca(raiz, 4, 7);
    if (anc2) printf("LCA de 4 e 7: %d\n", anc2->info);

    arv_libera(raiz);

    return 0;
}
