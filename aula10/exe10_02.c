/*
Exercício 2:
Escrever um programa que leia as temperaturas dos sete dias da semana e determine a temperatura máxima e mínima.
*/
#include <stdio.h>

int main() {
    float temperaturas[7];
    float temperatura_maxima = 0.0, temperatura_minima = 0.0;
    int temperatura_maxima_indice = 0, temperatura_minima_indice = 0;

    char *dias_da_semana[7] = {
        "Segunda-feira",
        "Terça-feira",
        "Quarta-feira",
        "Quinta-feira",
        "Sexta-feira",
        "Sábado",
        "Domingo"
    };

    // Leitura das temperaturas
    for (int i = 0; i < 7; i++) {
        printf("Digite a temperatura de %s: ", dias_da_semana[i]);
        scanf("%f", &temperaturas[i]);
    }

    // Inicializa as temperaturas máxima e mínima para um valor válido no array
    temperatura_maxima = temperaturas[0];
    temperatura_minima = temperaturas[0];

    // Determina a temperatura máxima e mínima
    // Ou seja, uma dupla pequisa linear no array pelo max e min
    for (int i = 1; i < 7; i++) {
        if (temperaturas[i] > temperatura_maxima) {
            temperatura_maxima = temperaturas[i];
            temperatura_maxima_indice = i;
        }
        if (temperaturas[i] < temperatura_minima) {
            temperatura_minima = temperaturas[i];
            temperatura_minima_indice = i;
        }
    }

    printf("%s tivemos a temperatura mais alta com %.2f\n", 
        dias_da_semana[temperatura_maxima_indice], 
        temperatura_maxima);
    
    printf("%s tivemos a temperatura mais baixa com %.2f\n",
        dias_da_semana[temperatura_minima_indice],
        temperatura_minima);

    return 0;
}   