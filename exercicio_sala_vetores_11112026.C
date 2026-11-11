#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int j;
    int n;
    int num;
    int repetido;

    printf("Qual o tamanho do vetor?  ");
    scanf("%i", &n);
    int vetor[n]; 

    for(i = 0; i < n; i++) {
        printf("Digite um número inteiro %d: ", i + 1);
        scanf("%i", &num);
        repetido = 0; 
        for(j = 0; j < i; j++) {
            if(vetor[j] == num) {
                repetido = 1; 
                break; 
            }
        }
        if(repetido == 1) {
            printf("O número já foi adicionado ao vetor, tente outra vez.\n");
            i--; 
        } else {
            vetor[i] = num;
        }
    }
    printf("\nVetor final: ");
    for(j = 0; j < n; j++) { 
        printf("%i ", vetor[j]); 
    }
    printf("\n");
    return 0;
}
