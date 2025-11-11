#include <stdio.h>


struct Ponto {
    int x;
    int y;
};



int main() {


    // Declaração e inicialização de struct Ponto
    struct Ponto ponto = {
        .x = 10, 
        .y = 0
    };


    // Impressão das coordenadas do ponto único
    printf("Coordenada do ponto unico {x= %d, y= %d}\n", ponto.x, ponto.y);





    // Declaração e inicialização de um array de structs Ponto
    struct Ponto pontos[3] = {
        {.x = 1, .y = 2},
        {.x = 3, .y = 4},
        {.x = 5, .y = 6}
    };

    // Impressão das coordenadas dos pontos
    for (int i = 0; i < 3; i++) {
        printf("Coodenada do ponto %d {x= %d, y= %d}\n", i+1, pontos[i].x, pontos[i].y);
    }

    return 0;
}