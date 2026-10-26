#include <stdio.h>
#include <stdlib.h>
#include "funcionLista.h"

void createL(lista *li) {
    li->first = NULL;
}

int isEmpty(lista l) {
    if (l.first == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insertAtFirst(lista *li, element ele) {
    nodeL *newNode = (nodeL *)malloc(sizeof(nodeL));
    newNode->e = ele;
    newNode->next = NULL;
    if (li->first == NULL) {
        newNode->next = newNode;
    } else {
        nodeL *last = li->first;
        while (last->next != li->first) {
            last = last->next;
        }
        newNode->next = li->first;
        last->next = newNode;
    }
    li->first = newNode;
}

void InsertAtEnd(lista *li, element ele) {
    if (isEmpty(*li)) {
        insertAtFirst(li, ele);
    } else {
        nodeL *last = li->first;
        while (last->next != li->first) {
            last = last->next;
        }
        nodeL *newNode = (nodeL *)malloc(sizeof(nodeL));
        newNode->e = ele;
        newNode->next = li->first;
        last->next = newNode;
    }
}

void insertAfteri(lista *li, element e, int i) {
    nodeL *aux = searchi(li, i  );
    if (aux != NULL) {
        nodeL *newNode = (nodeL *)malloc(sizeof(nodeL));
        newNode->e = e;
        newNode->next = aux->next;
        aux->next = newNode;
    } else {
        printf("No existe el nodo.\n");
    }
}

nodeL *searchi(lista *li, int i) {
    nodeL *aux = li->first;
    int cont = 1;
    while (aux != NULL) {
        if (cont == i) {
            printf("Nodo con la posicion %d encontrado. El elmeento que hay en el nodo es: %d.", i, aux->e);
            return aux;
        }
        cont++;
        aux = aux->next;
    }
    printf("No se encontro ningún nodo en la posicion %d.\n", i);
    return NULL;
}

nodeL *searchElement(lista *li, element e) {
    if (isEmpty(*li)) {
        printf("Lista vacia, no se puede buscar elemento.\n");
        return NULL;
    }

    nodeL *aux = li->first;
    do {
        if (aux->e == e) {
            printf("Elemento %d encontrado en la lista.\n", e);
            return aux;
        }
        aux = aux->next;
    } while (aux != li->first);

    printf("El elemento %d no se encuentra en la lista.\n", e);
    return NULL;
}

int deleteFirst(lista *li) {
    if (isEmpty(*li)) {
        printf("Error, la lista vacia.\n");
        return -1;
    }

    nodeL *aux = li->first;
    nodeL *last = li->first;
    while (last->next != li->first) {
        last = last->next;
    }
    if (aux == last) {
        li->first = NULL;
    } else {
        li->first = aux->next;
        last->next = li->first;
    }
    free(aux);
    return 0;
}

int deleteLast(lista *li) {
    if (isEmpty(*li)) {
        printf("Error, la lista vacia.\n");
        return -1;
    }
    nodeL *Q = li->first;
    nodeL *T = NULL;
    while (Q->next != li->first) {
        T = Q;
        Q = Q->next;
    }
    if (T == NULL) {
        li->first = NULL;
    } else {
        T->next = li->first;
    }
    int e = Q->e;
    free(Q);
    return e;
}

void deleteElementi(lista *li, int i) {
    if (isEmpty(*li)) {
        printf("Error, lista vacia.\n");
        return;
    }

    nodeL *aux = li->first;
    nodeL *prev = NULL;
    int count = 1;

    if (i == 1) {
        while (aux->next != li->first) {
            aux = aux->next;
        }
        if (aux == li->first) {
            free(aux);
            li->first = NULL;
            return;
        } else {
            aux->next = li->first->next;
            free(li->first);
            li->first = aux->next;
            return;
        }
    }
    do {
        if (count == i) {
            prev->next = aux->next;
            free(aux);
            return;
        }
        prev = aux;
        aux = aux->next;
        count++;
    } while (aux != li->first);
    printf("Error, indice fuera de rango.\n");
}

void deleteList(lista *li) {
    while (!isEmpty(*li)) {
        deleteFirst(li);
    }
}

void printList(lista *li) {
    printf("\n");
    if (isEmpty(*li)) {
        printf("Lista vacia.\n");
        return;
    }
    nodeL *aux = li->first;
    do {
        printf("%d ", aux->e);
        aux = aux->next;
    } while (aux != li->first);
    printf("\n");
}