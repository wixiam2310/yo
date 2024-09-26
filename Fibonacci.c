#include <stdio.h>
#include <time.h>
#include <limits.h>  // Para obtener el valor máximo de int

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 0;
    double duracion;
    clock_t inicio, fin;

    printf("Calculando numeros de Fibonacci y sus tiempos de ejecucion:\n");

    while (1) {
        inicio = clock(); // Iniciar temporizador
        int resultado = fibonacci(n);
        fin = clock(); // Detener temporizador

        duracion = (double)(fin - inicio) / CLOCKS_PER_SEC; // Calcular duración en segundos

        // Verificar si el resultado se ha corrompido (es negativo o excede el rango)
        if (resultado < 0 || resultado > INT_MAX) {
            printf("Error: Fibonacci(%d) ha excedido el rango permitido del tipo int.\n", n);
            break;
        }

        printf("Fibonacci(%d) = %d, Tiempo tomado: %.6f segundos\n", n, resultado, duracion);

        // Para evitar que se ejecuten números que tomen mucho tiempo
        if (duracion > 1.0) { // Si toma más de 1 segundo
            printf("Fibonacci(%d) tomo mas de 1 segundo en calcularse.\n", n);
        }

        n++;
    }

    return 0;
}
