#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função auxiliar para verificar se uma posição está ocupada
int estaOcupado(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna)
{
    return tabuleiro[linha][coluna] == VALOR_NAVIO;
}

// Função para posicionar navio horizontal
int posicionarHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna)
{
    if (coluna + TAM_NAVIO > TAM_TABULEIRO)
        return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        if (estaOcupado(tabuleiro, linha, coluna + i))
            return 0;
    }
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linha][coluna + i] = VALOR_NAVIO;
    }
    return 1;
}

// Função para posicionar navio vertical
int posicionarVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna)
{
    if (linha + TAM_NAVIO > TAM_TABULEIRO)
        return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        if (estaOcupado(tabuleiro, linha + i, coluna))
            return 0;
    }
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linha + i][coluna] = VALOR_NAVIO;
    }
    return 1;
}

// Função para posicionar navio na diagonal principal (↘)
int posicionarDiagonalPrincipal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna)
{
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO)
        return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        if (estaOcupado(tabuleiro, linha + i, coluna + i))
            return 0;
    }
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linha + i][coluna + i] = VALOR_NAVIO;
    }
    return 1;
}

// Função para posicionar navio na diagonal secundária (↙)
int posicionarDiagonalSecundaria(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna)
{
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna - TAM_NAVIO + 1 < 0)
        return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        if (estaOcupado(tabuleiro, linha + i, coluna - i))
            return 0;
    }
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linha + i][coluna - i] = VALOR_NAVIO;
    }
    return 1;
}

int main()
{
    // Inicializa tabuleiro com água
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Posiciona navios
    // 1. Horizontal (linha 1, coluna 2)
    if (!posicionarHorizontal(tabuleiro, 1, 2))
    {
        printf("Falha ao posicionar navio horizontal.\n");
    }

    // 2. Vertical (linha 4, coluna 6)
    if (!posicionarVertical(tabuleiro, 4, 6))
    {
        printf("Falha ao posicionar navio vertical.\n");
    }

    // 3. Diagonal principal ↘ (linha 0, coluna 0)
    if (!posicionarDiagonalPrincipal(tabuleiro, 0, 0))
    {
        printf("Falha ao posicionar navio diagonal principal.\n");
    }

    // 4. Diagonal secundária ↙ (linha 2, coluna 9)
    if (!posicionarDiagonalSecundaria(tabuleiro, 2, 9))
    {
        printf("Falha ao posicionar navio diagonal secundária.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
