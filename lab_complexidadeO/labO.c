#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "codigos.c"

int *gera_vet_aleatorio(int pn){
    int *pvet = (int *)malloc(sizeof(int)*pn);
    int pind;
    for(pind=0;pind<pn;pind++)
        pvet[pind] = rand();
    return pvet;
}

int main(){
    FILE *input, *esforco;
    int n, *vetor, *vetBubb, *vetIns;
    double eB = 0, eI = 0;
    char opcao;
    srand(time(NULL));

    input = fopen("testes.txt", "r");
    printf("Digite sua opcao: T, R, S\n");
    scanf("%c", &opcao);
    while (opcao != 'S' || opcao != 's'){
        if (opcao == 'T' || opcao == 't'){
            esforco = fopen("esforcocompucaional.txt", "w");
            while (fscanf(input, "%d", &n) != EOF){
                vetor = gera_vet_aleatorio(n);
                vetBubb = (int *)malloc(sizeof(int)*n);
                vetIns = (int *)malloc(sizeof(int)*n);

                memcpy(vetBubb, vetor, n * sizeof(int));
                memcpy(vetIns, vetor, n * sizeof(int));

                eB = (double)bubble(n, vetBubb) / n;

                eI = (double)insertion(n, vetIns) / n;

                fprintf(esforco, "[%d, %.2f, %.2f]\n", n, eB, eI);
            }
            fclose(esforco);
        }
        else if (opcao == 'R' || opcao == 'r') {
            
        }
    }
    free(vetBubb);
    free(vetIns);
    free(vetor);
    fclose(input);
    return 0;
}