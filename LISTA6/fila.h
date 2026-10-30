#ifndef FILA_H
#define FILA_H

typedef struct {
    int valor;
} Elem;

typedef struct fila Fila;

Fila *criaFila();
void reset(Fila *fila);
int empty(Fila *fila);
int size(Fila *fila);
void enqueue(Fila *fila, Elem elem);
Elem dequeue(Fila *fila);
void front(Fila *fila);
void clear(Fila *fila);
void print(Fila *fila);
void liberaFila(Fila *fila);

int maior_elemento(Fila *fila);
void inverter_fila(Fila *fila);
void separar_par_impar(Fila *origem, Fila *pares, Fila *impares);
void remover(Fila *fila, int valor);
Fila *intercalar_filas(Fila *f1, Fila *f2);

typedef struct {
    int numero;
    char nome[100];
} Cliente;

typedef struct filaCliente FilaCliente;

FilaCliente *criaFilaCliente();
int emptyCliente(FilaCliente *f);
int sizeCliente(FilaCliente *f);
void enqueueCliente(FilaCliente *f, Cliente c);
Cliente dequeueCliente(FilaCliente *f);
Cliente *frontCliente(FilaCliente *f);
void printCliente(FilaCliente *f);
void liberaFilaCliente(FilaCliente *f);

#define TAM_CIRCULAR 6

typedef struct {
    Cliente itens[TAM_CIRCULAR];
    int inicio;
    int fim;
    int qtd;
} FilaCircular;

void initCircular(FilaCircular *fc);
int fullCircular(FilaCircular *fc);
int emptyCircular(FilaCircular *fc);
int enqueueCircular(FilaCircular *fc, Cliente c);
int dequeueCircular(FilaCircular *fc, Cliente *c);
Cliente *frontCircular(FilaCircular *fc);
void printCircular(FilaCircular *fc);

typedef struct {
    int id;
    char nome[100];
    int paginas;
} Documento;

typedef struct filaDocumento FilaDocumento;

FilaDocumento *criaFilaDocumento();
int emptyDocumento(FilaDocumento *f);
void enqueueDocumento(FilaDocumento *f, Documento d);
Documento dequeueDocumento(FilaDocumento *f);
void printDocumento(FilaDocumento *f);
void liberaFilaDocumento(FilaDocumento *f);

#endif
