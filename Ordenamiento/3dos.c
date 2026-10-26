#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void mergeSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int mit = inicio + (fin - inicio) / 2;
        mergeSort(arr, inicio, mit);
        mergeSort(arr, mit + 1, fin);

        int i, j, k;
        int tizq = mit - inicio + 1;
        int tder = fin - mit;
        int I[tizq], D[tder];

        for (i = 0; i < tizq-1; i++) {
            I[i] = arr[inicio + i];
        }
        for (j = 0; j < tder-1; j++) {
            D[j] = arr[mit + i + 1];
        }
        i = j = 0; 
        k = inicio;

        while (i < tizq && j < tder) {
            if (I[i] <= D[j]) {
                arr[k] = I[i];
                i++;
            } else {
                arr[k] = D[j];
                j++;
            }
            k++;
        }
        while (i < tizq) {
            arr[k] = I[i];
            i++;
            k++;
        }
        while (j < tder) {
            arr[k] = D[j];
            j++;
            k++;
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, act, j;
    for (i = 1; i < n; i++) {
        act = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > act) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = act;
    }
}

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);

    FILE *file;
    file = fopen("n10m.txt", "r");

    int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    int *arr_copia = (int*)malloc(n * sizeof(int));

    clock_t start, end;

    copyArray(arr_copia, arr, n);
    start = clock();
    mergeSort(arr, 0, n-1);
    end = clock();
    printf("Tiempo de ejecución de Merge Sort: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    copyArray(arr_copia, arr, n);
    start = clock();
    insertionSort(arr, n);
    end = clock();
    printf("Tiempo de ejecución de Insertion Sort: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    copyArray(arr, arr_copia, n);
    start = clock();
    bubbleSort(arr, n);
    end = clock();
    printf("Tiempo de ejecución de Bubble Sort: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    copyArray(arr_copia, arr, n);
    start = clock();
    selectionSort(arr, n);
    end = clock();
    printf("Tiempo de ejecución de Selection Sort: %f segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    free(arr);
    free(arr_copia);

    return 0;
}
