/*
Exercício 1 – Acesso indireto a uma variável
Objetivo: Compreender como um ponteiro pode ser usado para alterar o valor de uma variável.
Enunciado:
Declara uma variável inteira chamada a e inicializa-a com um valor qualquer.
Declara um ponteiro para inteiro chamado p.
Faz com que p aponte para a (ou seja, guarda o endereço de a em p).
Utiliza o ponteiro p para alterar o valor de a sem aceder diretamente à variável.
Mostra na consola o valor de a antes e depois da alteração.
*/

#include <stdio.h>

int main() {
    int a = 10;         // Declaração e inicialização da variável "a"
    int *p;             // Declaração do ponteiro "p"

    p = &a;             // Faz com que "p" aponte para "a"
    
    printf("Antes:\n"); 
    printf("O valor de \"a\": %d\n", a);
    printf("O endereço de \"a\": %p\n", &a);

    *p = 20;            // Utiliza o ponteiro "p" para alterar o valor de "a"

    printf("Depois:\n");
    printf("O valor de \"a\": %d\n", a);
    printf("O endereço de \"a\": %p\n", &a);

    return 0;
}
