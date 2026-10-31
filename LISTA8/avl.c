#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

AVL *criaNo(int valor) {
    AVL *novo = (AVL*)malloc(sizeof(AVL));
    if (novo == NULL) return NULL;
    novo->info = valor;
    novo->fb = 0;
    novo->sae = NULL;
    novo->sad = NULL;
    return novo;
}

int altura(AVL *raiz) {
    if (raiz == NULL) return -1;
    int he = altura(raiz->sae);
    int hd = altura(raiz->sad);
    return 1 + (he > hd ? he : hd);
}

void atualizaFB(AVL *raiz) {
    if (raiz != NULL) {
        raiz->fb = altura(raiz->sae) - altura(raiz->sad);
    }
}

AVL *rotacaoDireita(AVL *p) {
    AVL *q = p->sae;
    p->sae = q->sad;
    q->sad = p;
    atualizaFB(p);
    atualizaFB(q);
    return q;
}

AVL *rotacaoEsquerda(AVL *p) {
    AVL *q = p->sad;
    p->sad = q->sae;
    q->sae = p;
    atualizaFB(p);
    atualizaFB(q);
    return q;
}

AVL *rotacaoEsquerdaDireita(AVL *p) {
    p->sae = rotacaoEsquerda(p->sae);
    return rotacaoDireita(p);
}

AVL *rotacaoDireitaEsquerda(AVL *p) {
    p->sad = rotacaoDireita(p->sad);
    return rotacaoEsquerda(p);
}

AVL *rebalanceia(AVL *raiz) {
    if (raiz == NULL) return NULL;
    atualizaFB(raiz);

    if (raiz->fb > 1) {
        atualizaFB(raiz->sae);
        if (raiz->sae->fb < 0) {
            raiz = rotacaoEsquerdaDireita(raiz);
        } else {
            raiz = rotacaoDireita(raiz);
        }
    } else if (raiz->fb < -1) {
        atualizaFB(raiz->sad);
        if (raiz->sad->fb > 0) {
            raiz = rotacaoDireitaEsquerda(raiz);
        } else {
            raiz = rotacaoEsquerda(raiz);
        }
    }
    atualizaFB(raiz);
    return raiz;
}

AVL *insereAVL(AVL *raiz, int valor) {
    if (raiz == NULL) return criaNo(valor);

    if (valor < raiz->info) {
        raiz->sae = insereAVL(raiz->sae, valor);
    } else if (valor > raiz->info) {
        raiz->sad = insereAVL(raiz->sad, valor);
    } else {
        return raiz;
    }

    return rebalanceia(raiz);
}

int estaBalanceada(No *raiz) {
    if (raiz == NULL) return 1;
    int he = altura(raiz->sae);
    int hd = altura(raiz->sad);
    int diff = he - hd;
    if (diff < 0) diff = -diff;
    if (diff > 1) return 0;
    return estaBalanceada(raiz->sae) && estaBalanceada(raiz->sad);
}

static No *menorNo(No *n) {
    No *atual = n;
    while (atual != NULL && atual->sae != NULL) {
        atual = atual->sae;
    }
    return atual;
}

No *removeAVL(No *raiz, int chave) {
    if (raiz == NULL) return NULL;

    if (chave < raiz->info) {
        raiz->sae = removeAVL(raiz->sae, chave);
    } else if (chave > raiz->info) {
        raiz->sad = removeAVL(raiz->sad, chave);
    } else {
        if (raiz->sae == NULL || raiz->sad == NULL) {
            No *temp = raiz->sae ? raiz->sae : raiz->sad;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
                free(temp);
            } else {
                No copia = *temp;
                free(temp);
                *raiz = copia;
            }
        } else {
            No *temp = menorNo(raiz->sad);
            raiz->info = temp->info;
            raiz->sad = removeAVL(raiz->sad, temp->info);
        }
    }

    if (raiz == NULL) return NULL;
    return rebalanceia(raiz);
}

void emOrdem(AVL *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->sae);
    printf("%d(fb:%d) ", raiz->info, raiz->fb);
    emOrdem(raiz->sad);
}

void imprimeArvore(AVL *raiz, int nivel) {
    if (raiz == NULL) return;
    imprimeArvore(raiz->sad, nivel + 1);
    for (int i = 0; i < nivel; i++) printf("   ");
    printf("%d [fb=%d]\n", raiz->info, raiz->fb);
    imprimeArvore(raiz->sae, nivel + 1);
}

void liberaAVL(AVL *raiz) {
    if (raiz != NULL) {
        liberaAVL(raiz->sae);
        liberaAVL(raiz->sad);
        free(raiz);
    }
}
