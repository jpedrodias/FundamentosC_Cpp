#include <stdio.h>

/*
2-	Desenvolva um programa que permita fazer um incremento de 3 valores ao valor apresentado pelo utilizador.
*/

int main() {
    int valor;

    printf("Digite um valor: ");
    scanf("%d", &valor);

    valor += 3; // alternativa a valor = valor + 3

    printf("Valor incrementado: %d\n", valor);

    return 0;
}