#include <stdio.h>

int AckermannRecursivo(int m, int n){
    if (m == 0){
        return n+1;
    }
    if (m > 0 && n == 0){
        return AckermannRecursivo(m-1,1);
    }
    if (m > 0 && n > 0){
        return AckermannRecursivo(m-1,AckermannRecursivo(m,n-1));
    }
}

int main(){
    int m, n;
    printf("Digite dois numeros inteiros e positivos: ");
    scanf("%d %d", &m, &n);
    if (m < 0 || n < 0){
        printf("Digite um numero inteiro positivo!");
    }
    else{
        printf("O valor da funcao de Ackermann para m = %d e n = %d e %d\n", m, n, AckermannRecursivo(m, n));
    }
    return 0;
}