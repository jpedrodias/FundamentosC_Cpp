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

int main(){
    srand(time(NULL)); // SEED - inicializa o gerador de números aleatórios

    const int MIN = 1;
    const int MAX = 10;

    // Número aleatório entre MIN e MAX --- rand() não aceita argumentos
    int numeroAleatorio = (rand() % (MAX - MIN + 1)) + MIN;

    #ifdef DEBUG_MODE
        // este bloco de código só é compilado se DEBUG_MODE estiver definido
        // na prática, este bloco não é compilado.
        printf("Número aleatório gerado: %d\n", numeroAleatorio);
    #endif

    int palpite;
    bool acertou = false;
    bool alertUser = true;

    while (!acertou) {
        printf("Digite seu palpite (entre %d e %d): ", MIN, MAX);
        scanf("%d", &palpite);

        acertou = (palpite == numeroAleatorio);
        alertUser = !acertou;

        while (alertUser) {
            printf("Palpite incorreto. Tente novamente.\n");
            alertUser = false;
        }
    }
    return 0;
}