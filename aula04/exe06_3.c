/*
3.	Cálculo de Média de Notas
O programa deve pedir ao utilizador a quantidade de notas que vai inserir.
Um for lê todas as notas e calcula a soma.
Um while valida que cada nota está entre 0 e 20.
O ciclo principal é controlado por um do...while, permitindo calcular médias de diferentes conjuntos de notas 
até que o utilizador decida sair.
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int quantidadeNotas, i;
    float nota, somaNotas, media;
    char choice;
    bool isValid, alertUser;
    do {

        do {
            printf("Digite a quantidade de notas que vai inserir: ");
            scanf("%d", &quantidadeNotas);

            isValid = (quantidadeNotas > 0);
            alertUser = !isValid;
            while (alertUser) {
                printf("Quantidade inválida. Por favor, insira um número positivo.\n");
                alertUser = false;
            }

        } while (!isValid); // Garantir que a quantidade de notas é positiva


        somaNotas = 0.0;

        for (i = 0; i < quantidadeNotas; i++) {
            // Validação da nota usando while
            do {
                printf("Digite a nota %d (entre 0 e 20): ", i + 1);
                scanf("%f", &nota);

                isValid = (nota >= 0 && nota <= 20);
                alertUser = !isValid;
                while (alertUser) {
                    printf("Nota inválida. Por favor, insira uma nota entre 0 e 20.\n");
                    alertUser = false;
                }

            } while (!isValid); // Garantir que a nota está entre 0 e 20

            somaNotas += nota;
        }

        media = somaNotas / quantidadeNotas;
        printf("A média das notas é: %.2f\n", media);

        // Perguntar se o utilizador quer calcular outra média
        printf("Deseja calcular a média de outro conjunto de notas? (s/n): ");
        scanf(" %c", &choice);

    } while (choice == 's' || choice == 'S');

    return 0;
}