#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para fusionar dos arreglos ordenados
void merge(int* nums1, int m, int* nums2, int n, int* merged) {
    int i = 0, j = 0, k = 0;
    
    // Fusiona los dos arreglos mientras no se hayan procesado todos los elementos de ambos
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];  // Si el elemento en nums1 es menor, lo agregamos al arreglo fusionado
        } else {
            merged[k++] = nums2[j++];  // Si no, agregamos el elemento de nums2
        }
    }
    
    // Si hay elementos restantes en nums1, los agregamos al arreglo fusionado
    while (i < m) {
        merged[k++] = nums1[i++];
    }
    
    // Si hay elementos restantes en nums2, los agregamos al arreglo fusionado
    while (j < n) {
        merged[k++] = nums2[j++];
    }
}

// Función para ordenar un arreglo usando el algoritmo de burbuja (Bubble Sort)
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];  // Intercambia los elementos si están fuera de orden
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Función para calcular la mediana de un arreglo
double findMedian(int* merged, int size) {
    if (size % 2 == 0) {
        // Si el tamaño es par, se devuelve el promedio de los dos valores del medio
        return (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    } else {
        // Si el tamaño es impar, se devuelve el valor central
        return merged[size / 2];
    }
}

int main() {
    int m, n;
    srand(time(0));  // Inicializa la semilla de números aleatorios

    // Solicita el tamaño de los arreglos
    printf("Ingrese la dimension de nums1: ");
    scanf("%d", &m);
    printf("Ingrese la dimension de nums2: ");
    scanf("%d", &n);

    // Asigna memoria dinámicamente para los arreglos
    int* nums1 = (int*)malloc(m * sizeof(int));
    int* nums2 = (int*)malloc(n * sizeof(int));
    int* merged = (int*)malloc((m + n) * sizeof(int));

    // Verifica si la memoria fue asignada correctamente
    if (nums1 == NULL || nums2 == NULL || merged == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Llena los arreglos con números aleatorios entre 1 y 100
    for (int i = 0; i < m; i++) {
        nums1[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < n; i++) {
        nums2[i] = rand() % 100 + 1;
    }

    // Medir el tiempo de ejecución
    clock_t start = clock();

    // Ordena ambos arreglos usando el algoritmo de burbuja
    bubbleSort(nums1, m);
    bubbleSort(nums2, n);

    // Muestra los arreglos ordenados
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

    // Fusiona los dos arreglos ordenados
    merge(nums1, m, nums2, n, merged);
    printf("Arreglo ambos arreglos fusionados: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    // Calcula la mediana
    double median = findMedian(merged, m + n);

    // Finaliza el temporizador
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;  // Calcula el tiempo de ejecución

    // Muestra el resultado
    printf("La mediana es: %.5f\n", median);
    printf("Tiempo de ejecucion: %.5f segundos\n", time_taken);

    // Libera la memoria asignada
    free(nums1);
    free(nums2);
    free(merged);

    return 0;
}
