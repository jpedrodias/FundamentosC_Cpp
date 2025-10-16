/*
8-	Escreva um programa em linguagem C que utilize as estruturas if, while, do while e for para gerir as notas de vários alunos.
O programa deve seguir as seguintes instruções:
a. Apresentação e repetição do programa
O programa deve começar por apresentar a informação:
=== Sistema de Gestão de Notas ===
Após a execução, deve perguntar ao utilizador se deseja repetir o programa (S para sim, N para não).
Esta parte deve ser implementada com um ciclo do while.

b. Introdução de notas com verificação de validade
O utilizador deve indicar quantos alunos serão avaliados (mínimo 1, máximo 10).
Caso o número esteja fora desse intervalo, deve ser apresentada uma mensagem de erro, usando uma estrutura if, e o programa deve pedir o valor novamente.
Esta validação deve ser feita dentro de um ciclo while.

c. Leitura das notas e cálculo da média
Utilize um ciclo for para ler a nota de cada aluno (entre 0 e 20).
Se uma nota inválida for introduzida, use um if para alertar o utilizador e pedir novamente a nota desse aluno.
No final, o programa deve calcular e mostrar:
A média da turma;
A nota mais alta;
A nota mais baixa.
Classificação final
Após calcular a média, o programa deve usar uma estrutura if para apresentar uma mensagem:
Média ≥ 16 → "Excelente desempenho!"
Média entre 10 e 15 → "Desempenho satisfatório."
Média < 10 → "Necessita de melhoria."
*/

#include <stdio.h>

int main(void) {
    char repetir;

    do {
        printf("=== Sistema de Gestão de Notas ===\n");

        /* pedir número de alunos (1..10) com validação em while */
        int alunos;
        do {
            printf("Quantos alunos (1-10)? ");
            scanf("%d", &alunos);
            if (alunos < 1 || alunos > 10) {
                printf("Número inválido. Introduza um valor entre 1 e 10: ");
            }
        } while (alunos < 1 || alunos > 10);


        double soma = 0.0;
        double media = 0.0;
        double maior = -1.0;
        double menor = 21.0;
        double nota;

        for (int i = 0; i < alunos; ++i) {
            do {
                printf("Nota do aluno %d (0-20): ", i + 1);
                scanf("%lf", &nota);
                if (nota < 0.0 || nota > 20.0) {
                    printf("Nota inválida. Tente novamente.\n");
                }
            } while (nota < 0.0 || nota > 20.0);

            soma += nota;
            if (nota > maior) maior = nota;
            if (nota < menor) menor = nota;
        }
        media = soma / alunos;

        printf("\nResultado:\n");
        printf("Média da turma: %.2f\n", media);
        printf("Nota mais alta: %.2f\n", maior);
        printf("Nota mais baixa: %.2f\n", menor);

        if (media >= 16.0) {
            printf("Excelente desempenho!\n");
        } else if (media >= 10.0) {
            printf("Desempenho satisfatório.\n");
        } else {
            printf("Necessita de melhoria.\n");
        }


        printf("\nDeseja repetir o programa? (S/N): ");
        scanf(" %c", &repetir);
    } while (repetir == 'S'); // saida do loop principal

    return 0;
}
