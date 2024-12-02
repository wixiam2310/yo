#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un nodo del árbol de Huffman
typedef struct MinHeapNode {
    char data;             // Carácter
    unsigned freq;         // Frecuencia del carácter
    struct MinHeapNode *left, *right;  // Hijos izquierdo y derecho
} MinHeapNode;

// Estructura para representar un heap de nodos
typedef struct MinHeap {
    unsigned size;         // Número de nodos en el heap
    unsigned capacity;     // Capacidad del heap
    MinHeapNode **array;   // Arreglo de nodos
} MinHeap;

// Función para crear un nuevo nodo
MinHeapNode* newNode(char data, unsigned freq) {
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Función para crear un heap vacío
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// Función para intercambiar dos nodos
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Función para ajustar el heap (reordenar para mantener la propiedad de heap)
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Función para extraer el nodo con la frecuencia mínima
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Función para insertar un nodo en el heap
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Función para construir el árbol de Huffman
MinHeap* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);

    // Crear nodos para cada carácter y agregarlo al heap
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;

    // Construir el árbol
    while (minHeap->size > 1) {
        MinHeapNode *left = extractMin(minHeap);
        MinHeapNode *right = extractMin(minHeap);

        MinHeapNode* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return minHeap;
}

// Función para generar los códigos de Huffman a partir del árbol
void printCodes(MinHeapNode* root, int arr[], int top) {
    // Si el nodo es NULL, retornar
    if (root == NULL)
        return;

    // Si es un nodo hoja, imprimir el carácter y su código
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }

    // Recursión en el subárbol izquierdo
    arr[top] = 0;
    printC

