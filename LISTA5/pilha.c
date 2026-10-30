#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

typedef struct Nodo {
    Elem info;
    struct Nodo *prox;
} Nodo;

struct pilha {
    Nodo *topo;
    int qtd;
};

Pilha *criaPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
        p->qtd = 0;
    }
    return p;
}

void reset(Pilha *pilha) {
    if (pilha == NULL) return;
    Nodo *aux = pilha->topo;
    while (aux != NULL) {
        Nodo *remover = aux;
        aux = aux->prox;
        free(remover);
    }
    pilha->topo = NULL;
    pilha->qtd = 0;
}

int empty(Pilha *pilha) {
    return (pilha == NULL || pilha->topo == NULL);
}

int size(Pilha *pilha) {
    if (pilha == NULL) return 0;
    return pilha->qtd;
}

void push(Pilha *pilha, Elem elem) {
    if (pilha == NULL) return;
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) return;
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->qtd++;
}

Elem pop(Pilha *pilha) {
    Elem e = {'\0'};
    if (empty(pilha)) return e;
    Nodo *remover = pilha->topo;
    e = remover->info;
    pilha->topo = remover->prox;
    free(remover);
    pilha->qtd--;
    return e;
}

void top(Pilha *pilha) {
    if (empty(pilha)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("%c\n", pilha->topo->info.carac);
}

void clear(Pilha *pilha) {
    reset(pilha);
}

void print(Pilha *pilha) {
    if (empty(pilha)) {
        printf("Pilha vazia\n");
        return;
    }
    Pilha *aux = criaPilha();
    Nodo *n = pilha->topo;
    while (n != NULL) {
        push(aux, n->info);
        n = n->prox;
    }
    while (!empty(aux)) {
        Elem e = pop(aux);
        printf("[%c] ", e.carac);
    }
    printf("\n");
    liberaPilha(aux);
}

void liberaPilha(Pilha *pilha) {
    if (pilha == NULL) return;
    reset(pilha);
    free(pilha);
}

void inverter_string(const char *str, char *resultado) {
    Pilha *p = criaPilha();
    for (int i = 0; str[i] != '\0'; i++) {
        push(p, (Elem){str[i]});
    }
    int idx = 0;
    while (!empty(p)) {
        resultado[idx++] = pop(p).carac;
    }
    resultado[idx] = '\0';
    liberaPilha(p);
}

int verifica_palindromo(const char *palavra) {
    Pilha *p = criaPilha();
    int len = 0;
    for (int i = 0; palavra[i] != '\0'; i++) {
        push(p, (Elem){palavra[i]});
        len++;
    }
    int eh = 1;
    for (int i = 0; i < len; i++) {
        if (palavra[i] != pop(p).carac) {
            eh = 0;
            break;
        }
    }
    liberaPilha(p);
    return eh;
}

int verifica_balanceamento(const char *expr) {
    Pilha *p = criaPilha();
    int balanceado = 1;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(p, (Elem){c});
        } else if (c == ')' || c == ']' || c == '}') {
            if (empty(p)) {
                balanceado = 0;
                break;
            }
            char topo = pop(p).carac;
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                balanceado = 0;
                break;
            }
        }
    }
    if (!empty(p)) balanceado = 0;
    liberaPilha(p);
    return balanceado;
}

void remove_repetidos_consecutivos(const char *str, char *resultado) {
    Pilha *p = criaPilha();
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (empty(p) || p->topo->info.carac != c) {
            push(p, (Elem){c});
        }
    }
    int tam = size(p);
    resultado[tam] = '\0';
    for (int i = tam - 1; i >= 0; i--) {
        resultado[i] = pop(p).carac;
    }
    liberaPilha(p);
}

void remover(Pilha *pilha, char valor) {
    if (pilha == NULL) return;
    Pilha *aux = criaPilha();
    while (!empty(pilha)) {
        Elem e = pop(pilha);
        if (e.carac != valor) {
            push(aux, e);
        }
    }
    while (!empty(aux)) {
        push(pilha, pop(aux));
    }
    liberaPilha(aux);
}

void inverter_palavras(const char *frase, char *resultado) {
    Pilha *p = criaPilha();
    int r_idx = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ') {
            push(p, (Elem){frase[i]});
        } else {
            while (!empty(p)) {
                resultado[r_idx++] = pop(p).carac;
            }
            resultado[r_idx++] = ' ';
        }
    }
    while (!empty(p)) {
        resultado[r_idx++] = pop(p).carac;
    }
    resultado[r_idx] = '\0';
    liberaPilha(p);
}

typedef struct NodoInt {
    int valor;
    struct NodoInt *prox;
} NodoInt;

int avalia_posfixa(const char *expr) {
    NodoInt *topo = NULL;
    int i = 0;
    while (expr[i] != '\0') {
        if (isspace(expr[i])) {
            i++;
            continue;
        }
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            NodoInt *novo = (NodoInt*)malloc(sizeof(NodoInt));
            novo->valor = num;
            novo->prox = topo;
            topo = novo;
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            char op = expr[i];
            i++;
            if (topo == NULL) continue;
            NodoInt *rem1 = topo;
            int b = rem1->valor;
            topo = topo->prox;
            free(rem1);

            if (topo == NULL) continue;
            NodoInt *rem2 = topo;
            int a = rem2->valor;
            topo = topo->prox;
            free(rem2);

            int res = 0;
            if (op == '+') res = a + b;
            else if (op == '-') res = a - b;
            else if (op == '*') res = a * b;
            else if (op == '/' && b != 0) res = a / b;

            NodoInt *novo = (NodoInt*)malloc(sizeof(NodoInt));
            novo->valor = res;
            novo->prox = topo;
            topo = novo;
        } else {
            i++;
        }
    }
    int final_res = 0;
    if (topo != NULL) {
        final_res = topo->valor;
        NodoInt *aux = topo;
        topo = topo->prox;
        free(aux);
    }
    return final_res;
}

typedef struct NodoStr {
    char url[120];
    struct NodoStr *prox;
} NodoStr;

struct pilhaString {
    NodoStr *topo;
};

PilhaString *criaPilhaString() {
    PilhaString *p = (PilhaString*)malloc(sizeof(PilhaString));
    if (p != NULL) p->topo = NULL;
    return p;
}

int emptyString(PilhaString *p) {
    return (p == NULL || p->topo == NULL);
}

void pushString(PilhaString *p, const char *url) {
    if (p == NULL) return;
    NodoStr *novo = (NodoStr*)malloc(sizeof(NodoStr));
    if (novo == NULL) return;
    strncpy(novo->url, url, sizeof(novo->url) - 1);
    novo->url[sizeof(novo->url) - 1] = '\0';
    novo->prox = p->topo;
    p->topo = novo;
}

char *popString(PilhaString *p) {
    if (emptyString(p)) return NULL;
    NodoStr *remover = p->topo;
    p->topo = remover->prox;
    char *texto = (char*)malloc(120 * sizeof(char));
    strcpy(texto, remover->url);
    free(remover);
    return texto;
}

char *topString(PilhaString *p) {
    if (emptyString(p)) return NULL;
    return p->topo->url;
}

void printString(PilhaString *p) {
    if (emptyString(p)) {
        printf("Historico vazio\n");
        return;
    }
    NodoStr *aux = p->topo;
    while (aux != NULL) {
        printf("- %s\n", aux->url);
        aux = aux->prox;
    }
}

void liberaPilhaString(PilhaString *p) {
    if (p == NULL) return;
    while (!emptyString(p)) {
        char *s = popString(p);
        free(s);
    }
    free(p);
}
