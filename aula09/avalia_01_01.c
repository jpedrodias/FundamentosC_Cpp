/*
Exercício 1 – Contador de Divisores
(usar for + if)
Peça ao utilizador para introduzir um número inteiro positivo n e conte quantos divisores ele
possui (números que dividem n sem resto). No final, apresente o total de divisores.
Exemplo:
Número: 8
Divisores: 4
*/
#include <stdio.h>
#define MAX_INT 65536 // 2^16 (bits)


int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);

int main() {
    int i, numero, divisores = 0;

    printf("Contador de Divisores\n");

    numero = ler_inteiro_no_intervalo(1, MAX_INT, "Introduza um número inteiro positivo: ");

    for (i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisores++;
        }
    }

    printf("Divisores: %d\n", divisores);
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