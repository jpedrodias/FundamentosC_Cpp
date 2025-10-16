/*
4- Escreva um programa que peça ao utilizador para introduzir um número e verifique se ele é positivo, negativo ou zero.
*/

#include <stdio.h>

int main() {
    int numero;

    printf("Introduza um número: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("O número é positivo.\n");
    } else if (numero < 0) {
        printf("O número é negativo.\n");
    } else {
        printf("O número é zero.\n");
    }

    return 0;
}