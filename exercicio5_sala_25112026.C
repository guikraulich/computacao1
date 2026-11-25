#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq1;
    arq1 = fopen("notas.csv", "w");
    
    if (arq1 == NULL) {
        printf("Erro ao criar o arquivo\n");
        return 1;
    }

    fprintf(arq1, "Notas da disciplina INF71A ao final de 2024/1\n");
    fprintf(arq1, "Luisa Fernanda, 7.8, 4.4, 6.5\n");
    fprintf(arq1, "Pedro Henrique, 2.2, 9.5, 8.0\n");
    fprintf(arq1, "Vitor Colatusso, 5.4, 10, 5.5\n");
    fprintf(arq1, "Agatha Helena, 5.6, 7.7, 9.0\n");

    fclose(arq1);

    FILE *arq2;
    arq2 = fopen("notas.csv", "r");
    
    if (arq2 == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    char linha[200];
    char *pedaco;
    char nome[100];
    float n1, n2, n3, media;
    float soma_geral = 0;
    int cont = 0;

    fgets(linha, 200, arq2);

    while (fgets(linha, 200, arq2) != NULL) {
        if (strlen(linha) > 2) {
            pedaco = strtok(linha, ",");
            strcpy(nome, pedaco);

            pedaco = strtok(NULL, ",");
            n1 = atof(pedaco);

            pedaco = strtok(NULL, ",");
            n2 = atof(pedaco);

            pedaco = strtok(NULL, ",");
            n3 = atof(pedaco);

            media = (n1 + n2 + n3) / 3.0;
            printf("Nome: %s - Media: %.2f\n", nome, media);

            soma_geral = soma_geral + media;
            cont++;
        }
    }

    float media_turma;
    media_turma = soma_geral / cont;
    printf("\nMedia da turma: %.2f\n", media_turma);

    fclose(arq2);

    return 0;
}
