#include <stdio.h>
#include <stdlib.h> // Para system("cls") ou system("clear")
#include <string.h>

struct Menu {
    int menu_width;
    int opcoes_length;
    char titulo[50];
    char opcoes_key[10][2];
    char opcoes_labels[10][50];
    int escolha_feita;
} Menu;


void cleanScreen();
void fillCharLine(const char* str, int count);
void drawMenu(struct Menu menu);
int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);
int ler_opcoes_do_menu(struct Menu menu, const char* mensagem);



int main(){

    struct Menu menuPrincipal = {
        35, // menu_width (aumentado para caber as opções)
        3,  // opcoes_length
        "Menu Principal - Jogo da Forca", 
        {"1", "2", "0"},
        {"Iniciar Jogo", "Configurar Jogo", "Sair"},
        0 // escolha_feita
    }; 
    enum MenuPrincipal { INICIAR_JOGO = 1, CONFIGURAR_JOGO, SAIR };
    int escolha;

    cleanScreen();
    drawMenu(menuPrincipal);
    menuPrincipal.escolha_feita = ler_inteiro_no_intervalo(0, 2, "Escolha uma opção: ");
    
    switch (menuPrincipal.escolha_feita) {
        case INICIAR_JOGO:
            printf("Iniciando o jogo...\n");
            break;
        case CONFIGURAR_JOGO:
            printf("Configurando o jogo...\n");
            break;
        case SAIR:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    

    return 0;
}


void cleanScreen() {
    // Limpa a tela do console
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
} // fim cleanScreen

void fillCharLine(const char* str, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s", str);
    }
}

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
