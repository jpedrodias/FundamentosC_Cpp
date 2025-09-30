/*
3-    Faça um programa que peça ao utilizador um número entre 12 e 20. Se a pessoa digitar um número diferente, 
mostrar a mensagem "entrada inválida" e solicitar o número novamente. Se digitar correto mostrar o número digitado.
E sem usar os IFs
*/
// gcc -o myapp aula04.c
// ./myapp

#include <stdio.h>
#include <stdbool.h>

int main() {
    const int MIN = 12;
    const int MAX = 20;

    int numero; // valor lido do teclado

    bool isValidNumber = false; // Controlo dos alerta
    bool alertUser = true;

    while ( !isValidNumber )  {
        printf("Digite um número entre 12 e 20: ");
        scanf("%d", &numero);

        isValidNumber = (numero >= MIN && numero <= MAX);
        alertUser = !isValidNumber;
        while (alertUser) {
            printf("Entrada inválida. Tente novamente.\n");
            alertUser = false;
        }
    }
    return 0;
}
