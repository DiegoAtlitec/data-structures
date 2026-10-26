#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void interElementos(int *b, int *c) {
    int a = *b;
    *b = *c;
    *c = a;
}

void selectionSort(int arr[], int n) {
    int i, j, menor;

    for (i = 0; i < n-2; i++) {
        menor = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[menor])
                menor = j;
        }
        interElementos(&arr[menor], &arr[i]);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Tamanio: "); scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    printf("\nArreglo no ordenado:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1001;
        printf("%d, ", arr[i]);
    }
    
    printf("\n");

    selectionSort(arr, n);

    printf("Array ordenado usando Selection Sort:\n");
    printArray(arr, n);
    return 0;
}
