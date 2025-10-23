/*
Exercício 1:
 Escrever um programa que calcule e escreva a diferença das notas de 4 alunos relativamente à sua média, usando vetores.
*/
#include <stdio.h>
#include <math.h>


int main(){
    
    int numero_de_alunos = 4;
    int valor;    // leitura do valor da nota
    int notas[numero_de_alunos]; 
    int soma = 0; // soma de todas as notas
    

    float media;
    float diferenca[numero_de_alunos];
    
    // Leitura das notas
    for(int i = 0; i < numero_de_alunos; i++){
        do {
            printf("Nota do aluno %d: ", i + 1);
            scanf("%d", &valor);
        } while (valor < 0 || valor > 20);  
        notas[i] = valor;
    }
    
    // Cálculo da soma
    soma = 0;
    for(int i = 0; i < numero_de_alunos; i++){
        soma += notas[i];
    }

    // Cálculo da média
    media = soma / (float)numero_de_alunos;
    
    // Cálculo das diferenças relativamente à média
    printf("\nDiferenças relativamente à média (%.2f):\n", media);
    for(int i = 0; i < numero_de_alunos; i++){
        diferenca[i] = (float)notas[i] - media;
        printf("\tAluno %d: Diferença = %4.2f", 
            i + 1, 
            fabs(diferenca[i]));
        

        if (diferenca[i] > 0)      { printf(" %s", "(acima da média)"  ); } 
        else if (diferenca[i] < 0) { printf(" %s", "(abaixo da média)" ); } 
        else                       { printf(" %s", "(na média)"        ); }
        printf("\n");
    }
    
    return 0;
    
}