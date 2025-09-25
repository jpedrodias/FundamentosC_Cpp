/*
Escreve um programa de mostre os primeiro 20 números naturais.
*/

#include <stdio.h>
#include <locale.h>

/*
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
*/
int main(){
    setlocale(LC_ALL, "Portuguese");

    for(int i = 10; i <= 100; i += 10){
        printf("%d\n", i);
    }
    return 0;
}