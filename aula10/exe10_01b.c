/*
Exercício 1:
 Escrever um programa que calcule e escreva a diferença das notas de 4 alunos relativamente à sua média, usando vetores.
*/
#include <stdio.h>
#include <math.h>


int main(){
    
    int numero_de_alunos = 2;
    int numero_de_notas = 2;

    int notas[numero_de_alunos][numero_de_notas]; 
    float medias[numero_de_alunos];
    float diferencas[numero_de_alunos];
    
    // Leitura das notas
    int valor; 
    for (int i = 0; i < numero_de_alunos; i++) {
        for(int j = 0; j < numero_de_notas; j++){
            printf("Nota do aluno %d (nota %d): ", i + 1, j + 1);
            scanf("%d", &valor);
            notas[i][j] = valor;
        }
    }   
    
    // Cálculo da soma
    int soma; float media; float soma_todos = 0.0;
    for (int i = 0; i < numero_de_alunos; i++) {
        soma = 0;
        for(int j = 0; j < numero_de_notas; j++){
            soma += notas[i][j];
            soma_todos += notas[i][j];
        }
        media = soma / (float)numero_de_notas;
        medias[i] = media;
        printf("Média do aluno %d: %.2f\n", i + 1, media);
    }

    float media_geral = soma_todos / (float)(numero_de_alunos * numero_de_notas);
    
    // Cálculo das diferenças relativamente à média
    printf("\nDiferenças relativamente à média (%.2f):\n", media_geral);
    for(int i = 0; i < numero_de_alunos; i++){
        diferencas[i] = (float)medias[i] - media_geral;

        printf("\tAluno %d: Diferença = %4.2f\n", 
            i + 1, 
            diferencas[i]
        );
    }
    
    return 0;
    
}