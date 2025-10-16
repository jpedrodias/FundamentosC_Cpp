/*
Exercício 4 — Gerador de Séries Numéricas
Crie um programa que gere diferentes séries numéricas, dependendo da escolha do utilizador:
===== MENU =====
1 - Sequência de números pares até N
2 - Sequência de Fibonacci até N termos
3 - Soma dos números ímpares até N
0 - Sair
================
- Use switch case para selecionar o tipo de série.
- Use for ou while para gerar as sequências.
- Use if para verificar paridade quando necessário.
Exemplo:
Opção: 2
Insira N: 7
Sequência Fibonacci: 0 1 1 2 3 5 8
*/

#include <stdio.h>
#include <stdbool.h>

void gera_pares(int n), gera_fibonacci(int n), soma_impares(int n);
int faz_menu();
int main() {
    int choice, n;
    do {

        choice = faz_menu();     
        
        if (choice != 0) {
            printf("Insira N: ");
            scanf("%d", &n);
        }

        switch (choice) {
            case 1: { gera_pares(n); break; }
            case 2: { gera_fibonacci(n); break; }
            case 3: { soma_impares(n); break; }
            case 0: break;
            default: printf("Opção inválida. Tente novamente.\n"); 
        }

    } while (choice != 0);

    return 0;
}

int faz_menu() {
    int choice;
    printf("╔═════════════════════════════════╦══════════════════╗\n");
    printf("║ 1 - Sequência de números pares até N       ║ Escolha a opção: ║\n");
    printf("║ 2 - Sequência de Fibonacci até N termos     ╚══════════════════╣\n");
    printf("║ 3 - Soma dos números ímpares até N          ║\n");
    printf("║ 0 - Sair                                   ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Opção: ");
    scanf("%d", &choice);
    return choice;
}


void gera_pares(int n) {
    printf("Sequência de números pares até %d: ", n);
    for (int i = 0; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

void gera_fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Sequência Fibonacci até %d termos: ", n);
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = a + b;
            a = b;
            b = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}

void soma_impares(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i += 2) {
        soma += i;
    }
    printf("Soma dos números ímpares até %d: %d\n", n, soma);
}


// gcc -o myapp exe09_04.c
// ./myapp