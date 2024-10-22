#include <stdio.h>
#include <stdlib.h>

// Definición de un nodo de lista vinculada
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar en la lista vinculada
struct Nodo* insertarEnLista(struct Nodo* cabeza, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    if (!cabeza) return nuevoNodo;  // Si la lista está vacía, devuelve el nuevo nodo.
    
    struct Nodo* actual = cabeza;
    while (actual->siguiente) {  // Recorre hasta el final de la lista.
        actual = actual->siguiente;
    }
    actual->siguiente = nuevoNodo;  // Añade el nuevo nodo al final de la lista.
    return cabeza;
}

// Función para imprimir una lista vinculada
void imprimirLista(struct Nodo* cabeza) {
    while (cabeza) {
        printf("%d ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("\n");
}

// Función para fusionar dos listas vinculadas
struct Nodo* fusionarListas(struct Nodo* l1, struct Nodo* l2) {
    // Nodo temporal para almacenar la lista fusionada
    struct Nodo cabeza;
    struct Nodo* cola = &cabeza;  // Cola de la lista fusionada
    cola->siguiente = NULL;

    // Comparar nodos y fusionar
    while (l1 && l2) {
        if (l1->dato < l2->dato) {
            cola->siguiente = l1;  // Enlaza el nodo de l1
            l1 = l1->siguiente;  // Avanza en l1
        } else {
            cola->siguiente = l2;  // Enlaza el nodo de l2
            l2 = l2->siguiente;  // Avanza en l2
        }
        cola = cola->siguiente;  // Avanza en la cola
    }

    // Si quedan nodos en alguna de las listas
    if (l1) {
        cola->siguiente = l1;  // Enlaza el resto de l1 si no está vacía
    } else {
        cola->siguiente = l2;  // Enlaza el resto de l2 si no está vacía
    }

    return cabeza.siguiente;  // Retorna la lista fusionada omitiendo el nodo temporal
}

// Función para fusionar k listas
struct Nodo* fusionarKListas(struct Nodo** listas, int k) {
    if (k == 0) return NULL;  // Si no hay listas, retorna NULL
    if (k == 1) return listas[0];  // Si solo hay una lista, retorna esa lista

    while (k > 1) {
        int i = 0;
        for (int j = 0; j < k / 2; j++) {
            listas[i++] = fusionarListas(listas[j], listas[k - 1 - j]);  // Fusiona dos listas
        }
        if (k % 2 == 1) { // Si k es impar, agrega la última lista
            listas[i++] = listas[k / 2]; 
        }
        k = i;  // Actualiza k a la cantidad de listas fusionadas
    }
    return listas[0];  // Retorna la lista final fusionada
}

int main() {
    int k = 3;  // Número de listas
    // Longitudes de cada lista
    int longitudes[3] = {3, 3, 2}; 
    // Ejemplo de listas
    int listas[3][3] = { {1, 4, 5}, {1, 3, 4}, {2, 6} }; 

    // Crear un arreglo de listas vinculadas
    struct Nodo* listasVinculadas[3] = {NULL};

    // Convertir los arreglos en listas vinculadas
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < longitudes[i]; j++) {
            listasVinculadas[i] = insertarEnLista(listasVinculadas[i], listas[i][j]);
        }
    }

    // Imprimir las listas iniciales
    printf("Listas originales:\n");
    for (int i = 0; i < k; i++) {
        printf("Lista %d: ", i + 1);
        imprimirLista(listasVinculadas[i]);
    }

    // Fusionar todas las listas
    struct Nodo* listaFusionada = fusionarKListas(listasVinculadas, k);

    // Imprimir el resultado final
    printf("Lista final fusionada: ");
    imprimirLista(listaFusionada);

    return 0;
}