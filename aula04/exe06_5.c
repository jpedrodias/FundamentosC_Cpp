/*
5.	Jogo de Tentativas Limitadas
O programa escolhe um número secreto entre 1 e 100.
O utilizador tem até 10 tentativas:
Um for controla o número de tentativas.
Dentro dele, um while garante que o utilizador só pode inserir números dentro do intervalo [1, 100].
O jogo pode ser repetido várias vezes se o utilizador desejar (do...while).

*/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define DEBUG_MODE 1 // Ativar modo de depuração » Colocar a 0 desativa a depuração.
#define _MIN 1
#define _MAX 100
#define _MAX_ATTEMPTS 10

int main()
{
    const int MIN = _MIN;
    const int MAX = _MAX;
    long epoch;
    char choice;
    int numeroQuaseAleatorio;

    do {

        epoch = time(NULL);
        int numeroQuaseAleatorio = epoch % (MAX - MIN + 1) + MIN;

        #ifdef DEBUG_MODE
                // este bloco de código só é compilado se DEBUG_MODE estiver definido
                // na prática, este bloco não é compilado.
                printf("Número secreto é: %d\n", numeroQuaseAleatorio);
        #endif

        int tentativas = 0;
        int palpite;
        bool acertou = false;
        bool alertUser = true;

        while (!acertou && tentativas < _MAX_ATTEMPTS) {
            tentativas++;
            printf("Digite seu palpite %d (entre %d e %d): ", tentativas, MIN, MAX);
            scanf("%d", &palpite);

            acertou = (palpite == numeroQuaseAleatorio);
            alertUser = !acertou;

            while (alertUser)
            {
                printf("Palpite incorreto. Tente novamente.\n");
                alertUser = false;
            }
        }

        alertUser = true;
        while (acertou && alertUser) {
            printf("Parabéns! Você acertou o número %d em %d tentativas.\n", numeroQuaseAleatorio, tentativas);
            alertUser = false; // sair do ciclo
        }

        alertUser = true;
        while (!acertou && alertUser) {
            printf("Suas tentativas acabaram. O número era %d. Boa sorte na próxima vez!\n", numeroQuaseAleatorio);
            alertUser = false; // sair do ciclo
        }

        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &choice);
    } while (choice == 's' || choice == 'S'); // repetir o jogo enquanto o usuário quiser

    return 0;
}