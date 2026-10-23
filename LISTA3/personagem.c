#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personagem.h"

struct personagem {
    char nome[50];
    int pontos_de_vida;
    int pontos_de_ataque;
};

Personagem *personagem_cria(char *nome) {
    Personagem *p = (Personagem *)malloc(sizeof(Personagem));
    if (p != NULL) {
        strncpy(p->nome, nome, 49);
        p->nome[49] = '\0';
        p->pontos_de_vida = 100;
        p->pontos_de_ataque = 20;
    }
    return p;
}

void personagem_atacar(Personagem *atacante, Personagem *alvo) {
    if (atacante != NULL && alvo != NULL) {
        alvo->pontos_de_vida -= atacante->pontos_de_ataque;
        if (alvo->pontos_de_vida < 0) {
            alvo->pontos_de_vida = 0;
        }
    }
}

void personagem_curar(Personagem *p) {
    if (p != NULL) {
        p->pontos_de_vida += 20; /* Valor arbitrário para cura */
        if (p->pontos_de_vida > 100) {
            p->pontos_de_vida = 100;
        }
    }
}

int personagem_vivo(Personagem *p) {
    if (p != NULL) {
        return p->pontos_de_vida > 0 ? 1 : 0;
    }
    return 0;
}

void personagem_status(Personagem *p) {
    if (p != NULL) {
        printf("Nome: %s | Vida: %d | Ataque: %d\n", p->nome, p->pontos_de_vida, p->pontos_de_ataque);
    }
}

void personagem_libera(Personagem *p) {
    if (p != NULL) {
        free(p);
    }
}
