/*
Questão/Dúvida: Carregar o módulo math.h implica carregar todas as funções matemáticas?
Resposta: Sim, ao incluir o cabeçalho math.h, você tem acesso a todas as funções matemáticas definidas nele. 
No entanto, isso não significa que todas as funções serão carregadas
*/

#include <stdio.h>
#include <math.h>

int main(){

    float n1 = sin(0);
    float n2 = cos(0);
    float n3 = tan(0);
    float n4 = sqrt(16);

}