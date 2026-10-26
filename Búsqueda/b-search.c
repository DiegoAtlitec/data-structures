#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* genArr(int n, int min, int max) {
    int* arreglo = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % (max - min + 1) + min;
    }
    return arreglo;
}

int busquedaBinaria(int* arr, int n, int num) {
    int ini = 0;
    int fin = n - 1;
    while (ini <= fin) {
        int medio = (fin - ini) / 2;
        if (num == arr[medio]) {
            return medio; 
        }
        else if (num < arr[medio] ) {
            fin = medio - 1;
        } else {
            ini = medio +1;
        }
    }
    return -1; 
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int* arreglo = genArr(n, 10000, 15000);

    printf("arreglo generado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }    
    
    printf("\n");

    int num;
    printf("numero a buscar: ");
    scanf("%d", &num);

    int posicion = busquedaBinaria(arreglo, n, num);

    if (posicion != -1) {
        printf("%d esta en la posición %d del arreglo.\n", num, posicion);
    } else {
        printf("%d no esta en el arreglo.\n", num);
    }

    free(arreglo);
    return 0;
}
