#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para fusionar dos arreglos
void merge(int* nums1, int m, int* nums2, int n, int* merged) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }
    while (i < m) {
        merged[k++] = nums1[i++];
    }
    while (j < n) {
        merged[k++] = nums2[j++];
    }
}

// Función para ordenar usando el algoritmo de burbuja (Bubble Sort)
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Función para calcular la mediana de dos arreglos fusionados
double findMedian(int* merged, int size) {
    if (size % 2 == 0) {
        // Si el tamaño es par, devuelve el promedio de los dos valores del medio
        return (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    } else {
        // Si es impar, devuelve el valor del medio
        return merged[size / 2];
    }
}

int main() {
    int m, n;
    srand(time(0));  // Inicializar la semilla de números aleatorios

    printf("Ingrese la dimesion de nums1: ");
    scanf("%d", &m);
    printf("Ingrese la dimension de nums2: ");
    scanf("%d", &n);

    // Asignación dinámica de memoria para los arreglos
    int* nums1 = (int*)malloc(m * sizeof(int));
    int* nums2 = (int*)malloc(n * sizeof(int));
    int* merged = (int*)malloc((m + n) * sizeof(int));

    // Verificar que la memoria fue asignada correctamente
    if (nums1 == NULL || nums2 == NULL || merged == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Generar arreglos aleatorios con valores entre 1 y 100
    for (int i = 0; i < m; i++) {
        nums1[i] = rand() % 100 + 1;  // Generar números entre 1 y 100
    }
    for (int i = 0; i < n; i++) {
        nums2[i] = rand() % 100 + 1;  // Generar números entre 1 y 100
    }

    // Medir el tiempo de ejecución
    clock_t start = clock();

    // Ordenar los arreglos
    bubbleSort(nums1, m);
    bubbleSort(nums2, n);

    // Mostrar los arreglos ordenados
    printf("Arreglo nums1 (ordenado): ");
    for (int i = 0; i < m; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("Arreglo nums2 (ordenado): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    // Fusionar los arreglos ordenados
    merge(nums1, m, nums2, n, merged);
    printf("Arreglo ambos arreglos: ");
    for (int i = 0; i < m+n; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    // Calcular la mediana
    double median = findMedian(merged, m + n);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;  // Tiempo en segundos

    printf("La mediana es: %.5f\n", median);
    printf("Tiempo de ejecucion: %.5f en segundos\n", time_taken);

    // Liberar la memoria asignada
    free(nums1);
    free(nums2);
    free(merged);

    return 0;
}