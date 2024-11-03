#include <stdio.h>

// Función que calcula la máxima cantidad de agua que se puede contener
int maxArea(int* height, int n) {
    int max_area = 0;         // Variable para almacenar el área máxima
    int left = 0;              // Puntero al inicio del arreglo
    int right = n - 1;         // Puntero al final del arreglo
    
    // Mientras los punteros no se crucen
    while (left < right) {
        // Calcula el área actual
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        
        // Actualiza el área máxima si la actual es mayor
        if (area > max_area) {
            max_area = area;
        }
        
        // Mueve el puntero que apunta a la altura menor
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_area;
}

int main() {
    // Ejemplo 1
    int height1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n1 = sizeof(height1) / sizeof(height1[0]);
    int result1 = maxArea(height1, n1);
    printf("Ejemplo 1:\nInput: height = [1,8,6,2,5,4,8,3,7]\n");
    printf("Salida: Maxima cantidad de agua que se puede contener: %d\n\n", result1);
    
    // Ejemplo 2
    int height2[] = {1, 1};
    int n2 = sizeof(height2) / sizeof(height2[0]);
    int result2 = maxArea(height2, n2);
    printf("Ejemplo 2:\nInput: height = [1,1]\n");
    printf("Salida: Maxima cantidad de agua que se puede contener: %d\n", result2);
    
    return 0;
}