#include <stdio.h>
#include <stdlib.h>

void havelHakimi(int n, int degrees[]) {
    int i, j, k;

    // Suma de los grados de los vértices
    int sum = 0;
    for(i = 0; i < n; i++) {
        sum += degrees[i];
    }

    // Verificar si la suma de los grados es par
    if(sum % 2 != 0) {
        printf("No se puede construir un grafo\n");
        return;
    }

    // Algoritmo de Havel-Hakimi
    for(i = 0; i < n; i++) {
        // Encontrar el grado máximo y su índice
        int maxDegree = 0;
        int maxIndex = 0;
        for(j = i; j < n; j++) {
            if(degrees[j] > maxDegree) {
                maxDegree = degrees[j];
                maxIndex = j;
            }
        }

        // Verificar si todos los grados son cero
        if(maxDegree == 0) {
            break;
        }

        // Eliminar el vértice con el grado máximo
        degrees[maxIndex] = 0;
        for(j = i + 1; j <= i + maxDegree; j++) {
            degrees[j]--;
            if(degrees[j] < 0) {
                printf("No se puede construir un grafo\n");
                return;
            }
        }

        // Ordenar los grados en orden descendente
        for(j = i; j < n; j++) {
            for(k = j + 1; k < n; k++) {
                if(degrees[j] < degrees[k]) {
                    int temp = degrees[j];
                    degrees[j] = degrees[k];
                    degrees[k] = temp;
                }
            }
        }
    }

    // Si el algoritmo terminó antes de recorrer todos los vértices, entonces no se puede construir un grafo
    if(i < n) {
        printf("No se puede construir un grafo\n");
        return;
    }

    // Se puede construir un grafo
    printf("Se puede construir un grafo\n");
}

int main() {
    // Ejemplo de uso
    int n = 6;
    int degrees[] = {4, 4, 3, 2, 2};
    havelHakimi(n, degrees);

    return 0;
}