/*
Exercício 2 – Troca de valores usando ponteiros
Objetivo: Aprender a usar ponteiros em funções para modificar variáveis externas.
1. Cria uma função chamada troca que receba dois ponteiros para inteiro (int *x e int *y). 
2. Dentro da função, troca os valores das variáveis apontadas pelos ponteiros. 
3. No main, declara duas variáveis inteiras a e b com valores diferentes. 
4. Chama a função troca(&a, &b) e mostra os valores antes e depois da troca.
*/

#include <stdio.h>

void troca(int *x, int *y);


int main() {
    int a = 5;
    int b = 10;

    printf("Antes da troca:\n");
    printf("\tNo endereço de \"a\": %p, está armazenado o valor: %d\n", &a, a);
    printf("\tNo endereço de \"b\": %p, está armazenado o valor: %d\n", &b, b);

    troca(&a, &b);

    printf("Depois da troca:\n");
    printf("\tNo endereço de \"a\": %p, está armazenado o valor: %d\n", &a, a);
    printf("\tNo endereço de \"b\": %p, está armazenado o valor: %d\n", &b, b);


    printf("Endereços das funções:\n");
    printf("A função \"troca\" está localizada no endereço: %p\n", &troca);
    printf("A função \"main\" está localizada no endereço: %p\n", &main);
    return 0;
}


void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
