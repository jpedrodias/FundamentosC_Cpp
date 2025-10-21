/*
Exercício 4 – Contador de Algarismos
(usar while + if)
Peça ao utilizador para inserir um número inteiro positivo e determine quantos dígitos ele tem.
Usar divisões sucessivas por 10 para contar os algarismos.
Exemplo:
Número: 4582
O número tem 4 algarismos
*/
#include <stdio.h>
#define MAX_INT 2147483647 // 2^31 - 1 (bits)


int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    int numero, contador = 0;

    printf("Contador de Algarismos\n");
    numero = ler_inteiro_no_intervalo(1, MAX_INT, "Introduza um número inteiro positivo: ");

    while (numero != 0) {
        numero /= 10;
        contador++;
    }

    printf("O número tem %d algarismos\n", contador);
    return 0;
}   


int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem) {

    int valor;
    do {
        printf("%s", mensagem);
        scanf("%d", &valor);
        if (valor < minimo || valor > maximo) {
            printf("Valor inválido. O valor deve estar entre %d e %d.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
} // fim ler_inteiro_no_intervalo