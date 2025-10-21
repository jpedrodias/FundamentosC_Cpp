/*
Exercício 6 – Menu de Operações Matemáticas
(usar do...while + switch case)
Crie um programa com o seguinte menu:
===== MENU =====
1 - Dobrar um número
2 - Triplicar um número
3 - Calcular o quadrado de um número
0 - Sair
================
O utilizador escolhe uma opção e insere o número. O programa mostra o resultado. O menu
deve repetir até o utilizador escolher 0 - Sair. Se a opção for inválida, mostrar “Opção
inválida”.
*/
#include <stdio.h>
#define MAX_INT 65536 // 2^16 (bits)


float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    int escolha;
    float numero, resultado;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Dobrar um número\n");
        printf("2 - Triplicar um número\n");
        printf("3 - Calcular o quadrado de um número\n");
        printf("0 - Sair\n");
        printf("================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                numero = ler_numero_no_intervalo(-MAX_INT, MAX_INT, "Insira um número para dobrar: ");
                resultado = numero * 2;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 2:
                numero = ler_numero_no_intervalo(-MAX_INT, MAX_INT, "Insira um número para triplicar: ");
                resultado = numero * 3;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 3:
                numero = ler_numero_no_intervalo(-MAX_INT, MAX_INT, "Insira um número para calcular o quadrado: ");
                resultado = numero * numero;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}


float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem) {

    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        if (valor < minimo || valor > maximo) {
            printf("Valor inválido. O valor deve estar entre %d e %d.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
} // fim ler_numero_no_intervalo