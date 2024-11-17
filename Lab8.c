#include <stdio.h>
#include <stdlib.h>

int numSubarraysWithAvgThreshold(int *arr, int n, int k, int threshold) {
    int count = 0;
    int sum = 0;
    int target = k * threshold;

    // Calcular la suma inicial de la primera ventana
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    // Verificar si la primera suma cumple con el requisito
    if (sum >= target) {
        count++;
    }

    // Usar ventana deslizante para calcular las sumas subsecuentes
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k]; // Actualizar la suma
        if (sum >= target) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, k, threshold;

    // Leer tamaño del arreglo
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &n);

    // Validar tamaño del arreglo
    if (n <= 0) {
        printf("El tamano del arreglo debe ser mayor que 0.\n");
        return 1;
    }

    // Crear el arreglo dinámicamente
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Leer los elementos del arreglo
    printf("Ingrese los elementos del arreglo separados por espacios:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Leer k y threshold
    printf("Ingrese el tamano del sub-arreglo (k): ");
    scanf("%d", &k);

    printf("Ingrese el umbral (threshold): ");
    scanf("%d", &threshold);

    // Validar entrada
    if (k > n || k <= 0) {
        printf("El tamano del sub-arreglo debe estar entre 1 y %d.\n", n);
        free(arr);
        return 1;
    }

    if (threshold < 0) {
        printf("El umbral debe ser mayor o igual a 0.\n");
        free(arr);
        return 1;
    }

    // Calcular el resultado
    int result = numSubarraysWithAvgThreshold(arr, n, k, threshold);
    printf("El numero de sub-arreglos con promedio >= %d es: %d\n", threshold, result);

    // Liberar memoria
    free(arr);

    return 0;
}
