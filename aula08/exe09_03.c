/*
Exercício 3 — Menu de Cálculos Repetidos
Crie um programa que mostre o seguinte menu e permita repetir até o utilizador escolher sair:
===== MENU =====
1 - Somar dois números
2 - Calcular média de 3 números
3 - Verificar se número é positivo ou negativo
0 - Sair
================
Use:
- Um ciclo do...while para manter o menu ativo.
- Um switch case para tratar cada opção.
- if para verificar condições (ex.: número positivo/negativo).
*/

#include <stdio.h>
#include <stdbool.h>


void faz_escolha_1(), faz_escolha_2(), faz_escolha_3();
int faz_menu();


int main() {
    int choice;
    do {

        choice = faz_menu();     
        
        switch (choice) {
            case 1: { faz_escolha_1(); break; }
            case 2: { faz_escolha_2(); break; }
            case 3: { faz_escolha_3(); break; }
            case 0: break;
            default: printf("Opção inválida. Tente novamente.\n"); 
        }

    } while (choice != 0);

    return 0;
} 


int faz_menu() {
    int choice;
    printf("╔═════════════════════════════════╦══════════════════╗\n");
    printf("║ 1 - Somar dois números          ║ Escolha a opção: ║\n");
    printf("║ 2 - Calcular média de 3 números ╚══════════════════╣\n");
    printf("║ 3 - Verificar se número é positivo ou negativo     ║\n");
    printf("║ 0 - Sair                                           ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
    printf("Opção: ");
    scanf("%d", &choice);
    return choice;
}


void faz_escolha_1() {
    float a, b;
    printf("Insira dois números para somar:\n");
    scanf("%f %f", &a, &b);
    printf("Resultado: %.2f + %.2f = %.2f\n", a, b, a + b);
}


void faz_escolha_2() {
    float x, y, z, media;
    printf("Insira três números para calcular a média:\n");
    scanf("%f %f %f", &x, &y, &z);
    media = (x + y + z) / 3;
    printf("Média: %.2f\n", media);
}


void faz_escolha_3() {
    int num;
    printf("Insira um número para verificar se é positivo ou negativo: ");
    scanf("%d", &num);
    if (num > 0) {
        printf("O número %d é positivo.\n", num);
    } else if (num < 0) {
        printf("O número %d é negativo.\n", num);
    } else {
        printf("O número é zero.\n");
    }
}
