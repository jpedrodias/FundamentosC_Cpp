#include <stdio.h>
#include <locale.h>

// gcc -o myapp aula04.c
// ./myapp


void exemplo_while(), exemplo_doWhile();


int main() {
    setlocale(LC_ALL, "Portuguese");

    exemplo_doWhile();

    return 0;
}


void exemplo_while() {

    printf("Exemplo de um ciclo while\n");

    int i = 10;
    while (i > 0) {
        printf("O valor de i: %d\n", i);
        i--;
    }

}


void exemplo_doWhile() {

    printf("Exemplo 2de um ciclo do while\n");

    int i = 10;
    do {
        printf("O valor de i: %d\n", i);
        i--;
    } while (i > 0);

} 