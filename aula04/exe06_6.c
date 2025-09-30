/*
5.	Jogo de Tentativas Limitadas
O programa escolhe um número secreto entre 1 e 100.
O utilizador tem até 10 tentativas:
Um for controla o número de tentativas.
Dentro dele, um while garante que o utilizador só pode inserir números dentro do intervalo [1, 100].
O jogo pode ser repetido várias vezes se o utilizador desejar (do...while).

ATENÇÃO: 
•	Usar a biblioteca time.h (Esta biblioteca contém funções relacionadas com data e tempo.)
•	Usar a função srand(time(NULL)); a função rand() gera números pseudoaleatórios.

*/


/*
4 - Escreva um programa que defina um número secreto (por exemplo, 7) e peça ao utilizador para adivinhar esse número.
O programa deve continuar a pedir um palpite até que o utilizador acerte. Quando acertar, o programa deve exibir uma mensagem de sucesso.
PS: Ainda sem usar IFs ou do Whiles
*/

#include <stdio.h>
#include <stdbool.h>

// Gerador de números aleatórios
#include <stdlib.h>  // Para rand() e srand()
#include <time.h>    // Para time()

#define DEBUG_MODE 1 // Ativar modo de depuração
#define _MIN 1
#define _MAX 100
#define _MAX_ATTEMPTS 10

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