#include <stdio.h>

/*
Desenvolva um programa que permita converter os dias inseridos em anos.
*/


int main() {
    int dias, anos;
    
    // solicitar ao usuário o número de dias
    printf("Digite o número de dias: ");
    scanf("%i", &dias);
    
    // calcular o número de anos
    anos = dias / 365;
    
    // exibir o resultado
    printf("%i dias correspondem a %i anos.\n", dias, anos);
    
    return 0;
}

