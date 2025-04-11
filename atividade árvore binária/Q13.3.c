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

// Function to count the leaves of the tree
int leafCount(BinaryTree tree){
    if (tree == NULL) return 0;

    if (tree->left == NULL && tree->right == NULL) return 1;
    return leafCount(tree->left) + leafCount(tree->right);
}

int main() {
    BinaryTree tree = createTreeNode(1,
        createTreeNode(2, createTreeNode(4, NULL, NULL), NULL),
        createTreeNode(3, NULL, createTreeNode(5, NULL, NULL))
    );

    printf("Total de folhas: %d\n", leafCount(tree));

    destroyTree(&tree);
    return 0;
}
