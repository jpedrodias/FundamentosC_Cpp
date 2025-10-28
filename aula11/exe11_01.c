/*
Exercício 1
Cria uma função maior() que recebe dois números e devolve o maior.
*/

#include <stdio.h>

int qual_maior(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}


int main() {
    int numero_1, numero_2;

    printf("Digite o valor de a: ");
    scanf("%d", &numero_1);

    printf("Digite o valor de b: ");
    scanf("%d", &numero_2);

    int maior = qual_maior(numero_1, numero_2);

    printf("O maior número é: %d\n", maior);

    return 0;
}