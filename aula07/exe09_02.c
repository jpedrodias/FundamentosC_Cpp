/*
Exercício 2 — Contagem e Classificação de Números
Peça ao utilizador 10 números inteiros (usando um ciclo while).
Durante a leitura, conte quantos são pares e quantos são ímpares (usando if).
No fim, mostre o total de cada tipo.
Exemplo:
Insira um número: 7
Insira um número: 4
...
Números pares: 4
Números ímpares: 6
*/


#include <stdio.h>
#include <stdbool.h>

int main() {
    int count_number = 0, number;
    int count_par = 0, count_impar = 0;

    while (count_number < 10) {
        printf("Insira o número %d: ", count_number + 1);
        scanf("%d", &number);

        if (number % 2 == 0) {
            count_par++;
        } else {
            count_impar++;
        }
        count_number++;
    }

    printf("\nContagem final:\n");
    printf("Números pares: %d\n", count_par);
    printf("Números ímpares: %d\n", count_impar);

    return 0;
}