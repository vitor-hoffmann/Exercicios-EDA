#include <stdio.h>

int somaDigitos(int num){
    if (num == 0){
        return 0;
    }
    else{
        return (num % 10) + somaDigitos(num / 10);
    }
}

int main(){
    printf("%d\n", somaDigitos(911));
    
    return 0;
}