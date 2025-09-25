/*
3.	Escrever todos os nºs entre 10 e 100 de 10 em 10.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    for(int i = 10; i <= 100; i += 10){
        printf("%d\n", i);
    }

    return 0;
}