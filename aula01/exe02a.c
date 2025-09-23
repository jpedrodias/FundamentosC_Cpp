#include <stdio.h>

/*
1-	Desenvolva um programa que permita fazer um incremento ao valor apresentado pelo utilizador.
*/

int main() {
    int valor;

    printf("Digite um valor: ");
    scanf("%d", &valor);

    valor++;

    printf("Valor incrementado: %d\n", valor);

    return 0;
}