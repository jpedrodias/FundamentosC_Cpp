/*
1 - Peça ao utilizador para inserir uma letra e determine se é vogal ou consoante (considere apenas letras minúsculas para simplificação).
 
Atenção:
Variável do tipo CHAR
Na identificação da variável use “%c”
Exemplo: scanf(" %c", &letra);
 
Pode converter todas as letras para minúsculas usando o tolower(letra)
Exemplo:
letra = tolower(letra); // Converte para minúscula
#include <ctype.h> // Biblioteca para usar tolower()
*/

#include <stdio.h>
#include <locale.h> // incluido para suportar acentuação
#include <ctype.h>

int main() {
    setlocale(LC_ALL, "Portuguese"); // incluido em locale.h para suportar acentuação

    char letra;

    printf("Insira uma letra minúscula: "); 
    scanf(" %c", &letra);
    letra = tolower(letra);

    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
        printf("A letra %c é uma vogal.\n", letra);

    } else if (letra >= 'a' && letra <= 'z') {
        printf("A letra %c é uma consoante.\n", letra);

    } else {
        printf("O caractere %c não é uma letra.\n", letra);
    }

    return 0;
}