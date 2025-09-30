/*
2- Crie um programa para ler 3 notas e mostrar a média das mesmas
*/
// gcc -o myapp aula04.c
// ./myapp

#include <stdio.h>

int main() {
    int nota; // valor lido do teclado
    int soma = 0, media; // a média será a soma a dividir por n
    int numeroNotas = 3;

    int i = 0;
    while (i < numeroNotas) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%d", &nota);
        soma += nota;
        i++;
    }
    media = soma / numeroNotas;
    printf("A média das notas é: %d\n", media);

    return 0;
}