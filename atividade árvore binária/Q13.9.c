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


void printWeOrder(BinaryTree tree){
    if (tree == NULL) return;
    printWeOrder(tree->right);
    printf("%d\n", tree->item);
    printWeOrder(tree->left);
}

int main() {
    BinaryTree tree = NULL;

    insertTreeNode(10, &tree);
    insertTreeNode(20, &tree);
    insertTreeNode(5, &tree);
    insertTreeNode(15, &tree);

    printf("Itens em ordem decrescente:\n");
    printWeOrder(tree); 

    destroyTree(&tree);
    return 0;
}
