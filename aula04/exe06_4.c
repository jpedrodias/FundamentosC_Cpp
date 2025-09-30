/*
4. Relatório de Vendas
O utilizador indica o número de vendedores de uma loja.
Com um for, o programa recolhe as vendas de cada vendedor.
Um while garante que o valor das vendas é sempre positivo.
O programa pode repetir-se para diferentes lojas usando um do...while.
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int numeroVendedores, i;
    float vendas, totalVendas;
    char choice;
    bool isValid, alertUser;

    do {

        do {
            printf("Digite o número de vendedores na loja: ");
            scanf("%d", &numeroVendedores);

            isValid = (numeroVendedores > 0);
            alertUser = !isValid;
            while (alertUser) {
                printf("Número inválido. Por favor, insira um número positivo.\n");
                alertUser = false;
            }

        } while (!isValid); // Garantir que o número de vendedores é positivo

        totalVendas = 0.0;

        for (i = 0; i < numeroVendedores; i++) {
            // Validação das vendas usando while
            do {
                printf("Digite o valor das vendas do vendedor %d: ", i + 1);
                scanf("%f", &vendas);

                isValid = (vendas >= 0);
                alertUser = !isValid;
                while (alertUser) {
                    printf("Valor inválido. Por favor, insira um valor positivo.\n");
                    alertUser = false;
                }

            } while (!isValid); // Garantir que o valor das vendas é positivo ou zero (vendedor muito mau!)

            totalVendas += vendas;
        }

        printf("O total de vendas da loja é: %.2f\n", totalVendas);

        // Perguntar se o utilizador quer calcular o total de vendas de outra loja
        printf("Deseja calcular o total de vendas de outra loja? (s/n): ");
        scanf(" %c", &choice);

    } while (choice == 's' || choice == 'S');

    return 0;
}   