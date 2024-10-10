#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Estructura para representar un punto
typedef struct {
    int x, y;
} Point;

// Función para comparar los puntos según la coordenada X
int compareX(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// Función para comparar los puntos según la coordenada Y
int compareY(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// Función para calcular la distancia entre dos puntos
float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// Función que encuentra la distancia mínima entre un conjunto de puntos de tamaño n
float bruteForce(Point P[], int n) {
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

// Encuentra la distancia mínima en una lista de puntos ordenados por la coordenada Y
float stripClosest(Point strip[], int size, float d) {
    float min = d;  // Guardamos el valor de d

    qsort(strip, size, sizeof(Point), compareY);  // Ordenamos por Y

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

// Una función recursiva para encontrar la distancia mínima
float closestUtil(Point P[], int n) {
    // Si hay menos de 3 puntos, usamos la fuerza bruta
    if (n <= 3)
        return bruteForce(P, n);

    // Encuentra el punto medio
    int mid = n / 2;
    Point midPoint = P[mid];

    // Divide en dos subarrays
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);

    // Encuentra la menor distancia
    float d = fmin(dl, dr);

    // Construye el arreglo de puntos en la franja
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j++] = P[i];

    // Encuentra la distancia mínima en la franja
    return fmin(d, stripClosest(strip, j, d));
}

// La función principal que encuentra la menor distancia entre los puntos
float closest(Point P[], int n) {
    qsort(P, n, sizeof(Point), compareX);  // Ordena los puntos según X
    return closestUtil(P, n);
}

// Función para generar puntos aleatorios
void generar_puntos_aleatorios(Point* P, int n) {
    for (int i = 0; i < n; i++) {
        P[i].x = rand() % 200 - 100;  // Genera un número aleatorio en el rango [-100, 100]
        P[i].y = rand() % 200 - 100;  // Genera un número aleatorio en el rango [-100, 100]
    }
}

int main() {
    srand(time(NULL)); // Inicializa la semilla para números aleatorios

    // Definición de los valores de n
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        Point* P = malloc(n * sizeof(Point)); // Reserva memoria para los puntos
        if (P == NULL) {
            fprintf(stderr, "Error al asignar memoria\n");
            return 1;
        }

        generar_puntos_aleatorios(P, n); // Genera los puntos aleatorios

        clock_t start = clock(); // Inicia el temporizador
        float min_distance = closest(P, n); // Llama a la función para encontrar la menor distancia
        clock_t end = clock(); // Finaliza el temporizador

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // Calcula el tiempo de ejecución
        printf("Para n=%d: La distancia mas corta es %.6f | Tiempo de ejecucion: %.6f segundos\n", n, min_distance, time_taken);

        free(P); // Libera la memoria asignada
    }

    return 0;
}