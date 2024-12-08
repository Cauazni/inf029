
// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:Cauã Santos Alves Pereira Silva
//  email:cauasapsilva@gmail.com / 20232160037@ifba.edu.br
//  Matrícula:20232160037
//  Semestre:2024.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################



#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define NUM_NAVIOS 5

char jogador1[TAM_TABULEIRO][TAM_TABULEIRO];
char jogador2[TAM_TABULEIRO][TAM_TABULEIRO];

int num_navios = NUM_NAVIOS;



void limpar_console() {
    system("clear");
}

void inicializar_tabuleiros() {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            jogador1[i][j] = ' ';
            jogador2[i][j] = ' ';
        }
    }
}

void listar_tabuleiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int mostrar_navios) {
    printf("    ");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d   ", i);
    }
    printf("\n");
    printf("   +");
    for (int i = 0; i < TAM_TABULEIRO * 4 + 1; i++) {
        printf("-");
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d |", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (!mostrar_navios && tabuleiro[i][j] == 'N') {
                printf("   ");
            } else {
                printf(" %c ", tabuleiro[i][j]);
            }
            printf("|");
        }
        printf("\n");
        printf("   +");
        for (int k = 0; k < TAM_TABULEIRO * 4 + 1; k++) {
            printf("-");
        }
        printf("\n");
    }
}

int verificar_posicao_valida(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'h') {
        for (int i = 0; i < tamanho; i++) {
            if (coluna + i >= TAM_TABULEIRO || tabuleiro[linha][coluna + i] != ' ') {
                return 0;
            }
        }
    } else if (direcao == 'v') {
        for (int i = 0; i < tamanho; i++) {
            if (linha + i >= TAM_TABULEIRO || tabuleiro[linha + i][coluna] != ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void posicionar_navio(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'h') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = 'N';
        }
    } else if (direcao == 'v') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = 'N';
        }
    }
}

void disparar(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
        printf("Tiro inválido.\n");
    } else if (tabuleiro[linha][coluna] == 'N') {
        tabuleiro[linha][coluna] = '0';
        printf("Acertou um navio!\n");
        num_navios--;
    } else if (tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = 'X';
        printf("Água...\n");
    } else {
        printf("Posição já atingida.\n");
    }
}

int main() {
    inicializar_tabuleiros();
    printf("Jogador 1, posicione seus navios:\n");
    for (int i = 0; i < NUM_NAVIOS; i++) {
        int linha, coluna;
        char direcao;
        int tamanho;
        if (i == 0) tamanho = 4;
        else if (i == 1) tamanho = 3;
        else if (i >= 2 && i <= 4) tamanho = 1;
        else tamanho = 2;

        printf("Posicione o navio de tamanho %d (linha coluna direção 'h' ou 'v'): ", tamanho);
        scanf("%d %d %c", &linha, &coluna, &direcao);

        if (!verificar_posicao_valida(jogador1, linha, coluna, tamanho, direcao)) {
            printf("Posição inválida, tente novamente.\n");
            i--;
        } else {
            posicionar_navio(jogador1, linha, coluna, tamanho, direcao);
        }
    }

    limpar_console();
    printf("Jogador 2, posicione seus navios:\n");
    for (int i = 0; i < NUM_NAVIOS; i++) {
        int linha, coluna;
        char direcao;
        int tamanho;
        if (i == 0) tamanho = 4;
        else if (i == 1) tamanho = 3;
        else if (i >= 2 && i <= 4) tamanho = 1;
        else tamanho = 2;

        printf("Posicione o navio de tamanho %d (linha coluna direção 'h' ou 'v'): ", tamanho);
        scanf("%d %d %c", &linha, &coluna, &direcao);

        if (!verificar_posicao_valida(jogador2, linha, coluna, tamanho, direcao)) {
            printf("Posição inválida, tente novamente.\n");
            i--;
        } else {
            posicionar_navio(jogador2, linha, coluna, tamanho, direcao);
        }
    }

    int vez = 1;
    int linha, coluna;
    while (num_navios > 0) {
        limpar_console();
        printf("Tabuleiro do Jogador %d:\n", vez);
        if (vez == 1) {
            listar_tabuleiro(jogador1, 1);
            printf("\n");
            printf("Jogador 1, sua vez de atirar (linha coluna): ");
            scanf("%d %d", &linha, &coluna);
            disparar(jogador2, linha, coluna);
        } else {
            listar_tabuleiro(jogador2, 1);
            printf("\n");
            printf("Jogador 2, sua vez de atirar (linha coluna): ");
            scanf("%d %d", &linha, &coluna);
            disparar(jogador1, linha, coluna);
        }

        vez = (vez == 1) ? 2 : 1;
    }

    limpar_console();
    printf("Fim de jogo! O jogador %d venceu.\n", (vez == 1) ? 2 : 1);

    return 0;
}