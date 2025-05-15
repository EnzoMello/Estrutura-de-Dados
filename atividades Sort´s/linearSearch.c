#include <stdio.h>
#include <stdlib.h>

// busca linear
int buscaLinear(int *array, int tamanho, int elemento) { // retorna o índice do elemento se encontrado, caso contrário retorna -1
    for (int i = 0; i < tamanho; i++) { // percorre cada indice do array
        if (array[i] == elemento) {
            return i; // elemento encontrado
        }
    }
    return -1; // elemento nao foi encontrado
}

void mostra(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int vetor[] = {61, 34, 29, 39, 22, 33, 75};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("\n> elementos do vetor: ");
    mostra(vetor, tamanho);

    printf("\n> tamanho do vetor: %d\n", tamanho);

    int valor = 29;
    int indice = buscaLinear(vetor, tamanho, valor);
    if (indice != -1) {
        printf("\nelemento %d encontrado -> índice: %d\n\n", valor, indice);
    } else {
        printf("\nelemento %d nao encontrado no vetor\n\n", valor);
    }

    return 0;
}