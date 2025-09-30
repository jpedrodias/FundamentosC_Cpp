/*
1- Crie um programa que imprima 11 vezes a frase " Hello World!" utilizando uma estrutura de repetição while.
*/

#include <stdio.h>

int main() {
    int count = 0;

    while (count < 11) {
        printf("%d Hello World!\n", count+1);
        count++;
    }

    return 0;
}