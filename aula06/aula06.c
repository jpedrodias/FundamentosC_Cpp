

#include <stdio.h>
#include <locale.h> // incluido para suportar acentuação

int main() {
    setlocale(LC_ALL, "Portuguese"); // incluido em locale.h para suportar acentuação


    int idade;
    printf("Qual a sua idade? \n");
    scanf("%i", &idade);
    if (idade >= 67) {
        printf("Tem idade para se reformar.\n");
    } else if (idade < 0 || idade > 120) {
        printf("Idade inválida.\n");
    } else {
        printf("Não tem idade para a reforma.\n");
    }
    return 0;
}
