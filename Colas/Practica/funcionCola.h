#ifndef FUNCIONCOLA_H
#define FUNCIONCOLA_H

#define SIZE 100

typedef struct {
    int array[SIZE];
    int head;
    int tail;
} squeue;

void create(squeue *sque);
int is_full(squeue *q);
int is_empty(squeue *q);
int enqueue(squeue *q, int e);
int dequeue(squeue *sque);
void printCola(squeue *q);
void atenderClientes(squeue *cola, int hora, int cliente_id, int total_clientes);

#endif
