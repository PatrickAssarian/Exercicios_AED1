#ifndef AVL_H
#define AVL_H

typedef struct avl_tree {
    int fb;
    int info;
    struct avl_tree *sae;
    struct avl_tree *sad;
} AVL;

typedef struct avl_tree No;

AVL *criaNo(int valor);
int altura(AVL *raiz);
void atualizaFB(AVL *raiz);

AVL *rotacaoDireita(AVL *p);
AVL *rotacaoEsquerda(AVL *p);
AVL *rotacaoEsquerdaDireita(AVL *p);
AVL *rotacaoDireitaEsquerda(AVL *p);

AVL *rebalanceia(AVL *raiz);
AVL *insereAVL(AVL *raiz, int valor);

int estaBalanceada(No *raiz);
No *removeAVL(No *raiz, int chave);

void emOrdem(AVL *raiz);
void imprimeArvore(AVL *raiz, int nivel);
void liberaAVL(AVL *raiz);

#endif
