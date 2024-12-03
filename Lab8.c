#include <stdio.h>
#include <stdlib.h>

// Función para contar cuántos subarreglos de tamaño k tienen un promedio >= threshold
int numSubarraysWithAvgThreshold(int *arr, int n, int k, int threshold) {
    int count = 0;  // Variable para contar los subarreglos que cumplen la condición
    int sum = 0;    // Variable para almacenar la suma de los elementos de la ventana
    int target = k * threshold;  // Calculamos el valor objetivo para la suma: k * threshold

    // Calcular la suma inicial de los primeros k elementos (primer subarreglo)
    for (int i = 0; i < k; i++) {
        sum += arr[i];  // Sumamos los primeros k elementos del arreglo
    }

    // Verificamos si el promedio de la primera ventana cumple con el umbral
    if (sum >= target) {
        count++;  // Si la suma cumple con el umbral, incrementamos el contador
    }

    // Usamos la ventana deslizante para calcular las sumas de los siguientes subarreglos
    for (int i = k; i < n; i++) {
        // Actualizamos la suma: agregamos el nuevo elemento (arr[i]) y quitamos el anterior (arr[i - k])
        sum += arr[i] - arr[i - k];
        
        // Si la nueva suma cumple con el umbral, incrementamos el contador
        if (sum >= target) {
            count++;
        }
    }

    // Retornamos el total de subarreglos que cumplen la condición
    return count;
}

int main() {
    int n, k, threshold;  // Variables para el tamaño del arreglo, tamaño del subarreglo y umbral

    // Leer el tamaño del arreglo
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &n);

    // Validar que el tamaño del arreglo sea mayor que 0
    if (n <= 0) {
        printf("El tamano del arreglo debe ser mayor que 0.\n");
        return 1;  // Si no es válido, terminamos el programa con un código de error
    }

    // Crear el arreglo dinámicamente con el tamaño dado por el usuario
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Verificar si la asignación de memoria fue exitosa
    if (arr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;  // Si hay error en la asignación de memoria, terminamos el programa
    }

    // Leer los elementos del arreglo desde la entrada estándar
    printf("Ingrese los elementos del arreglo separados por espacios:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Leer el tamaño del subarreglo (k)
    printf("Ingrese el tamano del sub-arreglo (k): ");
    scanf("%d", &k);

    // Leer el umbral (threshold)
    printf("Ingrese el umbral (threshold): ");
    scanf("%d", &threshold);

    // Validar que el tamaño del subarreglo (k) sea válido
    if (k > n || k <= 0) {
        printf("El tamano del sub-arreglo debe estar entre 1 y %d.\n", n);
        free(arr);  // Liberamos la memoria antes de salir
        return 1;   // Si k es inválido, terminamos el programa con un código de error
    }

    // Validar que el umbral (threshold) sea válido
    if (threshold < 0) {
        printf("El umbral debe ser mayor o igual a 0.\n");
        free(arr);  // Liberamos la memoria antes de salir
        return 1;   // Si threshold es negativo, terminamos el programa con un código de error
    }

    // Llamamos a la función para calcular el número de subarreglos con promedio >= threshold
    int result = numSubarraysWithAvgThreshold(arr, n, k, threshold);
    
    // Imprimimos el resultado
    printf("El numero de sub-arreglos con promedio >= %d es: %d\n", threshold, result);

    // Liberamos la memoria que habíamos asignado dinámicamente para el arreglo
    free(arr);

    return 0;  // Terminamos el programa correctamente
}
