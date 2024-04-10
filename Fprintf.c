#include <stdio.h>

int main(){

    FILE *arquivo;
    struct employ{
        char name[20];
        int age;
        float salary;
    };
    arquivo = fopen("arquivo.dat", "a+");
    struct employ b1 = {"Vitor", 20, 1200.50};
    fprintf(arquivo,"%s %d %.2f", b1.name, b1.age, b1.salary);
    fclose(arquivo);

    return 0;
}