//
// Created by norik on 5/8/2025.
//

#ifndef BIN_S_T_H
#define BIN_S_T_H

#include "barat.h"

typedef struct TreeNode{
    Barat info;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode *createNewNode(Barat newData);
TreeNode *insertTree(TreeNode *node, Barat newData);
void printTree_inorder(TreeNode* node);
int readFromFileTree(const char* filename, TreeNode** node);
void destroyBinaryTree(TreeNode **root);
void countSuitableBaratTree(TreeNode *node, int *count);
void printSuitableBaratok(TreeNode *node);
#endif //BIN_S_T_H
