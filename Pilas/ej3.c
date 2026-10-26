#include <stdio.h>
#include <stdlib.h>
#include "dstack.h"

int main() {
    NodeDS *DStack;
    createDS(&DStack);

    char expresion_balanceada[] = "{[4+6]*[59+(87*10)]}";
    printf("\nExpresión: %s\n", expresion_balanceada);
    checarExpresion(expresion_balanceada);

    createDS(&DStack);


    char expresion_no_balanceada[] = "{[][[(2*56)+(789-4))}";
    printf("\nExpresión: %s\n", expresion_no_balanceada);
    checarExpresion(expresion_no_balanceada);

    return 0;
}
