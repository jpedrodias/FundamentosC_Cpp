/*
Exercício 5 — Sistema de Notas com Validação
Crie um programa que leia as notas de vários alunos, garantindo que:
- Cada nota está entre 0 e 20 (se não estiver, deve pedir novamente usando um while).
- Para cada aluno, determine a situação:
 média < 10 → “Reprovado”
 média ≥ 10 → “Aprovado”
No final, use um switch case para mostrar um resumo:
1 - Total de alunos aprovados
2 - Total de alunos reprovados
3 - Média geral da turma
0 - Sair
O utilizador pode consultar várias opções até escolher sair.
*/

#include <stdio.h>
#include <stdbool.h>


int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);

int main(){

    int número_de_alunos;
    int número_de_aprovados = 0;
    int número_de_reprovados = 0;
    int soma_das_notas = 0;
    float média_geral;

    // PARTE 1: Pedir o número de alunos
    número_de_alunos = ler_inteiro_no_intervalo(1, 1000, "Insira o número de alunos: ");
    printf("Número de alunos: %d\n", número_de_alunos);


    // PARTE 2: Ler as notas dos alunos e contar aprovados/reprovados
    for (int i = 0; i < número_de_alunos; i++) {
        printf("\nAluno %d:\n", i + 1);

        int nota = ler_inteiro_no_intervalo(0, 20, "Insira a nota (0-20): ");
        
        soma_das_notas += nota;

        if (nota >= 10.0) {
            número_de_aprovados++;
            printf("Aluno %d: Aprovado\n", i + 1);
        } else {
            número_de_reprovados++;
            printf("Aluno %d: Reprovado\n", i + 1);
        }
    }
    média_geral = (float)soma_das_notas / número_de_alunos;


    // PARTE 3: Mostrar o menu de resumo
    int choice;
    do {
        printf("\n");
        printf("╔════════════════════════════════╦═══╗\n");
        printf("║ 1 - Total de alunos aprovados  ║ ? ║\n");
        printf("║ 2 - Total de alunos reprovados ╚═══╣\n");
        printf("║ 3 - Média geral da turma           ║\n");
        printf("║ 0 - Sair                           ║\n");
        printf("╚════════════════════════════════════╝\n");
        printf("Opção: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:  { printf("Total de alunos aprovados: %d\n",  número_de_aprovados);  break; }
            case 2:  { printf("Total de alunos reprovados: %d\n", número_de_reprovados); break; }
            case 3:  { printf("Média geral da turma: %.2f\n",     média_geral);          break; }
            case 0:  { break; }   
            default: { printf("Opção inválida. Tente novamente.\n"); }
        }
    } while (choice != 0);


    // Saída para o sistema operativo com código 0 (sucesso)
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
}   