#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// gcc -o myapp aula04.c -Wall -Wextra -Werror -std=c17
// ./myapp


void exemplo1(), exemplo2();


int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    exemplo1();
    
    return 0;
}

void exemplo1(){

    printf("Exemplo de um ciclo while\n");

    int i = 10;
    while (i > 0) {
        printf("O valor de i: %d\n", i);
        i--;
    }

}


void exemplo2(){

    printf("Exemplo de um ciclo do while\n");

    int i = 0;
    do {
        printf("Contagem: %d\n", i);
        i++;
    } while (i < 5);

}