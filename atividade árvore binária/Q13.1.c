#include "binary_tree.hpp"

BinaryTree createTreeNode(int item, BinaryTree left, BinaryTree right){
    BinaryTree newNode = (BinaryTree) malloc (sizeof (struct binary_tree)); 
    
    newNode->left = left; 
    newNode->right = right;
    newNode->item = item;

    return newNode;
}
