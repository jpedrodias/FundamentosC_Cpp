/*
Apontadores em C
Apontadores são variáveis que armazenam o endereço de memória de outra variável. 
Eles são amplamente utilizados em C para manipulação eficiente de dados, 
passagem de parâmetros para funções e alocação dinâmica de memória.
*/

#include <stdio.h>

void aniversario(int *idade);

int main() {
    int idade = 25;
    int *pIdade = &idade;


    printf("Idade.valor  = %d\n", idade);
    printf("Idade.endreço= %p\n", &idade);

    printf("------------------------\n");
    printf("O valor pIdade %p\n", pIdade);
    printf("O valor referenciado por pIdade %d\n", *pIdade);

    // & - operador que devolve o endereço de memória da variável
    // * - operador que devolve o valor guardado no endereço de memória 

    aniversario(&idade);
    printf("Tens %d anos de idade.\n", idade);
}


void aniversario(int *idade) {
    // *idade = *idade + 1
    (*idade)++;
}