/*
Exercício 3:
Cria uma função parOuImpar() que recebe um número e diz se é par.
*/
#include <stdio.h>

void parOuImpar(int *numero) {
    // o "*numero" é a referencia ao valor apontado por 'numero'
    char *resultado = (*numero % 2 == 0) ? "par" : "ímpar";
    printf("O número %d é %s.\n", *numero, resultado);
}

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    parOuImpar(&numero); // Passa o endereço de 'numero' em vez do número

    return 0;
}
