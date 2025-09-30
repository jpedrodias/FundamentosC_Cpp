/*
5- Validação de entrada
Escreva um programa que peça ao utilizador um número inteiro positivo.
O programa deve continuar a pedir até que o utilizador insira um valor menor que 0.
*/

#include <stdio.h>
#include <stdbool.h>

#define _MIN_VALUE 0     // não gasta RAM
const int MIN_VALUE = 0; // gasta RAM

int main(){

    int numero;
    bool gameOver = false;

    do {
        
        printf("Digite um número inteiro positivo: ");
        scanf("%d", &numero);

        gameOver = (numero < MIN_VALUE);
        gameOver = (numero < _MIN_VALUE);

    } while (!gameOver);
    return 0;
}