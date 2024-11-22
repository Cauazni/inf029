#include <stdio.h>

#define TAMANHO_TABULEIRO 3
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  0   1   2  \n");
    printf(" ┌───┬───┬───┐\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (j != 0) printf("│");
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n");
        if (i != 2) printf(" ├───┼───┼───┤\n");
    }
    printf(" └───┴───┴───┘\n");
}
int celulaValida(int linha, int coluna, char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return 0;
    }
    if (tabuleiro[linha][coluna] != ' ') {
        return 0;
    }
    return 1;
}
char verificarVencedor(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return tabuleiro[i][0];
        }
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return tabuleiro[0][i];
        }
    }
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }
    return ' ';
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna;
    char jogador = 'X'; 
    char vencedor = ' ';
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
    while (vencedor == ' ') {
        exibirTabuleiro(tabuleiro);
        printf("\nJogador %c, informe sua jogada (linha coluna): ", jogador);
        scanf("%d %d", &linha, &coluna);
        if (!celulaValida(linha, coluna, tabuleiro)) {
            printf("Célula inválida. Tente novamente.\n");
            continue;
        }
        tabuleiro[linha][coluna] = jogador;
        vencedor = verificarVencedor(tabuleiro);
        jogador = (jogador == 'X') ? 'O' : 'X';
    }
    exibirTabuleiro(tabuleiro);
    if (vencedor == ' ') {
        printf("\nEmpate!\n");
    } else {
        printf("\nJogador %c venceu!\n", vencedor);
    }

    return 0;
}