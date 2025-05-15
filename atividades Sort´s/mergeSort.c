#include <stdio.h>
#include <stdlib.h>

// merge sort (ordenação por intercalação)
void ordenacaoIntercalacao(int vetor[], int esquerda, int direita) { // vetor a ordenar, índice inicial do subarray, índice final do subarray
    if (esquerda < direita) { // se entrar nesse if, há mais de um elemento no subarray -> divide vetor em duas metades

        int meio = esquerda + (direita - esquerda) / 2; // calcula meio do vetor
        ordenacaoIntercalacao(vetor, esquerda, meio); // recursão para ordenar a metade esquerda
        ordenacaoIntercalacao(vetor, meio + 1, direita); // recursão para ordenar a metade direita

        // caso base da recursão: ate que os subarrays tenham apenas um elemento

        // tamanhoEsquerda é o tamanho da metade esquerda e tamanhoDireita é o tamanho da metade direita
        int tamanhoEsquerda = meio - esquerda + 1;
        int tamanhoDireita = direita - meio;

        // cria dois subarrays temporários para armazenar as metades do vetor
        int *vetorEsquerda = (int*)malloc(tamanhoEsquerda * sizeof(int));
        int *vetorDireita = (int*)malloc(tamanhoDireita * sizeof(int));

        // copia os elementos da metade esquerda para vetorEsquerda
        for (int i = 0; i < tamanhoEsquerda; i++)
            vetorEsquerda[i] = vetor[esquerda + i];
        
        // copia os elementos da metade direita para vetorDireita
        for (int i = 0; i < tamanhoDireita; i++)
            vetorDireita[i] = vetor[meio + 1 + i];

        // i percorre o vetorEsquerda e j percorre o vetorDireita
        // compara os elementos e adiciona ao vetor o menor valor
        int i = 0, j = 0, k = esquerda;
        while (i < tamanhoEsquerda && j < tamanhoDireita) {
            if (vetorEsquerda[i] <= vetorDireita[j])
                vetor[k++] = vetorEsquerda[i++];
            else
                vetor[k++] = vetorDireita[j++];
        }

        // se ainda restarem elementos em qualquer um dos dois subarrays, eles são copiados diretamente para o vetor original
        while (i < tamanhoEsquerda)
            vetor[k++] = vetorEsquerda[i++];

        while (j < tamanhoDireita)
            vetor[k++] = vetorDireita[j++];

        // libera memória de vetores alocados dinamicamente
        free(vetorEsquerda);
        free(vetorDireita);
    }
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

    printf("\n> vetor antes da ordenação: ");
    mostra(vetor, tamanho);

    ordenacaoIntercalacao(vetor, 0, tamanho - 1);

    printf("\n> vetor ordenado por intercalação: ");
    mostra(vetor, tamanho);

    return 0;
}