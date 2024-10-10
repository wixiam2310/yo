#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct{
    double x;
    double y;
}punto;
punto generar(){
    punto p;
    p.x = ((double)rand() / RAND_MAX) * 200 - 100;  
    p.y = ((double)rand() / RAND_MAX) * 200 - 100;
    return p;
}
double distancia(punto p1, punto p2){
    return sqrt(pow(p1.x - p2.x, 2) +(p1.y - p2.y, 2));
}
void puntocer(punto* puntos, int n, punto* p1, punto* p2, double* dismin){
*dismin=distancia(puntos[0], puntos[1]);
*p1=puntos[0];
*p2=puntos[1];
for(int i=0; i<n-1; i++){
    for(int j=0; j<n;j++){
        double dis=distancia(puntos[i], puntos[j]);
        if(dis<*dismin){
            *dismin=dis;
            *p1=puntos[i];
            *p2=puntos[j];
        }
    }
}
}

int main(){
 int n[] = {10, 100, 1000, 10000, 100000};
    srand(time(NULL)); 

    for (int k = 0; k < 5; k++) {
        printf("n = %d\n", n[k]);
        punto* puntos = (punto*)malloc(n[k] * sizeof(punto));
        for (int i = 0; i < n[k]; i++) {
            puntos[i] = generar();
        }

        punto p1, p2;
        double dismin;
        clock_t inicio = clock();
        puntocer(puntos, n[k], &p1, &p2, &dismin);
        clock_t fin = clock();
        double tiempoeje = (double)(fin - inicio) / CLOCKS_PER_SEC;
        printf("Los puntos mas cercanos son: (%.2f, %.2f) y (%.2f, %.2f)\n", p1.x, p1.y, p2.x, p2.y);
        printf("Distancia minima: %.6f\n", dismin);
        printf("Tiempo de ejecucion: %.6f segundos\n\n", tiempoeje);
        free(puntos);
    }
    return 33;
}