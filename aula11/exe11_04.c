/*
Exercício 4
Cria um pequeno programa com menu onde cada opção chama uma função.
Deve mostrar o seguinte menu:
===== MENU =====
1 - Dobrar um número
2 - Triplicar um número
3 - Calcular o quadrado de um número
0 - Sair
================
 
 
 
O programa deve funcionar da seguinte forma:
a.    O menu é apresentado repetidamente até o utilizador escolher a opção 0 (Sair).
b.    O utilizador deve escolher uma opção e introduzir um número inteiro.
c.     Dependendo da opção escolhida, o programa chama uma das seguintes funções:
o   Dobro: mostra o dobro do número;
o   Triplo: mostra o triplo do número;
o   Quadrado: mostra o quadrado do número.
d.    Se o utilizador escolher uma opção inválida, o programa deve mostrar “Opção inválida!” e voltar a apresentar o menu.
*/

#include <stdio.h>

int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);
int dobrar(int numero), triplicar(int numero), quadrado(int numero);

int main() {
    int opcao, numero;

    enum {OPCAO_SAIR = 0, OPCAO_DOBRAR = 1, OPCAO_TRIPLICAR = 2, OPCAO_QUADRADO = 3};

    do {
        do {
            printf("===== MENU =====\n");
            printf("1 - Dobrar um número\n");
            printf("2 - Triplicar um número\n");
            printf("3 - Calcular o quadrado de um número\n");
            printf("0 - Sair\n");
            printf("================\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 3); // LOOP de VALIDAÇÃO OPÇÃO

        if (opcao != 0) {
            numero = ler_inteiro_no_intervalo(1, 1000, "Introduza um número inteiro positivo: ");
        }

        switch (opcao) {
            case OPCAO_DOBRAR:
                printf("O dobro de %d é %d\n", numero, dobrar(numero));
                break;
            case OPCAO_TRIPLICAR:
                printf("O triplo de %d é %d\n", numero, triplicar(numero));
                break;
            case OPCAO_QUADRADO:
                printf("O quadrado de %d é %d\n", numero, quadrado(numero));
                break;
            case OPCAO_SAIR:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        } // fim switch

    } while (opcao != 0); // LOOP PRINCIPAL

    return 0;
} // fim main

int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem) {

    int valor;
    do {
        printf("%s", mensagem);
        scanf("%d", &valor);
        if (valor < minimo || valor > maximo) {
            printf("Valor inválido. O valor deve estar entre %d e %d.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
} // fim ler_inteiro_no_intervalo

int dobrar(int numero) {
    return numero * 2;
}

int triplicar(int numero) {
    return numero * 3;
}

int quadrado(int numero) {
    return numero * numero;
}
