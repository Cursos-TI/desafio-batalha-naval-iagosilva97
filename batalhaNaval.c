#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para imprimir o tabuleiro
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

int main()
{
    // Matriz representando o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Define as posições iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 1;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaNavioHorizontal + TAM_NAVIO <= TAM_TABULEIRO)
    {
        // Verifica se as posições já estão ocupadas
        int podeColocar = 1;
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] == VALOR_NAVIO)
            {
                podeColocar = 0;
                break;
            }
        }

        // Se puder, posiciona o navio horizontal
        if (podeColocar)
        {
            for (int i = 0; i < TAM_NAVIO; i++)
            {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = VALOR_NAVIO;
            }
        }
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaNavioVertical + TAM_NAVIO <= TAM_TABULEIRO)
    {
        // Verifica se as posições já estão ocupadas
        int podeColocar = 1;
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == VALOR_NAVIO)
            {
                podeColocar = 0;
                break;
            }
        }

        // Se puder, posiciona o navio vertical
        if (podeColocar)
        {
            for (int i = 0; i < TAM_NAVIO; i++)
            {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = VALOR_NAVIO;
            }
        }
    }

    // Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
