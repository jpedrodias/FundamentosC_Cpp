#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRA 50
#define TOTAL_PALAVRAS 20

// Banco de palavras
const char* palavras[TOTAL_PALAVRAS] = {
    "PROGRAMACAO", "COMPUTADOR", "ALGORITMO", "LINGUAGEM", "DESENVOLVIMENTO",
    "ESTRUTURA", "FUNCAO", "VARIAVEL", "PONTEIRO", "MEMORIA",
    "COMPILADOR", "DEPURACAO", "BIBLIOTECA", "ARQUIVO", "ENTRADA",
    "SISTEMA", "PROCESSADOR", "TECLADO", "INTERNET", "SOFTWARE"
};


// Funcao para desenhar a forca
void desenharForca(int erros) {
    printf("\n");
    printf("   ______\n");
    printf("   |    |\n");
    printf("   |    %c\n", (erros >= 1) ? 'O' : ' ');
    printf("   |   %c%c%c\n", (erros >= 3) ? '/' : ' ', (erros >= 2) ? '|' : ' ', (erros >= 4) ? '\\' : ' ');
    printf("   |   %c %c\n", (erros >= 5) ? '/' : ' ', (erros >= 6) ? '\\' : ' ');
    printf("   |\n");
    printf("___|___\n\n");
}

// Funcao para exibir a palavra com letras descobertas
void exibirPalavra(const char* palavra, const char* descobertas) {
    printf("Palavra: ");
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (descobertas[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

// Funcao para exibir letras ja tentadas
void exibirTentativas(const char* tentadas, int numTentadas) {
    if (numTentadas > 0) {
        printf("Letras tentadas: ");
        for (int i = 0; i < numTentadas; i++) {
            printf("%c ", tentadas[i]);
        }
        printf("\n");
    }
}

// Funcao para verificar se a letra ja foi tentada
int letraJaTentada(char letra, const char* tentadas, int numTentadas) {
    for (int i = 0; i < numTentadas; i++) {
        if (tentadas[i] == letra) {
            return 1;
        }
    }
    return 0;
}

// Funcao para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao para verificar se a palavra foi completamente descoberta
int palavraCompleta(const char* descobertas, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (!descobertas[i]) {
            return 0;
        }
    }
    return 1;
}

// Funcao principal do jogo
void jogar() {
    // Selecionar palavra aleatoria (tenta carregar de ficheiro palavras.txt ou palacras.txt)
    srand(time(NULL));
    char palavras_file[200][MAX_PALAVRA];
    int n_file = load_palavras("palavras.txt", palavras_file, 200);
    if (n_file == 0) {
        /* compatibilidade: ficheiro com nome possivelmente mal escrito */
        n_file = load_palavras("palacras.txt", palavras_file, 200);
    }

    const char* palavra;
    if (n_file > 0) {
        palavra = palavras_file[rand() % n_file];
    } else {
        palavra = palavras[rand() % TOTAL_PALAVRAS];
    }
    int tamanhoPalavra = strlen(palavra);

    // Arrays para controle do jogo
    char descobertas[MAX_PALAVRA] = {0};
    char tentadas[26] = {0};
    int numTentadas = 0;
    int erros = 0;

    printf("\n========================================\n");
    printf("        BEM-VINDO AO JOGO DA FORCA!\n");
    printf("========================================\n");
    printf("\nTema: Programacao e Computacao\n");
    printf("Voce tem %d tentativas!\n", MAX_TENTATIVAS);

    // Loop principal do jogo
    while (erros < MAX_TENTATIVAS && !palavraCompleta(descobertas, tamanhoPalavra)) {
        printf("\n----------------------------------------\n");
        desenharForca(erros);
        exibirPalavra(palavra, descobertas);
        exibirTentativas(tentadas, numTentadas);
        printf("\nTentativas restantes: %d\n", MAX_TENTATIVAS - erros);

        // Obter letra do jogador
        char letra;
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        limparBuffer();

        // Converter para maiuscula
        letra = toupper(letra);

        // Validar entrada
        if (!isalpha(letra)) {
            printf("\nPor favor, digite apenas letras!\n");
            continue;
        }

        // Verificar se a letra ja foi tentada
        if (letraJaTentada(letra, tentadas, numTentadas)) {
            printf("\nVoce ja tentou essa letra!\n");
            continue;
        }

        // Adicionar letra as tentadas
        tentadas[numTentadas++] = letra;

        // Verificar se a letra esta na palavra
        int acertou = 0;
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (palavra[i] == letra) {
                descobertas[i] = 1;
                acertou = 1;
            }
        }

        if (acertou) {
            printf("\nBoa! A letra '%c' esta na palavra!\n", letra);
        } else {
            erros++;
            printf("\nOps! A letra '%c' nao esta na palavra.\n", letra);
        }
    }

    // Resultado final
    printf("\n========================================\n");
    if (palavraCompleta(descobertas, tamanhoPalavra)) {
        printf("        PARABENS! VOCE VENCEU!\n");
        printf("========================================\n");
        printf("\nA palavra era: %s\n", palavra);
        printf("Voce conseguiu com %d erro(s)!\n", erros);
    } else {
        desenharForca(erros);
        printf("        GAME OVER!\n");
        printf("========================================\n");
        printf("\nA palavra era: %s\n", palavra);
        printf("Mais sorte na proxima vez!\n");
    }
}

int main() {
    char jogarNovamente;

    do {
        jogar();

        printf("\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &jogarNovamente);
        limparBuffer();
        jogarNovamente = toupper(jogarNovamente);

    } while (jogarNovamente == 'S');

    printf("\nObrigado por jogar! Ate a proxima!\n\n");

    return 0;
}
