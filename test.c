/*
 * test.c
 *
 *  Created on: 2017Äê2ÔÂ12ÈÕ
 *      Author: lujuan
 */
#include<stdlib.h>
#include<stdio.h>
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 struct TreeNode * initTree(){
	 struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	 root->val = 1;
	 root->left = NULL;
	 struct TreeNode *right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	 right->val = 2;
	 right->left = NULL;
	 right->right = NULL;

	 root->right = right;
	 return root;
 }
 struct TreeNode * makeEmptyTree(struct TreeNode *root){
	 if(root != NULL){
		 root->right = makeEmptyTree(root->right);
		 root->left = makeEmptyTree(root->left);
		 free(root);
	 }
	 return NULL;
 }
struct TreeNode* visit(struct TreeNode* root, int k){
    static int count = 0;
    if(root != NULL){
           count++;
        if(count == k){
            return root;
        }
    }
    return NULL;

}
struct TreeNode* InOrderTravelFindkthSmallest(struct TreeNode* root, int k){
    if(root == NULL)return NULL;
    else{
       struct TreeNode* left = InOrderTravelFindkthSmallest(root->left, k);
       struct TreeNode* mid = visit(root, k);
       struct TreeNode* right = InOrderTravelFindkthSmallest(root->right, k);
       struct TreeNode* result = left;
       //result = (result != NULL)?(result):(right);
       //result = (result != NULL)?(result):(mid);
       if(mid != NULL) result = mid;
       if(right != NULL)result = right;
       return  result;
    }
}
int kthSmallest(struct TreeNode* root, int k) {
    struct TreeNode* result = InOrderTravelFindkthSmallest(root, k);
    return result->val;
}
//int main(){
//	struct TreeNode * root = initTree();
//	int  a =  kthSmallest(root, 1);
//	printf("%d", a);
//	root = makeEmptyTree(root);
//	return 0;
//}
