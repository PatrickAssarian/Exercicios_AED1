/*
UNIVERSIDADE FEDERAL DE PELOTAS
Exercício 2 - Problema das Duas Somas

a) Qual é a complexidade de tempo de cada versão?
- dois_soma_1: O(n^2), pois possui dois laços de repetição aninhados que dependem do tamanho n.
- dois_soma2: O(n), pois possui um único laço while que avança 'inicio' ou recua 'fim', percorrendo o vetor no máximo n vezes.

b) Qual é a complexidade de espaço adicional de cada versão?
- dois_soma_1: O(1). Utiliza apenas variáveis simples (i, j).
- dois_soma2: O(1). Utiliza apenas variáveis simples (inicio, fim, soma).

c) Qual versão é mais eficiente? Por que?
- A Versão 2 (dois_soma2) é a mais eficiente. A complexidade de tempo linear O(n) cresce de forma muito mais lenta do que a complexidade quadrática O(n^2) da Versão 1, tornando-a consideravelmente mais rápida à medida que n aumenta.

d) Qual característica do vetor é necessária para que a estratégia da Versão 2 funcione corretamente?
- O vetor DEVE estar ordenado em ordem crescente. A lógica de mover os ponteiros 'inicio' e 'fim' depende do fato de que somar elementos à direita aumenta o valor e elementos à esquerda diminui o valor.
*/
