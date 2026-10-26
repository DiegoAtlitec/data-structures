#include <stdio.h>
#include "funcionCola.h"

void create(squeue *sque) {
    sque->head = 0;
    sque->tail = 0;
    for (int i = 0; i < SIZE; ++i) {
        sque->array[i] = 0;
    }
}

int is_empty(squeue *q) {
    return (q->head == q->tail);
}

int is_full(squeue *q) {
    return ((q->tail + 1) % SIZE == q->head);
}

int enqueue(squeue *q, int e) {
    if (is_full(q)) {
        printf("La cola esta llena. No se puede agregar mas elementos.\n");
        return -1;
    }
    q->array[q->tail] = e;
    q->tail = (q->tail + 1) % SIZE;
    return 0;
}


int dequeue(squeue *sque) {
    if (is_empty(sque)) {
        printf("La cola está vacia. No se puede hacer dequeue.\n");
        return -1; 
    }
    int dequeued_element = sque->array[sque->head];
    if (sque->head == sque->tail) {
        create(sque);
    } else {
        sque->head = (sque->head + 1) % SIZE;
    }
    return dequeued_element;
}

void copyCola(squeue *source, squeue *destination) {
    if (is_empty(source)) {
        printf("La cola fuente está vacia, no hay nada que copiar.\n");
        return;
    }

    if (is_full(destination)) {
        printf("La cola destino esta llena, no se pueden copiar mas elementos.\n");
        return;
    }

    destination->head = 0;
    destination->tail = 0;

    int i = source->head;
    while (i != source->tail) {
        enqueue(destination, source->array[i]);
        i = (i + 1) % SIZE;
    }
}

void printCola(squeue *q) {
    if (is_empty(q)) {
        printf("La cola está vacía.\n");
        return;
    }
    
    int i = q->head;
    while (i != q->tail) {
        printf("%d ", q->array[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

