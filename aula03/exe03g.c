#include <stdio.h>
#include <locale.h>

/*
O utilizador ao inserir o número de linhas que quer, desenhando um triângulo
*/
int main(){
    int linhas;

    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);

    for(int i = 1; i <= linhas; i++){
        printf("%d ", i);
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
