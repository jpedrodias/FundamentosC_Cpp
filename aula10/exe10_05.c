/*
Exercício 5:
Dada uma sequência de n números, imprima-a na ordem inversa à da
leitura.
*/

#include <stdio.h>

int main() {
    int n, i;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    int vetor[n];

    // Leitura dos elementos
    for (i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Impressão dos elementos na ordem inversa
    printf("Elementos na ordem inversa:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d\n", vetor[i]);
    }

    return 0;
}