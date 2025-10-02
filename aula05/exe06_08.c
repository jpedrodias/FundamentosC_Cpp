/* 
Exercício 8 — Jogo do Cronómetro
Enunciado:
Escreva um programa que simule um cronómetro que conta segundos até 10.
O utilizador pode a qualquer momento introduzir o número 0 para parar o cronómetro.
Use um for para contar de 1 até 10.
Use um while dentro do for para perguntar se o utilizador quer continuar a contagem ou parar.
*/


#include <stdio.h>
#include <stdbool.h>


int main(){
    int segundos;
    char userInput;
    bool sair;

    sair = false;
    for (segundos = 1; segundos <= 10 && !sair; segundos++) {
        printf("%d\n", segundos);

        userInput = '?';
        while (userInput=='?') {
            printf("Quer parar o cronómetro? (S) ");
            scanf(" %c", &userInput);
        }
        sair = (userInput == 's' || userInput == 'S');
    }

    sair = false;
    while (!sair) {
        printf("Cronómetro parado pelo utilizador aos %d segundos.\n", segundos - 1);
        sair = true;
    }

    sair = false;
    while (!sair) {
        printf("Cronómetro chegou a 10 segundos.\n");
        sair = true;    
    }

    return 0;
}