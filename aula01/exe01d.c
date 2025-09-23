#include <stdio.h>

/*
Desenvolva um programa para converter Euros para Dólares.
*/

int main() {
    const float COTACAO_EURO_DOLAR = 1.18; // Exemplo de cotação

    float euros, dolares;

    // solicitar ao usuário o valor em euros
    printf("Digite o valor em Euros: ");
    scanf("%f", &euros);    

    // converter euros para dólares
    dolares = euros * COTACAO_EURO_DOLAR;

    // exibir o resultado
    printf("%.2f Euros correspondem a %.2f Dólares.\n", euros, dolares);

    return 0;
}