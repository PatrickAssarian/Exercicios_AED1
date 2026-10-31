#include <stdio.h>
#include <stdlib.h>
#include "rubro_negra.h"

Rubro_Negra *criaNoRN(int valor) {
    Rubro_Negra *novo = (Rubro_Negra*)malloc(sizeof(Rubro_Negra));
    if (novo == NULL) return NULL;
    novo->info = valor;
    novo->cor = VERMELHO;
    novo->sae = NULL;
    novo->sad = NULL;
    novo->pai = NULL;
    return novo;
}

static void rotacaoEsquerda(Rubro_Negra **raiz, Rubro_Negra *x) {
    Rubro_Negra *y = x->sad;
    x->sad = y->sae;
    if (y->sae != NULL) y->sae->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL) {
        *raiz = y;
    } else if (x == x->pai->sae) {
        x->pai->sae = y;
    } else {
        x->pai->sad = y;
    }
    y->sae = x;
    x->pai = y;
}

static void rotacaoDireita(Rubro_Negra **raiz, Rubro_Negra *y) {
    Rubro_Negra *x = y->sae;
    y->sae = x->sad;
    if (x->sad != NULL) x->sad->pai = y;
    x->pai = y->pai;
    if (y->pai == NULL) {
        *raiz = x;
    } else if (y == y->pai->sae) {
        y->pai->sae = x;
    } else {
        y->pai->sad = x;
    }
    x->sad = y;
    y->pai = x;
}

static void corrigeInsercao(Rubro_Negra **raiz, Rubro_Negra *z) {
    while (z != *raiz && z->pai != NULL && z->pai->cor == VERMELHO) {
        if (z->pai == z->pai->pai->sae) {
            Rubro_Negra *tio = z->pai->pai->sad;
            if (tio != NULL && tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->sad) {
                    z = z->pai;
                    rotacaoEsquerda(raiz, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacaoDireita(raiz, z->pai->pai);
            }
        } else {
            Rubro_Negra *tio = z->pai->pai->sae;
            if (tio != NULL && tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                z = z->pai->pai;
            } else {
                if (z == z->pai->sae) {
                    z = z->pai;
                    rotacaoDireita(raiz, z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                rotacaoEsquerda(raiz, z->pai->pai);
            }
        }
    }
    (*raiz)->cor = PRETO;
}

Rubro_Negra *insereRN(Rubro_Negra *raiz, int valor) {
    Rubro_Negra *z = criaNoRN(valor);
    if (z == NULL) return raiz;

    Rubro_Negra *y = NULL;
    Rubro_Negra *x = raiz;

    while (x != NULL) {
        y = x;
        if (z->info < x->info) {
            x = x->sae;
        } else if (z->info > x->info) {
            x = x->sad;
        } else {
            free(z);
            return raiz;
        }
    }

    z->pai = y;
    if (y == NULL) {
        raiz = z;
    } else if (z->info < y->info) {
        y->sae = z;
    } else {
        y->sad = z;
    }

    corrigeInsercao(&raiz, z);
    return raiz;
}

static Rubro_Negra *minimoNo(Rubro_Negra *n) {
    while (n != NULL && n->sae != NULL) n = n->sae;
    return n;
}

static void transplante(Rubro_Negra **raiz, Rubro_Negra *u, Rubro_Negra *v) {
    if (u->pai == NULL) {
        *raiz = v;
    } else if (u == u->pai->sae) {
        u->pai->sae = v;
    } else {
        u->pai->sad = v;
    }
    if (v != NULL) {
        v->pai = u->pai;
    }
}

static void corrigeRemocao(Rubro_Negra **raiz, Rubro_Negra *x, Rubro_Negra *pai_x) {
    while (x != *raiz && (x == NULL || x->cor == PRETO)) {
        if (x == (pai_x != NULL ? pai_x->sae : NULL)) {
            Rubro_Negra *w = pai_x != NULL ? pai_x->sad : NULL;
            if (w != NULL && w->cor == VERMELHO) {
                w->cor = PRETO;
                pai_x->cor = VERMELHO;
                rotacaoEsquerda(raiz, pai_x);
                w = pai_x->sad;
            }
            if ((w == NULL || w->sae == NULL || w->sae->cor == PRETO) &&
                (w == NULL || w->sad == NULL || w->sad->cor == PRETO)) {
                if (w != NULL) w->cor = VERMELHO;
                x = pai_x;
                pai_x = (x != NULL) ? x->pai : NULL;
            } else {
                if (w != NULL && (w->sad == NULL || w->sad->cor == PRETO)) {
                    if (w->sae != NULL) w->sae->cor = PRETO;
                    w->cor = VERMELHO;
                    rotacaoDireita(raiz, w);
                    w = pai_x->sad;
                }
                if (w != NULL) {
                    w->cor = (pai_x != NULL) ? pai_x->cor : PRETO;
                    if (w->sad != NULL) w->sad->cor = PRETO;
                }
                if (pai_x != NULL) {
                    pai_x->cor = PRETO;
                    rotacaoEsquerda(raiz, pai_x);
                }
                x = *raiz;
                break;
            }
        } else {
            Rubro_Negra *w = pai_x != NULL ? pai_x->sae : NULL;
            if (w != NULL && w->cor == VERMELHO) {
                w->cor = PRETO;
                pai_x->cor = VERMELHO;
                rotacaoDireita(raiz, pai_x);
                w = pai_x->sae;
            }
            if ((w == NULL || w->sad == NULL || w->sad->cor == PRETO) &&
                (w == NULL || w->sae == NULL || w->sae->cor == PRETO)) {
                if (w != NULL) w->cor = VERMELHO;
                x = pai_x;
                pai_x = (x != NULL) ? x->pai : NULL;
            } else {
                if (w != NULL && (w->sae == NULL || w->sae->cor == PRETO)) {
                    if (w->sad != NULL) w->sad->cor = PRETO;
                    w->cor = VERMELHO;
                    rotacaoEsquerda(raiz, w);
                    w = pai_x->sae;
                }
                if (w != NULL) {
                    w->cor = (pai_x != NULL) ? pai_x->cor : PRETO;
                    if (w->sae != NULL) w->sae->cor = PRETO;
                }
                if (pai_x != NULL) {
                    pai_x->cor = PRETO;
                    rotacaoDireita(raiz, pai_x);
                }
                x = *raiz;
                break;
            }
        }
    }
    if (x != NULL) x->cor = PRETO;
}

Rubro_Negra *removeRN(Rubro_Negra *raiz, int valor) {
    Rubro_Negra *z = raiz;
    while (z != NULL && z->info != valor) {
        if (valor < z->info) z = z->sae;
        else z = z->sad;
    }
    if (z == NULL) return raiz;

    Rubro_Negra *y = z;
    Rubro_Negra *x = NULL;
    Rubro_Negra *pai_x = NULL;
    int cor_original = y->cor;

    if (z->sae == NULL) {
        x = z->sad;
        pai_x = z->pai;
        transplante(&raiz, z, z->sad);
    } else if (z->sad == NULL) {
        x = z->sae;
        pai_x = z->pai;
        transplante(&raiz, z, z->sae);
    } else {
        y = minimoNo(z->sad);
        cor_original = y->cor;
        x = y->sad;
        if (y->pai == z) {
            pai_x = y;
        } else {
            pai_x = y->pai;
            transplante(&raiz, y, y->sad);
            y->sad = z->sad;
            if (y->sad != NULL) y->sad->pai = y;
        }
        transplante(&raiz, z, y);
        y->sae = z->sae;
        if (y->sae != NULL) y->sae->pai = y;
        y->cor = z->cor;
    }

    free(z);

    if (cor_original == PRETO) {
        corrigeRemocao(&raiz, x, pai_x);
    }

    if (raiz != NULL) raiz->cor = PRETO;
    return raiz;
}

int alturaNegra(Rubro_Negra *raiz) {
    if (raiz == NULL) return 1;
    int an = alturaNegra(raiz->sae);
    return (raiz->cor == PRETO ? 1 : 0) + an;
}

static int validaRN_aux(Rubro_Negra *raiz, int *altura_negra_ref, int cont_preto) {
    if (raiz == NULL) {
        cont_preto++;
        if (*altura_negra_ref == -1) {
            *altura_negra_ref = cont_preto;
            return 1;
        }
        return (cont_preto == *altura_negra_ref);
    }

    if (raiz->cor == VERMELHO) {
        if ((raiz->sae != NULL && raiz->sae->cor == VERMELHO) ||
            (raiz->sad != NULL && raiz->sad->cor == VERMELHO)) {
            return 0;
        }
    } else {
        cont_preto++;
    }

    return validaRN_aux(raiz->sae, altura_negra_ref, cont_preto) &&
           validaRN_aux(raiz->sad, altura_negra_ref, cont_preto);
}

int validaPropriedadesRN(Rubro_Negra *raiz) {
    if (raiz == NULL) return 1;
    if (raiz->cor != PRETO) return 0;
    int ref = -1;
    return validaRN_aux(raiz, &ref, 0);
}

void emOrdemRN(Rubro_Negra *raiz) {
    if (raiz == NULL) return;
    emOrdemRN(raiz->sae);
    printf("%d(%c) ", raiz->info, raiz->cor == VERMELHO ? 'V' : 'P');
    emOrdemRN(raiz->sad);
}

void liberaRN(Rubro_Negra *raiz) {
    if (raiz != NULL) {
        liberaRN(raiz->sae);
        liberaRN(raiz->sad);
        free(raiz);
    }
}
