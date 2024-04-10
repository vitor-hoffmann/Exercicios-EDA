#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arquivo;
    char ch;
    struct employ{
        char name[20];
        int age;
        float salary;
    };

    arquivo = fopen("arquivo.dat", "r");
    if (arquivo == NULL){
        printf("Não foi possivel abrir o arquivo");
        exit(0);
    }
    while(1){
        ch = fgetc(arquivo);
        if (ch == EOF) exit(0);
        printf("%c", ch);
    }

    return 0;
}