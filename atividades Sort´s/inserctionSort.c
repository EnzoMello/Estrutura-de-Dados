/*Inserction Sort é um algoritmo que você vai ordenando a lista à medida que vai 
inserindo novos elementos*/

#include <stdio.h>
#include <stdlib.h>

void implementaInsertionSort(int lista[], int n){
    int i, novoElemento, j;

    // Insertion começa a partir do 2 elemento, pois o primeiro já é considerado uma sublista ordenada
    for (i = 1; i < n; i++) {
        novoElemento = lista[i];
        j = i - 1; // Variável j vai representar o último número da lista à esquerda, que é uma sublista já ordenada

        //Loop para ordenar enquanto j não sair da lista já ordenada e seu último número for maior que o novo elemento
        while(j >= 0 && lista[j] > novoElemento) {
            lista[j + 1] = lista[j]; // O próximo índice vai abrigar o valor do índice atual
            j--; // Verifica o próximo elemento da lista já ordenada.
        }

        lista[j + 1] = novoElemento;
    }

}

void printLista(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int lista[] = {7, 3, 8, 5, 2};
    int n = sizeof(lista) / sizeof(lista[0]);


    printf("Lista antes da ordenação: ");
    printLista(lista, n);

    implementaInsertionSort(lista, n);

    printf("Array depois da ordenação: ");
    printLista(lista, n);

    return 0;
}