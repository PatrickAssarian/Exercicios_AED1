#include <stdio.h>
#include <stdlib.h>

/*
 * Exercício 3
 */

// a) Retornar elemento na posição i
// Complexidade de Tempo: O(1)
// Complexidade de Espaço: O(1)
int acessar_elemento(int *v, int n, int i) {
    return v[i];
}

// b) Retornar o maior elemento
// Complexidade de Tempo: O(n)
// Complexidade de Espaço: O(1)
int maior_elemento(int *v, int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    return maior;
}

// c) Trocar metades de um vetor (n par)
// Complexidade de Tempo: O(n)
// Complexidade de Espaço: O(1)
void trocar_metades(int *M, int n) {
    int metade = n / 2;
    for (int i = 0; i < metade; i++) {
        int temp = M[i];
        M[i] = M[metade + i];
        M[metade + i] = temp;
    }
}

// d) Concatenar vetor A e B
// Complexidade de Tempo: O(m + n)
// Complexidade de Espaço Adicional: O(m + n) para o novo vetor
int *concatenar(int *A, int m, int *B, int n) {
    int *C = (int *)malloc((m + n) * sizeof(int));
    if (C != NULL) {
        for (int i = 0; i < m; i++) {
            C[i] = A[i];
        }
        for (int i = 0; i < n; i++) {
            C[m + i] = B[i];
        }
    }
    return C;
}

// e) Imprimir todos os pares (A, B)
// Complexidade de Tempo: O(m * n)
// Complexidade de Espaço Adicional: O(1)
void imprimir_pares(int *A, int m, int *B, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d)\n", A[i], B[j]);
        }
    }
}

// f) Soma dos elementos de uma matriz quadrada
// Complexidade de Tempo: O(n^2)
// Complexidade de Espaço Adicional: O(1)
int soma_matriz(int **A, int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            soma += A[i][j];
        }
    }
    return soma;
}

// g) Matriz transposta
// Complexidade de Tempo: O(n^2)
// Complexidade de Espaço Adicional: O(n^2) para a nova matriz
int **transposta(int **A, int n) {
    int **T = (int **)malloc(n * sizeof(int *));
    if (T != NULL) {
        for (int i = 0; i < n; i++) {
            T[i] = (int *)malloc(n * sizeof(int));
            if (T[i] != NULL) {
                for (int j = 0; j < n; j++) {
                    T[i][j] = A[j][i];
                }
            }
        }
    }
    return T;
}

// h) Multiplicação de Matrizes (A x B)
// Complexidade de Tempo: O(n^3)
// Complexidade de Espaço Adicional: O(n^2) para a nova matriz C
int **multiplicacao(int **A, int **B, int n) {
    int **C = (int **)malloc(n * sizeof(int *));
    if (C != NULL) {
        for (int i = 0; i < n; i++) {
            C[i] = (int *)calloc(n, sizeof(int)); // Aloca com zero
            if (C[i] != NULL) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
    }
    return C;
}
