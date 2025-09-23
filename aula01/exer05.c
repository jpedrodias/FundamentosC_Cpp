#include <stdio.h>

/*
Tabuada do número digitado sem utilizar ciclos...
*/

int main() {
    int numero, i;

    printf("Digite um número para ver sua tabuada: ");
    scanf("%d", &numero);

    printf("Tabuada do %d:\n", numero);
    i = 1;  printf("%d x %d = %d\n", numero, i, numero * i);
    i = 2;  printf("%d x %d = %d\n", numero, i, numero * i);
    i = 3;  printf("%d x %d = %d\n", numero, i, numero * i);
    i = 4;  printf("%d x %d = %d\n", numero, i, numero * i);
    i = 5;  printf("%d x %d = %d\n", numero, i, numero * i);
    i = 6;  printf("%d x %d = %d\n", numero, i, numero * i);
    i = 7;  printf("%d x %d = %d\n", numero, i, numero * i);
    i = 8;  printf("%d x %d = %d\n", numero, i, numero * i);
    i = 9;  printf("%d x %d = %d\n", numero, i, numero * i);
    i = 10; printf("%d x %d = %d\n", numero, i, numero * i);

    return 0;
}