#include <stdio.h>
#include <locale.h>

/*
Escreve um programa de mostre os primeiro 20 números naturais.
*/
int exemplo_1(){
    for(int i = 1; i <= 20; i++){
        printf("%d\n", i);
    }
    return 0;
}


/*
Escrever todos os números entre 10 e 100 de 10 em 10
*/
int exemplo_2(){
    for(int i = 10; i <= 100; i += 10){
        printf("%d\n", i);
    }
    return 0;
}


/*
Calcula a média das idade de 5 pessoas
*/
int exemplo_3(){
    int numero_pessoas;
    int idade, soma= 0;
    float media;

    printf("Digite número de alunos: ");
    scanf("%d", &numero_pessoas);

    for(int i = 1; i <= numero_pessoas; i++){
        printf("Digite a idade da %dª pessoa: ", i);
        scanf("%d", &idade);
        soma += idade;
    }
    media = (float)soma / numero_pessoas;
    printf("A média das idades é: %.2f\n", media);
    return 0;
}


/*
Apresenta a Tabuada de Multiplicação de um número qualquer
*/
int exemplo_4(){       
    int numero;

    printf("Digite um número para ver sua tabuada: ");
    scanf("%d", &numero);

    for(int i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
    return 0;
}

/*
- (1) Solicitar ao utilizador n números e
- (2) Contar quantos números que estão entre 10 e 20
- (3) e ... sem usar IFs.
*/
int exemplo_5(){
    const int MINIMO = 10; // condição 2
    const int MAXIMO = 20; // limites do problema
    
    int numeroPedidos;     // número de números a inserir;
    int contador = 0;      // contador de números dentro da condição
    int numero;            // leitura do número inserido

    printf("Digite quantos números deseja inserir: ");
    scanf("%d", &numeroPedidos);

    for(int i = 1; i <= numeroPedidos; i++){
        printf("Digite o %dº número: ", i);
        scanf("%d", &numero);
        contador += (int)(numero >= MINIMO && numero <= MAXIMO);
    }
    printf("Total de números entre 10 e 20: %d\n", contador);
    return 0;
}


/*
- (1) Solicitar ao utilizador n números e
- (2) Contar quantos números que estão entre 10 e 20
- (3) e ... sem usar IFs.
*/
int exemplo_6(){
    const int MINIMO = 10; // condição 2
    const int MAXIMO = 20; // limites do problema
    
    int numeroPedidos;     // número de números a inserir;
    int contador = 0;      // contador de números dentro da condição
    int numero;            // leitura do número inserido
    int fora; // ups esqueci-me que era para contar os foras


    printf("Digite quantos números deseja inserir: ");
    scanf("%d", &numeroPedidos);

    for(int i = 1; i <= numeroPedidos; i++){
        printf("Digite o %dº número: ", i);
        scanf("%d", &numero);
        contador += (int)((numero >= MINIMO) * (numero <= MAXIMO));
    }
    fora = numeroPedidos - contador;
    printf("Total de números entre 10 e 20: %d\n", contador);
    printf("Total de números fora do intervalo: %d\n", fora);
    return 0;
}


int main(){
    setlocale(LC_ALL, "Portuguese");

    exemplo_6();

    return 0;
}