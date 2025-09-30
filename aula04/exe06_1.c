/*
1 .	Gerador de Tabuadas com Repetição
O utilizador escolhe um número n.
O programa deve imprimir a tabuada de n de 1 até 10 com um ciclo for.
Depois, pergunta se o utilizador quer ver a tabuada de outro número 
(do...while garante que mostra pelo menos uma tabuada).
O programa só termina quando o utilizador responder "não".
Antes de sair, mostra quantas tabuadas foram geradas no total (usando um while para contar).
*/

#include <stdio.h>

int main() {
    int numero, contadorTabuadas = 0;
    char resposta;

    do {
        printf("Digite um número para ver a tabuada: ");
        scanf("%d", &numero);

        printf("Tabuada de %d:\n", numero);
        for (int i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", numero, i, numero * i);
        }

        contadorTabuadas++;

        printf("Deseja ver a tabuada de outro número? (s/n): ");
        scanf(" %c", &resposta); // espaço antes de %c para consumir o newline

    } while (resposta == 's' || resposta == 'S');

    // Contar quantas tabuadas foram geradas usando um while
    int totalTabuadas = 0;
    while (totalTabuadas < contadorTabuadas) {
        totalTabuadas++;
    }

    printf("Total de tabuadas geradas: %d\n", totalTabuadas);

    return 0;
}
