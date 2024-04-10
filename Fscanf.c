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
    struct employ e;
    arquivo = fopen("arquivo.dat", "r");
    if (arquivo == NULL) {
        puts("Não foi possivel abrir o arquivo");
        exit(0);
    }
    while (fscanf(arquivo, "%s %d %f", e.name, e.age, e.salary) != EOF){
        printf("%s %d %0.2f\n", e.name, e.age, e.salary);
    }
    fclose(arquivo);

    return 0;
}