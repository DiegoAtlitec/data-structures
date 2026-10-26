#include "palindromo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void initializeStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Error: La pila esta llena\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: La pila esta vacia\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, char item) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Error: La cola esta llena\n");
        return;
    }
    q->items[++(q->rear)] = item;
}

char dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Error: La cola esta vacia\n");
        return '\0';
    }
    return q->items[(q->front)++];
}

int isPalindrome(char *phrase) {
    int length = strlen(phrase);
    Stack stack;
    Queue queue;
    initializeStack(&stack);
    initializeQueue(&queue);

    for (int i = 0; i < length; i++) {
        if (!isspace(phrase[i])) {
            push(&stack, tolower(phrase[i]));
            enqueue(&queue, tolower(phrase[i]));
        }
    }

    while (stack.top != -1 && queue.front <= queue.rear) {
        if (pop(&stack) != dequeue(&queue)) {
            return 0; 
        }
    }

    return 1;
}