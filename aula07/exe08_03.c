/*
3- Direções
Peça ao utilizador uma letra que indique uma direção:
N → Norte
S → Sul
E → Este
O → Oeste
Mostre a direção correspondente.
Se a letra não for válida, apresente uma mensagem de erro.
*/

#include <stdio.h>

int main() {
    char direcao;
    
    printf("Digite uma letra para a direção (N, S, E, O): ");
    scanf(" %c", &direcao);
    
    switch(direcao) {
        case 'N':
        case 'n':
            printf("Norte\n");
            break;
        case 'S':
        case 's':
            printf("Sul\n");
            break;
        case 'E':
        case 'e':
            printf("Este\n");
            break;
        case 'O':
        case 'o':
            printf("Oeste\n");
            break;
        default:
            printf("Erro: Direção inválida!\n");
    }
    
    return 0;
}