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
int main() {
    int choice;
    float number, result;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Dobrar um número\n");
        printf("2 - Triplicar um número\n");
        printf("3 - Calcular o quadrado de um número\n");
        printf("0 - Sair\n");
        printf("================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Insira um número para dobrar: ");
                scanf("%f", &number);
                result = number * 2;
                printf("Resultado: %.2f\n", result);
                break;
            case 2:
                printf("Insira um número para triplicar: ");
                scanf("%f", &number);
                result = number * 3;
                printf("Resultado: %.2f\n", result);
                break;
            case 3:
                printf("Insira um número para calcular o quadrado: ");
                scanf("%f", &number);
                result = number * number;
                printf("Resultado: %.2f\n", result);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 0);

    return 0;
}