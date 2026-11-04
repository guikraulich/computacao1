#include <stdio.h>
#include <math.h>

    int calcula_raizes(float a, float b, float c, float *x1, float *x2){
        
        float delta;
        delta = (b*b)-4*a*c;
        *x1 = (-b+sqrt (delta))/2*a;
        *x2 = (-b-sqrt(delta))/2*a;
        return (*x1 , *x2);
    }

int main()
{
    float a, b, c,*x1,*x2;
    
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("a = %.2f\n", a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("b = %.2f\n", b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);
    printf("c = %.2f\n\n", c);
    
    if(a == 0){
        printf("Valor de a inválido, encerrando");
    } else{
        int status = calcula_raizes(a, b, c, x1, x2);
        printf("X1 = %.2f\n", *x1);
        printf("X2 = %.2f", *x2);
    }
    
    
    return 0;
}
