#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main() {
    printf("--- Exercicio 1 ---\n");
    printf("a) Inserindo 60, 40, 20:\n");
    AVL *a1 = NULL;
    a1 = insereAVL(a1, 60);
    a1 = insereAVL(a1, 40);
    a1 = insereAVL(a1, 20);
    printf("Percurso em-ordem: ");
    emOrdem(a1);
    printf("\nRaiz atual: %d (fb: %d)\n", a1->info, a1->fb);
    liberaAVL(a1);

    printf("\nb) Inserindo 15, 25, 35:\n");
    AVL *a2 = NULL;
    a2 = insereAVL(a2, 15);
    a2 = insereAVL(a2, 25);
    a2 = insereAVL(a2, 35);
    printf("Percurso em-ordem: ");
    emOrdem(a2);
    printf("\nRaiz atual: %d (fb: %d)\n", a2->info, a2->fb);
    liberaAVL(a2);

    printf("\nc) Inserindo 50, 10, 30:\n");
    AVL *a3 = NULL;
    a3 = insereAVL(a3, 50);
    a3 = insereAVL(a3, 10);
    a3 = insereAVL(a3, 30);
    printf("Percurso em-ordem: ");
    emOrdem(a3);
    printf("\nRaiz atual: %d (fb: %d)\n", a3->info, a3->fb);
    liberaAVL(a3);

    printf("\nd) Inserindo 10, 50, 30:\n");
    AVL *a4 = NULL;
    a4 = insereAVL(a4, 10);
    a4 = insereAVL(a4, 50);
    a4 = insereAVL(a4, 30);
    printf("Percurso em-ordem: ");
    emOrdem(a4);
    printf("\nRaiz atual: %d (fb: %d)\n", a4->info, a4->fb);
    liberaAVL(a4);

    printf("\n--- Exercicio 2 ---\n");
    printf("a) Inserindo 50, 30, 70, 20, 10:\n");
    AVL *t2a = NULL;
    int v2a[] = {50, 30, 70, 20, 10};
    for (int i = 0; i < 5; i++) t2a = insereAVL(t2a, v2a[i]);
    printf("Percurso em-ordem: ");
    emOrdem(t2a);
    printf("\nAltura: %d\n", altura(t2a));
    liberaAVL(t2a);

    printf("\n--- Exercicio 3 ---\n");
    printf("Ordem crescente: 10 a 70:\n");
    AVL *t3 = NULL;
    for (int i = 10; i <= 70; i += 10) t3 = insereAVL(t3, i);
    printf("Em-ordem: ");
    emOrdem(t3);
    printf("\nAltura final: %d\n", altura(t3));
    liberaAVL(t3);

    printf("\n--- Exercicio 4 ---\n");
    AVL *t4 = NULL;
    int v4[] = {6, 4, 8, 3, 5, 7, 9, 2};
    for (int i = 0; i < 8; i++) t4 = insereAVL(t4, v4[i]);
    printf("Antes da remocao do 5: ");
    emOrdem(t4);
    t4 = removeAVL(t4, 5);
    printf("\nApos remover 5: ");
    emOrdem(t4);
    printf("\n");
    liberaAVL(t4);

    printf("\n--- Exercicio 5 ---\n");
    AVL *t5 = NULL;
    int v5[] = {7, 5, 9, 2, 6, 8, 1, 3};
    for (int i = 0; i < 8; i++) t5 = insereAVL(t5, v5[i]);
    printf("Antes de remover 6: ");
    emOrdem(t5);
    t5 = removeAVL(t5, 6);
    printf("\nApos remover 6: ");
    emOrdem(t5);
    printf("\n");
    liberaAVL(t5);

    printf("\n--- Exercicio 7 ---\n");
    AVL *t7 = NULL;
    int v7[] = {5, 2, 7, 1, 4, 6, 8, 9};
    for (int i = 0; i < 8; i++) t7 = insereAVL(t7, v7[i]);
    printf("Antes de remover 5 (raiz com 2 filhos): ");
    emOrdem(t7);
    t7 = removeAVL(t7, 5);
    printf("\nApos remover 5: ");
    emOrdem(t7);
    printf("\nNova raiz: %d\n", t7->info);
    liberaAVL(t7);

    printf("\n--- Exercicio 8 ---\n");
    AVL *t8 = NULL;
    for (int i = 1; i <= 6; i++) t8 = insereAVL(t8, i * 10);
    printf("Arvore AVL criada. Verificando se esta balanceada: %s\n", estaBalanceada(t8) ? "Sim" : "Nao");
    liberaAVL(t8);

    printf("\n--- Exercicio 10 ---\n");
    AVL *t10 = NULL;
    int v10[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) t10 = insereAVL(t10, v10[i]);
    printf("Arvore montada: ");
    emOrdem(t10);
    printf("\nRemovendo 30...\n");
    t10 = removeAVL(t10, 30);
    printf("Resultado: ");
    emOrdem(t10);
    printf("\nEsta balanceada apos remocao? %s\n", estaBalanceada(t10) ? "Sim" : "Nao");
    liberaAVL(t10);

    return 0;
}
