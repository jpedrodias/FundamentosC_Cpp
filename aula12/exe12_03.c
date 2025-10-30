/*
Exercício 3 – Ponteiros e arrays
Objetivo: Praticar o acesso aos elementos de um vetor usando apenas ponteiros.
1. Declara um vetor de inteiros com 3 ou mais elementos.
2. Declara um ponteiro p que aponte para o primeiro elemento do vetor.
3. Usa apenas aritmética de ponteiros (*(p + i)) para mostrar cada elemento do vetor.
4. Experimenta modificar um elemento do vetor através do ponteiro e observa o resultado.
*/

#include <stdio.h>

int main(){
    // 1
    int vetor[] = {10, 20, 30};
    int size = sizeof(vetor) / sizeof(vetor[0]);

    // 2
    int *p = &vetor[0]; // Aponta para o primeiro elemento do vetor e não para o vetor

    // 3
    for (int i = 0; i < size; i++) {
        printf("Elemento %d: %d\n", i, *(p + i));
    }

    // 4
    *(p + 2) = 99;
    for (int i = 0; i < size; i++) {
        printf("Elemento %d: %d\n", i, *(p + i));
    }

    return 0;
}

