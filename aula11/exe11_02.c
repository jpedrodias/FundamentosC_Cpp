/*
Exercício 2:
Cria uma função media3() que calcula a média de três notas.
*/

#include <stdio.h>

float calc_media(float notas[], int size) {
    float soma = 0;
    for (int i = 0; i < size; i++) {
        soma += *(notas + i);
    }
    return soma / size;
}

int main() {
    float notas[3] = {0};
    int size = sizeof(notas) / sizeof(notas[0]);

    for (int i = 0; i < size; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    float media = calc_media(notas, size);
    printf("A média das notas é: %.2f\n", media);

    return 0;
}   