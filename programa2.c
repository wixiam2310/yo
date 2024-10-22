#include <stdio.h>
void cambio(int V) {
    int monedas[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n = sizeof(monedas) / sizeof(monedas[0]);
    
    printf("El cambio para %d es: ", V);
      // Recorremos las denominaciones
    for (int i = 0; i < n; i++) {
        // Mientras la denominación actual sea menor o igual que V
        while (V >= monedas[i]) {
            V -= monedas[i];  // Restamos el valor de la moneda/billete
            printf("%d ", monedas[i]);  // Imprimimos la moneda/billete utilizado
        }
    }
    printf("\n");
}

int main() {
    int V;
    printf("Ingresa cuanto quiere de cambio: ");
    scanf("%d", &V);
    cambio(V); 
    return 33;
}