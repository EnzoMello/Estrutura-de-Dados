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

// Function that checks if two trees are equal
int treeEquals(BinaryTree tree1, BinaryTree tree2){
    if (tree1 == NULL && tree2 == NULL) return 1;
    if (tree1 == NULL || tree2 == NULL) return 0;
    if (tree1->item != tree2->item) return 0;

    return 1 && treeEquals(tree1->left, tree2->left) && treeEquals(tree1->right, tree2->right);
}

int main() {
    BinaryTree tree1 = createTreeNode(1, 
        createTreeNode(2, NULL, NULL), 
        createTreeNode(3, NULL, NULL)
    );

    BinaryTree tree2 = createTreeNode(1, 
        createTreeNode(2, NULL, NULL), 
        createTreeNode(3, NULL, NULL)
    );

    printf("As árvores %s iguais.\n", treeEquals(tree1, tree2) ? "são" : "não são");

    destroyTree(&tree1);
    destroyTree(&tree2);
    return 0;
}
