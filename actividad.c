#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estructura para almacenar el beneficio y peso de cada artículo
struct Item {
    int profit, weight;
};

// Función de comparación para ordenar artículos según la relación profit/weight
int cmp(const void* a, const void* b) {
    struct Item* itemA = (struct Item*)a;
    struct Item* itemB = (struct Item*)b;
    double r1 = (double)itemA->profit / itemA->weight;
    double r2 = (double)itemB->profit / itemB->weight;
    return r1 > r2 ? -1 : 1;
}

// Función principal que resuelve el problema de la mochila fraccionaria
double fractionalKnapsack(int W, struct Item arr[], int N) {
    // Ordenar los artículos por la relación profit/weight en orden descendente
    qsort(arr, N, sizeof(struct Item), cmp);

    double finalValue = 0.0;

    // Iterar sobre todos los artículos
    for (int i = 0; i < N; i++) {
        // Si se puede agregar el artículo completo, agregarlo
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].profit;
        }
        // Si no se puede agregar el artículo completo, agregar una fracción de él
        else {
            finalValue += arr[i].profit * ((double)W / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    // Definir los artículos (20 en total)
    struct Item arr[] = {
        {10, 5}, {40, 4}, {30, 6}, {50, 3}, {35, 8},
        {70, 9}, {20, 2}, {80, 7}, {55, 5}, {60, 6},
        {90, 7}, {15, 3}, {45, 8}, {25, 4}, {50, 9},
        {10, 3}, {70, 6}, {85, 5}, {65, 9}, {30, 4}
    };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Prueba para W = 50
    int W1 = 50;
    clock_t start1 = clock();
    double maxProfit1 = fractionalKnapsack(W1, arr, N);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    printf("Capacidad W = %d: Maximo Profit = %.2f, Tiempo de ejecucion = %.6f segundos\n", W1, maxProfit1, time1);

    // Prueba para W = 80
    int W2 = 80;
    clock_t start2 = clock();
    double maxProfit2 = fractionalKnapsack(W2, arr, N);
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    printf("Capacidad W = %d: Maximo Profit = %.2f, Tiempo de ejecucion = %.6f segundos\n", W2, maxProfit2, time2);

    return 0;
}