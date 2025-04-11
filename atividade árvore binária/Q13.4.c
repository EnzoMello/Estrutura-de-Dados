#include "binary_tree.hpp"

BinaryTree createTreeNode(int item, BinaryTree left, BinaryTree right){
    BinaryTree newNode = (BinaryTree) malloc (sizeof (struct binary_tree)); 
    
    newNode->left = left; 
    newNode->right = right;
    newNode->item = item;

    return newNode;
}


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

// Function that checks the height of a tree
int treeHeight(BinaryTree tree){
    if (tree == NULL) return 0;

    int leftCount = 1 + treeHeight(tree->left);
    int rightCount = 1 + treeHeight(tree->right);

    if (leftCount > rightCount) return leftCount;

    return rightCount;
}

int main() {
    BinaryTree tree = NULL;

    insertTreeNode(10, &tree);
    insertTreeNode(5, &tree);
    insertTreeNode(20, &tree);
    insertTreeNode(3, &tree);
    insertTreeNode(7, &tree);

    printf("Altura da árvore: %d\n", treeHeight(tree));

    destroyTree(&tree);
    return 0;
}
