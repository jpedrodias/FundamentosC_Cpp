/*
Exercício 3 – Calculadora de Descontos
(usar switch case + if)
Crie um programa que peça o valor total de uma compra e mostre o seguinte menu:
===== MENU DE DESCONTOS =====
1 - Cliente regular (5%)
2 - Cliente fidelizado (10%)
3 - Promoção especial (15%)
0 - Sair
=============================
O utilizador escolhe a opção. O programa calcula e mostra o valor final a pagar, já com o
desconto. Se o valor for menor ou igual a 0, deve mostrar uma mensagem de erro. O
programa termina apenas quando o utilizador escolher 0 - Sair.
*/

// DÚVIDA: LOOP ENTRE os desscontos sem pedir NOVAMENTE o valor da compra?

#include <stdio.h>
#define MAX_INT 65536 // 2^16 (bits)


int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);

int main() {
    float valor_compra, valor_final;
    int escolha;

    printf("Introduza o valor total da compra: ");
    valor_compra = ler_inteiro_no_intervalo(-MAX_INT, MAX_INT, "Valor da compra: ");

    do {
        printf("\n===== MENU DE DESCONTOS =====\n");
        printf("1 - Cliente regular (5%%)\n");
        printf("2 - Cliente fidelizado (10%%)\n");
        printf("3 - Promoção especial (15%%)\n");
        printf("0 - Sair\n");
        printf("=============================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                valor_final = valor_compra * 0.95;
                break;
            case 2:
                valor_final = valor_compra * 0.90;
                break;
            case 3:
                valor_final = valor_compra * 0.85;
                break;
            case 0:
                printf("Saindo do programa.\n");
                continue;
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }

        if (valor_final <= 0) {
            printf("Erro: O valor final a pagar não pode ser menor ou igual a zero.\n");
        } else {
            printf("Valor final a pagar após desconto: %.2f\n", valor_final);
        }

    } while (escolha != 0);

    return 0;
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


