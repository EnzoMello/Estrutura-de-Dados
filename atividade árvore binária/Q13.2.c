#include "binary_tree.hpp"

BinaryTree createTreeNode(int item, BinaryTree left, BinaryTree right){
    BinaryTree newNode = (BinaryTree) malloc (sizeof (struct binary_tree)); 
    
    // Defines tree nodes and item type
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

// Function to count the nodes in the tree
int nodeCount(BinaryTree tree){
    if (tree == NULL) return 0;

    return 1 + nodeCount(tree->left) + nodeCount(tree->right);
}

int main() {
    BinaryTree tree = createTreeNode(1,
        createTreeNode(2, createTreeNode(4, NULL, NULL), NULL),
        createTreeNode(3, NULL, createTreeNode(5, NULL, NULL))
    );

    printf("Total de nós: %d\n", nodeCount(tree));

    destroyTree(&tree);
    return 0;
}


