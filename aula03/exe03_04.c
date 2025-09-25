/*
4.	Escrever um programa para exibir os números de 1 até 50 na tela.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    for(int i = 1; i <= 50; i++){
        printf("%d\n", i);
    }
    return 0;
}