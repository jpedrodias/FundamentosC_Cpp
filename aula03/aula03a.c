#include <stdio.h>
#include <locale.h>

/*
Escreve um programa de mostre os primeiro 20 números naturais.
int main(){
    setlocale(LC_ALL, "Portuguese");

    for(int i = 1; i <= 20; i++){
        printf("%d\n", i);
    }
    return 0;
}
*/

/*
Escrever todos os números entre 10 e 100 de 10 em 10
int main(){
    setlocale(LC_ALL, "Portuguese");

    for(int i = 10; i <= 100; i += 10){
        printf("%d\n", i);
    }
    return 0;
}
*/

/*
Calcula a média das idade de 5 pessoas
*/
int main(){
    setlocale(LC_ALL, "Portuguese");

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
