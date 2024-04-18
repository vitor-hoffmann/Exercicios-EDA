#include <stdio.h>
#include <stdlib.h>

int main(){

    int *v = malloc(sizeof(int)*2);
    free(v);
    return 0;
}