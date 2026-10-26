//Alumno: González Hernandez Diego
//2BV2

#ifndef TREE_H
#define TREE_H

typedef struct {
    int clave;
    char nombre[100];
} element;

typedef struct nodeT{
    element e;
    struct nodeT *left;
    struct nodeT *right;
} nodeT;

typedef nodeT* Tree;

void insert(Tree *t, Tree le, Tree ri, element ele);
void pre_orden(Tree r);
void post_orden(Tree r);
void en_orden(Tree r);
void remover(Tree *r);
Tree buscar(Tree r, int clave);
#endif
