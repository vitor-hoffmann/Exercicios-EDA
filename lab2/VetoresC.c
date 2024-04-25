#include <stdio.h>
#include <stdlib.h>

int *CriaVetInt(int qnt){
    int *ptr = (int *)malloc(sizeof(int)*qnt);
    if (ptr == NULL){
        exit(1);
    }
    return ptr;
}

float *CriaVetFloat(int qnt){
    float *ptr = (float *)malloc(sizeof(float)*qnt);
    if (ptr == NULL){
        exit(1);
    }
    return ptr;
}