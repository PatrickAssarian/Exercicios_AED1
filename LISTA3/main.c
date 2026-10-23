#include <stdio.h>
#include "personagem.h"

int main() {
    Personagem *heroi = personagem_cria("Heroi");
    Personagem *monstro = personagem_cria("Monstro");

    printf("--- Status Inicial ---\n");
    personagem_status(heroi);
    personagem_status(monstro);

    printf("\n--- Batalha ---\n");
    printf("O Heroi ataca o Monstro!\n");
    personagem_atacar(heroi, monstro);
    personagem_status(monstro);

    printf("\nO Monstro contra-ataca!\n");
    personagem_atacar(monstro, heroi);
    personagem_status(heroi);

    printf("\nO Heroi usa uma pocao de cura!\n");
    personagem_curar(heroi);
    personagem_status(heroi);

    printf("\nO Monstro ataca repetidamente ate derrotar o Heroi...\n");
    personagem_atacar(monstro, heroi);
    personagem_atacar(monstro, heroi);
    personagem_atacar(monstro, heroi);
    personagem_atacar(monstro, heroi);
    personagem_atacar(monstro, heroi);
    
    personagem_status(heroi);

    if (personagem_vivo(heroi)) {
        printf("\nO Heroi continua vivo!\n");
    } else {
        printf("\nO Heroi foi derrotado!\n");
    }

    /* Liberação da memória */
    personagem_libera(heroi);
    personagem_libera(monstro);

    return 0;
}
