#include <stdio.h>
#include "funcionCola.h"

int main() {
    squeue sq1, sq2;
    create(&sq1); 
    create(&sq2); 

    printf("Agregando elementos a la cola sq1...\n");
    enqueue(&sq1, 10);
    enqueue(&sq1, 20);
    enqueue(&sq1, 30);
    printf("Elementos agregados a la cola sq1.\n");

    printf("Contenido de la cola sq1: \n");
    printCola(&sq1);

    printf("Copiando elementos de sq1 a sq2...\n");
    copyCola(&sq1, &sq2);
    printf("Elementos copiados de sq1 a sq2.\n");

    printf("Contenido de la cola sq2: \n");
    printCola(&sq2);

    printf("Eliminando un elemento de la cola sq2...\n");
    dequeue(&sq2);
    printf("Elemento eliminado de la cola sq2.\n");

    printf("Contenido de la cola sq2 después de eliminar un elemento: \n");
    printCola(&sq2);

    return 0;
}
