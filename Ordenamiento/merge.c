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