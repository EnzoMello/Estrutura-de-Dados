#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int size, int *arr) {
    int aux, i, j, troca;

    for (i = size - 1; i >= 1; --i) {
        troca = 0; // moveu para dentro do loop para reiniciar a cada passagem
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                troca = 1;
            }
        }
        if (troca == 0) {
            break;
        }
    }
}

int main() {
    int size = 1000;
    int arr[1000];

    // Semente para números aleatórios diferentes a cada execução
    srand(time(NULL));

    // Preenche o vetor com valores aleatórios entre 0 e 9999
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }

    // Ordena o vetor
    bubble_sort(size, arr);

    // Imprime os elementos ordenados
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
