#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void interElementos(int *b, int *c) {
    int a = *b;
    *b = *c;
    *c = a;
}

void bubbleOrd(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                interElementos(&arr[j], &arr[j + 1]);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d, ", arr[i]);
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

    bubbleOrd(arr, n);

    printf("\nArreglo ordenado:\n ");
    printArray(arr, n);

    free(arr);
}

