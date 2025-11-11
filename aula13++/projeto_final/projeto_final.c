#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Para system("cls") ou system("clear")
#include <string.h> // strcopy
#include <ctype.h>
#include <time.h>
#include <locale.h> // Para setlocale Portuguese

#define _CRT_SECURE_NO_WARNINGS // dica do Pedro Sanches


#define DEBUG_MODE 1 // 1 ativa prints de DEBUG e 0 desativa
#define MAX_TENTATIVAS 6
#define MAX_PALAVRAS 20 // número máximo de palavras carregadas de ficheiro
#define MAX_PALAVRAS_NIVEL 5 // número máximo de palavras por nível de dificuldade
#define MAX_PALAVRA_SIZE 25 // tamanho máximo de cada palavra

/*

Menu Principal

 - 1. Iniciar Jogo
 - 2. Configurar Jogo
    - 1. Definir Dificuldade » - sub menu dificuldades e voltar
    - 2. Definir Tema        » - sub menu temas e voltar
    - 0. voltar 
 - Sobre
 - Sair

*/



// Definição da estrutura para definir menus
struct Menu {
    int menu_width;
    int opcoes_length;
    char titulo[50];
    char opcoes_key[10][2];
    char opcoes_labels[10][50];
    int escolha_feita;
} Menu;


// Definição da estrutura para definir o estado do jogo
struct Estado_do_Jogo {
    char tema_atual[MAX_PALAVRA_SIZE];
    char palavra_atual[MAX_PALAVRA_SIZE];
    int  dificuldade_atual; // 0: fácil, 1: médio, 2: difícil, 3: muito difícil
} Estado_do_Jogo;


// Funções para desenhar os menus
void cleanScreen();
void fillCharLine(const char* str, int count);
void drawMenu(struct Menu menu);


// Funções para validação dos dados inseridos pelo utilizador
int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);
int ler_opcoes_do_menu(struct Menu menu, const char* mensagem);
void ler_enter_para_continuar(const char* mensagem);

// Função do jogo da forca
void jogar(const char *palavra); /* rotina de jogo (usa a palavra fornecida) */

// Função para selecionar uma palavra com base no nível de dificuldade
int selecionar_palavra_por_nivel(char palavras_file[MAX_PALAVRAS][MAX_PALAVRA_SIZE], int n, struct Estado_do_Jogo *estado);

// Carregar palavras de ficheiros - Os ficheiros têm vários temas
int load_palavras_file(const char *filename, char out_palavras[MAX_PALAVRAS][MAX_PALAVRA_SIZE], int max_palavras);
int carregar_tema(const char *tema, char palavras_file[MAX_PALAVRAS][MAX_PALAVRA_SIZE], int max_palavras);



int main(){
    // define a localidade para Português
    setlocale(LC_ALL, "Portuguese"); 

    // inicializar gerador de números aleatórios uma vez
    srand((unsigned) time(NULL));



    // Definições para abrir os ficheiros de palavras palavras_codigo, palavras_animais, palavras_frutas
    char configuracoes_temas[][30] = {"codigo", "animais", "frutas"}; // "palavras_%s.txt"

    struct Estado_do_Jogo estado_jogo = {
        .tema_atual = "",
        .palavra_atual = "",
        .dificuldade_atual = 0
    };
    strcpy(estado_jogo.tema_atual, configuracoes_temas[0]);



    // Definição do menu Principal
    struct Menu menuPrincipal = {
        .menu_width = 40,
        .opcoes_length = 4,
        .titulo = "Menu Principal - Jogo da Forca", 
        .opcoes_key = {"1", "2", "3", "0"},
        .opcoes_labels = {"Iniciar Jogo", "Configurar Jogo", "Sobre", "Sair"},
        .escolha_feita = 0
    }; 
    enum enumMenuPrincipal { INICIAR_JOGO = 1, CONFIGURAR_JOGO = 2, SOBRE = 3, SAIR = 0 };



    // Definição do menu Configurar
    struct Menu menuConfigurar = {
        .menu_width    = 40,
        .opcoes_length = 3,
        .titulo = "Menu Configurar - Jogo da Forca",
        .opcoes_key = {"1", "2", "0"},
        .opcoes_labels = {"Definir Dificuldade", "Definir Tema", "Voltar ao Menu Principal"},
        .escolha_feita = 0
    };
    enum enumMenuConfigurar { CONFIGURAR_DIFICULDADE = 1, CONFIGURAR_TEMA = 2, CONFIGURAR_VOLTAR = 0 };



    // Definição do menu Sobre
    struct Menu menuSobre = {
        .menu_width    = 40,
        .opcoes_length = 3,
        .titulo = "Sobre o Jogo da Forca",
        .opcoes_key = {"", "", "0"},
        .opcoes_labels = {"Autor: Pedro Dias", "Versao: 0.1", "Voltar ao Menu Principal"},
        .escolha_feita = 0
    };
    enum enumMenuSobre { VOLTAR_SOBRE = 0 };



    // Definição do menu Configurar / Nível de Dificuldade
    struct Menu menuConfigurarDificuldade = {
        .menu_width = 40,
        .opcoes_length = 5,
        .titulo = "Selecionar Dificuldade",
        .opcoes_key = {"1", "2", "3", "4", "0"},
        .opcoes_labels = {"Facil (ate 5 letras)", "Medio (ate 10 letras)", "Dificil (ate 15 letras)", "Muito Dificil (16+)", "Voltar"},
        .escolha_feita = 0
    };
    enum enumMenuDificuldade { FACIL = 1, MEDIO = 2, DIFICIL = 3, MUITO_DIFICIL = 4, VOLTAR_DIFICULDADE = 0 };


    // Definição do menu Configurar / Tema
    struct Menu menuConfigurarTema = {
        .menu_width = 40,
        .opcoes_length = 4,
        .titulo = "Selecionar Tema",
        .opcoes_key = {"1", "2", "3", "0"},
        .opcoes_labels = {"Codigo", "Animais", "Frutas", "Voltar"},
        .escolha_feita = 0
    };
    enum enumMenuTema { TEMA_CODIGO = 1, TEMA_ANIMAIS = 2, TEMA_FRUTAS = 3, VOLTAR_TEMA = 0 };


    bool gameOver = false;
    while (gameOver == false) {
        cleanScreen();
        drawMenu(menuPrincipal);
        menuPrincipal.escolha_feita = ler_opcoes_do_menu(menuPrincipal, "Escolha uma opção: ");
        
        switch (menuPrincipal.escolha_feita) {
            case INICIAR_JOGO:
                { // "Naked block" | "Bare block" | "Anonymous block"

                    // buffer para palavras lidas do ficheiro de palavras (por tema)
                    char palavras_file[MAX_PALAVRAS][MAX_PALAVRA_SIZE];
                    int capacidade = (int)(sizeof(palavras_file) / sizeof(palavras_file[0]));
                    int n = carregar_tema(estado_jogo.tema_atual, palavras_file, capacidade);
                    if (n > 0) {

                        // pick é o índice da palavra escolhida - não usado nesta versão porque o estado_jogo é passado por endereço
                        int pick = selecionar_palavra_por_nivel(palavras_file, n, &estado_jogo);
                        
                        #ifdef DEBUG_MODE
                            printf("Palavra escolhida (para teste): %s\n", estado_jogo.palavra_atual);
                            ler_enter_para_continuar("Pressione Enter para voltar ao menu...");
                        #endif
                        
                        // Chamar a rotina de jogo passando a palavra escolhida
                        jogar(estado_jogo.palavra_atual);

                    } else {
                        printf("Nenhuma palavra disponível para o tema atual.\n");
                    }

                    #ifdef DEBUG_MODE
                        ler_enter_para_continuar("Pressione Enter para voltar ao menu...");
                    #endif
                }
                break;

            case CONFIGURAR_JOGO:

                cleanScreen();
                drawMenu(menuConfigurar);
                menuConfigurar.escolha_feita = ler_opcoes_do_menu(menuConfigurar, "Escolha uma opção: ");

                switch (menuConfigurar.escolha_feita) {
                case CONFIGURAR_DIFICULDADE:
                    
                    cleanScreen();
                    drawMenu(menuConfigurarDificuldade);
                    menuConfigurarDificuldade.escolha_feita = ler_opcoes_do_menu(menuConfigurarDificuldade, "Escolha uma opção: ");

                    if (menuConfigurarDificuldade.escolha_feita >= 1 && menuConfigurarDificuldade.escolha_feita <= 4) {
                        estado_jogo.dificuldade_atual = menuConfigurarDificuldade.escolha_feita - 1; /* 0..3 */
                        
                        #ifdef DEBUG_MODE
                        const char *legenda_dificuldade[] = {"Facil (<=5)", "Medio (<=10)", "Dificil (<=15)", "Muito Dificil (16+)"};
                        printf("Dificuldade definida para: %s\n", legenda_dificuldade[estado_jogo.dificuldade_atual]);
                        ler_enter_para_continuar("Pressione Enter para voltar ao menu...");
                        #endif

                    }
                    break;
                case CONFIGURAR_TEMA:
                    
                    cleanScreen();
                    drawMenu(menuConfigurarTema);
                    menuConfigurarTema.escolha_feita = ler_opcoes_do_menu(menuConfigurarTema, "Escolha uma opção: ");

                    if (menuConfigurarTema.escolha_feita >= 1 && menuConfigurarTema.escolha_feita <= (int)(sizeof(configuracoes_temas) / sizeof(configuracoes_temas[0]))) {
                        int idx = menuConfigurarTema.escolha_feita - 1;
                        strcpy(estado_jogo.tema_atual, configuracoes_temas[idx]);
                        
                        #ifdef DEBUG_MODE
                            printf("Tema definido para: %s\n", estado_jogo.tema_atual);
                            ler_enter_para_continuar("Pressione Enter para voltar ao menu...");
                        #endif

                    }
                    break;
                default:
                    break;
                }
                break;
            case SOBRE:
                cleanScreen();
                drawMenu(menuSobre);
                menuSobre.escolha_feita = ler_opcoes_do_menu(menuSobre, "Escolha uma opção: ");

                switch (menuSobre.escolha_feita) {
                    case VOLTAR_SOBRE:
                        break;
                    default:
                        break;
                }
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



// Limpa ecra »  Em Windows usa "cls", noutros sistemas usa "clear".
void cleanScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
} // fim cleanScreen



/*
Imprime "str" repetida "count" vezes sem nova linha.
Usada para desenhar linhas do menu (bordas e espaços).
Parâmetros:
- str: string a repetir (por exemplo "═" ou " ")
- count: número de repetições
*/
void fillCharLine(const char* str, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s", str);
    }
} // fim fillCharLine



/* Desenha um menu caixa no ecrã com título e opções.
O "struct Menu" contém largura, número de opções, título,chaves das opções e rótulos.
Esta função apenas imprime o menu formatado; não processa entrada do utilizador.
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

    // Listar todas as opções do menu
    for (int i = 0; i < opcoes_length; i++) {

        if (menu.opcoes_key[i][0] == '\0') {
            // Verificar se a chave está vazia: comparar o primeiro carácter com '\0'.
            printf("║ %s", menu.opcoes_labels[i]);
            int opcao_length = strlen(menu.opcoes_labels[i]) + 2;
            fillCharLine(" ", menu_width - opcao_length - 1);
            printf("║\n");
        } else {
            // Senão, colocar também a opção key
            printf("║ %s - %s", menu.opcoes_key[i], menu.opcoes_labels[i]);
            int opcao_length = strlen(menu.opcoes_key[i]) + strlen(menu.opcoes_labels[i]) + 5;
            fillCharLine(" ", menu_width - opcao_length - 1);
            printf("║\n");
        }

    }

    // Linha inferior: ╚═══...═══╝
    printf("╚");
    fillCharLine("═", menu_width - 2);
    printf("╝\n");
} // fim drawMenu



/*
Lê um inteiro do utilizador garantindo que fica entre `minimo` e `maximo`.
Repete o pedido até o utilizador fornecer um valor válido.
Parâmetros:
 - minimo: limite inferior (inclusivo)
 - maximo: limite superior (inclusivo)
 - mensagem: mensagem mostrada ao pedir o valor
Retorna: o inteiro lido (garantido dentro do intervalo).
 */
int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem) {
    int valor;
    do {
        printf("%s", mensagem);
        scanf("%d", &valor);
        /* Consumir o resto da linha (inclui o '\n' deixado pelo utilizador) para evitar
         * que leitores seguintes (fgets) sejam imediatamente satisfeitos por esse '\n'.
         */
        int _c;
        while ((_c = getchar()) != '\n' && _c != EOF) { }
        if (valor < minimo || valor > maximo) {
            printf("Valor inválido. O valor deve estar entre %d e %d.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
} // fim ler_inteiro_no_intervalo



/* Aguarda o utilizador pressionar Enter. Mostra uma mensagem e lê uma linha.
Usa fgets para consumir a linha atual (se existir) ou bloquear até o utilizador pressionar Enter.
*/
void ler_enter_para_continuar(const char* mensagem) {
    char buf[64];
    printf("%s", mensagem);
    fflush(stdout);
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        /* EOF ou erro — apenas retorna */
        return;
    }
} // fim ler_enter_para_continuar



/*
Lê a opção escolhida pelo utilizador para um dado `Menu`.
O utilizador escreve a chave (por exemplo "1", "0"). A função valida se a chave corresponde a uma das `opcoes_key` do menu 
e retorna o inteiro correspondente (converte a string com atoi).
Retorna o inteiro da opção encontrada ou -1 em caso de erro.
 */
int ler_opcoes_do_menu(struct Menu menu, const char* mensagem) {
    char input[3];
    int valido;
    int opcao_encontrada = -1;

    do {
        printf("%s", mensagem);
        scanf("%2s", input);
        /* Consumir o resto da linha (inclui o '\n') para deixar stdin numa
         * posição limpa para chamadas que usem fgets posteriormente.
         */
        int _c2;
        while ((_c2 = getchar()) != '\n' && _c2 != EOF) { }

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
} // fim load_palavras_file



/*
 * Carrega o ficheiro de palavras para o array `palavras_file`.
 * O nome do ficheiro é construído como "palavras_<tema>.txt".
 * Retorna o número de palavras lidas (0 indica falha/nenhuma palavra).
 */
int carregar_tema(const char *tema, char palavras_file[MAX_PALAVRAS][MAX_PALAVRA_SIZE], int max_palavras) {
    
    char filename[256];
    // faz o mesmo que o printf mas com "fazer" strings
    snprintf(filename, sizeof(filename), "palavras_%s.txt", tema);

    int n = load_palavras_file(filename, palavras_file, max_palavras);
    if (n > 0) {
        printf("Iniciando o jogo... carregado %d palavra(s) do ficheiro '%s'.\n", n, filename);
    } else {
        printf("Não foi possível carregar palavras do ficheiro '%s'.\n", filename);
        printf("Iniciando o jogo com palavras embutidas...\n");
    }
    return n;
} // fim carregar_tema



/* Seleciona uma palavra com base no nível guardado em estado->dificuldade_atual.
- palavras_file: array de palavras carregadas
- n: número de palavras carregadas
- estado: ponteiro para o estado do jogo (atualiza estado->palavra_atual)
Retorna o índice da palavra escolhida (0..n-1) ou -1 se n <= 0.
 */
int selecionar_palavra_por_nivel(char palavras_file[MAX_PALAVRAS][MAX_PALAVRA_SIZE], int n, struct Estado_do_Jogo *estado) {
    if (n <= 0) return -1;

    int nivel = estado->dificuldade_atual;
    int nivel_idx_i = nivel * MAX_PALAVRAS_NIVEL; /* índice inicial (inclusivo) */
    int pick = 0;

    if (nivel_idx_i >= n) {
        // fallback: escolher qualquer palavra disponível
        pick = rand() % n;
    } else {
        int available = n - nivel_idx_i;
        int choice_range = (available >= MAX_PALAVRAS_NIVEL) ? MAX_PALAVRAS_NIVEL : available;
        pick = nivel_idx_i + (rand() % choice_range);
    }

    // Tentar evitar repetir a palavra anterior quando houver alternativas
    if (n > 1 && estado->palavra_atual[0] != '\0') {
        int attempts = 0;
        while (strcmp(estado->palavra_atual, palavras_file[pick]) == 0 && attempts < 10) {
            if (nivel_idx_i >= n) {
                pick = rand() % n;
            } else {
                int available = n - nivel_idx_i;
                int choice_range = (available >= MAX_PALAVRAS_NIVEL) ? MAX_PALAVRAS_NIVEL : available;
                pick = nivel_idx_i + (rand() % choice_range);
            }
            attempts++;
        }
    }

    // Guardar palavra escolhida no estado
    strncpy(estado->palavra_atual, palavras_file[pick], MAX_PALAVRA_SIZE - 1);
    estado->palavra_atual[MAX_PALAVRA_SIZE - 1] = '\0';

    return pick;
} // fim selecionar_palavra_por_nivel



/*
 * Recebe a "palavra" e executa um ciclo de jogo
 * com desenho ASCII da forca, leitura de letras e verificação de vitória/derrota.
 */
void desenharForca(int erros) {
    printf("\n");
    printf("   ______\n");
    printf("   |    |\n");
    printf("   |    %c\n",    (erros >= 1) ? 'O' : ' ');
    printf("   |   %c%c%c\n", (erros >= 3) ? '/' : ' ', (erros >= 2) ? '|' : ' ', (erros >= 4) ? '\\' : ' ');
    printf("   |   %c %c\n",  (erros >= 5) ? '/' : ' ', (erros >= 6) ? '\\' : ' ' );
    printf("   |\n");
    printf("___|___\n\n");
} // fim desenharForca



// Exibe a palavra com letras descobertas e underscores para letras não descobertas
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
} // fim exibirPalavra



// Exibe as letras já tentadas pelo jogador
void exibirTentativas(const char* tentadas, int numTentadas) {
    if (numTentadas > 0) {
        printf("Letras tentadas: ");
        for (int i = 0; i < numTentadas; i++) {
            printf("%c ", tentadas[i]);
        }
        printf("\n");
    }
} // fim exibirTentativas



// Verifica se a letra já foi tentada
int letraJaTentada(char letra, const char* tentadas, int numTentadas) {
    for (int i = 0; i < numTentadas; i++) {
        if (tentadas[i] == letra) return 1;
    }
    return 0;
} // fim letraJaTentada



// Limpa o buffer de entrada para evitar problemas com scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
} // fim limparBufferEntrada



// Verifica se a palavra foi completamente descoberta
int palavraCompleta(const char* descobertas, int tamanho) {
    for (int i = 0; i < tamanho; i++) if (!descobertas[i]) return 0;
    return 1;
} // fim palavraCompleta



// Função principal para iniciar o jogo da forca.
void jogar(const char *palavra) {

    if (!palavra || palavra[0] == '\0') {
        printf("Nenhuma palavra definida para jogar.\n");
        return;
    }

    int tamanhoPalavra = (int)strlen(palavra);
    char descobertas[MAX_PALAVRA_SIZE] = {0};
    char tentadas[26] = {0};
    int numTentadas = 0;
    int erros = 0;

    // Limpar o ecrã antes de iniciar o jogo
    cleanScreen();

    while (erros < MAX_TENTATIVAS && !palavraCompleta(descobertas, tamanhoPalavra)) {

        
        cleanScreen();
        
        int box_width = 40;
        const char *titulo_jogo = "BEM-VINDO AO JOGO DA FORCA!";
        printf("\n");
        printf("╔"); fillCharLine("═", box_width - 2); printf("╗\n");
        printf("║ %s", titulo_jogo);
        int titulo_length = (int)strlen(titulo_jogo);
        fillCharLine(" ", box_width - titulo_length - 3);
        printf("║\n");
        printf("╠"); fillCharLine("═", box_width - 2); printf("╣\n");
        char buf[64];
        int l = snprintf(buf, sizeof(buf), "Voce tem %d tentativas!", MAX_TENTATIVAS);
        printf("║ %s", buf);
        fillCharLine(" ", box_width - l - 3);
        printf("║\n");
        printf("╚"); fillCharLine("═", box_width - 2); printf("╝\n");
        printf("\n");
        desenharForca(erros);
        exibirPalavra(palavra, descobertas);
        exibirTentativas(tentadas, numTentadas);
        printf("\nTentativas restantes: %d\n", MAX_TENTATIVAS - erros);

        char letra;
        printf("\nDigite uma letra: ");
        if (scanf(" %c", &letra) != 1) {
            limparBufferEntrada();
            continue;
        }
        limparBufferEntrada();

        letra = (char) toupper((unsigned char)letra);
        if (!isalpha((unsigned char)letra)) {
            printf("\nPor favor, digite apenas letras!\n");
            continue;
        }

        if (letraJaTentada(letra, tentadas, numTentadas)) {
            printf("\nVoce ja tentou essa letra!\n");
            continue;
        }

        tentadas[numTentadas++] = letra;

        int acertou = 0;
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (palavra[i] == letra) { descobertas[i] = 1; acertou = 1; }
        }

        if (acertou) {
            printf("\nBoa! A letra '%c' esta na palavra!\n", letra);
        } else {
            erros++;
            printf("\nOps! A letra '%c' nao esta na palavra.\n", letra);
        }
    }

    // Resultado final: desenhar uma caixa com caracteres box-drawing (como drawMenu)
    int box_width = 40;
    printf("\n");
    if (palavraCompleta(descobertas, tamanhoPalavra)) {
        
        // Desenhar a forca final (vitoria)
        const char *title = "PARABENS! VOCE VENCEU!";
        char line1[128];
        char line2[128];
        snprintf(line1, sizeof(line1), "A palavra era: %s", palavra);
        snprintf(line2, sizeof(line2), "Voce conseguiu com %d erro(s)!", erros);

        printf("╔"); fillCharLine("═", box_width - 2); printf("╗\n");
        printf("║ %s", title);
        int tlen = (int)strlen(title);
        fillCharLine(" ", box_width - tlen - 3);
        printf("║\n");
        printf("╠"); fillCharLine("═", box_width - 2); printf("╣\n");

        printf("║ %s", line1);
        fillCharLine(" ", box_width - (int)strlen(line1) - 3);
        printf("║\n");

        printf("║ %s", line2);
        fillCharLine(" ", box_width - (int)strlen(line2) - 3);
        printf("║\n");

        printf("╚"); fillCharLine("═", box_width - 2); printf("╝\n");

    } else {

        // Mostrar a forca final antes da caixa para o utilizador ver o estado
        desenharForca(erros);
        const char *title = "GAME OVER!";
        char line1[128];
        char line2[128];
        snprintf(line1, sizeof(line1), "A palavra era: %s", palavra);
        snprintf(line2, sizeof(line2), "Mais sorte na proxima vez!");

        printf("╔"); fillCharLine("═", box_width - 2); printf("╗\n");
        printf("║ %s", title);
        int tlen = (int)strlen(title);
        fillCharLine(" ", box_width - tlen - 3);
        printf("║\n");
        printf("╠"); fillCharLine("═", box_width - 2); printf("╣\n");

        printf("║ %s", line1);
        fillCharLine(" ", box_width - (int)strlen(line1) - 3);
        printf("║\n");

        printf("║ %s", line2);
        fillCharLine(" ", box_width - (int)strlen(line2) - 3);
        printf("║\n");

        printf("╚"); fillCharLine("═", box_width - 2); printf("╝\n");
        
    }
} // fim jogar
