/*
Exercício 2 – Contagem Regressiva com Passo
(usar for + validação com if)
Peça ao utilizador dois números: início e passo. O programa deve mostrar uma contagem
regressiva desde início até 0, diminuindo de passo em passo. Se o passo for inválido (≤ 0),
deve pedir novamente até ser válido.
Exemplo:
Início: 15
Passo: 4
Contagem: 15 11 7 3
*/
#include <stdio.h>
#define MAX_INT 65536 // 2^16 (bits)


int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);

int main() {
    int inicio, passo;

    printf("Contagem Regressiva com Passo\n");

    inicio = ler_inteiro_no_intervalo(1, 10000, "Início: ");

    do {
        passo = ler_inteiro_no_intervalo(1, 10000, "Passo: ");
    } while (passo <= 0); // redundância devido à validação na função mas ...

    printf("Contagem: ");
    for (int i = inicio; i > 0; i -= passo) {
        printf("%d ", i);
    }
    printf("\n");

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