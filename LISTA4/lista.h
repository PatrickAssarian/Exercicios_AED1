#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int valor;
} Info;

typedef struct Nodo {
    Info info;
    struct Nodo *prox;
} Nodo;

typedef struct {
    Nodo *pFirst;
} Head;

Head *criaLista();
int listaVazia(Head *lista);
void inserirInicio(Head *lista, Info dado);
void inserirFinal(Head *lista, Info dado);
int removerInicio(Head *lista);
int removerFinal(Head *lista);
int buscar(Head *lista, int valor, Info *resultado);
void imprimirLista(Head *lista);
void liberaLista(Head *lista);

int quantidade_elementos(Head *lista);
int quantidade_maiores(Head *lista, int valor);
void remover_todos_valor(Head *lista, int valor);
void inverter_lista(Head *lista);
void inverter_n_primeiros(Head *lista, int n);
void incorporar_listas(Head *lista1, Head *lista2);
void intercalar_listas(Head *lista1, Head *lista2);
void separar_por_posicao(Head *listaOriginal, Head *listaImpares, Head *listaPares);
Head* copiar_lista(Head *lista);
void remover_valores_pares(Head *lista);

typedef struct NodoDuplo {
    Info info;
    struct NodoDuplo *prox;
    struct NodoDuplo *ant;
} NodoDuplo;

typedef struct {
    NodoDuplo *pFirst;
} HeadDupla;

HeadDupla *criaListaDupla();
void inserirFinalDupla(HeadDupla *lista, Info dado);
void imprimirListaDupla(HeadDupla *lista);
void liberaListaDupla(HeadDupla *lista);

int remover_primeira_ocorrencia(HeadDupla *lista, int valor);
int eh_palindromo(HeadDupla *lista);

#endif