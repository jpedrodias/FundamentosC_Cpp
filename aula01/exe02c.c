#include <stdio.h>

/*
3-	Desenvolva um programa que permita converter o valor de KM apresentado pelo utilizador nos metros correspondentes.
*/
int main() {
    float km, metros;

    printf("Digite a distância em KM: ");
    scanf("%f", &km);

    metros = km * 1000;

    printf("A distância em metros é: %.0f metros\n", metros);

    return 0;
}