#ifndef ARVORE_H
#define ARVORE_H

typedef struct arv Arv;

struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};

Arv* inicializa();
Arv* arv_cria(int valor, Arv* sae, Arv* sad);
Arv* arv_libera(Arv* a);
void preOrder(Arv *raiz);
void inOrder(Arv *raiz);
void postOrder(Arv *raiz);

int quantidade_nos(Arv *raiz);
int soma_valores(Arv *raiz);
int maior_elemento(Arv *raiz);
int altura(Arv *raiz);
int nos_dois_filhos(Arv *raiz);
void imprimir_internos_externos(Arv *raiz);
int existe_caminho_soma(Arv *raiz, int soma_alvo);
int eh_cheia(Arv *raiz);
int eh_perfeita(Arv *raiz);
int eh_completa(Arv *raiz);
int sao_identicas(Arv *a, Arv *b);
void soma_por_nivel(Arv *raiz);
void imprimir_caminho_alvo(Arv *raiz, int valor_alvo);
Arv *lca(Arv *raiz, int v1, int v2);

#endif
