#include <stdio.h>
#include <locale.h>

/*
- (1) Solicitar ao utilizador n números e
- (2) Contar quantos números que estão entre 10 e 20
- (3) e ... sem usar IFs.
*/
int main(){
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
