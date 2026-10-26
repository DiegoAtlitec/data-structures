#include "dstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_emptyDS(NodeDS *ds) {
    if (ds == NULL)
        return 1;
    else
        return 0;
}

void createDS(NodeDS **ds) {
    *ds = NULL;
}

void push(NodeDS **ds, element ele) {
    NodeDS *new;
    new = (NodeDS *)malloc(sizeof(NodeDS));
    new->e = ele;
    new->next = *ds;
    *ds = new;
}

element pop(NodeDS **ds) {
    NodeDS *nodeaux;
    element elementaux;
    if (is_emptyDS(*ds)) {
        printf("Error de underflow\n");
        elementaux = -1;
    } else {
        nodeaux = *ds;
        *ds = nodeaux->next;
        elementaux = nodeaux->e;
        free(nodeaux);
    }
    return elementaux;
}

void printStack(NodeDS *pila, const char *nombre) {
    printf("Pila %s:\n", nombre);
    int stackSize = 0;
    NodeDS *current = pila;

    while (current != NULL) {
        stackSize++;
        current = current->next;
    }

    element *stackArray = (element *)malloc(stackSize * sizeof(element));

    current = pila;
    int index = 0;
    while (current != NULL) {
        stackArray[index++] = current->e;
        current = current->next;
    }

    for (int i = stackSize - 1; i >= 0; i--) {
        printf("%d", stackArray[i]);
    }

    free(stackArray);
    printf("\n");
}

void suma(char *num1, char *num2) {
    NodeDS *pilaNum1 = NULL;
    NodeDS *pilaNum2 = NULL;
    NodeDS *resultado = NULL;

    for (int i = 0; i < strlen(num1); i++) {
        push(&pilaNum1, num1[i] - '0');
    }

    for (int i = 0; i < strlen(num2); i++) {
        push(&pilaNum2, num2[i] - '0');
    }

    printStack(pilaNum1, "Uno");
    printStack(pilaNum2, "Dos");

    int carry = 0;
    while (!is_emptyDS(pilaNum1) || !is_emptyDS(pilaNum2) || carry) {
        int sum = carry;
        if (!is_emptyDS(pilaNum1)) {
            sum += pop(&pilaNum1);
        }
        if (!is_emptyDS(pilaNum2)) {
            sum += pop(&pilaNum2);
        }
        push(&resultado, sum % 10);
        carry = sum / 10;
    }

    printf("Suma:\n");
    while (!is_emptyDS(resultado)) {
        printf("%d", pop(&resultado));
    }
    printf("\n");
}
