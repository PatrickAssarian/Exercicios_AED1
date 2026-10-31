# Respostas Teóricas - Atividade AVL

### Exercício 1
a) **60, 40, 20:**
- Fatores antes da rotação: FB(60) = 2, FB(40) = 1, FB(20) = 0.
- Pivô: 60.
- Caso: Linha reta à esquerda (Esquerda-Esquerda / LL).
- Rotação: Rotação simples à direita em 60.
- Árvore final: 40 como raiz, 20 à esquerda, 60 à direita.

b) **15, 25, 35:**
- Fatores antes da rotação: FB(15) = -2, FB(25) = -1, FB(35) = 0.
- Pivô: 15.
- Caso: Linha reta à direita (Direita-Direita / RR).
- Rotação: Rotação simples à esquerda em 15.
- Árvore final: 25 como raiz, 15 à esquerda, 35 à direita.

c) **50, 10, 30:**
- Fatores antes da rotação: FB(50) = 2, FB(10) = -1, FB(30) = 0.
- Pivô: 50.
- Caso: Joelho (Esquerda-Direita / LR).
- Rotação: Rotação dupla esquerda-direita em 50 (esquerda no 10, direita no 50).
- Árvore final: 30 como raiz, 10 à esquerda, 50 à direita.

d) **10, 50, 30:**
- Fatores antes da rotação: FB(10) = -2, FB(50) = 1, FB(30) = 0.
- Pivô: 10.
- Caso: Joelho (Direita-Esquerda / RL).
- Rotação: Rotação dupla direita-esquerda em 10 (direita no 50, esquerda no 10).
- Árvore final: 30 como raiz, 10 à esquerda, 50 à direita.

---

### Exercício 2
a) **50, 30, 70, 20, 10:**
- Pivô: nó 30 (FB = 2, caso LL).
- Altura da subárvore do pivô antes da inserção do 10: 1 (nós 30 e 20).
- Altura da subárvore do pivô após a rotação: 1 (raiz 20, filhos 10 e 30).
- Conclusão sobre os ancestrais: Como a altura da subárvore do pivô voltou a ser 1 (a mesma de antes da inserção), o caminho até a raiz 50 não sofreu variação de altura. Nenhum ancestral é afetado e nenhuma outra rotação é necessária.

b) **50, 30, 70, 80, 90:**
- Pivô: 70 (caso RR). Rotação simples à esquerda em 70.
- Altura antes: 1. Altura depois da rotação: 1. Ancestrais permanecem inalterados.

c) **50, 30, 70, 10, 20:**
- Pivô: 30 (caso LR). Rotação dupla esquerda-direita em 30.
- Altura antes: 1. Altura depois: 1.

d) **50, 30, 70, 90, 80:**
- Pivô: 70 (caso RL). Rotação dupla direita-esquerda em 70.
- Altura antes: 1. Altura depois: 1.

---

### Exercício 3
- Ao inserir 10..70 em ordem crescente, ocorrem sucessivas rotações simples à esquerda sempre que um nó atinge FB = -2. Ao final, a árvore possui altura 2 com raiz 40, subárvore esquerda (20 com filhos 10 e 30) e subárvore direita (60 com filhos 50 e 70).
- Em ordem decrescente, o comportamento é estritamente simétrico com rotações simples à direita.

---

### Exercício 4
- Ao remover a folha 5, o nó 4 passa a ter apenas o filho esquerdo 3 (que tem filho 2). O FB de 4 se ajusta sem extrapolar o limite (-1 a 1), permanecendo balanceada.

---

### Exercício 5
- Remoção do 6: o nó 5 fica com FB = 2 (pivô). Seu filho 2 possui FB = 0.
- Aplica-se rotação simples à direita em 5. A subárvore reequilibra e o processo para pois não há propagação de desbalanceamento acima.

---

### Exercício 7
- Remoção do 5 (raiz com 2 filhos): localiza-se o menor elemento da subárvore direita (sucessor em-ordem), que é o nó 6. O valor 6 substitui o 5 na raiz, e o nó 6 original é removido fisicamente de sua posição original, mantendo a árvore balanceada com raiz 6.
