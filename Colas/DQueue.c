#include "DQueue.h"

void create(QueueD *Q){
	Q->tail=Q->head=NULL;
}

void enqueue(QueueD *Q,element ele){
	NodeQD *new;
	new=(NodeQD*)malloc(sizeof(NodeQD));
	new->e=ele;
	if(isEmpty(*Q)){
		Q->head=new;
		Q->head->next=NULL;
	}else{
		new->next=NULL;
		Q->tail->next=new;
	}
	Q->tail=new;
}

element dequeue(QueueD *Q){
	element aux;
	NodeQD *n;
	if(!isEmpty(*Q)){
		aux=Q->head->e;
		n=Q->head;
		Q->head=Q->head->next;
		free(n);
		
	}else{
		printf("Cola vacia");
		aux=-1;
	}
	return aux;
}

int isEmpty(QueueD Q){
	if(Q.head==NULL)
		return 1;
	else
		return 0;
}

void deleteQD(QueueD *Q){
	NodeQD *n;
	while(!isEmpty(*Q)){
		printf("\nDelete %d",dequeue(Q));
	}
	Q->tail=NULL;
}

void delElement(QueueD *Q, element ele) {
	if (isEmpty(*Q)) {
        printf("La cola está vacía.\n");
        return;
    }
    NodeQD *aux = Q->head;
    NodeQD *prev = NULL;
    int found = 0;

    while (aux != NULL) {
        if (aux->e == ele) {
            NodeQD *toDelete = aux;
            if (prev == NULL) {  // Si estamos eliminando el primer nodo
                Q->head = aux->next;
            } else {
                prev->next = aux->next;
            }
            if (aux->next == NULL) {  // Si estamos eliminando el último nodo
                Q->tail = prev;
            }
            aux = aux->next;
            free(toDelete);
            found = 1;
        } else {
            prev = aux;
            aux = aux->next;
        }
    }
    if (!found) {
        printf("El elemento %d no se encontró en la cola.\n", ele);
    }
}

void enqueue_order(QueueD *Q, element ele) {
    NodeQD *new = (NodeQD*)malloc(sizeof(NodeQD));
    new->e = ele;
    new->next = NULL;

    if (isEmpty(*Q)) {
        // Si la cola está vacía, insertamos el primer elemento
        Q->head = Q->tail = new;
    } else if (ele <= Q->head->e) {
        // Si el elemento es menor o igual que el primer elemento, insertamos al inicio
        new->next = Q->head;
        Q->head = new;
    } else if (ele >= Q->tail->e) {
        // Si el elemento es mayor o igual que el último elemento, insertamos al final
        Q->tail->next = new;
        Q->tail = new;
    } else {
        // Insertar el elemento en la posición ordenada
        NodeQD *current = Q->head;
        while (current->next != NULL && current->next->e < ele) {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
}

void delDuplicates(QueueD *Q) {
    if (isEmpty(*Q)) return;
    
    NodeQD *aux = Q->head;

    while (aux != NULL && aux->next != NULL) {
        if (aux->e == aux->next->e) {
            NodeQD *toDelete = aux->next;
            aux->next = aux->next->next;
            if (toDelete == Q->tail) {
                Q->tail = aux;
            }
            free(toDelete);
        } else {
            aux = aux->next;
        }
    }
}

void printCola(QueueD *Q) {
    if (is_empty(q)) {
        printf("La cola está vacía.\n");
        return;
    }
    
    int i = q->head;
    while (i != q->tail) {
        printf("%d ", q->array[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
