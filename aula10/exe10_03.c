/*
Exercício 3:
Escreva um programa que realize a leitura dos salários pagos a um indivíduo durante um ano. 
Em seguida deverá mostrar os valores mensais e o total anual.
*/
#include <stdio.h>

int main() {
    float salarios[12];
    float total_anual = 0.0;

    // Leitura dos salários mensais
    for (int i = 0; i < 12; i++) {
        printf("Digite o salário de %dº mês: ", i + 1);
        scanf("%f", &salarios[i]);
        total_anual += salarios[i];
    }

    // Exibição dos salários mensais
    printf("\nSalários mensais:\n");
    for (int i = 0; i < 12; i++) {
        printf("Mês %d: %.2f\n", i + 1, salarios[i]);
    }

    // Exibição do total anual
    printf("Total anual: %.2f\n", total_anual);

    return 0;
}