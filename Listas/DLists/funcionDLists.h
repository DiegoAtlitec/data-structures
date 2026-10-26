#ifndef FUNCIONDLISTS_H
#define FUNCIONDLISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct nodeDL {
    struct nodeDL *prev;
    struct nodeDL *next;
    element e;
} nodeDL;

typedef struct DList {
    nodeDL *first;
    nodeDL *last;
} DList;

void createDL(DList *dli);
int isEmptyDL(DList dli);
void insertAtFirst(DList *dli, element ele);
void insertAtLast(DList *dli, element ele);
void insertAfterElementi(DList *dli, element ele, int i);
nodeDL* searchElement(DList dli, element ele);
nodeDL* searchElementi(DList dli, int i);
element deleteFirst(DList *dli);
element deleteLast(DList *dli);
element deleteElementi(DList *L, int i);
void deleteDuplicate(DList *dli);
void deleteDL(DList *dli);
void printDList(DList dli);

#endif
