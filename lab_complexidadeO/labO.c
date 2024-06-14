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
    FILE *input, *esforco, *media;
    int n, *vetor, *vetBubb, *vetIns;
    double eB = 0, eI = 0;
    char opcao;
    srand(time(NULL));

    input = fopen("testes2.txt", "r");
    while (1){
        printf("Digite sua opcao: T, R, S\n");
        scanf("%c", &opcao);
        getchar();
        if (opcao == 'T' || opcao == 't'){
            esforco = fopen("esforcocompucaional.txt", "w");
            rewind(input);
            while (fscanf(input, "%d", &n) != EOF){
                vetor = gera_vet_aleatorio(n);
                vetBubb = (int *)malloc(sizeof(int)*n);
                vetIns = (int *)malloc(sizeof(int)*n);

                memcpy(vetBubb, vetor, n * sizeof(int));
                memcpy(vetIns, vetor, n * sizeof(int));

                eB = (double)bubble(n, vetBubb) / n;

                eI = (double)insertion(n, vetIns) / n;

                fprintf(esforco, "[%d, %.2f, %.2f]\n", n, eB, eI);
                free(vetBubb);
                free(vetIns);
                free(vetor);
            }
            fclose(esforco);
        }
        else if (opcao == 'R' || opcao == 'r') {
            int count = 0;
            double totalEB = 0, totalEI = 0;
            double melhorEB = 1e9, piorEB = -1e9;
            double melhorEI = 1e9, piorEI = -1e9;

            media = fopen("esforcocompucaional.txt", "r");
            if (media == NULL) {
                printf("Erro ao abrir o arquivo de esforço computacional.\n");
                return 1;
            }

            while (fscanf(media, "[%d, %lf, %lf]\n", &n, &eB, &eI) != EOF) {
                totalEB += eB;
                totalEI += eI;

                if (eB < melhorEB) melhorEB = eB;
                if (eB > piorEB) piorEB = eB;
                if (eI < melhorEI) melhorEI = eI;
                if (eI > piorEI) piorEI = eI;

                count++;
            }
            fclose(media);

            if (count > 0) {
                printf("Dados eB: Media = %.2f, Melhor Caso = %.2f, Pior Caso = %.2f\n",
                    totalEB / count, melhorEB, piorEB);
                printf("Dados eI: Media = %.2f, Melhor Caso = %.2f, Pior Caso = %.2f\n",
                    totalEI / count, melhorEI, piorEI);
            } else {
                printf("Nenhum dado encontrado.\n");
            }
        }
        else if (opcao == 'S' || opcao == 's'){
            fclose(input);
            free(vetBubb);
            free(vetIns);
            free(vetor);
            exit(0);
        }
    }
    return 0;
}