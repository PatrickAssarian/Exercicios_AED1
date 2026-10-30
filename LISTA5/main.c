#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    printf("--- Exercicio 1 ---\n");
    Pilha *p1 = criaPilha();
    push(p1, (Elem){'X'});
    push(p1, (Elem){'Y'});
    push(p1, (Elem){'Z'});
    printf("Pilha atual: ");
    print(p1);
    printf("Elemento no topo: ");
    top(p1);
    printf("Tamanho da pilha: %d\n", size(p1));
    Elem removido = pop(p1);
    printf("Elemento desempilhado: %c\n", removido.carac);
    printf("Pilha apos pop: ");
    print(p1);
    clear(p1);
    printf("Pilha apos clear (vazia?): %s\n", empty(p1) ? "Sim" : "Nao");
    liberaPilha(p1);

    printf("\n--- Exercicio 2 ---\n");
    char entrada2[] = "ESTRUTURA DE DADOS";
    char invertida2[100];
    inverter_string(entrada2, invertida2);
    printf("Entrada: %s\n", entrada2);
    printf("Saida: %s\n", invertida2);

    printf("\n--- Exercicio 3 ---\n");
    char pal1[] = "ARARA";
    char pal2[] = "RADAR";
    char pal3[] = "CASA";
    printf("%s -> %s\n", pal1, verifica_palindromo(pal1) ? "palindromo" : "nao e palindromo");
    printf("%s -> %s\n", pal2, verifica_palindromo(pal2) ? "palindromo" : "nao e palindromo");
    printf("%s -> %s\n", pal3, verifica_palindromo(pal3) ? "palindromo" : "nao e palindromo");

    printf("\n--- Exercicio 4 ---\n");
    char exp1[] = "(3 + 5) * (7 - 2)";
    char exp2[] = "(2 * (4 + 3)";
    printf("Expressao: %s\n", exp1);
    printf("%s\n", verifica_balanceamento(exp1) ? "A expressao esta corretamente balanceada." : "A expressao nao esta corretamente balanceada.");
    printf("Expressao: %s\n", exp2);
    printf("%s\n", verifica_balanceamento(exp2) ? "A expressao esta corretamente balanceada." : "A expressao nao esta corretamente balanceada.");

    printf("\n--- Exercicio 5 ---\n");
    char entrada5[] = "AAABBBCCDAA";
    char saida5[50];
    remove_repetidos_consecutivos(entrada5, saida5);
    printf("Entrada: %s\n", entrada5);
    printf("Saida: %s\n", saida5);

    printf("\n--- Exercicio 6 ---\n");
    Pilha *p6 = criaPilha();
    push(p6, (Elem){'A'});
    push(p6, (Elem){'B'});
    push(p6, (Elem){'C'});
    push(p6, (Elem){'B'});
    push(p6, (Elem){'D'});
    printf("Pilha original: ");
    print(p6);
    remover(p6, 'B');
    printf("Apos remover 'B': ");
    print(p6);
    liberaPilha(p6);

    printf("\n--- Exercicio 7 ---\n");
    char frase7[] = "ESTRUTURAS DE DADOS";
    char saida7[100];
    inverter_palavras(frase7, saida7);
    printf("Entrada: %s\n", frase7);
    printf("Saida: %s\n", saida7);

    printf("\n--- Exercicio 8 ---\n");
    char pos1[] = "3 5 +";
    char pos2[] = "5 1 2 + 4 * + 3 -";
    char pos3[] = "5 2 - 4 * 6 2 / +";
    printf("Expressao: %s -> Resultado: %d\n", pos1, avalia_posfixa(pos1));
    printf("Expressao: %s -> Resultado: %d\n", pos2, avalia_posfixa(pos2));
    printf("Expressao: %s -> Resultado: %d\n", pos3, avalia_posfixa(pos3));

    printf("\n--- Exercicio 9 ---\n");
    PilhaString *hist = criaPilhaString();
    printf("Visitar: google.com\n");
    pushString(hist, "google.com");
    printf("Visitar: ufpel.edu.br\n");
    pushString(hist, "ufpel.edu.br");
    printf("Visitar: wikipedia.org\n");
    pushString(hist, "wikipedia.org");

    printf("Voltar\n");
    free(popString(hist));
    printf("Pagina atual: %s\n", topString(hist));

    printf("Voltar\n");
    free(popString(hist));
    printf("Pagina atual: %s\n", topString(hist));

    liberaPilhaString(hist);

    return 0;
}
