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

nodeL *searchElement(lista *li, element e) {
    nodeL *aux = li->first;
    while (aux != NULL) {
        if (aux->e == e) {
            printf("Elemento %d encontrado en la lista.\n", e);
            return aux;
        }
        aux = aux->next;
    }
    printf("El elemento %d no se encuentra en la lista.\n", e);
    return NULL;
}

nodeL *searchi(lista *li, int i) {
    nodeL *aux = li->first;
    int cont = 1;
    while (aux != NULL) {
        if (cont == i) {
            printf("Nodo con la posicion %d encontrado. El elemeton que hay en el nodo es: %d.\n", i, aux->e);
            return aux;
        }
        cont++;
        aux = aux->next;
    }
    printf("No se encontró ningún nodo en la posicion %d.\n", i);
    return NULL;
}

void insertAtFirst(lista *li, element ele) {
    nodeL *newNode;
    newNode = (nodeL *)malloc(sizeof(nodeL));
    newNode->e = ele;
    newNode->next = li->first;
    li->first = newNode;
}

void insertAfteri(lista *li, element e, int i) {
    nodeL *aux = searchi(li, i);
    if (aux != NULL) {
        nodeL *newNode = (nodeL *)malloc(sizeof(nodeL));
        newNode->e = e;
        newNode->next = aux->next;
        aux->next = newNode;
    } else {
        printf("No existe el nodo.\n");
    }
}

void InsertAtEnd(lista *li, element ele) {
    if (isEmpty(*li)) {
        insertAtFirst(li, ele);
    } else {
        nodeL *last = li->first;
        while (last->next != NULL) {
            last = last->next;
        }
        nodeL *newNode = (nodeL *)malloc(sizeof(nodeL));
        newNode->e = ele;
        newNode->next = NULL;
        last->next = newNode;
    }
}

int deleteFirst(lista *li) {
    if (isEmpty(*li)) {
        printf("Error, la lista vacia.\n");
        return -1;
    }

    nodeL *aux = li->first;
    li->first = aux->next;
    free(aux);

    return 0;
}

int deleteLast(lista *list) {
    nodeL *Q, *T;
    element e = -1;
    Q = list->first;
    if (isEmpty(*list)) {
        printf("Error, la lista vacia.\n");
        return e;
    }
    if (Q->next == NULL) {
        e = Q->e;
        free(Q);
        list->first = NULL;
        return e;
    }
    while (Q->next->next != NULL) { 
        Q = Q->next;
    }
    T = Q->next; 
    e = T->e; 
    free(T); 
    Q->next = NULL; 
    return e;
}

void deleteList(lista *li) {
    nodeL *list_p = li->first;
    while (!isEmpty(*li)) {
        li->first = li->first->next;
        free(list_p);
        list_p = li->first;
    }
}

void deleteElementi(lista *li, int i) {
    if (isEmpty(*li)) {
        printf("Error, lista vacia.\n");
        return;
    }

    if (i == 1) {
        deleteFirst(li);
        return;
    }

    nodeL *prev = searchi(li, i-1);
    if (prev == NULL || prev->next == NULL) {
        printf("Error, indice fuera de rango.\n");
        return;
    }

    nodeL *temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

void printList(lista *li) {
    printf("\n");
    nodeL *aux = li->first;
    while (aux != NULL) {
        printf("%d ", aux->e); 
        aux = aux->next;
    }
    printf("\n");
}