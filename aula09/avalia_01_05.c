/*
Exercício 5 – Soma até atingir limite
(usar do...while + if)
Escreva um programa que vá pedindo números ao utilizador até que a soma total ultrapasse
100. Quando isso acontecer, o programa mostra:
- O total da soma.
- Quantos números foram introduzidos.
*/

#include <stdio.h>
#define MAX_INT 2147483647 // 2^31 - 1 (bits)

#define DEBUG_MODE 0  // definir para 1 para ativar mensagens de debug

float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    float numero, total = 0;
    int contador = 0;

    printf("Soma até atingir limite de 100\n");
    do {
        numero = ler_numero_no_intervalo(-MAX_INT, MAX_INT, "Introduza um número: ");
        total += numero;
        contador++;

        if (DEBUG_MODE) {
            printf("[DEBUG] Número introduzido #%d: %.1f, Soma atual: %.1f\n", contador, numero, total);
        }

    } while (total <= 100.0);

    printf("Total da soma: %.1f\n", total);
    printf("Quantidade de números introduzidos: %d\n", contador);

    return 0;
}


float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem) {

    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        if (valor < minimo || valor > maximo) {
            printf("Valor inválido. O valor deve estar entre %d e %d.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
} // fim ler_numero_no_intervalo