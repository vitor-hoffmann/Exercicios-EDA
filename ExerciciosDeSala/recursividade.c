#include <stdio.h>

int fat(int x){
    if (x == 1){
        return 1;
    }
    else{
        return x * fat(x-1);
    }
}

int main(){
    int num;
    scanf("%d", &num);
    printf("fatorial: %d", fat(num));
    return 0;
}