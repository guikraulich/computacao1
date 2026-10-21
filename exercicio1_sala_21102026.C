#include <stdio.h>

//Função que calcula o IMC
float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

// Função para verificar o IMC
char verificarSituacao(float peso, float altura) {
    // Chamada de fução de cálculo do IMC
    float imc = calcularIMC(peso, altura);
// Loop para atribuição do caractere em função do IMC
    if (imc < 18.5f) {
        return 'B';
    } else if (imc < 25.0f) {
        return 'N';
    } else if (imc < 30.0f) {
        return 'S';
    } else if (imc < 35.0f) {
        return 'O';
    } else if (imc < 40.0f) {
        return '1';
    } else {
        return '2';
    }
}
//Função main que chama as outras e mostra os resultados
int main() {
    float peso, altura;

    printf("Digite valores menores ou iguais a zero para sair.\n\n");

    while (1) {
        printf("Digite o peso (em kg): ");
        scanf("%f", &peso);
        
        printf("Digite a altura (em metros): ");
        scanf("%f", &altura);

        //Programa para encerrar quando peso ou altura <=0
        if (peso <= 0 || altura <= 0) {
            printf("\nNúmero invalido, programa encerrando...\n");
            break;
        }

        // Chamadas de função
        float imcCalculado = calcularIMC(peso, altura);
        char situacao = verificarSituacao(peso, altura);

        // Printando o resultado
        printf("O seyu IMC: %.2f \n Classificação: '%c'\n", imcCalculado, situacao);
    }

    return 0;
}
