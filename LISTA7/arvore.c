#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Arv* inicializa() {
    return NULL;
}

Arv* arv_cria(int valor, Arv* sae, Arv* sad) {
    Arv* p = (Arv*)malloc(sizeof(Arv));
    if (p != NULL) {
        p->info = valor;
        p->esq = sae;
        p->dir = sad;
    }
    return p;
}

Arv* arv_libera(Arv* a) {
    if (a != NULL) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

void preOrder(Arv *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->info);
    preOrder(raiz->esq);
    preOrder(raiz->dir);
}

void inOrder(Arv *raiz) {
    if (raiz == NULL) return;
    inOrder(raiz->esq);
    printf("%d ", raiz->info);
    inOrder(raiz->dir);
}

void postOrder(Arv *raiz) {
    if (raiz == NULL) return;
    postOrder(raiz->esq);
    postOrder(raiz->dir);
    printf("%d ", raiz->info);
}

int quantidade_nos(Arv *raiz) {
    if (raiz == NULL) return 0;
    return 1 + quantidade_nos(raiz->esq) + quantidade_nos(raiz->dir);
}

int soma_valores(Arv *raiz) {
    if (raiz == NULL) return 0;
    return raiz->info + soma_valores(raiz->esq) + soma_valores(raiz->dir);
}

int maior_elemento(Arv *raiz) {
    if (raiz == NULL) return -999999;
    int max = raiz->info;
    if (raiz->esq != NULL) {
        int max_esq = maior_elemento(raiz->esq);
        if (max_esq > max) max = max_esq;
    }
    if (raiz->dir != NULL) {
        int max_dir = maior_elemento(raiz->dir);
        if (max_dir > max) max = max_dir;
    }
    return max;
}

int altura(Arv *raiz) {
    if (raiz == NULL) return -1;
    int he = altura(raiz->esq);
    int hd = altura(raiz->dir);
    return 1 + (he > hd ? he : hd);
}

int nos_dois_filhos(Arv *raiz) {
    if (raiz == NULL) return 0;
    int qtd = (raiz->esq != NULL && raiz->dir != NULL) ? 1 : 0;
    return qtd + nos_dois_filhos(raiz->esq) + nos_dois_filhos(raiz->dir);
}

static int conta_folhas(Arv *raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esq == NULL && raiz->dir == NULL) return 1;
    return conta_folhas(raiz->esq) + conta_folhas(raiz->dir);
}

static int conta_internos(Arv *raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esq == NULL && raiz->dir == NULL) return 0;
    return 1 + conta_internos(raiz->esq) + conta_internos(raiz->dir);
}

void imprimir_internos_externos(Arv *raiz) {
    printf("Nos internos: %d\n", conta_internos(raiz));
    printf("Nos externos (folhas): %d\n", conta_folhas(raiz));
}

int existe_caminho_soma(Arv *raiz, int soma_alvo) {
    if (raiz == NULL) return 0;
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return (soma_alvo == raiz->info);
    }
    int restante = soma_alvo - raiz->info;
    return existe_caminho_soma(raiz->esq, restante) || existe_caminho_soma(raiz->dir, restante);
}

int eh_cheia(Arv *raiz) {
    if (raiz == NULL) return 1;
    if (raiz->esq == NULL && raiz->dir == NULL) return 1;
    if (raiz->esq != NULL && raiz->dir != NULL) {
        return eh_cheia(raiz->esq) && eh_cheia(raiz->dir);
    }
    return 0;
}

int eh_perfeita(Arv *raiz) {
    if (raiz == NULL) return 1;
    int h = altura(raiz);
    int total = quantidade_nos(raiz);
    int esperado = (1 << (h + 1)) - 1;
    return (total == esperado);
}

static int verifica_completa_aux(Arv *raiz, int index, int total_nos) {
    if (raiz == NULL) return 1;
    if (index >= total_nos) return 0;
    return verifica_completa_aux(raiz->esq, 2 * index + 1, total_nos) &&
           verifica_completa_aux(raiz->dir, 2 * index + 2, total_nos);
}

int eh_completa(Arv *raiz) {
    int total = quantidade_nos(raiz);
    return verifica_completa_aux(raiz, 0, total);
}

int sao_identicas(Arv *a, Arv *b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;
    if (a->info != b->info) return 0;
    return sao_identicas(a->esq, b->esq) && sao_identicas(a->dir, b->dir);
}

static int soma_nivel_aux(Arv *raiz, int nivel_desejado, int nivel_atual) {
    if (raiz == NULL) return 0;
    if (nivel_atual == nivel_desejado) return raiz->info;
    return soma_nivel_aux(raiz->esq, nivel_desejado, nivel_atual + 1) +
           soma_nivel_aux(raiz->dir, nivel_desejado, nivel_atual + 1);
}

void soma_por_nivel(Arv *raiz) {
    if (raiz == NULL) return;
    int h = altura(raiz);
    for (int i = 0; i <= h; i++) {
        int s = soma_nivel_aux(raiz, i, 0);
        printf("Nivel %d: soma = %d\n", i, s);
    }
}

static int busca_caminho_aux(Arv *raiz, int valor_alvo, int caminho[], int tam) {
    if (raiz == NULL) return 0;
    caminho[tam] = raiz->info;
    tam++;
    if (raiz->info == valor_alvo) {
        printf("Caminho ate %d: ", valor_alvo);
        for (int i = 0; i < tam; i++) {
            printf("%d", caminho[i]);
            if (i < tam - 1) printf(" -> ");
        }
        printf("\n");
        return 1;
    }
    if (busca_caminho_aux(raiz->esq, valor_alvo, caminho, tam)) return 1;
    if (busca_caminho_aux(raiz->dir, valor_alvo, caminho, tam)) return 1;
    return 0;
}

void imprimir_caminho_alvo(Arv *raiz, int valor_alvo) {
    int caminho[100];
    busca_caminho_aux(raiz, valor_alvo, caminho, 0);
}

Arv *lca(Arv *raiz, int v1, int v2) {
    if (raiz == NULL) return NULL;
    if (raiz->info == v1 || raiz->info == v2) return raiz;

    Arv *esq = lca(raiz->esq, v1, v2);
    Arv *dir = lca(raiz->dir, v1, v2);

    if (esq != NULL && dir != NULL) return raiz;
    return (esq != NULL) ? esq : dir;
}
