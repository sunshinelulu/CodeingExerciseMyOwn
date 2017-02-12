/*
 * BinarySearchTree.c
 *
 *  Created on: 2017年2月11日
 *      Author: lujuan
 */
#include "BinarySearchTree.h"
#include<stdio.h>
#include<stdlib.h>
struct TreeNode{
	ElementType Element;
	BinarySearchTree Left;
	BinarySearchTree Right;

};
BinarySearchTree MakeEmptyBinarySearchTree(BinarySearchTree T){
	if(T != NULL){
		T->Left = MakeEmptyBinarySearchTree(T->Left);
		T->Right = MakeEmptyBinarySearchTree(T->Right);
		free(T);
	}
	return NULL;

}
PositionBinarySearchTree FindBinarySearchTree(ElementType X, BinarySearchTree T){
	if(T == NULL) return NULL;
	else{
		if(X < T->Element)
			return FindBinarySearchTree(X, T->Left);
		else{
			if(X > T->Element)
				return FindBinarySearchTree(X, T->Right);
			else
				return T;
		}
	}
}
PositionBinarySearchTree FindMinBinarySearchTree(BinarySearchTree T){
	if(T == NULL)return NULL;
	else{
		if(T->Left == NULL)return T;
		else
			return FindMinBinarySearchTree(T->Left);
	}
}
PositionBinarySearchTree FindMaxBinarySearchTree(BinarySearchTree T){
	if(T == NULL)return NULL;
		else{
			if(T->Right == NULL)return T;
			else
				return FindMaxBinarySearchTree(T->Right);
		}
}
BinarySearchTree InsertBinarySearchTree(ElementType X, BinarySearchTree T){
	if(T == NULL){
		T = (BinarySearchTree)malloc(sizeof( struct TreeNode));
		if( T != NULL){
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}else{
		if(X < T->Element)
			T->Left = InsertBinarySearchTree(X, T->Left);
		else{
			if(X < T->Element){
				T->Right = InsertBinarySearchTree(X, T->Right);
			}
		}
	}
	return T;
}
BinarySearchTree DeleteBinarySearchTree(ElementType X, BinarySearchTree T){
	if(T == NULL)printf("element not found!\n");
	else{
		if(X < T->Element)
			T->Left = DeleteBinarySearchTree(X, T->Left);
		else{
			if(X < T->Element){
				T->Right = DeleteBinarySearchTree(X, T->Right);
			}else{//当前节点为我们所需要删除的节点
				if(T->Left && T->Right){
					PositionBinarySearchTree temp = FindMinBinarySearchTree(T->Right);
					T->Element = temp->Element;
					DeleteBinarySearchTree(T->Element, T->Right);
				}else{
					PositionBinarySearchTree temp = T;
					if(T->Left != NULL)
						T = T->Left;
					else
						T = T->Right;
					free(temp);
				}
			}
		}
	}
	return T;
}


