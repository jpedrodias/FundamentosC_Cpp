/*
Exercício 4:
Escrever um programa que declare um vetor de 20 inteiros, leia um valor para cada posição e 
no final mostre quantos elementos possuem valor maior, menor e igual ao primeiro elemento do vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define valor_minimo 1
#define valor_maximo 10

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));

    int vetor[20];
    int value_de_referencia;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int i, maior = 0, menor = 0, igual = 0;

    // INPUTS » Lazy Mode: valores aleatórios
    for (i = 0; i < tamanho; i++) {
        // printf("Digite o valor para a posição %d: ", i);
        // scanf("%d", &vetor[i]);
        vetor[i] = random_int(valor_minimo, valor_maximo);
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    // PROCESSAMENTO
    value_de_referencia = vetor[0];
    for (i = 1; i < tamanho; i++) {
        if (vetor[i] > value_de_referencia) {
            maior++;
        } else if (vetor[i] < value_de_referencia) {
            menor++;
        } else {
            igual++;
        }
    }

    // OUTPUT
    printf("Elementos maiores: %d\n", maior);
    printf("Elementos menores: %d\n", menor);
    printf("Elementos iguais:  %d\n", igual);

    return 0;
}
