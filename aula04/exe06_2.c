/*
2. Listagem de Números Pares e Ímpares
O utilizador insere um número N (inteiro positivo).
O programa deve:
Usar um for para listar todos os números de 1 até N.
Usar um while para contar quantos desses números são pares.
Usar um do...while para repetir o processo caso o utilizador queira introduzir um novo valor de N.
*/

#include <stdio.h>



int main() {
    int N, i, countPares;
    char choice;

    do {

        do {
            printf("Digite um número (inteiro positivo N): ");
            scanf("%d", &N);
        } while (N <= 0); // Garantir que N é positivo

        // Listar números de 1 até N
        printf("Números de 1 até %d:\n", N);
        for (i = 1; i <= N; i++) {
            printf("%d ", i);
        }
        printf("\n");

        // Contar números pares usando while
        countPares = 0;
        i = 1;
        while (i <= N) {
            countPares += (i % 2 == 0);
            i++;
        }
        printf("Total de números pares entre 1 e %d: %d\n", N, countPares);

        // Perguntar se o utilizador quer repetir
        printf("Deseja inserir outro valor para N? (s/n): ");
        scanf(" %c", &choice);

    } while (choice == 's' || choice == 'S');

    return 0;
}