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
#define TAMANHO_DO_HISTÓRICO 5 // tamanho do histórico de operações

int faz_menu();
int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {


    // Gestão do histórico -para gestão do historico mas com limites de n movimentos
    char labels[][10] = {
        "Depósito",
        "Levanta."
    };

    const int CODIDO_OPERACAO_DEPOSITO = 0;
    const int CODIDO_OPERACAO_LEVANTAMENTO = 1;
    
    int historico_texto[TAMANHO_DO_HISTÓRICO]; // 0 ou 1 para os tipos de movimento
    float historico_valor_do_movimento[TAMANHO_DO_HISTÓRICO] = {0.0};
    float historico_valor_do_saldo[TAMANHO_DO_HISTÓRICO] = {0.0};
    int historico_movimentos = -1; // total de movimentos realizados
    int historico_index = -1;      // para usar como índice do histórico (módulo de TAMANHO_DO_HISTÓRICO)
    // Fim da Gestão do histórico

    float saldo = 0.0; // saldo do cliente
    float valor = 0.0; // valor da transação

    int choice; // para o menu
    do {

        choice = faz_menu();     
        
        switch (choice) {
            case 1: { 
                valor = ler_inteiro_no_intervalo(1, 10000, "Insira o valor a depositar: ");
                saldo += valor;

                // GESTÃO DO HISTÓRICO
                historico_movimentos++;
                historico_index = historico_movimentos % TAMANHO_DO_HISTÓRICO;

                historico_texto[historico_index] = CODIDO_OPERACAO_DEPOSITO; // 0 para depósito » 1 será para levantamento
                historico_valor_do_movimento[historico_index] = valor;
                historico_valor_do_saldo[historico_index] = saldo;

                break;
            }

            case 2: { 
                valor = ler_inteiro_no_intervalo(1, 10000, "Insira o valor a levantar: ");
                if (valor > saldo) {
                    printf("Saldo insuficiente. Operação cancelada.\n");
                    break;
                }
                saldo -= valor;
                
                // GESTÃO DO HISTÓRICO
                historico_movimentos++;
                historico_index = historico_movimentos % TAMANHO_DO_HISTÓRICO;

                historico_texto[historico_index] = CODIDO_OPERACAO_LEVANTAMENTO; // 0 para depósito » 1 será para levantamento
                historico_valor_do_movimento[historico_index] = -valor;
                historico_valor_do_saldo[historico_index] = saldo;

                break;
            }

            case 3: { 
                printf("Saldo atual: %.2f\n", saldo);

                break;
            }
            
            case 4: { 
                printf("Histórico de operações:\n");

                // calcular número de entradas válidas
                int count = (historico_movimentos >= 0) ? (historico_movimentos + 1) : 0;
                if (count > TAMANHO_DO_HISTÓRICO) {count = TAMANHO_DO_HISTÓRICO;}

                if (count == 0) {
                    printf("Sem operações no histórico.\n");
                    
                    break;
                }

                // índice da entrada mais antiga
                int start;
                if (count < TAMANHO_DO_HISTÓRICO) {
                    start = 0; // ainda não encheu o buffer, começa em 0
                } else {
                    // encheu/rodou o buffer: a entrada mais antiga é a seguinte ao último inserido
                    start = (historico_movimentos + 1) % TAMANHO_DO_HISTÓRICO;
                }

                for (int j = 0; j < count; j++) {
                    int idx = (start + j) % TAMANHO_DO_HISTÓRICO;
                    printf("%2d - %s: %8.2f€ | Saldo atual: %8.2f€\n",
                        j + 1,
                        labels[historico_texto[idx]],
                        historico_valor_do_movimento[idx],
                        historico_valor_do_saldo[idx]
                    );
                }
                break;
            }

            case 0: break;
            default: printf("Opção inválida. Tente novamente.\n"); 
        }

    } while (choice != 0);

    return 0;
}

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

}