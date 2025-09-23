# include <stdio.h>

int main() {
    
    int num1, num2, add;

    printf("Insira o primeiro algarismo: \n");
    scanf("%i", &num1);

    printf("Insira o segundo algarismo: \n");
    scanf("%i", &num2);

    // calcular a adição
    add = num1 + num2;
    printf("O resultado da adição de %i e %i é: %i\n", num1, num2, add);

    return 0;
}