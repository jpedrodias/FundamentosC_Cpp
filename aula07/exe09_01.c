/*
Exercício 1 — Analisador de Números Primos
Crie um programa que leia um número inteiro n e determine se é primo.
Depois, pergunte ao utilizador (usando switch case) o que deseja fazer:
1 - Verificar outro número
2 - Ver todos os números primos até n
0 - Sair
- Use for para testar se o número é primo (divisores).
- Use while ou do...while para manter o menu ativo.
- Use switch case para controlar as opções.
Exemplo:
Insira um número: 7
O número 7 é primo.
1 - Verificar outro número
2 - Ver todos os primos até n
0 - Sair
Opção: 2
2 3 5 7
*/

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}


void listPrimesUpTo(int n) {

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");

}


int main() {
    int choice, number;
    do {
        printf("Insira um número: ");
        scanf("%d", &number);

        if (isPrime(number)) {
            printf("O número %d é primo.\n", number);
        } else {
            printf("O número %d não é primo.\n", number);
        }

        // segunda parte - menu com opções usadas no switch case
        printf("1 - Verificar outro número\n");
        printf("2 - Ver todos os primos até %d\n", number);
        printf("0 - Sair\n");
        printf("Opção: ");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                continue;
            case 2:
                listPrimesUpTo(number);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (choice != 0);
    return 0;
}