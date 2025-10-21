
# Exercício 1 – Contador de Divisores
(usar for + if)
Peça ao utilizador para introduzir um número inteiro positivo n e conte quantos divisores ele
possui (números que dividem n sem resto). No final, apresente o total de divisores.
Exemplo:
Número: 8
Divisores: 4

```c
#include <stdio.h>
#define MAX_INT 65536 // 2^16 (bits)


int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    int i, numero, divisores = 0;

    printf("Contador de Divisores\n");

    numero = ler_inteiro_no_intervalo(1, MAX_INT, "Introduza um número inteiro positivo: ");

    for (i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisores++;
        }
    }

    printf("Divisores: %d\n", divisores);
    return 0;
}


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
```


***

# Exercício 2 – Contagem Regressiva com Passo
(usar for + validação com if)
Peça ao utilizador dois números: início e passo. O programa deve mostrar uma contagem
regressiva desde início até 0, diminuindo de passo em passo. Se o passo for inválido (≤ 0),
deve pedir novamente até ser válido.
Exemplo:
Início: 15
Passo: 4
Contagem: 15 11 7 3

```c
#include <stdio.h>
#define MAX_INT 65536 // 2^16 (bits)

int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    int inicio, passo;

    printf("Contagem Regressiva com Passo\n");

    inicio = ler_inteiro_no_intervalo(1, 10000, "Início: ");

    do {
        passo = ler_inteiro_no_intervalo(1, 10000, "Passo: ");
    } while (passo <= 0); // redundância devido à validação na função mas ...

    printf("Contagem: ");
    for (int i = inicio; i > 0; i -= passo) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}


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
```

***

# Exercício 3 – Calculadora de Descontos
(usar switch case + if)
Crie um programa que peça o valor total de uma compra e mostre o seguinte menu:
```text
===== MENU DE DESCONTOS =====
1 - Cliente regular (5%)
2 - Cliente fidelizado (10%)
3 - Promoção especial (15%)
0 - Sair
=============================
```
O utilizador escolhe a opção. O programa calcula e mostra o valor final a pagar, já com o
desconto. Se o valor for menor ou igual a 0, deve mostrar uma mensagem de erro. O
programa termina apenas quando o utilizador escolher 0 - Sair.


```c
#include <stdio.h>
#define MAX_INT 65536 // 2^16 (bits)


float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    float valor_compra, valor_final;
    int escolha;

    printf("Introduza o valor total da compra: ");
    valor_compra = ler_numero_no_intervalo(-MAX_INT, MAX_INT, "Valor da compra: ");

    do {
        printf("\n===== MENU DE DESCONTOS =====\n");
        printf("1 - Cliente regular (5%%)\n");
        printf("2 - Cliente fidelizado (10%%)\n");
        printf("3 - Promoção especial (15%%)\n");
        printf("0 - Sair\n");
        printf("=============================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                valor_final = valor_compra * 0.95;
                break;
            case 2:
                valor_final = valor_compra * 0.90;
                break;
            case 3:
                valor_final = valor_compra * 0.85;
                break;
            case 0:
                printf("Saindo do programa.\n");
                continue;
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }

        if (valor_final <= 0) {
            printf("Erro: O valor final a pagar não pode ser menor ou igual a zero.\n");
        } else {
            printf("Valor final a pagar após desconto: %.2f\n", valor_final);
        }

    } while (escolha != 0);

    return 0;
}


float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem) {

    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        if (valor < minimo || valor > maximo) {
            printf("Valor inválido. O valor deve estar entre %d e %d.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
} // fim ler_numero_no_intervalo
```

***

# Exercício 4 – Contador de Algarismos
(usar while + if)
Peça ao utilizador para inserir um número inteiro positivo e determine quantos dígitos ele tem.
Usar divisões sucessivas por 10 para contar os algarismos.
Exemplo:
Número: 4582
O número tem 4 algarismos

```c
#include <stdio.h>
#define MAX_INT 2147483647 // 2^31 - 1 (bits)


int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    int numero, contador = 0;

    printf("Contador de Algarismos\n");
    numero = ler_inteiro_no_intervalo(1, MAX_INT, "Introduza um número inteiro positivo: ");

    while (numero != 0) {
        numero /= 10;
        contador++;
    }

    printf("O número tem %d algarismos\n", contador);
    return 0;
}   


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
```

***

# Exercício 5 – Soma até atingir limite
(usar do...while + if)
Escreva um programa que vá pedindo números ao utilizador até que a soma total ultrapasse
100. Quando isso acontecer, o programa mostra:
- O total da soma.
- Quantos números foram introduzidos.

```c
#include <stdio.h>
#define MAX_INT 2147483647 // 2^31 - 1 (bits)

#define DEBUG_MODE 0  // definir para 1 para ativar mensagens de debug

float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    float numero, total = 0;
    int contador = 0;

    printf("Soma até atingir limite de 100\n");
    do {
        numero = ler_numero_no_intervalo(-MAX_INT, MAX_INT, "Introduza um número: ");
        total += numero;
        contador++;

        if (DEBUG_MODE) {
            printf("[DEBUG] Número introduzido #%d: %.1f, Soma atual: %.1f\n", contador, numero, total);
        }

    } while (total <= 100.0);

    printf("Total da soma: %.1f\n", total);
    printf("Quantidade de números introduzidos: %d\n", contador);

    return 0;
}


float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem) {

    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        if (valor < minimo || valor > maximo) {
            printf("Valor inválido. O valor deve estar entre %d e %d.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
} // fim ler_numero_no_intervalo
```


***

# Exercício 6 – Menu de Operações Matemáticas
(usar do...while + switch case)
Crie um programa com o seguinte menu:
```text
===== MENU =====
1 - Dobrar um número
2 - Triplicar um número
3 - Calcular o quadrado de um número
0 - Sair
================
```
O utilizador escolhe uma opção e insere o número. O programa mostra o resultado. O menu
deve repetir até o utilizador escolher 0 - Sair. Se a opção for inválida, mostrar “Opção
inválida”.

```c
#include <stdio.h>
#define MAX_NUM 65536 // 2^16 (bits)


float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    int escolha;
    float numero, resultado;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Dobrar um número\n");
        printf("2 - Triplicar um número\n");
        printf("3 - Calcular o quadrado de um número\n");
        printf("0 - Sair\n");
        printf("================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                numero = ler_numero_no_intervalo(-MAX_NUM, MAX_NUM, "Insira um número para dobrar: ");
                resultado = numero * 2;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 2:
                numero = ler_numero_no_intervalo(-MAX_NUM, MAX_NUM, "Insira um número para triplicar: ");
                resultado = numero * 3;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 3:
                numero = ler_numero_no_intervalo(-MAX_NUM, MAX_NUM, "Insira um número para calcular o quadrado: ");
                resultado = numero * numero;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}


float ler_numero_no_intervalo(int minimo, int maximo, const char* mensagem) {

    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        if (valor < minimo || valor > maximo) {
            printf("Valor inválido. O valor deve estar entre %d e %d.\n", minimo, maximo);
        }
    } while (valor < minimo || valor > maximo);
    return valor;
} // fim ler_numero_no_intervalo
```
***
## end of doc