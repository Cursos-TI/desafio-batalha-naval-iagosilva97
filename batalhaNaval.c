#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define TAM_NAVIO 3

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro com representação visual
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro[i][j] == AGUA)
                printf("~ ");
            else if (tabuleiro[i][j] == NAVIO)
                printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* ");
        }
        printf("\n");
    }
}

// Posicionamento de navio simples: horizontal
int posicionarHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna)
{
    if (coluna + TAM_NAVIO > TAM_TABULEIRO)
        return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
        if (tabuleiro[linha][coluna + i] != AGUA)
            return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha][coluna + i] = NAVIO;
    return 1;
}

// Posicionamento de navio: diagonal ↘
int posicionarDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna)
{
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO)
        return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
        if (tabuleiro[linha + i][coluna + i] != AGUA)
            return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha + i][coluna + i] = NAVIO;
    return 1;
}

// Cria matriz de habilidade cone
void criarMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            // Expansão triangular para baixo
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i && i <= TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade cruz
void criarMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade octaedro (losango)
void criarMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE])
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica a matriz da habilidade ao tabuleiro no ponto de origem
void aplicarHabilidadeAoTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                                  int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                                  int origemLinha, int origemColuna)
{
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            int tabLinha = origemLinha - offset + i;
            int tabColuna = origemColuna - offset + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (tabLinha >= 0 && tabLinha < TAM_TABULEIRO &&
                tabColuna >= 0 && tabColuna < TAM_TABULEIRO)
            {
                if (habilidade[i][j] == 1 && tabuleiro[tabLinha][tabColuna] == AGUA)
                {
                    tabuleiro[tabLinha][tabColuna] = HABILIDADE;
                }
            }
        }
    }
}

int main()
{
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializa tabuleiro e navios
    inicializarTabuleiro(tabuleiro);
    posicionarHorizontal(tabuleiro, 2, 2); // Navio 1
    posicionarDiagonal(tabuleiro, 6, 1);   // Navio 2

    // Cria habilidades
    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidadeAoTabuleiro(tabuleiro, cone, 1, 5);
    aplicarHabilidadeAoTabuleiro(tabuleiro, cruz, 5, 5);
    aplicarHabilidadeAoTabuleiro(tabuleiro, octaedro, 7, 7);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
