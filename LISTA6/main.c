#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    printf("--- Exercicio 1 ---\n");
    Fila *f1 = criaFila();
    enqueue(f1, (Elem){10});
    enqueue(f1, (Elem){20});
    enqueue(f1, (Elem){30});
    printf("Fila atual: ");
    print(f1);
    printf("Elemento da frente: ");
    front(f1);
    printf("Tamanho da fila: %d\n", size(f1));
    Elem rem = dequeue(f1);
    printf("Desenfileirado: %d\n", rem.valor);
    printf("Apos dequeue: ");
    print(f1);
    clear(f1);
    printf("Fila apos clear (vazia?): %s\n", empty(f1) ? "Sim" : "Nao");
    liberaFila(f1);

    printf("\n--- Exercicio 2 ---\n");
    Fila *f2 = criaFila();
    enqueue(f2, (Elem){12});
    enqueue(f2, (Elem){45});
    enqueue(f2, (Elem){23});
    enqueue(f2, (Elem){8});
    printf("Fila: ");
    print(f2);
    printf("Maior elemento: %d\n", maior_elemento(f2));
    printf("Fila continua preservada: ");
    print(f2);
    liberaFila(f2);

    printf("\n--- Exercicio 3 ---\n");
    Fila *f3 = criaFila();
    enqueue(f3, (Elem){10});
    enqueue(f3, (Elem){20});
    enqueue(f3, (Elem){30});
    enqueue(f3, (Elem){40});
    printf("Inicio -> 10 -> 20 -> 30 -> 40 -> Fim\n");
    inverter_fila(f3);
    printf("Fila invertida: ");
    print(f3);
    liberaFila(f3);

    printf("\n--- Exercicio 4 ---\n");
    Fila *f4 = criaFila();
    enqueue(f4, (Elem){10});
    enqueue(f4, (Elem){15});
    enqueue(f4, (Elem){20});
    enqueue(f4, (Elem){7});
    enqueue(f4, (Elem){30});
    printf("Fila original: ");
    print(f4);
    Fila *pares = criaFila();
    Fila *impares = criaFila();
    separar_par_impar(f4, pares, impares);
    printf("Pares: ");
    print(pares);
    printf("Impares: ");
    print(impares);
    liberaFila(f4);
    liberaFila(pares);
    liberaFila(impares);

    printf("\n--- Exercicio 5 ---\n");
    Fila *f5 = criaFila();
    enqueue(f5, (Elem){5});
    enqueue(f5, (Elem){20});
    enqueue(f5, (Elem){5});
    enqueue(f5, (Elem){30});
    enqueue(f5, (Elem){5});
    printf("Fila antes: ");
    print(f5);
    remover(f5, 5);
    printf("Apos remover todas as ocorrencias do 5: ");
    print(f5);
    liberaFila(f5);

    printf("\n--- Exercicio 6 ---\n");
    Fila *f6_1 = criaFila();
    enqueue(f6_1, (Elem){10});
    enqueue(f6_1, (Elem){20});
    enqueue(f6_1, (Elem){30});
    Fila *f6_2 = criaFila();
    enqueue(f6_2, (Elem){40});
    enqueue(f6_2, (Elem){50});
    enqueue(f6_2, (Elem){60});
    printf("Fila 1: ");
    print(f6_1);
    printf("Fila 2: ");
    print(f6_2);
    Fila *f6_res = intercalar_filas(f6_1, f6_2);
    printf("Resultado intercalado: ");
    print(f6_res);
    liberaFila(f6_1);
    liberaFila(f6_2);
    liberaFila(f6_res);

    printf("\n--- Exercicio 7 ---\n");
    Fila *senhas = criaFila();
    printf("Gerando senhas 101, 102, 103...\n");
    enqueue(senhas, (Elem){101});
    enqueue(senhas, (Elem){102});
    enqueue(senhas, (Elem){103});
    printf("Proxima senha a ser chamada: ");
    front(senhas);
    printf("Total de pessoas aguardando: %d\n", size(senhas));
    printf("Chamando senha: %d\n", dequeue(senhas).valor);
    printf("Total aguardando agora: %d\n", size(senhas));
    liberaFila(senhas);

    printf("\n--- Exercicio 8 ---\n");
    FilaCliente *clinica = criaFilaCliente();
    printf("Paciente cadastrado: 101 - Ana Silva\n");
    enqueueCliente(clinica, (Cliente){101, "Ana Silva"});
    printf("Paciente cadastrado: 102 - Joao Souza\n");
    enqueueCliente(clinica, (Cliente){102, "Joao Souza"});
    printf("Paciente cadastrado: 103 - Carlos Lima\n");
    enqueueCliente(clinica, (Cliente){103, "Carlos Lima"});

    Cliente *prox = frontCliente(clinica);
    if (prox) printf("Proximo paciente: %d - %s\n", prox->numero, prox->nome);

    Cliente atendido = dequeueCliente(clinica);
    printf("Atendendo: %d - %s\n", atendido.numero, atendido.nome);

    prox = frontCliente(clinica);
    if (prox) printf("Proximo paciente: %d - %s\n", prox->numero, prox->nome);
    liberaFilaCliente(clinica);

    printf("\n--- Exercicio 9 ---\n");
    FilaCircular agencia;
    initCircular(&agencia);
    enqueueCircular(&agencia, (Cliente){1, "Marcos"});
    enqueueCircular(&agencia, (Cliente){2, "Beatriz"});
    enqueueCircular(&agencia, (Cliente){3, "Lucas"});
    printf("Fila da agencia: ");
    printCircular(&agencia);
    Cliente atendidoAgencia;
    dequeueCircular(&agencia, &atendidoAgencia);
    printf("Chamado para atendimento: %d - %s\n", atendidoAgencia.numero, atendidoAgencia.nome);
    printf("Fila apos atendimento: ");
    printCircular(&agencia);

    printf("\n--- Exercicio 10 ---\n");
    FilaDocumento *impressao = criaFilaDocumento();
    printf("Documento adicionado: ID=1, Nome=\"Relatorio.pdf\", Paginas=5\n");
    enqueueDocumento(impressao, (Documento){1, "Relatorio.pdf", 5});
    printf("Documento adicionado: ID=2, Nome=\"Resumo.pdf\", Paginas=2\n");
    enqueueDocumento(impressao, (Documento){2, "Resumo.pdf", 2});
    printf("Documento adicionado: ID=3, Nome=\"O Hobbit.pdf\", Paginas=328\n");
    enqueueDocumento(impressao, (Documento){3, "O Hobbit.pdf", 328});

    Documento doc = dequeueDocumento(impressao);
    printf("Imprimindo: %s (%d paginas)\n", doc.nome, doc.paginas);
    printf("Ainda na fila de impressao:\n");
    printDocumento(impressao);
    liberaFilaDocumento(impressao);

    return 0;
}
