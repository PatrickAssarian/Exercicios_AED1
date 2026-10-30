#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    printf("--- Exercicio 1 ---\n");
    Head *l1 = criaLista();
    inserirFinal(l1, (Info){10});
    inserirFinal(l1, (Info){20});
    inserirInicio(l1, (Info){5});
    printf("Lista criada: ");
    imprimirLista(l1);

    Info buscado;
    if (buscar(l1, 10, &buscado)) {
        printf("Valor 10 encontrado na lista!\n");
    }
    removerInicio(l1);
    printf("Apos remover inicio: ");
    imprimirLista(l1);
    removerFinal(l1);
    printf("Apos remover final: ");
    imprimirLista(l1);
    liberaLista(l1);

    printf("\n--- Exercicio 2 ---\n");
    Head *l2 = criaLista();
    inserirFinal(l2, (Info){10});
    inserirFinal(l2, (Info){20});
    inserirFinal(l2, (Info){30});
    inserirFinal(l2, (Info){40});
    printf("Lista: ");
    imprimirLista(l2);
    printf("Quantidade de elementos: %d\n", quantidade_elementos(l2));
    liberaLista(l2);

    printf("\n--- Exercicio 3 ---\n");
    Head *l3 = criaLista();
    inserirFinal(l3, (Info){10});
    inserirFinal(l3, (Info){25});
    inserirFinal(l3, (Info){15});
    inserirFinal(l3, (Info){30});
    printf("Lista: ");
    imprimirLista(l3);
    printf("Elementos maiores que 20: %d\n", quantidade_maiores(l3, 20));
    liberaLista(l3);

    printf("\n--- Exercicio 4 ---\n");
    Head *l4 = criaLista();
    inserirFinal(l4, (Info){1});
    inserirFinal(l4, (Info){2});
    inserirFinal(l4, (Info){3});
    inserirFinal(l4, (Info){2});
    inserirFinal(l4, (Info){4});
    printf("Lista: ");
    imprimirLista(l4);
    remover_todos_valor(l4, 2);
    printf("Removendo o valor 2: ");
    imprimirLista(l4);
    liberaLista(l4);

    printf("\n--- Exercicio 5 ---\n");
    Head *l5 = criaLista();
    inserirFinal(l5, (Info){10});
    inserirFinal(l5, (Info){20});
    inserirFinal(l5, (Info){30});
    inserirFinal(l5, (Info){40});
    printf("Lista normal: ");
    imprimirLista(l5);
    inverter_lista(l5);
    printf("Lista invertida: ");
    imprimirLista(l5);
    liberaLista(l5);

    printf("\n--- Exercicio 6 ---\n");
    Head *l6 = criaLista();
    inserirFinal(l6, (Info){10});
    inserirFinal(l6, (Info){20});
    inserirFinal(l6, (Info){30});
    inserirFinal(l6, (Info){40});
    inserirFinal(l6, (Info){50});
    printf("Lista: ");
    imprimirLista(l6);
    inverter_n_primeiros(l6, 3);
    printf("Invertendo os 3 primeiros: ");
    imprimirLista(l6);
    liberaLista(l6);

    printf("\n--- Exercicio 7 ---\n");
    Head *l7_1 = criaLista();
    inserirFinal(l7_1, (Info){10});
    inserirFinal(l7_1, (Info){20});
    inserirFinal(l7_1, (Info){30});
    Head *l7_2 = criaLista();
    inserirFinal(l7_2, (Info){40});
    inserirFinal(l7_2, (Info){50});
    printf("Lista 1: ");
    imprimirLista(l7_1);
    printf("Lista 2: ");
    imprimirLista(l7_2);
    incorporar_listas(l7_1, l7_2);
    printf("Depois de incorporar:\n");
    printf("Lista 1: ");
    imprimirLista(l7_1);
    printf("Lista 2: ");
    imprimirLista(l7_2);
    liberaLista(l7_1);
    liberaLista(l7_2);

    printf("\n--- Exercicio 8 ---\n");
    Head *l8_1 = criaLista();
    inserirFinal(l8_1, (Info){10});
    inserirFinal(l8_1, (Info){30});
    inserirFinal(l8_1, (Info){50});
    Head *l8_2 = criaLista();
    inserirFinal(l8_2, (Info){20});
    inserirFinal(l8_2, (Info){40});
    inserirFinal(l8_2, (Info){60});
    printf("Lista 1: ");
    imprimirLista(l8_1);
    printf("Lista 2: ");
    imprimirLista(l8_2);
    intercalar_listas(l8_1, l8_2);
    printf("Depois de intercalar:\n");
    printf("Lista 1: ");
    imprimirLista(l8_1);
    printf("Lista 2: ");
    imprimirLista(l8_2);
    liberaLista(l8_1);
    liberaLista(l8_2);

    printf("\n--- Exercicio 9 ---\n");
    Head *l9 = criaLista();
    inserirFinal(l9, (Info){10});
    inserirFinal(l9, (Info){20});
    inserirFinal(l9, (Info){30});
    inserirFinal(l9, (Info){40});
    inserirFinal(l9, (Info){50});
    Head *l9_impares = criaLista();
    Head *l9_pares = criaLista();
    printf("Lista completa: ");
    imprimirLista(l9);
    separar_por_posicao(l9, l9_impares, l9_pares);
    printf("Posicoes impares: ");
    imprimirLista(l9_impares);
    printf("Posicoes pares: ");
    imprimirLista(l9_pares);
    liberaLista(l9);
    liberaLista(l9_impares);
    liberaLista(l9_pares);

    printf("\n--- Exercicio 10 ---\n");
    Head *l10 = criaLista();
    inserirFinal(l10, (Info){10});
    inserirFinal(l10, (Info){20});
    inserirFinal(l10, (Info){30});
    printf("Original: ");
    imprimirLista(l10);
    Head *l10_copia = copiar_lista(l10);
    printf("Copia: ");
    imprimirLista(l10_copia);
    liberaLista(l10);
    liberaLista(l10_copia);

    printf("\n--- Exercicio 11 ---\n");
    Head *l11 = criaLista();
    inserirFinal(l11, (Info){1});
    inserirFinal(l11, (Info){2});
    inserirFinal(l11, (Info){4});
    inserirFinal(l11, (Info){5});
    inserirFinal(l11, (Info){8});
    inserirFinal(l11, (Info){9});
    printf("Com pares: ");
    imprimirLista(l11);
    remover_valores_pares(l11);
    printf("Sem pares: ");
    imprimirLista(l11);
    liberaLista(l11);

    printf("\n--- Exercicio 12 e 13 ---\n");
    HeadDupla *ld13 = criaListaDupla();
    inserirFinalDupla(ld13, (Info){10});
    inserirFinalDupla(ld13, (Info){20});
    inserirFinalDupla(ld13, (Info){30});
    inserirFinalDupla(ld13, (Info){40});
    printf("Lista dupla: ");
    imprimirListaDupla(ld13);
    remover_primeira_ocorrencia(ld13, 30);
    printf("Apos remover 30: ");
    imprimirListaDupla(ld13);
    liberaListaDupla(ld13);

    printf("\n--- Exercicio 14 ---\n");
    HeadDupla *ld14 = criaListaDupla();
    inserirFinalDupla(ld14, (Info){10});
    inserirFinalDupla(ld14, (Info){20});
    inserirFinalDupla(ld14, (Info){30});
    inserirFinalDupla(ld14, (Info){20});
    inserirFinalDupla(ld14, (Info){10});
    printf("Lista dupla: ");
    imprimirListaDupla(ld14);
    if (eh_palindromo(ld14)) {
        printf("Resultado: E palindromo\n");
    } else {
        printf("Resultado: Nao e palindromo\n");
    }
    liberaListaDupla(ld14);

    return 0;
}