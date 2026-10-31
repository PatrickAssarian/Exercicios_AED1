# Respostas Teóricas - Atividade Árvore Rubro-Negra

### Exercício 10

#### a) Por que o nó inserido é sempre pintado de vermelho?
Porque a **4ª propriedade** (todos os caminhos simples de um nó até qualquer folha descendente devem conter exatamente o mesmo número de nós pretos) é a mais custosa e difícil de restaurar. Inserindo o nó como **vermelho**, o número de nós pretos em nenhum caminho é alterado, preservando a altura negra de toda a árvore. A única propriedade que pode ser violada é a 3ª (nó vermelho não pode ter pai vermelho), que é resolvida localmente através de recolorações ou, no máximo, duas rotações.

---

#### b) Por que a remoção de um nó vermelho nunca exige correção?
Porque remover um nó vermelho não altera a quantidade de nós pretos em nenhum caminho simples da árvore (a altura negra permanece inalterada). Além disso, o pai e o filho do nó vermelho removido eram necessariamente pretos (não há dois vermelhos adjacentes), portanto nenhuma violação da propriedade rubro-negra ocorre.

---

#### c) Quantas rotações, no máximo, são feitas numa inserção? E numa remoção? Justifique.
- **Inserção:** No máximo **2 rotações**. As recolorações (Caso 1) podem se propagar subindo pela árvore até a raiz, mas assim que um caso que exige rotação ocorre (Caso 2: Triângulo $\rightarrow$ 1 rotação para transformar em Linha Reta; Caso 3: Linha Reta $\rightarrow$ 1 rotação no avô), o balanceamento é concluído imediatamente.
- **Remoção:** No máximo **3 rotações**. O pior caso ocorre quando o Caso 1 (irmão vermelho) executa 1 rotação para torná-lo preto, caindo no Caso 3 (irmão preto com sobrinho interno vermelho), que executa mais 1 rotação para preparar para o Caso 4 (sobrinho externo vermelho), que finaliza com a 3ª rotação.

---

#### d) Em quais situações a altura negra da raiz aumenta? E em quais ela diminui?
- **Aumenta (em 1):** Na **inserção**, quando a recoloração do Caso 1 se propaga até a raiz e a própria raiz é recolorida de vermelho. Ao final da correção, a raiz é obrigatoriamente repintada de preto (Propriedade 2), aumentando a altura negra de todos os caminhos da árvore uniformemente em 1.
- **Diminui (em 1):** Na **remoção**, quando um nó duplamente preto propaga a falta de um preto subindo por toda a árvore (Caso 2/Caso 6 sucessivos com ancestrais pretos) até atingir a raiz. Quando o duplo preto chega à raiz, o preto extra é simplesmente descartado, reduzindo a altura negra de todos os caminhos uniformemente em 1.
