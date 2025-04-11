#include "binary_tree.hpp"

// Cria um nó comum de arvore e o retorna
BinaryTree createTreeNode(int item, BinaryTree left, BinaryTree right){
    BinaryTree newNode = (BinaryTree) malloc (sizeof (struct binary_tree)); // Aloca memória para a árvore
    
    // Define nós e tipo de item da árvore
    newNode->left = left; 
    newNode->right = right;
    newNode->item = item;

    return newNode;
}

// Questao 13.2
int nodeCount(BinaryTree tree){
    if (tree == NULL) return 0;

    return 1 + nodeCount(tree->left) + nodeCount(tree->right);
}

// Questao 13.3
int leafCount(BinaryTree tree){
    if (tree == NULL) return 0;

    if (tree->left == NULL && tree->right == NULL) return 1;
    return leafCount(tree->left) + leafCount(tree->right);
}

// Questao 13.4
int treeHeight(BinaryTree tree){
    if (tree == NULL) return 0;

    int leftCount = 1 + treeHeight(tree->left);
    int rightCount = 1 + treeHeight(tree->right);

    if (leftCount > rightCount) return leftCount;

    return rightCount;
}

// Questao 13.5
int treeHas(int item, BinaryTree tree){
    if (tree == NULL) return 0;

    if (item == tree->item) return 1;
    else if (item < tree->item) return treeHas(item, tree->left);
    else return treeHas(item, tree->right);
}

// Questao 13.6
int treeIsStrictlyBinary(BinaryTree tree){
    // If a node is a leaf
    if (tree->left == NULL && tree->right == NULL) return 1;

    // If there are two "sons" in a node
    if (tree->left != NULL && tree->right != NULL){
        return treeIsStrictlyBinary(tree->left) & treeIsStrictlyBinary(tree->right);
    }

    // If it's neither a leaf or it has not two sons
    return 0;
}


// Questao 13.7
int treeEquals(BinaryTree tree1, BinaryTree tree2){
    if (tree1 == NULL && tree2 == NULL) return 1;
    if (tree1 == NULL || tree2 == NULL) return 0;
    if (tree1->item != tree2->item) return 0;

    return 1 && treeEquals(tree1->left, tree2->left) && treeEquals(tree1->right, tree2->right);
}


// Questão 13.8
int expressionIsValid(BinaryTree tree) {
    if (tree -> item == NULL) return 0;

    if(tree -> left == NULL && tree -> right == NULL){
        return tree -> item;
    }

    int esq = expressionIsValid(tree -> left);
    int dir = expressionIsValid(tree -> right);

    switch(tree -> item) {
        case '+': return esq + dir;
        case '-': return esq - dir;
        case '*': return esq * dir;
        case '/': return esq / dir;
        default: return 0;

    }

}

// Questao 13.9
void printWeOrder(BinaryTree tree){
    if (tree == NULL) return;
    printWeOrder(tree->right);
    printf("%d\n", tree->item);
    printWeOrder(tree->left);
}

// esq raiz dir
void printTreeInOrder(BinaryTree tree){
    if (tree == NULL) return;
    printTreeInOrder(tree->left);
    printf("%d\n", tree->item);
    printTreeInOrder(tree->right);
}

// raiz esq dir
void printTreePreOrder(BinaryTree tree){
    if (tree == NULL) return;
    printf("%d\n", tree->item);
    printTreePreOrder(tree->left);
    printTreePreOrder(tree->right);
}

// esq dir raiz
void printTreePostOrder(BinaryTree tree){
    if (tree == NULL) return;
    printTreePostOrder(tree->left);
    printTreePostOrder(tree->right);
    printf("%d\n", tree->item);
}

// Destrói a árvore, liberando memória
void destroyTree(BinaryTree *treePtr){
    if (*treePtr == NULL) return;
    destroyTree(&(*treePtr)->left);
    destroyTree(&(*treePtr)->right);
    free(*treePtr);
    *treePtr = NULL;
}

// Insere os nós em uma árvore, de modo que ela seja uma arvore de busca binaria
void insertTreeNode(int item, BinaryTree *treePtr){
    if (*treePtr == NULL){
        *treePtr = createTreeNode(item, NULL, NULL);
    } else if (item <= (*treePtr)->item){
        insertTreeNode(item, &(*treePtr)->left);
    } else {
        insertTreeNode(item, &(*treePtr)->right);
    }
}

