#include <stdio.h>
#include"myStack.h"
#include<stdlib.h>
struct TreeNode * initTree(){
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	struct TreeNode *left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	struct TreeNode *right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	left->left = NULL;left->right = NULL;
	right->left = NULL;right->right = NULL;
	left->val = 2;
	right->val = 3;
	root->left = left;root->right = right;
	root->val = 1;
	return root;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    stack * topStack = (stack * )malloc(sizeof(stack));
    if(topStack == NULL)return NULL;
     topStack->element = root;
     topStack->next = NULL;
     topStack->isVisited = 0;
     int *array = NULL;
     * returnSize = 0;
     while(~isEmpty(topStack)){
         if(topStack->isVisited){
             array = addArray(array, returnSize, topStack->element->val);
             topStack = Pop(topStack);
         }else{
             topStack->isVisited = 1;
             stack *newTop = topStack;
             if(topStack->element->right != NULL)
                newTop = Push(newTop, topStack->element->right);
            if(topStack->element->left != NULL)
                newTop = Push(newTop, topStack->element->left);
            topStack = newTop;
         }
     }
     return array;
}
