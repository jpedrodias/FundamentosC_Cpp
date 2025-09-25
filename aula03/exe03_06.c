/*
6.	Leia várias idades e calcule a média entre as idades (usar uma variável para idade).
*/

#include <stdio.h>
#include <locale.h>


int main(){
    int numero_pessoas;
    int idade, soma= 0;
    float media;

    printf("Digite número de alunos: ");
    scanf("%d", &numero_pessoas);

    for(int i = 1; i <= numero_pessoas; i++){
        printf("Digite a idade da %dª pessoa: ", i);
        scanf("%d", &idade);
        soma += idade;
    }
    media = (float)soma / numero_pessoas;
    printf("A média das idades é: %.2f\n", media);
    return 0;
}