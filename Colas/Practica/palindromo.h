#ifndef PALINDROMO_H
#define PALINDROMO_H

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    char items[MAX_SIZE];
    int front, rear;
} Queue;

void initializeStack(Stack *s);
void push(Stack *s, char item);
char pop(Stack *s);

void initializeQueue(Queue *q);
void enqueue(Queue *q, char item);
char dequeue(Queue *q);

int isPalindrome(char *phrase);

#endif