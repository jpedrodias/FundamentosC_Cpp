/*
Exercício 4:
Escrever um programa que declare um vetor de 20 inteiros, leia um valor para cada posição e 
no final mostre quantos elementos possuem valor maior, menor e igual ao primeiro elemento do vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define valor_minimo 0
#define valor_maximo 10

int main() {
    srand(time(NULL));

    int vetor[20];
    int value_de_referencia;

    int i, maior = 0, menor = 0, igual = 0;

    // INPUTS » Lazy Mode: valores aleatórios
    for (i = 0; i < 20; i++) {
        // printf("Digite o valor para a posição %d: ", i);
        // scanf("%d", &vetor[i]);
        vetor[i] = rand() % (valor_maximo - valor_minimo + 1) + valor_minimo;
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    // PROCESSAMENTO
    value_de_referencia = vetor[0];
    for (i = 1; i < 20; i++) {
        if (vetor[i] > value_de_referencia) {
            maior++;
        } else if (vetor[i] < value_de_referencia) {
            menor++;
        } else {
            igual++;
        }
    }

    // OUTPUT
    printf("Elementos maiores que o primeiro: %d\n", maior);
    printf("Elementos menores que o primeiro: %d\n", menor);
    printf("Elementos iguais ao primeiro: %d\n", igual);

    return 0;
}
