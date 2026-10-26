//Alumno: González Hernandez Diego
//2BV2

#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main() {
    Tree t = NULL;
    element materia1 = {5780, "Calculo"};
    element materia2 = {4090, "Programación"};
    element materia3 = {6890, "Economía"};
    element materia4 = {2098, "Algoritmos y estructuras de datos"};
    element materia5 = {5990, "Algebra lineal"};
    element materia6 = {4789, "Comunicación oral y escrita"};
    element materia7 = {7865, "Bases de datos"};

    insert(&t, NULL, NULL, materia1);
    insert(&t, NULL, NULL, materia2);
    insert(&t, NULL, NULL, materia3);
    insert(&t, NULL, NULL, materia4);
    insert(&t, NULL, NULL, materia5);
    insert(&t, NULL, NULL, materia6);
    insert(&t, NULL, NULL, materia7);

    Tree resultado;

    printf("\n");

    resultado = buscar(t, 2098);
    if (resultado != NULL) {
        printf("Materia con clave %d encontrada: %s\n", resultado->e.clave, resultado->e.nombre);
    } else {
        printf("Materia con clave %d no encontrada.\n", 2098);
    }

    resultado = buscar(t, 6987);
    if (resultado != NULL) {
        printf("Materia con clave %d encontrada: %s\n", resultado->e.clave, resultado->e.nombre);
    } else {
        printf("Materia con clave %d no encontrada.\n", 6987);
    }

    resultado = buscar(t, 4789);
    if (resultado != NULL) {
        printf("Materia con clave %d encontrada: %s\n", resultado->e.clave, resultado->e.nombre);
    } else {
        printf("Materia con clave %d no encontrada.\n", 4789);
    }

    printf("\nRecorrido pre-orden:\n");
    pre_orden(t);    
    printf("\nRecorrido en-orden:\n");
    en_orden(t);    
    printf("\nRecorrido post-orden:\n");
    post_orden(t);

    printf("\n");

    remover(&t);

    return 0;
}
