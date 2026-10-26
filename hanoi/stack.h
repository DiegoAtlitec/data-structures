#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack();
void push(Stack* stack, int data);
int pop(Stack* stack);
int isEmpty(Stack* stack);
void freeStack(Stack* stack);

#endif
