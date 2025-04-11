#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree
{
    struct binary_tree *left;
    struct binary_tree *right;
    int item;
} *BinaryTree;

BinaryTree createTreeNode(int item, BinaryTree left, BinaryTree right);
void printTreeInOrder(BinaryTree tree);
void printTreePreOrder(BinaryTree tree);
void printTreePostOrder(BinaryTree tree);
void insertTreeNode(int item, BinaryTree *treePtr);
int treeIsStrictlyBinary(BinaryTree tree);
int treeEquals(BinaryTree tree1, BinaryTree tree2);
int treeHeight(BinaryTree tree);
int nodeCount(BinaryTree tree);
int leafCount(BinaryTree tree);
int expressionIsValid(BinaryTree tree);
int treeHas(int item, BinaryTree tree);
void destroyTree(BinaryTree *treePtr);

#endif