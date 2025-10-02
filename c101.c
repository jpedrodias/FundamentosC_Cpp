#include <stdio.h>
#include <stdbool.h>

/* Extra
Initialize total to zero.
Ask the user to enter 5 integer numbers, add the positive numbers to the total and
count how many negative values were entered.
Output the total and the count value.
YOU ARE NOT ALLOWED TO USE ARRAYS or IFS.
The number must be between -100 and 100 and not equal to zero.
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