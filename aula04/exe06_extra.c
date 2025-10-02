#include <stdio.h>
#include <stdbool.h>


/*
Inicialize o total a zero.
Peça ao utilizador para introduzir 5 números inteiros; 
Some os números positivos ao total e conte quantos valores negativos foram introduzidos; 
Mostre o total e a contagem;
O número deve estar entre -100 e 100 e não pode ser zero;
Não usar instruções if. 
*/

int main() {
   
    int number;             // to store user input
    int total = 0;          // to accumulate the sum of positive numbers
    int negativeCount = 0;  // to count negative numbers
    int count = 0;          // to count the number of inputs
    bool isPositive;        // to check if the number is positive
    bool isNegative;        // to check if the number is negative
    bool isValidInput;      // check if the input is valid

    while (count < 5) {

        isValidInput = false;
        while (!isValidInput) {
            printf("Enter an integer number between -100 and 100: ");
            scanf("%d", &number);
            isValidInput = (number >= -100 && number <= 100 && number != 0);
        }

        isPositive = (number > 0);
        isNegative = (number < 0);

        while (isPositive) {
            total += number;
            isPositive = false; // exit this inner loop
        }
        
        while (isNegative) {
            negativeCount++;
            isNegative = false; // exit this inner loop
        }
        count++;
    }

    printf("Total of positive numbers: %d\n", total);
    printf("Count of negative numbers: %d\n", negativeCount);

    return 0;
}