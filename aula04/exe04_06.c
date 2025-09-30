/*
6 - Soma acumulada até zero

Faça um programa que leia números inteiros do utilizador e calcule a soma acumulada.
O ciclo só termina quando o utilizador digitar o número 0.
No fim, o programa deve mostrar a soma total.
*/

#include <stdio.h>

# define _ZERO 0     // não gasta RAM

int main(){
    
    int numero;   // a ser lido do ecra
    int soma = 0; // soma acumulada

    do {
        printf("Digite um número inteiro (0 para terminar): ");
        scanf("%d", &numero);

        soma += numero; // soma = soma + numero;

    } while (numero != _ZERO);

    printf("A soma total é: %d\n", soma);

    return 0;
}
