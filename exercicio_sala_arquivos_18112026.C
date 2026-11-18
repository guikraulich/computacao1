#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAM 100

int main() {
    FILE *arquivo;
    char palavra[MAX_TAM];
    char linha[MAX_TAM];
    char letra;
    int contador = 0;

    arquivo = fopen("palavras.txt", "w");
    if (arquivo == NULL) {
        perror("Ero ao criar o arquivo palavras.txt");
        return 1;
    }

    printf("Digite palavras (digite 'fim' para encerrar):\n");

    while (1) {
        printf("> ");
        if (fgets(palavra, sizeof(palavra), stdin) == NULL) {
            break;
        }


        palavra[strcspn(palavra, "\n")] = '\0';


        if (strcmp(palavra, "fim") == 0) {
            break;
        }


        if (strlen(palavra) > 0) {
            fprintf(arquivo, "%s\n", palavra);
        }
    }

    if (fclose(arquivo) != 0) {
        perror("Erro ao fechar o arquivo apos a escrita");
        return 1;
    }

    printf("\nDigite a letra inicial que deseja buscar: ");
    scanf(" %c", &letra); 
    letra = tolower((unsigned char)letra);

    arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo palavras.txt para leitura");
        return 1;
    }

    while (fscanf(arquivo, "%99s", linha) == 1) {
        if (tolower((unsigned char)linha[0]) == letra) {
            contador++;
        }
    }

    if (fclose(arquivo) != 0) {
        perror("Erro ao fechar o arquivo apos a leitura");
        return 1;
    }

    printf("\nNumero de palavras que comecam com '%c': %d\n", letra, contador);

    return 0;
}
