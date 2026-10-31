#ifndef RUBRO_NEGRA_H
#define RUBRO_NEGRA_H

#define PRETO 0
#define VERMELHO 1

typedef struct rubro_negra {
    int info;
    struct rubro_negra *sae;
    struct rubro_negra *sad;
    struct rubro_negra *pai;
    int cor;
} Rubro_Negra;

Rubro_Negra *criaNoRN(int valor);
Rubro_Negra *insereRN(Rubro_Negra *raiz, int valor);
Rubro_Negra *removeRN(Rubro_Negra *raiz, int valor);

int alturaNegra(Rubro_Negra *raiz);
int validaPropriedadesRN(Rubro_Negra *raiz);
void emOrdemRN(Rubro_Negra *raiz);
void liberaRN(Rubro_Negra *raiz);

#endif
