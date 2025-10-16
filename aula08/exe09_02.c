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
    
    int numero_i = 0, numero;
    int contador_de_pares = 0, contador_de_impares = 0;

    while (numero_i < 10) {
        printf("Insira o número %d: ", numero_i + 1);
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            contador_de_pares++;
        } else {
            contador_de_impares++;
        }
        numero_i++;
    }

    printf("\nContagem final:\n");
    printf("Números pares: %d\n", contador_de_pares);
    printf("Números ímpares: %d\n", contador_de_impares);

    return 0;
}