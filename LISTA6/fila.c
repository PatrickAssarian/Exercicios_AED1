#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct Nodo {
    Elem info;
    struct Nodo *prox;
} Nodo;

struct fila {
    Nodo *inicio;
    Nodo *fim;
    int qtd;
};

Fila *criaFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->qtd = 0;
    }
    return f;
}

void reset(Fila *fila) {
    if (fila == NULL) return;
    Nodo *aux = fila->inicio;
    while (aux != NULL) {
        Nodo *remover = aux;
        aux = aux->prox;
        free(remover);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtd = 0;
}

int empty(Fila *fila) {
    return (fila == NULL || fila->inicio == NULL);
}

int size(Fila *fila) {
    if (fila == NULL) return 0;
    return fila->qtd;
}

void enqueue(Fila *fila, Elem elem) {
    if (fila == NULL) return;
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) return;
    novo->info = elem;
    novo->prox = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    fila->qtd++;
}

Elem dequeue(Fila *fila) {
    Elem e = {0};
    if (empty(fila)) return e;
    Nodo *remover = fila->inicio;
    e = remover->info;
    fila->inicio = remover->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(remover);
    fila->qtd--;
    return e;
}

void front(Fila *fila) {
    if (empty(fila)) {
        printf("Fila vazia\n");
        return;
    }
    printf("%d\n", fila->inicio->info.valor);
}

void clear(Fila *fila) {
    reset(fila);
}

void print(Fila *fila) {
    if (empty(fila)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Inicio -> ");
    Nodo *aux = fila->inicio;
    while (aux != NULL) {
        printf("%d -> ", aux->info.valor);
        aux = aux->prox;
    }
    printf("Fim\n");
}

void liberaFila(Fila *fila) {
    if (fila == NULL) return;
    reset(fila);
    free(fila);
}

int maior_elemento(Fila *fila) {
    if (empty(fila)) return 0;
    int n = size(fila);
    Elem primeiro = dequeue(fila);
    int max = primeiro.valor;
    enqueue(fila, primeiro);
    for (int i = 1; i < n; i++) {
        Elem atual = dequeue(fila);
        if (atual.valor > max) {
            max = atual.valor;
        }
        enqueue(fila, atual);
    }
    return max;
}

typedef struct NodoPilhaAux {
    Elem info;
    struct NodoPilhaAux *prox;
} NodoPilhaAux;

void inverter_fila(Fila *fila) {
    if (empty(fila)) return;
    NodoPilhaAux *topo = NULL;
    while (!empty(fila)) {
        Elem e = dequeue(fila);
        NodoPilhaAux *novo = (NodoPilhaAux*)malloc(sizeof(NodoPilhaAux));
        novo->info = e;
        novo->prox = topo;
        topo = novo;
    }
    while (topo != NULL) {
        NodoPilhaAux *rem = topo;
        enqueue(fila, rem->info);
        topo = topo->prox;
        free(rem);
    }
}

void separar_par_impar(Fila *origem, Fila *pares, Fila *impares) {
    if (origem == NULL) return;
    int n = size(origem);
    for (int i = 0; i < n; i++) {
        Elem e = dequeue(origem);
        if (e.valor % 2 == 0) {
            enqueue(pares, e);
        } else {
            enqueue(impares, e);
        }
        enqueue(origem, e);
    }
}

void remover(Fila *fila, int valor) {
    if (empty(fila)) return;
    int n = size(fila);
    for (int i = 0; i < n; i++) {
        Elem e = dequeue(fila);
        if (e.valor != valor) {
            enqueue(fila, e);
        }
    }
}

Fila *intercalar_filas(Fila *f1, Fila *f2) {
    Fila *res = criaFila();
    while (!empty(f1) || !empty(f2)) {
        if (!empty(f1)) {
            enqueue(res, dequeue(f1));
        }
        if (!empty(f2)) {
            enqueue(res, dequeue(f2));
        }
    }
    return res;
}

typedef struct NodoCliente {
    Cliente info;
    struct NodoCliente *prox;
} NodoCliente;

struct filaCliente {
    NodoCliente *inicio;
    NodoCliente *fim;
    int qtd;
};

FilaCliente *criaFilaCliente() {
    FilaCliente *f = (FilaCliente*)malloc(sizeof(FilaCliente));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->qtd = 0;
    }
    return f;
}

int emptyCliente(FilaCliente *f) {
    return (f == NULL || f->inicio == NULL);
}

int sizeCliente(FilaCliente *f) {
    if (f == NULL) return 0;
    return f->qtd;
}

void enqueueCliente(FilaCliente *f, Cliente c) {
    if (f == NULL) return;
    NodoCliente *novo = (NodoCliente*)malloc(sizeof(NodoCliente));
    if (novo == NULL) return;
    novo->info = c;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->qtd++;
}

Cliente dequeueCliente(FilaCliente *f) {
    Cliente c = {0, ""};
    if (emptyCliente(f)) return c;
    NodoCliente *remover = f->inicio;
    c = remover->info;
    f->inicio = remover->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(remover);
    f->qtd--;
    return c;
}

Cliente *frontCliente(FilaCliente *f) {
    if (emptyCliente(f)) return NULL;
    return &(f->inicio->info);
}

void printCliente(FilaCliente *f) {
    if (emptyCliente(f)) {
        printf("Nenhum cliente aguardando\n");
        return;
    }
    NodoCliente *aux = f->inicio;
    while (aux != NULL) {
        printf("- %d : %s\n", aux->info.numero, aux->info.nome);
        aux = aux->prox;
    }
}

void liberaFilaCliente(FilaCliente *f) {
    if (f == NULL) return;
    while (!emptyCliente(f)) {
        dequeueCliente(f);
    }
    free(f);
}

void initCircular(FilaCircular *fc) {
    fc->inicio = 0;
    fc->fim = 0;
    fc->qtd = 0;
}

int fullCircular(FilaCircular *fc) {
    return ((fc->fim + 1) % TAM_CIRCULAR == fc->inicio);
}

int emptyCircular(FilaCircular *fc) {
    return (fc->inicio == fc->fim);
}

int enqueueCircular(FilaCircular *fc, Cliente c) {
    if (fullCircular(fc)) {
        return 0;
    }
    fc->itens[fc->fim] = c;
    fc->fim = (fc->fim + 1) % TAM_CIRCULAR;
    fc->qtd++;
    return 1;
}

int dequeueCircular(FilaCircular *fc, Cliente *c) {
    if (emptyCircular(fc)) {
        return 0;
    }
    *c = fc->itens[fc->inicio];
    fc->inicio = (fc->inicio + 1) % TAM_CIRCULAR;
    fc->qtd--;
    return 1;
}

Cliente *frontCircular(FilaCircular *fc) {
    if (emptyCircular(fc)) return NULL;
    return &(fc->itens[fc->inicio]);
}

void printCircular(FilaCircular *fc) {
    if (emptyCircular(fc)) {
        printf("Fila circular vazia\n");
        return;
    }
    int idx = fc->inicio;
    while (idx != fc->fim) {
        printf("[%d: %s] ", fc->itens[idx].numero, fc->itens[idx].nome);
        idx = (idx + 1) % TAM_CIRCULAR;
    }
    printf("\n");
}

typedef struct NodoDoc {
    Documento info;
    struct NodoDoc *prox;
} NodoDoc;

struct filaDocumento {
    NodoDoc *inicio;
    NodoDoc *fim;
    int qtd;
};

FilaDocumento *criaFilaDocumento() {
    FilaDocumento *f = (FilaDocumento*)malloc(sizeof(FilaDocumento));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->qtd = 0;
    }
    return f;
}

int emptyDocumento(FilaDocumento *f) {
    return (f == NULL || f->inicio == NULL);
}

void enqueueDocumento(FilaDocumento *f, Documento d) {
    if (f == NULL) return;
    NodoDoc *novo = (NodoDoc*)malloc(sizeof(NodoDoc));
    if (novo == NULL) return;
    novo->info = d;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->qtd++;
}

Documento dequeueDocumento(FilaDocumento *f) {
    Documento d = {0, "", 0};
    if (emptyDocumento(f)) return d;
    NodoDoc *remover = f->inicio;
    d = remover->info;
    f->inicio = remover->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(remover);
    f->qtd--;
    return d;
}

void printDocumento(FilaDocumento *f) {
    if (emptyDocumento(f)) {
        printf("Nenhum documento na fila de impressao\n");
        return;
    }
    NodoDoc *aux = f->inicio;
    while (aux != NULL) {
        printf("- ID=%d, Nome=\"%s\", Paginas=%d\n", aux->info.id, aux->info.nome, aux->info.paginas);
        aux = aux->prox;
    }
}

void liberaFilaDocumento(FilaDocumento *f) {
    if (f == NULL) return;
    while (!emptyDocumento(f)) {
        dequeueDocumento(f);
    }
    free(f);
}
