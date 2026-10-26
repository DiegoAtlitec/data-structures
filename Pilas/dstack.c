#include "dstack.h"
#include <stdio.h>
#include <stdlib.h>

int is_emptyDS(NodeDS *ds) {
    return ds == NULL;
}

void createDS(NodeDS **ds) {
    *ds = NULL;
}

int checarBalance(const char *expresion) {
    int parentesis = 0;
    int corchetes = 0;
    int llaves = 0;

    for (int i = 0; expresion[i] != '\0'; i++) {
        switch (expresion[i]) {
            case '(':
                parentesis++;
                break;
            case ')':
                parentesis--;
                break;
            case '[':
                corchetes++;
                break;
            case ']':
                corchetes--;
                break;
            case '{':
                llaves++;
                break;
            case '}':
                llaves--;
                break;
        }
    }

    if (parentesis == 0 && corchetes == 0 && llaves == 0) {
        printf("La expresión está balanceada.\n");
        return 1;
    } else {
        printf("La expresión NO está balanceada.\n");
        if (parentesis > 0) {
            printf("Faltan %d ).\n", parentesis);
        } else if (parentesis < 0) {
            printf("Faltan %d (.\n", -parentesis);
        }
        if (corchetes > 0) {
            printf("Faltan %d ].\n", corchetes);
        } else if (corchetes < 0) {
            printf("Faltan %d [.\n", -corchetes);
        }
        if (llaves > 0) {
            printf("Faltan %d }.\n", llaves);
        } else if (llaves < 0) {
            printf("Faltan %d {.\n", -llaves);
        }
        return 0;
    }
}

void checarExpresion(const char *expresion) {
    if (checarBalance(expresion)) {
        printf("La expresión está balanceada.\n");
    } else {
        printf("La expresión NO está balanceada.\n");
    }
}