//Tamayo Escalante Eduardo Osmar
//Gonzalez Hernandez Diego 

#include <stdio.h>
#define MAX_SIZE 100 

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void inStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Error: Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

void printStack(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

void copyStack(Stack *fuente, Stack *destino) {
    Stack tempStack; 

    inStack(&tempStack);

    while (!isEmpty(destino)) {
        pop(destino);
    }

    while (!isEmpty(fuente)) {
        int item = pop(fuente);
        push(&tempStack, item);
    }

    while (!isEmpty(&tempStack)) {
        int item = pop(&tempStack);
        push(destino, item);
        push(fuente, item);
    }
}

int main() {
    Stack fuente, destino;

    inStack(&fuente);
    inStack(&destino);

    push(&fuente, 1);
    push(&fuente, 2);
    push(&fuente, 3);

    printf("Contenido de la pila original:\n");
    printStack(&fuente);

    copyStack(&fuente, &destino);

    printf("Contenido de la pila copia:\n");
    if (isEmpty(&destino)) {
        printf("La pila copia está vacía\n");
    } else {
        printf("La pila copia no está vacía\n");
    }

    printf("Contenido de la pila copia despues de copiar:\n");
    printStack(&destino);

    return 0;
}


