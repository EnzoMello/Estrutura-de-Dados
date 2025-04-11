#include <iostream>
#include <cstring>

using namespace std;

// Classe No que vai representar um nó da lista duplamente encadeada
class No {
    public:
        int mat;
        char nome[23]; // variáveis para matrícula e nome da pessoa
        No *prox;
        No *ant; // ponteiros do tipo No apontando para proxm elemento e anterior
        No(int m, char n[23]) {
            mat = m;
            strcpy(nome, n);
            prox = NULL;
            ant = NULL; // classe No atribui valores às variáveis respectivas e inicializa os ponteiros como NULL
        }
};

// Classe Lista representa a lista em si
class Lista {
    private: // possui um ponteiro do tipo No apontando para início e fim da lista
        No *inicio;
        No *fim;

    public:
        Lista() {
            inicio = NULL;
            fim = NULL; // inicia esses ponteiros com valores NULL e inicia a lista de forma vazia
        }

        void inserirOrdenado(int mat, char nome[23]) {
            No *novo = new No(mat, nome); // cria um novo No, que será inserido com seus parâmetros
            if (!inicio) {
                inicio = fim = novo; // Se a lista está vazia, esse No criado será o único elemento
            } else if (mat < inicio->mat) {
                novo->prox = inicio;
                inicio->ant = novo;
                inicio = novo; // O novo nó aponta para o antigo primeiro nó e ele aponta para o novo nó, substituindo o primeiro elemento
            } else { 
                No *atual = inicio;
                while (atual->prox && atual->prox->mat < mat) {
                    atual = atual->prox;
                } // Se o valor de mat for maior que o do No base, percorre a lista procurando um elemento que tenha o valor mat maior do que o mat do novo No

                if (!atual->prox) {
                    atual->prox = novo;
                    novo->ant = atual;
                    fim = novo; // Se o proxm ponteiro for null, ele aponta para o novo no e o anteiro aponta para o atual. 
                } else {
                    novo->prox = atual->prox; 
                    novo->ant = atual;
                    atual->prox->ant = novo;
                    atual->prox = novo; /*Na inserção no meio da lista duplamente encadeada, o novo nó ajusta seu ponteiro `prox` para o próximo nó e `ant` para o anterior. Em seguida, o próximo nó ajusta seu ponteiro `ant` para o novo nó, e o nó anterior ajusta seu ponteiro `prox` para ele. 
                    Assim, o novo nó é corretamente "encaixado" entre dois nós existentes.*/
                }
            }
        }

        void mostrarInicioAoFim() {
            No *atual = inicio;
            while (atual) {
                cout << "Matricula: " << atual->mat << ", Nome: " << atual->nome << endl;
                atual = atual->prox;
            }
        } // percorre a lista usando o ponteiro proximo e printando cada No

        void removerUltimo() {
            if (!fim) {
                cout << "Lista vazia, nada a remover!" << endl;
                return;
            } // lista vazia

            No *removido = fim;

            if (inicio == fim) { 
                inicio = fim = NULL; // lista com um elemento
            } else {
                fim = fim->ant;
                fim->prox = NULL;
            } // lista com mais de um elemento ajusta os ponteiros colocando fim apontando pra o penúltimo elemento

            delete removido; // libera memória do elemento removido
            cout << "Último elemento removido com sucesso." << endl;
        }

        void removerPrimeiro() {
            if (!inicio) {
                cout << "Lista vazia, nada a remover!" << endl;
                return;
            }

            No *removido = inicio;

            if (inicio == fim) {
                inicio = fim = NULL;
            } else {
                inicio = inicio->prox;
                inicio->ant = NULL;
            } // lista com mais de um elemento ajusta os ponteiros colocando início apontando o segundo elemento

            delete removido;
            cout << "Primeiro elemento removido com sucesso." << endl;
        }
};

//EXEMPLO DE USO
int main() {
    Lista lista;
    char nome1[23] = "Elanne";
    char nome2[23] = "Emanoel";
    char nome3[23] = "Marcio";
    char nome4[23] = "Pedro";

    lista.inserirOrdenado(2, nome2);
    lista.inserirOrdenado(1, nome1);
    lista.inserirOrdenado(4, nome4);
    lista.inserirOrdenado(3, nome3);

    cout << "Lista após inserção ordenada:" << endl;
    lista.mostrarInicioAoFim();

    cout << "\nRemovendo o último elemento..." << endl;
    lista.removerUltimo();
    lista.mostrarInicioAoFim();

    cout << "\nRemovendo o primeiro elemento..." << endl;
    lista.removerPrimeiro();
    lista.mostrarInicioAoFim();

    return 0;
}
