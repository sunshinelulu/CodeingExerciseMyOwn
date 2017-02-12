/*
 * BuildTreeByIn_Pre_Order.c
 * 根据前序和后序遍历的结果构建二叉树
 *  Created on: 2016年12月11日
 *      Author: lujuan
 */
#include<stdlib.h>
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

int findPreorder(int val, int* preorder, int start, int end){
	int i;
     for(i = start; i <= end; i++){
        if(preorder[i] == val)
        return i;
    }
    return -1;
}
int findInorder(int val, int* inorder, int start, int end){
	int j;
    for(j = start; j <= end; j++){
        if(inorder[j] == val)
        return j;
    }
    return -1;

}
struct TreeNode* fun(int* preorder, int pStart, int pEnd, int* inorder, int iStart, int iEnd){
        struct TreeNode* newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        newNode->val = preorder[pStart];
        newNode->left = 0;
        newNode->right = 0;
        if(pStart == pEnd && iStart == iEnd)
            return newNode;
        else{
            int inorder2,preorder2;
            inorder2 = findInorder(preorder[pStart], inorder, iStart,  iEnd);
            preorder2 = findPreorder(inorder[inorder2-1], preorder, pStart, pEnd);
            newNode->left = fun(preorder, pStart+1, preorder2,  inorder, iStart, inorder2-1);
            newNode->right = fun(preorder, preorder2+1, pEnd, inorder, inorder2+1, iEnd);
            return newNode;
        }

}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {

    struct TreeNode* temp = fun(preorder, 0, preorderSize-1, inorder, 0,  inorderSize-1);
    return temp;
}
//int main(){
//	int a[3] = {1,2,3};
//	int b[3] = {2,1,3};
//	buildTree(a,3,b,3);
//	return 0;
//}
