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
        printf("No se puede asignar memoria.\n");
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
        printf("No se puede asignar memoria.\n");
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

void insertAfterElementi(DList *dli, element ele, int i) {
    nodeDL *aux = searchElementi(*dli, i-1);
    if (aux != NULL) {
        nodeDL *new = (nodeDL*)malloc(sizeof(nodeDL));
        if (new == NULL) {
            printf("No se puede asignar memoria.\n");
            return;
        }
        new->e = ele;
        if (aux->next != NULL) {
            new->next = aux->next;
            (aux->next)->prev = new;
        } else {
            new->next = NULL;
        }
        aux->next = new;
        new->prev = aux;
    } else {
        printf("No se puede agregar.\n");
    }
}

nodeDL* searchElement(DList dli, element ele) {
    nodeDL *aux = dli.first;
    if (isEmptyDL(dli)) {
        printf("Error, lista vacia\n");
        return NULL;
    }
    while (aux != NULL) {
        if (aux->e == ele) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

nodeDL* searchElementi(DList dli, int i) {
    if (isEmptyDL(dli)) {
        printf("Error, lista vacia\n");
        return NULL;
    }
    nodeDL* aux = dli.first;
    int ind = 1;
    while (aux != NULL) {
        if (ind == i) {
            return aux;
        }
        ind++;
        aux = aux->next;
    }
    printf("Error, indice fuera de rango\n");
    return NULL;
}

element deleteFirst(DList *dli) {
    element data;
    if (isEmptyDL(*dli)) {
        printf("Lista vacia.\n");
        return -1;
    } else if (dli->first == dli->last) {
        data = dli->first->e;
        free(dli->first);
        dli->first = NULL;
        dli->last = NULL;
    } else {
        nodeDL *copia = dli->first;
        data = copia->e;
        dli->first = copia->next;
        dli->first->prev = NULL;
        free(copia);
    }
    return data;
}

element deleteLast(DList *dli) {
    if (isEmptyDL(*dli)) {
        printf("Lista vacia.\n");
        return -1;
    }
    element aux = dli->last->e;
    if (dli->first == dli->last) {
        free(dli->last);
        dli->first = NULL;
        dli->last = NULL;
    } else {
        nodeDL *temp = dli->last->prev;
        free(dli->last);
        dli->last = temp;
        dli->last->next = NULL; 
    }
    return aux;
}


element deleteElementi(DList *L, int i) {
    if (isEmptyDL(*L)) {
        printf("Lista vacia.\n");
        return -1;
    }
    
    nodeDL *toDelete = searchElementi(*L, i);
    if (toDelete == NULL) {
        printf("indice fuera de rango.\n");
        return -1;
    }

    element data = toDelete->e;

    if (toDelete->prev == NULL) {
        L->first = toDelete->next;
        if (L->first != NULL) {
            L->first->prev = NULL;
        } else {
            L->last = NULL;
        }
    } else if (toDelete->next == NULL) {
        L->last = toDelete->prev;
        L->last->next = NULL;
    } else {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
    }

    free(toDelete);
    return data;
}

void deleteDuplicate(DList *dli){
    if (isEmptyDL(*dli)) {
        printf("La lista esta vacia.\n");
        return;
    }
    
    nodeDL *aux = dli->first;
    nodeDL *ind = NULL;
    nodeDL *temp = NULL;

    while (aux != NULL) {
        ind = aux->next;
        while (ind != NULL) {
            if (aux->e == ind->e) {
                temp = ind;
                if (ind->next != NULL) {
                    ind->next->prev = ind->prev;
                } else {
                    dli->last = ind->prev;
                }
                ind->prev->next = ind->next;
                ind = ind->next;
                free(temp);
            } else {
                ind = ind->next;
            }
        }
        aux = aux->next;
    }
}


void deleteDL(DList *dli) {
    if (isEmptyDL(*dli)) {
        printf("Lista vacia.\n");
        return;
    }
    nodeDL *aux = dli->first;
    nodeDL *next;
    int ind = 1;
    while (aux != NULL) {
        next = aux->next;
        printf("Elemento %d eliminado %d\n", ind, aux->e);
        free(aux);
        aux = next;
        ind++;
    }
    dli->first = NULL;
    dli->last = NULL;
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