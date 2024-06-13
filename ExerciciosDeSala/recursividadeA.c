#include <stdio.h>

long int somavet(int *a, int qtde) {
    if (qtde == 0)
        return 0;
    else
        return a[qtde - 1] + somavet(a, qtde - 1);
}

int stringIgual(char *a, char *b){
    if (*a == '\0' && *b == '\0'){
        return 1;
    }
    if (*a == *b){
        return stringIgual(a + 1, b + 1);
    }
    return 0;
}

int fib(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    if (n > 1){
        return fib(n-1)+fib(n-2);
    }
}

int main(){

    int vet[10] = {1,2,3,4,5,6,7,8,9,10};
    long int resultado = somavet(vet, 10);
    printf("%d\n", resultado);
    char a[] = "hello";
    char b[] = "world";
    printf("%d\n", stringIgual(a,b));
    int n = 30;
    printf("%d\n", fib(n));
    return 0;
}