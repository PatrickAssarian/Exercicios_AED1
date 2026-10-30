#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char carac;
} Elem;

typedef struct pilha Pilha;

Pilha *criaPilha();
void reset(Pilha *pilha);
int empty(Pilha *pilha);
int size(Pilha *pilha);
void push(Pilha *pilha, Elem elem);
Elem pop(Pilha *pilha);
void top(Pilha *pilha);
void clear(Pilha *pilha);
void print(Pilha *pilha);
void liberaPilha(Pilha *pilha);

void inverter_string(const char *str, char *resultado);
int verifica_palindromo(const char *palavra);
int verifica_balanceamento(const char *expr);
void remove_repetidos_consecutivos(const char *str, char *resultado);
void remover(Pilha *pilha, char valor);
void inverter_palavras(const char *frase, char *resultado);
int avalia_posfixa(const char *expr);

typedef struct pilhaString PilhaString;

PilhaString *criaPilhaString();
int emptyString(PilhaString *p);
void pushString(PilhaString *p, const char *url);
char *popString(PilhaString *p);
char *topString(PilhaString *p);
void printString(PilhaString *p);
void liberaPilhaString(PilhaString *p);

#endif
