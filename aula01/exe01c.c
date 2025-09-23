#include <stdio.h>

/*
3- Desenvolva um programa que permita converter os dias inseridos em anos.
*/


int main() {
    int dias, anos, sobras;
    
    // solicitar ao usuário o número de dias
    printf("Digite o número de dias: ");
    scanf("%i", &dias);
    
    // calcular o número de anos sem considerar anos bissextos
    anos = dias / 365;
    sobras = dias % 365;

    // exibir o resultado
    printf("%i dias correspondem a %i anos.\n", dias, anos);
    printf("Restam %i dias que não completam um ano.\n", sobras);
    
    
    return 0;
}

