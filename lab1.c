#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

const wchar_t mapa_acentos[][2] = {
    { L'á', L'a' }, { L'à', L'a' }, { L'ã', L'a' }, { L'â', L'a' },
    { L'é', L'e' }, { L'è', L'e' }, { L'ẽ', L'e' }, { L'ê', L'e' },
    { L'í', L'i' }, { L'ì', L'i' }, { L'ĩ', L'i' }, { L'î', L'i' },
    { L'ó', L'o' }, { L'ò', L'o' }, { L'õ', L'o' }, { L'ô', L'o' },
    { L'ú', L'u' }, { L'ù', L'u' }, { L'ũ', L'u' }, { L'û', L'u' },
    { L'ç', L'c' }
};

void word2vec(const char *txtentrada){
    char ch;
    char words[1000][50];
    int word_count = 0;
    FILE *saida, *entrada, *ordenadas, *saidacorreta;
    entrada = fopen(txtentrada, "r");
    saida = fopen("ordenadas.txt", "w");
    if (entrada == NULL || saida == NULL){
        printf("Erro ao abrir ou criar o arquivo!");
        exit(0);
    }
    while(1){
        ch = fgetc(entrada);
        if (ch == EOF) break;
        else if (ch == '.' || ch == '-' || ch == ','){
            continue;
        }
        else if (ch >= 'A' && ch <= 'Z'){
            ch += 32;
            fputc(ch, saida);
        }
        else{
            fputc(ch, saida);
        }
    }
    fclose(entrada);
    fclose(saida);
    ordenadas = fopen("ordenadas.txt", "r");
    saidacorreta = fopen("arquivocompleto.txt", "w");
    while (fscanf(ordenadas, "%s", words[word_count]) != EOF) {
        if (strlen(words[word_count]) > 3) {
            int is_duplicate = 0;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(words[word_count], words[i]) == 0) {
                    is_duplicate = 1;
                    break;
                }
            }
            if (!is_duplicate) {
                fprintf(saidacorreta, "%s\n", words[word_count]);
                word_count++;
            }
        }
}
    fclose(saidacorreta);
    fclose(ordenadas);
}

int main(){ 
    word2vec("arquivo.dat");
    return 0;
}
