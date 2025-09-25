#include <stdio.h>
#include <locale.h>
/*
4-	Desenvolva um programa que permita converter o valor de segundos apresentado pelo utilizador nos minutos correspondentes.
*/

int main() {
    setlocale(LC_ALL, "Portuguese");

    int segundos, minutos, sobras;

    printf("Digite o valor em segundos: ");
    scanf("%d", &segundos);

    minutos = segundos / 60;
    sobras = segundos % 60;

    printf("O valor em minutos é: %d minutos\n", minutos);
    printf("Segundos restantes: %d segundos\n", sobras);

    return 0;
}