#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char caracter;
    struct no *proximo;
} No;

void inicializa_pilha(No **topo) {
    *topo = NULL;
}

int pilha_vazia(No *topo) {
    return topo == NULL;
}

void empilha(No **topo, char c) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo != NULL) {
        novo->caracter = c;
        novo->proximo = *topo;
        *topo = novo;
    } else {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
}

char desempilha(No **topo) {
    if (!pilha_vazia(*topo)) {
        No *aux = *topo;
        char c = aux->caracter;
        *topo = aux->proximo;
        free(aux);
        return c;
    } else {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
}

int forma_par(char f, char d) {
    switch (f) {
        case ')':
            return d == '(';
        case ']':
            return d == '[';
        case '}':
            return d == '{';
        default:
            return 0;
    }
}

int identifica_formacao(char x[]) {
    No *topo;
    inicializa_pilha(&topo);

    for (int i = 0; x[i] != '\0'; i++) {
        char c = x[i];
        if (c == '(' || c == '[' || c == '{') {
            empilha(&topo, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pilha_vazia(topo) || !forma_par(c, desempilha(&topo))) {
                return 1; // mal formada
            }
        }
    }
    return pilha_vazia(topo) ? 0 : 1; // 0 se bem formada, 1 se mal formada
}

int main() {
    char *expressoes[] = {
        "(a + b) * c",
        "(a + [b * c])",
        "(a + b) * (c + d]",
        "[(a + b) * c]",
        "(a + b] * c)",
        "{[a + b] * (c + d)}"
    };

    for (int i = 0; i < 6; i++) {
        printf("\nExpressao: %s\nRetorno: %d\n", expressoes[i], identifica_formacao(expressoes[i]));
    }

    return 0;
}
