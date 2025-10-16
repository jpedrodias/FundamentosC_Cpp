/*
3 - Desenvolva um programa que solicite três números inteiros ao utilizador e utilize a estrutura if para determinar e exibir o maior deles.

*/

#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Insira o primeiro número: ");
    scanf("%d", &num1);
    printf("Insira o segundo número: ");
    scanf("%d", &num2);
    printf("Insira o terceiro número: ");
    scanf("%d", &num3);

    if (num1 > num2 && num1 > num3) {
        printf("O maior número é: %d\n", num1);
    } else if (num2 > num1 && num2 > num3) {
        printf("O maior número é: %d\n", num2);
    } else {
        printf("O maior número é: %d\n", num3);
    }

    return 0;
}