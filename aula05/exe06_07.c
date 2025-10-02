/*

Exercício 6 — Jogo do Número Par
Enunciado:
O computador escolhe um número entre 1 e 50.
O utilizador tem 7 tentativas para acertar.
Se o palpite for par, o programa indica apenas se é maior ou menor que o número secreto.
Se o palpite for ímpar, o programa indica se o número secreto também é ímpar ou par.
Use um for para controlar o número de tentativas.
Use um while para garantir que o palpite está entre 1 e 50.

PS: Não usar IFs
*/

#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>  // Para rand() e srand()
#include <time.h>    // Para time()


#define DEBUG_MODE 1 // Ativar modo de depuração
#define _MIN 1
#define _MAX 50
#define _MAX_ATTEMPTS 7


int main(){
    srand(time(NULL)); // SEED - inicializa o gerador de números aleatórios

    const int MIN = _MIN;
    const int MAX = _MAX;

    char choice;
    int numeroAleatorio;
    int tentativas;
    int palpite;

    bool acertou;
    bool alertUser;

    bool isEven;
    bool isOdd;
    bool isGreater;

    do {
        // Número aleatório entre MIN e MAX --- rand() não aceita argumentos
        numeroAleatorio = (rand() % (MAX - MIN + 1)) + MIN;

        #ifdef DEBUG_MODE
            // este bloco de código só é compilado se DEBUG_MODE estiver definido
            // na prática, este bloco não é compilado.
            printf("Número aleatório gerado: %d\n", numeroAleatorio);
        #endif

        tentativas = 0;
        acertou = false;

        while (!acertou && tentativas < _MAX_ATTEMPTS) {
            tentativas++;
            printf("Digite seu palpite %d (entre %d e %d): ", tentativas, MIN, MAX);
            scanf("%d", &palpite);

            acertou = (palpite == numeroAleatorio);
            alertUser = !acertou;

            while (alertUser) {
                printf("Palpite incorreto. Tente novamente.\n");
                alertUser = false;
            }
        }

        
        // verificar se o número é par ou ímpar sem usar IFs
        isEven = (palpite % 2 == 0);
        isOdd = !isEven;
        isGreater = (palpite > numeroAleatorio);

        alertUser = true;
        while (isEven && alertUser) {
            // Se o palpite for par, indicar se é maior ou menor que o número secreto
            
            alertUser = true;
            while (isGreater && alertUser) {
                printf(" O número secreto é menor que %d.\n", palpite);
                alertUser = false;
            }

            alertUser = true;
            while (!isGreater && alertUser) {
                printf(" O número secreto é maior que %d.\n", palpite);
                alertUser = false;
            }

            alertUser = false;
        }


        alertUser = true;
        while (isOdd && alertUser) {

            // Se o palpite for par, indicar AINDA se é maior ou menor que o número secreto
            alertUser = true;
            while (isGreater && alertUser) {
                printf(" O número secreto é menor que %d.\n", palpite);
                alertUser = false;
            }
            alertUser = true;
            while (!isGreater && alertUser) {
                printf(" O número secreto é maior que %d.\n", palpite);
                alertUser = false;
            }

            
            alertUser = true;
            while (isEven && alertUser) {
                printf(" O número secreto é par.\n");
                alertUser = false;
            }
            while (isOdd && alertUser) {
                printf(" O número secreto é ímpar.\n"); 
                alertUser = false;
            }
            alertUser = false;
        }


        alertUser = true;
        while (acertou && alertUser) {
            printf("Parabéns! Você acertou o número %d em %d tentativas.\n", numeroAleatorio, tentativas);
            alertUser = false; // sair do ciclo
        }

        alertUser = true;
        while (!acertou && alertUser) {
            printf("Suas tentativas acabaram. O número era %d. Boa sorte na próxima vez!\n", numeroAleatorio);
            alertUser = false; // sair do ciclo
        }

        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &choice);
    } while (choice == 's' || choice == 'S');
    return 0;
}