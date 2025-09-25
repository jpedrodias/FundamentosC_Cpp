/*
8.	Triângulo de números
Construa um programa que, para n = 5, escreva:
1.	1
2.	12
3.	123
4.	1234
5.	12345

*/

#include <stdio.h>
#include <locale.h>

int main(){
    int linhas;

    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);

    for(int i = 1; i <= linhas; i++){
        printf("%d. ", i);
        for(int j = 1; j <= i; j++){
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
