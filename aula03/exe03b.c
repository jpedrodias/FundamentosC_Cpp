#include <stdio.h>
#include <locale.h>

/*
Escrever todos os números entre 10 e 100 de 10 em 10
*/
int main(){
    for(int i = 10; i <= 100; i += 10){
        printf("%d\n", i);
    }
    return 0;
}