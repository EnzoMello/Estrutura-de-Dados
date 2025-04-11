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

// Function that checks if the operator is an expression sign
int isOperator(int item) {
    return item == '+' || item == '-' || item == '*' || item == '/';
}

int expressionIsValid(BinaryTree tree) {
    if (tree -> item == NULL) return 0;

    // If not an operator, returns a number
    if(!isOperator(tree -> item)){
        return tree -> item;
    }

    int esq = expressionIsValid(tree -> left);
    int dir = expressionIsValid(tree -> right);

    // Applies the operator to its children
    switch(tree -> item) {
        case '+': return esq + dir;
        case '-': return esq - dir;
        case '*': return esq * dir;
        case '/': return esq / dir;
        default: return 0;

    }

}


int main() {

    // Expression ((9 + 3) / 2) * (11 - 1)
    BinaryTree tree = 
    createTreeNode(42, 
        createTreeNode(47, 
            createTreeNode(43, 
                createTreeNode(9, NULL, NULL),
                createTreeNode(3, NULL, NULL)
            ),
            createTreeNode(2, NULL, NULL)
        ),
        createTreeNode(45, 
            createTreeNode(11, NULL, NULL),
            createTreeNode(1, NULL, NULL)
        )
    );

    int verification = expressionIsValid(tree);
    printf("Result: %d", verification);

    return 0;
}