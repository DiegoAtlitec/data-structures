#include <stdio.h>
#include <stdlib.h>

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void interElementos(int *b, int *c) {
    int a = *b;
    *b = *c;
    *c = a;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                interElementos(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int menor;
    for (int i = 0; i < n-1; i++) {
        menor = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[menor]) {
                menor = j;
            }
        }
        interElementos(&arr[menor], &arr[i]);
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];
        for (i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void impArr(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamaño del arreglo>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    FILE *file;
    file = fopen("n10m.txt", "r");

    int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    printf("\nArreglo original:\n");
    impArr(arr, n); printf("\n");
    printf("\n");

    int *arr_copia = (int*)malloc(n * sizeof(int));
    copyArray(arr, arr_copia, n);

    bubbleSort(arr, n); printf("\nBubble Sort:\n");
    impArr(arr, n); printf("\n");

    selectionSort(arr, n); printf("\nSelection Sort:\n");
    impArr(arr, n); printf("\n");

    mergeSort(arr, 0, n-1); printf("\nMerge Sort:\n");
    impArr(arr, n); printf("\n");

    insertionSort(arr, n); printf("\nInsertion Sort:\n");
    impArr(arr, n); printf("\n");

    free(arr);
    free(arr_copia);

    return 0;
}
