#include <stdio.h>
#include <string.h>

void compressString(const char *word, char *comp) {
    int i = 0, length = strlen(word);
    int compIndex = 0;

    while (i < length) {
        char c = word[i];
        int count = 0;

        // Cuenta el número de repeticiones consecutivas de 'c', hasta un máximo de 9
        while (i < length && word[i] == c && count < 9) {
            count++;
            i++;
        }

        // Agrega el número de repeticiones seguido del carácter a comp
        comp[compIndex++] = count + '0'; // Convierte el número a carácter
        comp[compIndex++] = c;
    }

    comp[compIndex] = '\0'; // Termina la cadena comprimida
}

int main() {
    char word[100];
    char comp[200]; // La cadena comprimida puede ser de hasta el doble de longitud de la original

    printf("Ingrese una palabra para comprimir: ");
    scanf("%s", word);

    compressString(word, comp);

    printf("Cadena comprimida: %s\n", comp);

    return 0;
}