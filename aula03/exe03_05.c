/*
5.	Ler um valor inteiro (aceitar somente valores entre 1 e 10) e escrever a tabuada de 1 a 10 do valor lido.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int numero;

    printf("Digite um número para ver sua tabuada: ");
    scanf("%d", &numero);

    for(int i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
    return 0;
}