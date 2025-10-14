/*
2- Calculadora Simples
Peça ao utilizador dois números e uma operação (+, -, *, /).
Mostre o resultado da operação escolhida.
Exemplo:
• Entrada: 5 2 +
• Saída: Resultado: 7
*/

#include <stdio.h>

int main() {
    float num1, num2, resultado;
    char operacao;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao);

    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Erro: Divisão por zero não é permitida.\n");
                return 1;
            }
            break;
        default:
            printf("Operação inválida.\n");
            return 1;
    }

    printf("Resultado: %.2f\n", resultado);
    return 0;
}