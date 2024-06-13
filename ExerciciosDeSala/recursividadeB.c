#include <stdio.h>
#include <string.h>

int somaDigitos(int num){
    if (num == 0){
        return 0;
    }
    else{
        return (num % 10) + somaDigitos(num / 10);
    }
}

int multSB(int a, int b){
    if (b == 0){
        return 0;
    }
    else {
        return a + multSB(a, b - 1);
    }
}

int potencia(int x, int n){
    if (n == 0 || x == 0){
        return 1;
    }
    if (n == 1){
        return x;
    }
    else{
        return x * potencia(x,n-1);
    }
}

int palindromo(char *str){
    int len = strlen(str);
    
}

int main(){
    printf("%d\n", somaDigitos(911));
    printf("%d\n", multSB(2,3));
    printf("%d\n", potencia(2,4));
    printf("%d\n", palindromo("ola"));
    return 0;
}