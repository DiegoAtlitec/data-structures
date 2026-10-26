//Alumno: González Hernandez Diego
//2BV2

#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void insert(Tree *r, Tree le, Tree ri, element ele) {
    if (*r == NULL) {
        Tree new = (Tree)malloc(sizeof(struct nodeT));
        new->e = ele;
        new->left = le;
        new->right = ri;
        *r = new;
    } else {
        if (ele.clave < (*r)->e.clave) {
            insert(&((*r)->left), le, ri, ele);
        } else {
            insert(&((*r)->right), le, ri, ele);
        }
    }
}

void pre_orden(Tree r) {
    if (r != NULL) {
        printf("Clave: %d, Nombre: %s\n", r->e.clave, r->e.nombre);
        pre_orden(r->left);
        pre_orden(r->right);
    }
}

void post_orden(Tree r) {
    if (r != NULL) {
        post_orden(r->left);
        post_orden(r->right);
        printf("Clave: %d, Nombre: %s\n", r->e.clave, r->e.nombre);
    }
}

void en_orden(Tree r) {
    if (r != NULL) {
        en_orden(r->left);
        printf("Clave: %d, Nombre: %s\n", r->e.clave, r->e.nombre);
        en_orden(r->right);
    }
}

void remover(Tree *r) {
    if (*r != NULL) {
        remover(&(*r)->left);
        remover(&(*r)->right);
        free(*r);
    }
}

Tree buscar(Tree r, int clave) {
    if (r == NULL || r->e.clave == clave) {
        return r;}
    if (clave < r->e.clave) {
        return buscar(r->left, clave);
      } else {
        return buscar(r->right, clave);}
}
