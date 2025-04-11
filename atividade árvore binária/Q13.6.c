#include "binary_tree.hpp"

BinaryTree createTreeNode(int item, BinaryTree left, BinaryTree right){
    BinaryTree newNode = (BinaryTree) malloc (sizeof (struct binary_tree)); 
    
    newNode->left = left; 
    newNode->right = right;
    newNode->item = item;

    return newNode;
}

// Function that inserts a node into the tree
void insertTreeNode(int item, BinaryTree *treePtr){
    if (*treePtr == NULL){
        *treePtr = createTreeNode(item, NULL, NULL);
    } else if (item <= (*treePtr)->item){
        insertTreeNode(item, &(*treePtr)->left);
    } else {
        insertTreeNode(item, &(*treePtr)->right);
    }
}

void destroyTree(BinaryTree *treePtr){
    if (*treePtr == NULL) return;
    destroyTree(&(*treePtr)->left);
    destroyTree(&(*treePtr)->right);
    free(*treePtr);
    *treePtr = NULL;
}

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

int main() {
    BinaryTree tree = createTreeNode(1, 
        createTreeNode(2, createTreeNode(4, NULL, NULL), createTreeNode(5, NULL, NULL)), 
        createTreeNode(3, createTreeNode(6, NULL, NULL), createTreeNode(7, NULL, NULL))
    );

    printf("A árvore %s estritamente binária.\n", treeIsStrictlyBinary(tree) ? "é" : "não é");

    destroyTree(&tree);
    return 0;
}
