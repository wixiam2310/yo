#include <stdio.h>

void generarTrianguloPascal(int numRows) {
    int triangulo[numRows][numRows];

    // Inicializamos todas las posiciones del triángulo en 0
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
            triangulo[i][j] = 0;
        }
    }

    // Generamos las filas del triángulo
    for (int i = 0; i < numRows; i++) {
        triangulo[i][0] = 1; // El primer elemento de cada fila es 1
        for (int j = 1; j <= i; j++) {
            triangulo[i][j] = triangulo[i - 1][j - 1] + triangulo[i - 1][j];
        }
    }

    // Mostramos el triángulo
    printf("Triángulo de Pascal con %d filas:\n", numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangulo[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numRows;
    printf("Ingrese el numero de filas del triangulo de Pascal (1 <= numRows <= 30): ");
    scanf("%d", &numRows);

    if (numRows < 1 || numRows > 30) {
        printf("Numero de filas fuera de rango. Intente nuevamente con un valor entre 1 y 30.\n");
        return 1;
    }

    generarTrianguloPascal(numRows);
    return 0;
}