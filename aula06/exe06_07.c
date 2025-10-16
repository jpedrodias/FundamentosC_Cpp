/*
Enunciado: Cálculo da área de dois círculos e identificação do maior
Escreva um programa em linguagem C que utilize a biblioteca math.h para calcular a área de dois círculos e determinar qual deles tem a maior área.
O programa deve:
Pedir ao utilizador o raio de dois círculos (r1 e r2);
Calcular a área de cada círculo usando a fórmula:
Aˊrea=π×r2\text{Área} = \pi \times r^2Aˊrea=π×r2
(Utilize a constante M_PI da biblioteca math.h);
Mostrar no ecrã as áreas calculadas com duas casas decimais;
Indicar qual dos dois círculos é maior, ou se têm áreas iguais.

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>  // para obter o valor de PI

// Função para pedir um valor double positivo ao utilizador
double pedirFloat(const char *header, const char *msg, const char *msgError);



int main() {
    /* Obter PI de forma portátil e usar double para os cálculos */
    const long double PI = acos(-1.0L);

    // Considerar uma pequena tolerância para comparação de números de ponto flutuante
    // por causa da representação binária dos números decimais
    const long double tolerancia = 1e-9L;

    double r1, r2, area1, area2;


    const char *msgInput = "Insira o raio do círculo (positivo): ";
    const char *msgError = "Raio inválido. Por favor, insira um valor positivo.\n";

    /* Pedir e validar os raios */
    r1 = pedirFloat("Círculo 1", msgInput, msgError);
    r2 = pedirFloat("Círculo 2", msgInput, msgError);

    area1 = r1 * r1 * PI;
    area2 = r2 * r2 * PI;

    printf("Área do círculo 1: %.2f\n", area1);
    printf("Área do círculo 2: %.2f\n", area2);

    // Comparar as áreas considerando a tolerância
    if (area1 > area2 + tolerancia) {
        printf("O círculo 1 é maior que o círculo 2.\n");
    } else if (area2 > area1 + tolerancia) {
        printf("O círculo 2 é maior que o círculo 1.\n");
    } else {
        printf("Os círculos têm áreas iguais.\n");
    }
    
    return 0;
}

double pedirFloat(const char *header, const char *msg, const char *msgError) {
    double valor;
    bool valorValido = false;

    printf("%s\n", header);

    do {
        printf("%s", msg);
        scanf("%lf", &valor);
        if (valor > 0.0) {
            valorValido = true;
        } else {
            printf("%s", msgError);
        }
    } while (!valorValido);

    return valor;
}