#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int value;
    struct No *left, *right;
} No;

/**
 * @brief Cria um novo nó com valor informado, alocando memória e iniciando os filho do nó como Null
 * 
 * @param value Valor a ser armazenado no novo nó.
 * @return No* Ponteiro para o novo nó criado.
 */
No* newNode(int value) {
    No* no = (No*) malloc(sizeof(No));
    no->value = value;
    no->left = no->right = NULL;
    return no;
}

/**
 * @brief Insere um valor na árvore binária de busca, verificando se o valor é maior ou não do que a raíz atual
 * 
 * @param root Raiz da árvore.
 * @param value Valor a ser inserido.
 * @return root raíz atual.
 */
No* insert(No* root, int value) {
    if (root == NULL) return newNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    return root;
}

/**
 * @brief Encontra o maior valor na subárvore esquerda. Começa com a raíz da subárvore e vai até o nó mais à direita.
 * 
 * @param root Raiz da subárvore esquerda.
 * @return No* Nó com o maior valor.
 */
No* maxInLeftSubtree(No* root) {
    No* current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}

/**
 * @brief Remove um nó da árvore usando o método de cópia.
 * 
 * @param root Raiz da árvore.
 * @param value Valor a ser removido.
 * @return Node* Nova raiz após a remoção.
 */
No* removeNode(No* root, int value) {
    // Árvore vazia = Não remove
    if (root == NULL) return NULL;

    // Procura à esquerda, caso seja um valor menor, ou à direita, caso seja maior
    if (value < root->value)
        root->left = removeNode(root->left, value);
    else if (value > root->value)
        root->right = removeNode(root->right, value);
    else {

        // Caso 1: sem filhos. Apenas libera memória
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Caso 2: um filho. Pega o filho, armazena e substitui o ponteiro para o pai do filho.
        else if (root->left == NULL || root->right == NULL) {
            No* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        // Caso 3: dois filhos → cópia do maior da subárvore esquerda para nó atual e remoção do nó duplicado. 
        else {
            No* temp = maxInLeftSubtree(root->left);
            root->value = temp->value;
            root->left = removeNode(root->left, temp->value);
        }
    }
    return root;
}

/**
 * @brief Imprime os valores da árvore em ordem (esquerda, raiz, direita).
 * 
 * @param root Raiz da árvore.
 */
void inOrder(No* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

/**
 * @brief Libera todos os nós da árvore da memória.
 * 
 * @param root Raiz da árvore.
 */
void freeTree(No* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    No* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Árvore original (em ordem): ");
    inOrder(root);

    printf("\nRemovendo 50 (nó com dois filhos)...\n");
    root = removeNode(root, 50);

    printf("Árvore após remoção (em ordem): ");
    inOrder(root);

    freeTree(root);
    return 0;
}
