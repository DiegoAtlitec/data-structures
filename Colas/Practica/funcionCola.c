//Alumnos: 
//Gonzalez Hernandez Diego
//Tamayo Escalante Eduardo Osmar



#include <stdio.h>
#include <stdlib.h>
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
        printf("La cola esta llena. No se pueden agregar mas elementos.\n");
        return -1;
    }
    q->array[q->tail] = e;
    q->tail = (q->tail + 1) % SIZE;
    return 0;
}

int dequeue(squeue *sque) {
    if (is_empty(sque)) {
    printf("La cola esta vacía. No se puede hacer dequeue.\n");
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

void atenderClientes(squeue *cola, int hora, int cliente_id, int total_clientes) {
    if (hora >= 960 || total_clientes <= 0) {
        if (total_clientes > 0) {
            printf("Se dejo de atender en el cliente: %d. Faltaron por atender %d clientes.\n", cliente_id, total_clientes);
        } else {
            printf("Todos los clientes han sido atendidos.\n");
        }
        return;
    }

    int asunto = rand() % 5 + 1;
    enqueue(cola, asunto);

    int minutos_atencion = rand() % 15 + 1;
    printf("Cliente ID: %d,\n", cliente_id);
    printf("\tAsunto: ");
    switch(asunto) {
        case 1:
            printf("Compra de alimentos,\n");
            break;
        case 2:
            printf("Devolución,\n");
            break;
        case 3:
            printf("Cambio,\n");
            break;
        case 4:
            printf("Dudas,\n");
            break;
        case 5:
            printf("Otros,\n");
            break;
    }
    printf("\tHora inicio: %02d:%02d,\n", hora / 60, hora % 60);
    
    int hora_fin_atencion = hora + minutos_atencion;
    printf("\tHora fin: %02d:%02d\n", hora_fin_atencion / 60, hora_fin_atencion % 60);

    dequeue(cola);
    atenderClientes(cola, hora_fin_atencion, cliente_id + 1, total_clientes - 1);
}
