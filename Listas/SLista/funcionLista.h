typedef int element;

typedef struct NodeL {
    element e;
    struct NodeL *next;
} nodeL;

typedef struct lista {
    nodeL *first;
} lista;

void createL(lista *li);
int isEmpty(lista l);
nodeL *searchi(lista *li, int i);
nodeL *searchElement(lista *li, element e);
void insertAtFirst(lista *li, element ele);
void insertAfteri(lista *li, element e, int i);
void InsertAtEnd(lista *li, element ele);
int deleteFirst(lista *li);
int deleteLast(lista *list);
void deleteElementi(lista *li, int i);
void deleteList(lista *li);
void printList(lista *li);