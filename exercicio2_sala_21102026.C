#include <stdio.h>
//A função que recebe parâmetro inteiro (ano) e retorna 1 ou 0
int ehBissexto (int ano){
    
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)){
        return 1;
    } else {
        return 0;
    }
}

//Função que analisa e mostra se o ano digitado é bissexto
int main()
{
    int ano;
    printf("Digite algum ano: ");
    scanf("%i", &ano);
    if (ehBissexto(ano) == 1){
        printf("O ano %i é bissexto", ano);
    } else {
        printf("O ano %i não é bissexto", ano);
    }
    return 0;
}
