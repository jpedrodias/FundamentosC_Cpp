/*
1- Desenvolva um programa que permita determinar se tem idade para a reforma:
a. Idade >= 67 --- idade para a reforma.
*/

#include <stdio.h>
#include <stdbool.h> // incluído para usar o tipo bool
#include <locale.h> // incluido para suportar acentuação

// Definições dos parâmetros do programa
#define _IDADE_REFORMA 67
#define _IDADE_MIN 0
#define _IDADE_MAX 120

int main() {
    setlocale(LC_ALL, "Portuguese"); // incluido em locale.h para suportar acentuação


    int idade;
    bool idadeValida = false;

    do {
        
        printf("Qual a sua idade? \n");
        scanf("%i", &idade);

        idadeValida = (idade >= _IDADE_MIN && idade <= _IDADE_MAX);
        if (!idadeValida) {
            printf("Idade inválida. Por favor, insira uma idade entre 0 e 120.\n");
        }

    } while (!idadeValida);

    if (idade >= _IDADE_REFORMA) {
        printf("Tem idade para se reformar.\n");
    }
    else {
        printf("Não tem idade para a reforma.\n");
    }
    return 0;
}
