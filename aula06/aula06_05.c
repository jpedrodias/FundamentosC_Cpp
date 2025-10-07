/*
5-	Escreva um programa que solicite o valor de uma compra e aplique os seguintes descontos:
•	Se o valor for superior a 100 euros, aplicar um desconto de 10%.
•	Se o valor for menor ou igual a 100 euros, aplicar um desconto de 5%.
•	Mostrar o valor final a pagar.
*/

#include <stdio.h>


int main() {
    double desconto = 0.05;  // Desconto padrão de 5%

    double valorCompra, valorFinal;

    printf("Insira o valor da compra: ");
    scanf("%lf", &valorCompra);

    if (valorCompra > 100.0) {
        desconto = 0.10;  // Atualiza desconto para 10%
    }
    valorFinal = valorCompra * (1 - desconto);
   
    printf("Valor final a pagar: %.2f euros\n", valorFinal);

    return 0;
}