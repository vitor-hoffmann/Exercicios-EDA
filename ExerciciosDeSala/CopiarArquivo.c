#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *original, *copia;
    char ch;
    original = fopen("arquivo.txt", "r");
    if (original == NULL){
        printf("Erro ao abrir o arquivo");
        exit(0);
    }
    copia = fopen("novoarquivo.txt","w");
    if (copia == NULL){
        printf("Erro ao gravar dados");
        exit(0);
    }
    while(1){
        ch = fgetc(original);
        if (ch == EOF) break;      
        fputc(ch, copia);  
    }
    return 0;
}