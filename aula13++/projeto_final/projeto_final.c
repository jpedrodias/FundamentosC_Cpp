#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Para system("cls") ou system("clear")
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h> // Para setlocale Portuguese


#define DEBUG_MODE 1 // 1 ativa prints de DEBUG e 0 desativa
#define MAX_TENTATIVAS 6
#define MAX_PALAVRAS 20 // número máximo de palavras carregadas de ficheiro
#define MAX_PALAVRA_SIZE 25 // tamanho máximo de cada palavra


// estrutura para definir menus
struct Menu {
    int menu_width;
    int opcoes_length;
    char titulo[50];
    char opcoes_key[10][2];
    char opcoes_labels[10][50];
    int escolha_feita;
} Menu;


// funções para desenhar os menus
void cleanScreen();
void fillCharLine(const char* str, int count);
void drawMenu(struct Menu menu);

// funções para validação dos dados inseridos pelo utilizador
int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);
int ler_opcoes_do_menu(struct Menu menu, const char* mensagem);

// Carregar palavras de ficheiros - Os ficheiros têm vários temas
int load_palavras_file(const char *filename, char out_palavras[MAX_PALAVRAS][MAX_PALAVRA_SIZE], int max_palavras);
int carregar_tema(const char *tema, char palavras_file[MAX_PALAVRAS][MAX_PALAVRA_SIZE], int max_palavras);



int main(){
    // define a localidade para Português
    setlocale(LC_ALL, "Portuguese"); 

    // inicializar gerador de números aleatórios uma vez
    srand((unsigned) time(NULL));


    // Definições para abrir os ficheiros de palavras palavras_code, palavras_animais, palavras_frutas
    char configuracoes_temas[][30] = {"code", "animals", "fruits"}; // "palavras_%s.txt"
    char configuracoes_temas_current[30];
    strcpy(configuracoes_temas_current, configuracoes_temas[0]); // tema padrão "code"


    // Definição do menu principal
    struct Menu menuPrincipal = {
        40, // menu_width (aumentado para caber as opções)
        4,  // opcoes_length
        "Menu Principal - Jogo da Forca", 
        {"1", "2", "3", "0"},
        {"Iniciar Jogo", "Configurar Jogo", "Sobre", "Sair"},
        0 // escolha_feita
    }; 
    enum MenuPrincipal { INICIAR_JOGO = 1, CONFIGURAR_JOGO = 2, SOBRE = 3, SAIR = 0 };


    // Definição do menu configurar
    struct Menu menuConfigurar = {
        40, 3,
        "Menu Configurar - Jogo da Forca",
        {"1", "2", "0"},
        {"Definir Dificuldade", "Definir Tema", "Voltar ao Menu Principal"},
        0
    };
    enum MenuConfigurar { CONFIGURAR_DIFICULDADE = 1, CONFIGURAR_TEMA = 2, VOLTAR_MENU_PRINCIPAL = 0 };


    bool gameOver = false;
    while (gameOver == false) {
        cleanScreen();
        drawMenu(menuPrincipal);
        menuPrincipal.escolha_feita = ler_opcoes_do_menu(menuPrincipal, "Escolha uma opção: ");
        
        switch (menuPrincipal.escolha_feita) {
            case INICIAR_JOGO:
                {
                    /* buffer para palavras lidas do ficheiro */
                    char palavras_file[MAX_PALAVRAS][MAX_PALAVRA_SIZE];
                    int capacidade = (int)(sizeof(palavras_file) / sizeof(palavras_file[0]));
                    int n = carregar_tema(configuracoes_temas_current, palavras_file, capacidade);
                    if (n > 0) {
                        int idx = rand() % n;
                        #ifdef DEBUG_MODE
                        printf("Palavra escolhida (para teste): %s\n", palavras_file[idx]);
                        #endif
                        /* Aqui podes chamar a função de jogar passando a palavra escolhida */
                    } else {
                        printf("Nenhuma palavra disponível para o tema atual.\n");
                    }
                    #ifdef DEBUG_MODE
                    menuPrincipal.escolha_feita = ler_inteiro_no_intervalo(0, 0, "Pressione Enter para voltar ao menu...");
                    #endif
                }
                break;
            case CONFIGURAR_JOGO:
                printf("Configurando o jogo...\n");
                cleanScreen();
                drawMenu(menuConfigurar);
                menuConfigurar.escolha_feita = ler_opcoes_do_menu(menuConfigurar, "Escolha uma opção: ");

                switch (menuConfigurar.escolha_feita) {
                case CONFIGURAR_DIFICULDADE:
                    /* a dificuldade é o tamanho da palavra: até 5, até 10, até 15 ou mais*/
                    break;
                case CONFIGURAR_TEMA:
                    printf("Selecionar Tema:\n");
                    for (int i = 0; i < (int)(sizeof(configuracoes_temas) / sizeof(configuracoes_temas[0])); i++) {
                        printf("%d - %s\n", i + 1, configuracoes_temas[i]);
                    }
                    {
                        int tema_escolhido = ler_inteiro_no_intervalo(1, (int)(sizeof(configuracoes_temas) / sizeof(configuracoes_temas[0])), "Escolha o número do tema: ");
                        strcpy(configuracoes_temas_current, configuracoes_temas[tema_escolhido - 1]);
                        printf("Tema definido para: %s\n", configuracoes_temas_current);
                    }
                    break;
                default:
                    break;
                }


                break;
            case SOBRE:
                printf("Jogo da Forca - Versão 1.0\nDesenvolvido por PedroDias\n");
                break;
            case SAIR:
                printf("Saindo do programa...\n");
                gameOver = true;
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0; 
} // fim main


/*
 * Limpa a tela do console.
 * Em Windows usa "cls", noutros sistemas usa "clear".
 * Não tem parâmetros e não retorna valor.
 */
void cleanScreen() {
    // Limpa a tela do console
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
} // fim cleanScreen


/*
 * Imprime `str` repetida `count` vezes sem nova linha.
 * Usada para desenhar linhas do menu (bordas e espaços).
 * Parâmetros:
 *  - str: string a repetir (por exemplo "═" ou " ")
 *  - count: número de repetições
 */
void fillCharLine(const char* str, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s", str);
    }
}


/*
 * Desenha um menu caixa no ecrã com título e opções.
 * O `struct Menu` contém largura, número de opções, título,
 * chaves das opções e rótulos. Esta função apenas imprime o menu
 * formatado; não processa entrada do utilizador.
 */
void drawMenu(struct Menu menu){
    int menu_width = menu.menu_width;
    int opcoes_length = menu.opcoes_length;

    // Linha superior: ╔═══...═══╗
    printf("╔");
    fillCharLine("═", menu_width - 2);
    printf("╗\n");

    // Linha do título: ║ Titulo...║
    printf("║ %s", menu.titulo);
    int titulo_length = strlen(menu.titulo);
    fillCharLine(" ", menu_width - titulo_length - 3);
    printf("║\n");

    // Separador: ╠═══...═══╣
    printf("╠");
    fillCharLine("═", menu_width - 2);
    printf("╣\n");

    // Linhas das opções
    for (int i = 0; i < opcoes_length; i++) {
        printf("║ %s - %s", menu.opcoes_key[i], menu.opcoes_labels[i]);
        int opcao_length = strlen(menu.opcoes_key[i]) + strlen(menu.opcoes_labels[i]) + 5;
        fillCharLine(" ", menu_width - opcao_length - 1);
        printf("║\n");
    }

    // Linha inferior: ╚═══...═══╝
    printf("╚");
    fillCharLine("═", menu_width - 2);
    printf("╝\n");
}


/*
 * Lê um inteiro do utilizador garantindo que fica entre `minimo` e `maximo`.
 * Repete o pedido até o utilizador fornecer um valor válido.
 * Parâmetros:
 *  - minimo: limite inferior (inclusivo)
 *  - maximo: limite superior (inclusivo)
 *  - mensagem: mensagem mostrada ao pedir o valor
 * Retorna: o inteiro lido (garantido dentro do intervalo).
 */
int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem) {
    int valor;
    do {
        printf("%s", mensagem);
        scanf("%d", &valor);
        if (valor < minimo || valor > maximo) {
            printf("Valor inválido. O valor deve estar entre %d e %d.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
} // fim ler_inteiro_no_intervalo


/*
 * Lê a opção escolhida pelo utilizador para um dado `Menu`.
 * O utilizador escreve a chave (por exemplo "1", "0"). A função valida
 * se a chave corresponde a uma das `opcoes_key` do menu e retorna o
 * inteiro correspondente (converte a string com atoi).
 * Retorna o inteiro da opção encontrada ou -1 em caso de erro.
 */
int ler_opcoes_do_menu(struct Menu menu, const char* mensagem) {
    char input[3];
    int valido;
    int opcao_encontrada = -1;

    do {
        printf("%s", mensagem);
        scanf("%2s", input);

        // Verificar se o input corresponde a alguma opcao_key do menu
        valido = 0;
        for (int i = 0; i < menu.opcoes_length; i++) {
            if (strcmp(input, menu.opcoes_key[i]) == 0) {
                valido = 1;
                opcao_encontrada = atoi(input); // Converter string para int
                break;
            }
        }

        if (!valido) {
            printf("Opção inválida! Escolha uma das opções do menu: ");
            for (int i = 0; i < menu.opcoes_length; i++) {
                printf("%s", menu.opcoes_key[i]);
                if (i < menu.opcoes_length - 1) {
                    printf(", ");
                }
            }
            printf("\n");
        }
    } while (!valido);

    return opcao_encontrada;
} // fim ler_opcoes_do_menu


/*
 * Lê palavras de um ficheiro (uma palavra por linha) para um array fornecido.
 * Retorna o número de palavras lidas. Linhas vazias são ignoradas.
 * Cada palavra é truncada a (MAX_PALAVRA-1) e terminada por '\0'.
 */
int load_palavras_file(const char *filename, char out_palavras[MAX_PALAVRAS][MAX_PALAVRA_SIZE], int max_palavras) {
    FILE *f = fopen(filename, "r");
    if (!f) return 0;

    char line[512];
    int count = 0;
    while (count < max_palavras && fgets(line, sizeof(line), f)) {
        /* trim left */
        char *s = line;
        while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') s++;
        /* trim right/newline */
        char *e = s + strlen(s) - 1;
        while (e >= s && (*e == '\n' || *e == '\r' || *e == ' ' || *e == '\t')) { *e = '\0'; e--; }
        if (*s == '\0') continue; /* linha vazia */

        /* copiar e normalizar para maiúsculas */
        size_t i;
        for (i = 0; i < (size_t)MAX_PALAVRA_SIZE - 1 && s[i] != '\0'; i++) {
            out_palavras[count][i] = toupper((unsigned char)s[i]);
        }
        out_palavras[count][i] = '\0';
        count++;
    }
    fclose(f);
    return count;
}


/*
 * Carrega o ficheiro de palavras para o array `palavras_file`.
 * O nome do ficheiro é construído como "palavras_<tema>.txt".
 * Retorna o número de palavras lidas (0 indica falha/nenhuma palavra).
 */
int carregar_tema(const char *tema, char palavras_file[MAX_PALAVRAS][MAX_PALAVRA_SIZE], int max_palavras) {
    char filename[256];
    snprintf(filename, sizeof(filename), "palavras_%s.txt", tema);

    int n = load_palavras_file(filename, palavras_file, max_palavras);
    if (n > 0) {
        printf("Iniciando o jogo... carregado %d palavra(s) do ficheiro '%s'.\n", n, filename);
    } else {
        printf("Não foi possível carregar palavras do ficheiro '%s'.\n", filename);
        printf("Iniciando o jogo com palavras embutidas...\n");
    }
    return n;
}
