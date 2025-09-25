#include <stdio.h>
#include <locale.h>

/*
Apresenta a Tabuada de Multiplicação de um número qualquer
*/
int main(){       
    int numero;

    printf("Digite um número para ver sua tabuada: ");
    scanf("%d", &numero);

    for(int i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
    return 0;
}