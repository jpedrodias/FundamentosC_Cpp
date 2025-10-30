/*
Exercício 5 – Gestão de Notas dos Alunos
(usar do...while, switch case, if e várias funções)
Crie um programa em linguagem C que ajude a gerir as notas de um aluno.
O programa deve apresentar o seguinte menu:
===== GESTÃO DE NOTAS =====
1 - Inserir notas
2 - Calcular média
3 - Verificar aprovação
0 - Sair
===========================
O funcionamento deve ser o seguinte:
1. O programa deve ter três funções principais, além do main():
    * inserirNotas: lê as três notas do aluno.
    * calcularMedia: devolve a média aritmética das notas.
    * verificarAprovacao: mostra se o aluno está Aprovado (média ≥ 10) ou Reprovado (média < 10).

2. O menu deve repetir até o utilizador escolher 0 - Sair.
3. A sequência de execução esperada é:
    * Primeiro o utilizador escolhe 1 para inserir as notas;
    * Depois pode escolher 2 para ver a média;
    * E finalmente 3 para verificar se foi aprovado.
4. Se o utilizador tentar calcular a média ou verificar aprovação sem ter inserido notas, 
o programa deve mostrar uma mensagem de aviso: “Primeiro deve inserir as notas!”


Dicas:
• Usa variáveis globais simples ou passa os valores por referência (&) para partilhar
os dados entre funções.
• Garante que o menu repete até a opção 0.
• O programa deve mostrar resultados claros e formatados.
*/

#include <stdio.h>
#include <stdbool.h>


int escolher_opção();
bool inserirNotas(float notas[], int size);
float calcularMedia(float notas[], int size);
void verificarAprovacao(float media);
int ler_inteiro_no_intervalo(int minimo, int maximo, const char* mensagem);


int main() {
    // Implementação do programa de gestão de notas dos alunos
    int size = 3;
    float notas[size], media;
    bool notas_inseridas = false;

    int opcao;
    enum {OPCAO_SAIR = 0, OPCAO_INSERIR = 1, OPCAO_MEDIA = 2, OPCAO_APROVACAO = 3};

    do {

        do {
            opcao = escolher_opção();
        } while (opcao < OPCAO_SAIR || opcao > OPCAO_APROVACAO); // LOOP de VALIDAÇÃO OPÇÃO
        

        switch (opcao) {
            case OPCAO_INSERIR:
                notas_inseridas = inserirNotas(notas, size);
                break;

            case OPCAO_MEDIA:
                if (!notas_inseridas) {
                    printf("Primeiro deve inserir as notas!\n");
                    break;
                }
                media = calcularMedia(notas, size);
                printf("A média é: %.2f\n", media);
                break;

            case OPCAO_APROVACAO:
                if (!notas_inseridas) {
                    printf("Primeiro deve inserir as notas!\n");
                    break;
                }
                verificarAprovacao(media);
                break;

            case OPCAO_SAIR:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        } // fim switch

    } while (opcao != 0); // LOOP PRINCIPAL

    return 0;
} // fim main


int escolher_opção(){
    int opcao;
    printf("===== GESTÃO DE NOTAS =====\n");
    printf("1 - Inserir notas\n");
    printf("2 - Calcular média\n");
    printf("3 - Verificar aprovação\n");
    printf("0 - Sair\n");
    printf("===========================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}


void verificarAprovacao(float media){
    if(media >= 10.0){
        printf("Aluno Aprovado!\n");
    } else {
        printf("Aluno Reprovado!\n");
    }
}


float calcularMedia(float notas[], int size){
    float soma = 0.0;
    for(int i = 0; i < size; i++){
        soma += notas[i];
    }
    return soma / size;
}


bool inserirNotas(float notas[], int size){
    for(int i = 0; i < size; i++){
        notas[i] = ler_inteiro_no_intervalo(0, 20, "Introduza uma nota entre 0 e 20: ");
    }
    return true;
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
