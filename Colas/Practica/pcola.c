#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcionCola.h"

int main() {
    srand(time(NULL));

    squeue cola;
    create(&cola);

    int total_clientes = rand() % 81 + 20; 
    atenderClientes(&cola, 480, 1, total_clientes);

    return 0;
}
