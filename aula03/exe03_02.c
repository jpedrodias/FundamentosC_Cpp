/*
2.	Escrever todos os nºs entre 1 e 20, de forma decrescente
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    for(int i = 20; i >= 1; i--){
        printf("%d\n", i);
    }
    return 0;
}