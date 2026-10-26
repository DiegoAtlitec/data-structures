#include <stdio.h>
#include <stdlib.h>
#include "funcionLista.h"

int main() {
    lista myList;
    createL(&myList);

    insertAtFirst(&myList, 30);
    insertAtFirst(&myList, 20);
    insertAtFirst(&myList, 15);
    insertAtFirst(&myList, 10);

    InsertAtEnd(&myList, 40);
    InsertAtEnd(&myList, 45);
    InsertAtEnd(&myList, 50);

    printf("Lista con elementos:");
    printList(&myList);

    printf("Lista despues de insertar el 25 despues de la posicion 3:\n");
    insertAfteri(&myList, 25, 3);
    printList(&myList);

    deleteFirst(&myList);
    printf("Lista despues de borrar el primer elemento:");
    printList(&myList);

    deleteLast(&myList);
    printf("Lista dsepues de borrar el ultimo elemento:");
    printList(&myList);

    deleteElementi(&myList, 3);
    printf("iLsta despues de borrar el nodo con la posicion 3:");
    printList(&myList);

    printf("Buscando el elemento 28...\n");
    searchElement(&myList, 28);
    printf("Buscando el elemento 40...\n");
    searchElement(&myList, 40);

    printf("Buscando elemento en la posicoin 2...\n");
    searchi(&myList, 2);

    printf("\nBuscando elemento en la posicoin 6...\n");
    searchi(&myList, 6);

    printf("\nBuscando elemento en la posicoin 10...\n");
    searchi(&myList, 10);

    printf("\nLista antes borrarla:");
    printList(&myList);

    printf("Borrando la toda lista...\n");
    deleteList(&myList);
    printf("Lista despues de borrrarla:\n");
    printList(&myList);

    return 0;
}
