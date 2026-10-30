#include <stdio.h>
#include <stdlib.h>
#include "lista.h" 

Head *criaLista() {
    Head *lista = (Head*)malloc(sizeof(Head));
    if (lista != NULL) lista->pFirst = NULL;
    return lista;
}

int listaVazia(Head *lista) {
    return (lista == NULL || lista->pFirst == NULL);
}

void inserirInicio(Head *lista, Info dado) {
    if (lista == NULL) return;
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo != NULL) {
        novo->info = dado;
        novo->prox = lista->pFirst;
        lista->pFirst = novo;
    }
}

void inserirFinal(Head *lista, Info dado) {
    if (lista == NULL) return;
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) return;
    novo->info = dado;
    novo->prox = NULL;
    
    if (lista->pFirst == NULL) {
        lista->pFirst = novo;
    } else {
        Nodo *aux = lista->pFirst;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
    }
}

int removerInicio(Head *lista) {
    if (listaVazia(lista)) return 0;
    Nodo *remover = lista->pFirst;
    lista->pFirst = remover->prox;
    free(remover);
    return 1;
}

int removerFinal(Head *lista) {
    if (listaVazia(lista)) return 0;
    Nodo *aux = lista->pFirst, *ant = NULL;
    while (aux->prox != NULL) {
        ant = aux;
        aux = aux->prox;
    }
    if (ant == NULL) lista->pFirst = NULL;
    else ant->prox = NULL;
    free(aux);
    return 1;
}

int buscar(Head *lista, int valor, Info *resultado) {
    Nodo *aux = lista->pFirst;
    while (aux != NULL) {
        if (aux->info.valor == valor) {
            *resultado = aux->info;
            return 1;
        }
        aux = aux->prox;
    }
    return 0; 
}

void imprimirLista(Head *lista) {
    Nodo *aux = lista->pFirst;
    while (aux != NULL) {
        printf("[%d] -> ", aux->info.valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void liberaLista(Head *lista) {
    if (lista == NULL) return;
    Nodo *aux = lista->pFirst;
    while (aux != NULL) {
        Nodo *remover = aux;
        aux = aux->prox;
        free(remover);
    }
    free(lista);
}

int quantidade_elementos(Head *lista) {
    int qtd = 0;
    Nodo *aux = lista->pFirst;
    while (aux != NULL) {
        qtd++;
        aux = aux->prox;
    }
    return qtd;
}

int quantidade_maiores(Head *lista, int valor) {
    int qtd = 0;
    Nodo *aux = lista->pFirst;
    while (aux != NULL) {
        if (aux->info.valor > valor) qtd++;
        aux = aux->prox;
    }
    return qtd;
}

void remover_todos_valor(Head *lista, int valor) {
    if (lista == NULL) return;
    Nodo *atual = lista->pFirst, *ant = NULL;
    
    while (atual != NULL) {
        if (atual->info.valor == valor) {
            Nodo *remover = atual;
            if (ant == NULL) lista->pFirst = atual->prox; 
            else ant->prox = atual->prox;                 
            atual = atual->prox;
            free(remover);
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
}

void inverter_lista(Head *lista) {
    if (lista == NULL || lista->pFirst == NULL) return;
    Nodo *ant = NULL, *atual = lista->pFirst, *prox = NULL;
    
    while (atual != NULL) {
        prox = atual->prox;  
        atual->prox = ant;   
        ant = atual;         
        atual = prox;
    }
    lista->pFirst = ant; 
}

void inverter_n_primeiros(Head *lista, int n) {
    if (lista == NULL || lista->pFirst == NULL || n <= 1) return;
    
    Nodo *ant = NULL, *atual = lista->pFirst, *prox = NULL;
    Nodo *primeiro_original = lista->pFirst;
    int cont = 0;
    
    while (atual != NULL && cont < n) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
        cont++;
    }
    
    primeiro_original->prox = atual; 
    lista->pFirst = ant;
}

void incorporar_listas(Head *lista1, Head *lista2) {
    if (lista1 == NULL || lista2 == NULL || lista2->pFirst == NULL) return;
    
    if (lista1->pFirst == NULL) {
        lista1->pFirst = lista2->pFirst;
    } else {
        Nodo *aux = lista1->pFirst;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = lista2->pFirst;
    }
    lista2->pFirst = NULL; 
}

void intercalar_listas(Head *lista1, Head *lista2) {
    if (lista1 == NULL || lista2 == NULL || lista2->pFirst == NULL) return;
    if (lista1->pFirst == NULL) { 
        lista1->pFirst = lista2->pFirst; 
        lista2->pFirst = NULL; 
        return; 
    }

    Nodo *a_atual = lista1->pFirst;
    Nodo *b_atual = lista2->pFirst;
    Nodo *a_ant = NULL;

    while (a_atual != NULL && b_atual != NULL) {
        Nodo *a_prox = a_atual->prox;
        Nodo *b_prox = b_atual->prox;

        a_atual->prox = b_atual;
        b_atual->prox = a_prox;

        a_ant = b_atual;
        a_atual = a_prox;
        b_atual = b_prox;
    }

    if (b_atual != NULL && a_ant != NULL) {
        a_ant->prox = b_atual;
    }

    lista2->pFirst = NULL; 
}

void separar_por_posicao(Head *listaOriginal, Head *listaImpares, Head *listaPares) {
    if (listaOriginal == NULL) return;
    Nodo *aux = listaOriginal->pFirst;
    int pos = 1;
    
    while (aux != NULL) {
        if (pos % 2 != 0) inserirFinal(listaImpares, aux->info);
        else inserirFinal(listaPares, aux->info);
        
        aux = aux->prox;
        pos++;
    }
}

Head* copiar_lista(Head *lista) {
    Head *novaLista = criaLista();
    Nodo *aux = lista->pFirst;
    while (aux != NULL) {
        inserirFinal(novaLista, aux->info); 
        aux = aux->prox;
    }
    return novaLista;
}

void remover_valores_pares(Head *lista) {
    if (lista == NULL) return;
    Nodo *atual = lista->pFirst, *ant = NULL;
    
    while (atual != NULL) {
        if (atual->info.valor % 2 == 0) {
            Nodo *remover = atual;
            if (ant == NULL) lista->pFirst = atual->prox;
            else ant->prox = atual->prox;
            
            atual = atual->prox;
            free(remover);
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
}

HeadDupla *criaListaDupla() {
    HeadDupla *lista = (HeadDupla*)malloc(sizeof(HeadDupla));
    if (lista != NULL) lista->pFirst = NULL;
    return lista;
}

void inserirFinalDupla(HeadDupla *lista, Info dado) {
    if (lista == NULL) return;
    NodoDuplo *novo = (NodoDuplo*)malloc(sizeof(NodoDuplo));
    if (novo == NULL) return;
    novo->info = dado;
    novo->prox = NULL;
    novo->ant = NULL;

    if (lista->pFirst == NULL) {
        lista->pFirst = novo;
    } else {
        NodoDuplo *aux = lista->pFirst;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
    }
}

void imprimirListaDupla(HeadDupla *lista) {
    if (lista == NULL) return;
    NodoDuplo *aux = lista->pFirst;
    while (aux != NULL) {
        printf("[%d] <=> ", aux->info.valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void liberaListaDupla(HeadDupla *lista) {
    if (lista == NULL) return;
    NodoDuplo *aux = lista->pFirst;
    while (aux != NULL) {
        NodoDuplo *remover = aux;
        aux = aux->prox;
        free(remover);
    }
    free(lista);
}

int remover_primeira_ocorrencia(HeadDupla *lista, int valor) {
    if (lista == NULL || lista->pFirst == NULL) return 0;
    
    NodoDuplo *aux = lista->pFirst;
    while (aux != NULL && aux->info.valor != valor) {
        aux = aux->prox;
    }
    if (aux == NULL) return 0; 
    
    if (aux->ant == NULL) {
        lista->pFirst = aux->prox;
        if (lista->pFirst != NULL) lista->pFirst->ant = NULL;
    } 
    else {
        aux->ant->prox = aux->prox;
        if (aux->prox != NULL) aux->prox->ant = aux->ant; 
    }
    free(aux);
    return 1;
}

int eh_palindromo(HeadDupla *lista) {
    if (lista == NULL || lista->pFirst == NULL) return 1;
    
    NodoDuplo *inicio = lista->pFirst;
    NodoDuplo *fim = lista->pFirst;
    
    while (fim->prox != NULL) {
        fim = fim->prox;
    }
    
    while (inicio != fim && inicio->ant != fim) {
        if (inicio->info.valor != fim->info.valor) {
            return 0; 
        }
        inicio = inicio->prox;
        fim = fim->ant;
    }
    return 1; 
}