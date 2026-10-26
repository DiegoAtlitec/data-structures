#include <stdio.h>
#include "funcionDLists.h"

int main() {
    DList dl;
    createDL(&dl);

    insertAtFirst(&dl, 30);
    insertAtFirst(&dl, 30);
    insertAtFirst(&dl, 20);
    insertAtFirst(&dl, 10);
    insertAtFirst(&dl, 10);
    printf("Despues de insertar elementos al principio:\n");
    printDList(dl);

    insertAtLast(&dl, 40);
    insertAtLast(&dl, 50);
    insertAtLast(&dl, 60);
    insertAtLast(&dl, 60);
    printf("Despues de insertar elementos al final:\n");
    printDList(dl);

    deleteDuplicate(&dl);
    printf("Lista sin elementos duplicados:\n");
    printDList(dl);

    insertAfterElementi(&dl, 15, 2);
    printf("Despues de colocar elemento en la posicion 2:\n");
    printDList(dl);

    deleteFirst(&dl);
    printf("Despues de borrar primer elemento:\n");
    printDList(dl);

    deleteLast(&dl);
    printf("Despues de borrar ultimo elemento:\n");
    printDList(dl);

    printf("Elemento eliminado en la posicion 3: %d\n", deleteElementi(&dl, 3));
    printf("Despues de borrar elemento en la posicion 3:\n");
    printDList(dl);

    printf("Ahora se v a borrar toda la lsita: \n");
    deleteDL(&dl);
    printf("Despues de borrar la lista completa:\n");
    printDList(dl);

    return 0;
}
