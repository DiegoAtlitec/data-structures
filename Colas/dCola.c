#include <stdio.h>
#include "DQueue.h"

int main() {
    QueueD q;
    create(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 10);
    enqueue(&q, 30);
    enqueue(&q, 10);

    printf("Cola antes de eliminar:\n");
    printCola(&q);

    removeOccurrences(&q, 10);

    printf("Cola después de eliminar las ocurrencias de 10:\n");
    printCola(&q);

    return 0;
}