/*
2 - Desenvolva um programa que permita determinar se a nota é:
a. 0 a 4 -- fraco
b. 5 a 9 -- insuficiente
c. 10 a 14 -- satisfaz
d. 15 a 18 -- satisfaz bastante
e. 19 a 20 –  Excelente
*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    int nota;
    bool notaValida = false;

    while (!notaValida) {
        printf("Insira a nota (0-20): ");
        scanf("%d", &nota);

        notaValida = (nota >= 0 && nota <= 20);
        if (!notaValida) {
            printf("Nota inválida. Por favor, insira uma nota entre 0 e 20.\n");    
        }
    }  // fim do input e da validação da nota

    if (nota <= 4) {
        printf("Fraco\n");
    } else if (nota <= 9) {
        printf("Insuficiente\n");
    } else if (nota <= 14) {
        printf("Satisfaz\n");
    } else if (nota <= 18) {
        printf("Satisfaz bastante\n");
    } else {
        printf("Excelente\n");
    }

    return 0;
}