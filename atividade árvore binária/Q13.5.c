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

int treeHas(int item, BinaryTree tree){
    if (tree == NULL) return 0;

    if (item == tree->item) return 1;
    else if (item < tree->item) return treeHas(item, tree->left);
    else return treeHas(item, tree->right);
}


int main() {
    BinaryTree tree = NULL;

    insertTreeNode(10, &tree);
    insertTreeNode(5, &tree);
    insertTreeNode(15, &tree);

    int x = 5;
    printf("Item %d %s na árvore.\n", x, treeHas(x, tree) ? "está" : "não está");

    destroyTree(&tree);
    return 0;
}

