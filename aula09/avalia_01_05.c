/*
Exercício 5 – Soma até atingir limite
(usar do...while + if)
Escreva um programa que vá pedindo números ao utilizador até que a soma total ultrapasse
100. Quando isso acontecer, o programa mostra:
- O total da soma.
- Quantos números foram introduzidos.
*/

#include <stdio.h>

int main() {
    int num, total = 0, count = 0;

    do {
        printf("Introduza um número: ");
        scanf("%d", &num);
        total += num;
        count++;
    } while (total <= 100);

    printf("Total da soma: %d\n", total);
    printf("Quantidade de números introduzidos: %d\n", count);

    return 0;
}