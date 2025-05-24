#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>

// Tamanho do nosso oceano
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3  // Cada navio tem 3 partes

// Símbolos para mostrar no mapa
#define AGUA '~'
#define NAVIO 'N'

// Função para mostrar nosso oceano
void mostrarOceano(char oceano[LINHAS][COLUNAS]) {
    printf("\n  Mapa do Oceano\n\n");
    
    // Mostra as colunas (A-J)
    printf("   ");
    for (int c = 0; c < COLUNAS; c++) {
        printf(" %c ", 'A' + c);
    }
    printf("\n");
    
    // Mostra cada linha com seu conteúdo
    for (int l = 0; l < LINHAS; l++) {
        printf("%2d ", l + 1);  // Números das linhas (1-10)
        
        for (int c = 0; c < COLUNAS; c++) {
            printf(" %c ", oceano[l][c]);
        }
        printf("\n");
    }
    
    printf("\nLegenda:\n");
    printf(" %c - Água\n", AGUA);
    printf(" %c - Parte de um navio\n\n", NAVIO);
}

int main() {
    printf("Preparando o jogo de Batalha Naval!\n");
    
    // Criamos nosso oceano e enchemos de água
    char oceano[LINHAS][COLUNAS];
    for (int l = 0; l < LINHAS; l++) {
        for (int c = 0; c < COLUNAS; c++) {
            oceano[l][c] = AGUA;
        }
    }
    
    // Vamos posicionar nossos navios
    printf("Posicionando os navios...\n");
    
    // Navio horizontal (linha 3, coluna B)
    int navioH_linha = 2;  // Linha 3 (índice 2)
    int navioH_col = 1;    // Coluna B (índice 1)
    
    // Navio vertical (linha 5, coluna E)
    int navioV_linha = 4;  // Linha 5 (índice 4)
    int navioV_col = 4;    // Coluna E (índice 4)
    
    // Verificamos se os navios cabem no oceano
    // Navio horizontal precisa de 3 colunas livres
    if (navioH_col + TAMANHO_NAVIO > COLUNAS) {
        printf("Ops! O navio horizontal não cabe aqui.\n");
        return 1;
    }
    
    // Navio vertical precisa de 3 linhas livres
    if (navioV_linha + TAMANHO_NAVIO > LINHAS) {
        printf("Ops! O navio vertical não cabe aqui.\n");
        return 1;
    }
    
    // Verificamos se os navios não estão se encostando
    // (versão simplificada para iniciantes)
    if (navioH_linha >= navioV_linha - 1 && 
        navioH_linha <= navioV_linha + TAMANHO_NAVIO &&
        navioH_col <= navioV_col + 1 && 
        navioH_col + TAMANHO_NAVIO >= navioV_col) {
        printf("Ops! Os navios estão muito próximos.\n");
        return 1;
    }
    
    // Colocamos o navio horizontal no oceano
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        oceano[navioH_linha][navioH_col + i] = NAVIO;
    }
    
    // Colocamos o navio vertical no oceano
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        oceano[navioV_linha + i][navioV_col] = NAVIO;
    }
    
    // Mostramos como ficou nosso oceano com os navios
    mostrarOceano(oceano);
    
    printf("Pronto! O jogo está preparado para começar.\n");
    printf("Os navios estão marcados com '%c' no mapa.\n", NAVIO);
    
    return 0;
}