/*
Exercício 6 — Simulador de Caixa Automático
Implemente um programa que simule um caixa multibanco, permitindo:
===== MENU =====
1 - Depositar dinheiro
2 - Levantar dinheiro
3 - Consultar saldo
4 - Consultar histórico de operações
0 - Sair
================
Regras:
- O saldo inicial é 0.
- Use um do...while para manter o menu ativo.
- Use switch case para escolher a operação.
- Use if para validar levantamentos (não pode levantar mais do que o saldo).
- Guarde cada operação num contador ou array para o histórico.
Exemplo:
1 - Depositar dinheiro
Valor: 100
Saldo atual: 100
2 - Levantar dinheiro
Valor: 50
Saldo atual: 50
4 - Histórico:
Depósito: +100
Levantamento: -50
*/

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#define TAMANHO_DO_HISTÓRICO 5 // tamanho do histórico de operações

#define LIMITE_MÁXIMO_POR_MOVIMENTO 400 // limite máximo de movimento por transação
#define LIMITE_MÍNIMO_POR_MOVIMENTO 1   // limite mínimo de movimento por transação
#define SALDO_AUTORIZADO_INICIAL -10.0  // saldo autorizado inicial (a descoberto)


int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);

int faz_menu();
void mostrar_saldo(float saldo, float saldo_autorizado);
int ajustar_novo_saldo_autorizado(float saldo_atual, float saldo_autorizado_atual);

void pausa(void); // faz uma pausa até o utilizador premir Enter

int main() {
    setlocale(LC_ALL, "Portuguese"); // Definir a localidade para suportar caracteres especiais

    // Gestão do histórico -para gestão do historico mas com limites de n movimentos
    const char *historico_textos[] = {
        "Depósi.",
        "Levant.",
        "Saldo  ",
        "Histór."
    };
    
    // Gestão do histórico com um esquema de arrays paralelos
    int historico_texto[TAMANHO_DO_HISTÓRICO]; // 0 ou 1 para os tipos de movimento
    float historico_valor_do_movimento[TAMANHO_DO_HISTÓRICO] = {0.0};
    float historico_valor_do_saldo[TAMANHO_DO_HISTÓRICO] = {0.0};

    /* historico_movimentos passa a ser o total de movimentos já registados */
    int historico_movimentos = 0;  /* 0 = nenhum movimento ainda */
    int historico_index = -1;      /* último índice escrito (válido só se historico_movimentos>0) */

    float saldo_autorizado = SALDO_AUTORIZADO_INICIAL; // saldo autorizado é o valor mínimo que o cliente pode ter (a descoberto)
    float saldo = 0.0; // saldo do cliente
    float valor = 0.0; // valor da transação

    int choice; // para o menu
    do {

        choice = faz_menu();     
        
        switch (choice) {
            case 1: { 
                valor = ler_inteiro_no_intervalo(LIMITE_MÍNIMO_POR_MOVIMENTO, LIMITE_MÁXIMO_POR_MOVIMENTO * 100, "Insira o valor a depositar: ");
                saldo += valor;

                saldo_autorizado = ajustar_novo_saldo_autorizado(saldo, saldo_autorizado);

                // GESTÃO DO HISTÓRICO
                /* usar historico_movimentos como contador: escrever em index = total % tamanho, depois incrementar total */
                historico_index = historico_movimentos % TAMANHO_DO_HISTÓRICO;
                historico_valor_do_saldo[historico_index] = saldo;
                historico_valor_do_movimento[historico_index] = valor;
                historico_texto[historico_index] = choice - 1; /* 0 = depósito, 1 = levantamento */
                historico_movimentos++;
                // FIM DA GESTÃO DO HISTÓRICO

                mostrar_saldo(saldo, saldo_autorizado);
                pausa();
                break;
            }

            case 2: {
                valor = ler_inteiro_no_intervalo(LIMITE_MÍNIMO_POR_MOVIMENTO, LIMITE_MÁXIMO_POR_MOVIMENTO, "Insira o valor a levantar: ");
                if (saldo - valor < saldo_autorizado) {
                    printf("Saldo insuficiente. Operação cancelada.\n");
                    break; // sair do switch case
                }
                saldo -= valor;
                
                // GESTÃO DO HISTÓRICO
                historico_index = historico_movimentos % TAMANHO_DO_HISTÓRICO;
                historico_valor_do_saldo[historico_index] = saldo;
                historico_texto[historico_index] = choice - 1;    /* 1 = levantamento */
                historico_valor_do_movimento[historico_index] = -valor;
                historico_movimentos++;
                // FIM DA GESTÃO DO HISTÓRICO

                mostrar_saldo(saldo, saldo_autorizado);
                pausa();
                break;
            }

            case 3: { 
                mostrar_saldo(saldo, saldo_autorizado);
                pausa();
                break;
            }
            
            case 4: { 
                printf("Histórico de operações:\n");

                /* historico_movimentos é o total de movimentos registados */
                if (historico_movimentos == 0) {
                    printf("Sem operações no histórico.\n");
                    break;
                }

                /* número de entradas válidas (limitado pelo tamanho do buffer) */
                int entradas_validas = historico_movimentos;
                if (entradas_validas > TAMANHO_DO_HISTÓRICO) {
                    entradas_validas = TAMANHO_DO_HISTÓRICO;
                }

                /* índice da entrada mais antiga no buffer circular */
                int start_idx;
                if (entradas_validas < TAMANHO_DO_HISTÓRICO) {
                    start_idx = 0; /* buffer ainda não cheio */
                } else {
                    /* buffer cheio: a entrada mais antiga é a seguinte ao último escrito */
                    start_idx = (historico_index + 1) % TAMANHO_DO_HISTÓRICO;
                }

                /* índice da entrada mais recente (opcional, só para referência) */
                int end_idx = (start_idx + entradas_validas - 1) % TAMANHO_DO_HISTÓRICO;

                printf("╔══════════════════════════════════╦═══╗\n");
                printf("║ * EISnt Internacional Bank *     ║ € ║\n");
                printf("╠═══╦═════════╦═══════════╦════════╩═══╣\n");
                printf("║ # ║ Tipo    ║ Valor:    ║ Saldo:     ║\n");
                printf("╠═══╬═════════╬═══════════╬════════════╣\n");

                for (int j = 0; j < entradas_validas; j++) {
                    int idx = (start_idx + j) % TAMANHO_DO_HISTÓRICO;

                    int hist_tipo_i = historico_texto[idx];
                    const char *hist_tipo_str = historico_textos[hist_tipo_i];
                    
                    float hist_valor = historico_valor_do_movimento[idx];
                    float hist_saldo = historico_valor_do_saldo[idx];

                    printf("║%2d ║ %s ║ %8.2f€ ║ %9.2f€ ║\n",
                        j + 1,
                        hist_tipo_str,
                        hist_valor,
                        hist_saldo
                    );
                }
                printf("╚═══╩═════════╩═══════════╩════════════╝\n");
                pausa();
                break;
            }

            case 0: 
                break;
            default: 
                printf("Opção inválida. Tente novamente.\n"); 
        }

    } while (choice != 0);

    return 0;
} // fim main




void pausa(void) {
    /* Esta função foi criada usando ChatGPT"
        Pausa: só com scanf — espera pelo Enter do utilizador.
        Nota: isto não detecta uma tecla única sem Enter; scanf só fornece input após Enter. 
    */
    
    /* limpar eventual resto da linha (consome até ao '\n', se houver) */
    (void)scanf("%*[^\n]"); /* descarta caracteres até ao newline (se existirem) */
    (void)scanf("%*c");     /* consome o newline residual (se houver) */

    /* pedir ao utilizador para premir Enter e bloquear até isso acontecer */
    printf("Prima Enter para continuar...");
    fflush(stdout);

    (void)scanf("%*[^\n]"); /* descarta quaisquer caracteres antes do Enter inseridos agora */
    (void)scanf("%*c");     /* consome o '\n' do Enter */
} // fim pausa


int faz_menu() {
    int choice;
    do {
        printf("\n");
        printf("╔══════════════════════════════════╦═══╗\n");
        printf("║ * EISnt Internacional Bank *     ║ € ║\n");
        printf("╠══════════════════════════════════╩═══╣\n");
        printf("║ 1 - Depositar dinheiro               ║\n");
        printf("║ 2 - Levantar dinheiro                ║\n");
        printf("║ 3 - Consultar saldo                  ║\n");
        printf("║ 4 - Consultar histórico de operações ║\n");
        printf("║ 0 - Sair                             ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf("Opção: ");
        scanf("%d", &choice);
        if (choice < 0 || choice > 4) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice < 0 || choice > 4);
    return choice;
} // fim faz_menu


void mostrar_saldo(float saldo, float saldo_autorizado) {
    printf("\n");
    printf("Saldo atual: %.2f\n", saldo);
    printf("╔══════════════════════════════════╦═══╗\n");
    printf("║ * EISnt Internacional Bank *     ║ € ║\n");
    printf("╠══════════════════════════════════╩═══╣\n");
    printf("║                                      ║\n");
    printf("║ Saldo atual: %17.2f€      ║\n", saldo);
    printf("║                                      ║\n");

    if (saldo < 0) {
        printf("║      Atenção: Saldo negativo!        ║\n");
    } else {
        printf("║                                      ║\n");
    }

    printf("╠══════════════════════════════════════╣\n");
    printf("║ Saldo autorizado: %12.2f€      ║\n", saldo_autorizado);
    printf("╚══════════════════════════════════════╝\n");
} // fim mostrar_saldo


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


int ajustar_novo_saldo_autorizado(float saldo_atual, float saldo_autorizado_atual){
    /* Permite que o cliente tenha valores a descoberto.

    Ajusta o saldo autorizado com base no saldo máximo atingido.
    O saldo autorizado é 10% do saldo máximo atingido, arredondado para baixo em múltiplos de 10.
    
    O saldo autorizado só aumenta, nunca diminui.   
    
    Calcular 10% do saldo atual, arredondado para baixo ao múltiplo de 10:
       ex: 310 -> 10% = 31 -> arredondar para múltiplo de 10 inferior = 30 -> autorizado = -30
           400 -> 10% = 40 -> autorizado = -40
       Manter o saldo_autorizado atual se o novo for menos permissivo. */
    int percentual_dez_por_cento_em_mult10 = ((int)saldo_atual / 100) * 10;
    int novo_autorizado = -percentual_dez_por_cento_em_mult10;

    /* Se ainda não existe autorização (por exemplo valor 0) ou novo_autorizado for mais permissivo
       (numericamente menor, i.e., mais negativo), atualiza; caso contrário mantém o atual. */
    if (novo_autorizado < (int)saldo_autorizado_atual) {
        return novo_autorizado;
    }
    return (int)saldo_autorizado_atual;
} // fim ajustar_novo_saldo_autorizado