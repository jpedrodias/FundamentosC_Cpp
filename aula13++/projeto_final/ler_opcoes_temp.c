
int ler_opcoes(struct Menu menu, const char* mensagem) {
    char input[3];
    int valido;
    int opcao_encontrada = -1;

    do {
        printf("%s", mensagem);
        scanf("%2s", input);

        // Verificar se o input corresponde a alguma opcao_key
        valido = 0;
        for (int i = 0; i < menu.opcoes_length; i++) {
            if (strcmp(input, menu.opcoes_key[i]) == 0) {
                valido = 1;
                opcao_encontrada = atoi(input); // Converter para int
                break;
            }
        }

        if (!valido) {
            printf("Opção inválida! Escolha uma das opções do menu.\n");
        }
    } while (!valido);

    return opcao_encontrada;
} // fim ler_opcoes