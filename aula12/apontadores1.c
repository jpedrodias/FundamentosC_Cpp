/*
Apontadores em C
Apontadores são variáveis que armazenam o endereço de memória de outra variável. 
Eles são amplamente utilizados em C para manipulação eficiente de dados, 
passagem de parâmetros para funções e alocação dinâmica de memória.

// Adaptado de Bro Code https://www.youtube.com/watch?v=DplxIq0mc_Y
*/

#include <stdio.h>
void aniversario(int *idade);

int main () {
    int idade = 25;
    int *pIdade = &idade;

    printf("O valor de idade é %d\n", idade);
    printf("O endereço de idade é %p\n", &idade);

    printf("O valor de pIdade é %p\n", pIdade);
    printf("O valor referenciado pelo pIdade é %d\n", *pIdade);

    aniversario(&idade);

    printf("O valor de idade é %d\n", idade);
    printf("O endereço de idade é %p\n", &idade);
    
    return 0;
}


void aniversario(int *idade){
    //*idade = *idade + 1;
    (*idade)++;
    printf("Dentro da função o endereço de idade é %p\n", idade);
}
