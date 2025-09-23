# include <stdio.h> // incluir biblioteca padrão de entrada e saída


// função principal
int main() {

    printf("Hello World!\n"); // imprimir na tela a mensagem Hello World!

    int x = 2;
    int y = 3;


    // primeira operação
    x = y++ * 4; // x agora vale 5

    printf("O resultado da primeira operação é:  %d\n", x);
    
    // segunda operação
    x = 3 * 4 + y;
    printf("O resultado da segunda operação é:  %d\n", x);
    
    // terceira operação
    x = (3+4) * y;
    printf("O resultado da terceira operação é:  %d\n", x);


    return 0; // retornar 0 para indicar que o programa terminou corretamente
}