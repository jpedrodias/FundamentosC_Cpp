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
    int ascii;

    do {

        printf("Insira uma letra minúscula: "); 
        scanf(" %c", &letra);
        ascii = (unsigned int)letra; // garante valor 0..255
        printf("A letra %c corresponde ao valor ASCII: %d\n", letra, ascii);
        if (ascii < 97 || ascii > 122) {
            printf("Caractere inválido. Por favor, insira uma letra minúscula (a-z).\n");
        }

    } while (ascii < 97 || ascii > 122);

    
    if (ascii == 97 || ascii == 101 || ascii == 105 || ascii == 111 || ascii == 117) {
        printf("A letra %c é uma vogal.\n", letra);

    } else if (ascii >= 98 && ascii <= 122) {
        printf("A letra %c é uma consoante.\n", letra);

    } else {
        printf("O caractere %c não é uma letra.\n", letra);
    }


    return 0;
}