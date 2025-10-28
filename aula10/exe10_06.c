/*
Exercício 6:
Elabore um programa em que o utilizador insere N números para um vector.
O programa deverá imprimir o total de números pares inseridos. 
*/
#include <stdio.h>

int main() {
    int N, i, count = 0;

    printf("Quantos números deseja inserir? ");
    scanf("%d", &N);

    int numeros[N];

    for (i = 0; i < N; i++) {
        printf("Insira o número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        if (numeros[i] % 2 == 0) {
            count++;
        }
    }

    printf("Total de números pares inseridos: %d\n", count);

    return 0;
}