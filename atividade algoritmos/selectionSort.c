/* Algoritmo para ordenar uma lista sempre através do menor ou maior elemento, encurtando a lista ao longo de cada seleção*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

void implementarSelectionSort(int lista[], int n){
    int i, j, minIndex, temporaria;

    for(i = 0; i < n - 1; i++) {
        minIndex = i; // Assume que o primeiro elemento da lista é o menor

        // eu começo a partir do 1 elemento pós suposto menor número e comparo todos os números restantes com esse, achando o menor número.
        for(j = i + 1; j < n; j++){
            if (lista[j] < lista[minIndex]) {
                minIndex = j; // Se eu achar um número menor do que o suposto menor, minIndex passa a buscar o índice desse novo
            }
        }

        temporaria = lista[i]; // armazena temporariamente o valor do atual índice da lista, que é o atual menor número. Ex: 7
        lista[i] = lista[minIndex]; // Substitui o índice do atual menor número, com o novo menor número achado. Ex: 7 sai e entra 2 no lugar
        lista[minIndex] = temporaria; // No índice do novo menor número, é colocado o antigo, que foi armazenado temporariamente.
    }
}

void mostrarListaOrdenada(int lista[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main(){
    int lista[TAMANHO];
    int n = sizeof(lista) / sizeof(lista[0]);

    for(int i = 0; i < TAMANHO; i++){
        lista[i] = rand() % 100;
    }
    
    printf("Lista desordenada pela ordenação por seleção: \n");
    mostrarListaOrdenada(lista, n);

    printf("Lista ordenada pela ordenação por seleção: \n");
    implementarSelectionSort(lista, n);
    mostrarListaOrdenada(lista, n);

    return 0;
}