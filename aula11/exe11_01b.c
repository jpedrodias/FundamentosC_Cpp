/*
Exercício 1
Cria uma função maior() que recebe dois números e devolve o maior.
*/

#include <stdio.h>

int qual_o_maior(int *referencia_a, int *referencia_b) {
    if (*referencia_a > *referencia_b) {
        return *referencia_a;
    } else {
        return *referencia_b;
    }
}


int main() {
    int numero_1, numero_2;

    printf("Digite o valor de a: ");
    scanf("%d", &numero_1);

    printf("Digite o valor de b: ");
    scanf("%d", &numero_2);

    int maior = qual_o_maior(&numero_1, &numero_2);

    printf("O maior número é: %d\n", maior);

    return 0;
}