#include <stdio.h>
#include <stdlib.h>
#include "rubro_negra.h"

int main() {
    printf("--- Exercicio 1 ---\n");
    printf("a) Inserindo 10, 20, 30:\n");
    Rubro_Negra *r1 = NULL;
    r1 = insereRN(r1, 10);
    r1 = insereRN(r1, 20);
    r1 = insereRN(r1, 30);
    printf("Em-ordem (V=Vermelho, P=Preto): ");
    emOrdemRN(r1);
    printf("\nRaiz: %d(%c)\n", r1->info, r1->cor == PRETO ? 'P' : 'V');
    liberaRN(r1);

    printf("\ne) Inserindo 20, 10, 30, 5:\n");
    Rubro_Negra *r1e = NULL;
    int v1e[] = {20, 10, 30, 5};
    for (int i = 0; i < 4; i++) r1e = insereRN(r1e, v1e[i]);
    printf("Em-ordem: ");
    emOrdemRN(r1e);
    printf("\n");
    liberaRN(r1e);

    printf("\n--- Exercicio 2 ---\n");
    printf("Base: 40, 20, 60, 10, 30, 50, 70\n");
    Rubro_Negra *r2 = NULL;
    int base2[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) r2 = insereRN(r2, base2[i]);
    printf("Arvore base em-ordem: ");
    emOrdemRN(r2);
    printf("\nInserindo 5, 15, 3 (item a)...\n");
    r2 = insereRN(r2, 5);
    r2 = insereRN(r2, 15);
    r2 = insereRN(r2, 3);
    printf("Resultado: ");
    emOrdemRN(r2);
    printf("\nPropriedades RN validas? %s\n", validaPropriedadesRN(r2) ? "Sim" : "Nao");
    liberaRN(r2);

    printf("\n--- Exercicio 3 ---\n");
    Rubro_Negra *r3 = NULL;
    for (int i = 10; i <= 70; i += 10) r3 = insereRN(r3, i);
    printf("Crescente 10 a 70 em-ordem: ");
    emOrdemRN(r3);
    printf("\nAltura negra: %d\n", alturaNegra(r3));
    liberaRN(r3);

    printf("\n--- Exercicio 4 ---\n");
    Rubro_Negra *r4 = NULL;
    int v4[] = {50, 30, 70, 20, 40, 60, 80, 10};
    for (int i = 0; i < 8; i++) r4 = insereRN(r4, v4[i]);
    printf("Arvore montada: ");
    emOrdemRN(r4);
    printf("\nRemovendo 10 (folha vermelha): ");
    r4 = removeRN(r4, 10);
    emOrdemRN(r4);
    printf("\nRemovendo 20: ");
    r4 = removeRN(r4, 20);
    emOrdemRN(r4);
    printf("\nRemovendo 50: ");
    r4 = removeRN(r4, 50);
    emOrdemRN(r4);
    printf("\n");
    liberaRN(r4);

    printf("\n--- Exercicio 8 ---\n");
    printf("Exemplo visto em aula: 11, 2, 14, 1, 7, 13, 15, 5, 8, 4\n");
    Rubro_Negra *r8 = NULL;
    int v8[] = {11, 2, 14, 1, 7, 13, 15, 5, 8, 4};
    for (int i = 0; i < 10; i++) r8 = insereRN(r8, v8[i]);
    printf("Antes da remocao: ");
    emOrdemRN(r8);
    printf("\nRemovendo 1, 8 e 5 em sequencia...\n");
    r8 = removeRN(r8, 1);
    r8 = removeRN(r8, 8);
    r8 = removeRN(r8, 5);
    printf("Resultado: ");
    emOrdemRN(r8);
    printf("\nPropriedades validas? %s\n", validaPropriedadesRN(r8) ? "Sim" : "Nao");
    liberaRN(r8);

    printf("\n--- Exercicio 9 ---\n");
    Rubro_Negra *r9 = NULL;
    int v9_ins[] = {50, 30, 70, 20, 40, 60, 80, 10};
    for (int i = 0; i < 8; i++) r9 = insereRN(r9, v9_ins[i]);
    printf("1. Apos inserir chaves iniciais: ");
    emOrdemRN(r9);
    r9 = removeRN(r9, 70);
    printf("\n2. Apos remover 70: ");
    emOrdemRN(r9);
    r9 = insereRN(r9, 65);
    printf("\n3. Apos inserir 65: ");
    emOrdemRN(r9);
    r9 = removeRN(r9, 30);
    printf("\n4. Apos remover 30: ");
    emOrdemRN(r9);
    r9 = insereRN(r9, 35);
    printf("\n5. Apos inserir 35: ");
    emOrdemRN(r9);
    r9 = removeRN(r9, 50);
    printf("\n6. Apos remover 50: ");
    emOrdemRN(r9);
    printf("\nArvore final valida? %s\n", validaPropriedadesRN(r9) ? "Sim" : "Nao");
    liberaRN(r9);

    return 0;
}
