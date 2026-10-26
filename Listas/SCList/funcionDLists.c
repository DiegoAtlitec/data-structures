#include "funcionDLists.h"
#include <stdio.h>
#include <stdlib.h>

void createDL(DList *dli) {
    dli->first = NULL;
    dli->last = NULL;
}

int isEmptyDL(DList dli) {
    if(dli.first == NULL && dli.last == NULL){
        return 1;
    }else{
        return 0;
    }
}

void insertAtFirst(DList *dli, element ele) {
    nodeDL *Newnode = (nodeDL*)malloc(sizeof(nodeDL));
    if (Newnode == NULL) {
        return;
    }
    Newnode->e = ele;
    Newnode->prev = NULL;

    if (isEmptyDL(*dli)) {
        Newnode->next = NULL;
        dli->first = Newnode;
        dli->last = Newnode;
    } else {
        Newnode->next = dli->first;
        dli->first->prev = Newnode;
        dli->first = Newnode;
    }
}

void insertAtLast(DList *dli, element ele) {
    nodeDL *Newnode = (nodeDL*)malloc(sizeof(nodeDL));
    if (Newnode == NULL) {
        return;
    }
    Newnode->e = ele;
    Newnode->next = NULL;
    if (isEmptyDL(*dli)) {
        dli->first = Newnode;
        dli->last = Newnode;
        Newnode->prev = NULL;
    } else {
        Newnode->prev = dli->last;
        dli->last->next = Newnode;
        dli->last = Newnode;
    }
}

void deleteDuplicate(DList *dli){
    if (isEmptyDL(*dli)) {
        printf("La lista esta vacia.\n");
        return;
    }
    
    nodeDL *aux = dli->first;
    nodeDL *index = NULL;
    nodeDL *temp = NULL;

    while (aux != NULL) {
        index = aux->next;
        while (index != NULL) {
            if (aux->e == index->e) {
                temp = index;
                if (index->next != NULL) {
                    index->next->prev = index->prev;
                } else {
                    dli->last = index->prev;
                }
                index->prev->next = index->next;
                index = index->next;
                free(temp);
            } else {
                index = index->next;
            }
        }
        aux = aux->next;
    }
}

void printDList(DList dli) {
    if (isEmptyDL(dli)) {
        printf("La lista esta vacia.\n");
        return;
    }

    nodeDL *aux = dli.first;
    printf("Lista: ");
    while (aux != NULL) {
        printf("%d ", aux->e);
        aux = aux->next;
    }
    printf("\n");
}