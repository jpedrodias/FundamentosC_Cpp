#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// gcc -o myapp aula04.c -Wall -Wextra -Werror -std=c17
// ./myapp


void exemplo1(), exemplo2();


int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    if (argc < 2) {
        printf("Uso: ./myapp <número>\nEx.: ./myapp 1\n");
        return 1;
    }

    int opcao = atoi(argv[1]);  // Converte string para int

    switch (opcao) {
        case 1:
            exemplo1();
            break;
        case 2:
            exemplo2();
            break;
        default:
            printf("Default case\n");
    }
    
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