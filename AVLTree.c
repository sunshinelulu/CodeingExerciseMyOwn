/*
 * AVLTree.c
 *
 *  Created on: 2017Äê2ÔÂ11ÈÕ
 *      Author: lujuan
 */
#include "AVLTree.h"
#include<stdio.h>
#include<stdlib.h>
struct AvlNode{
	AvlElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};
AvlTree MakeEmpty(AvlTree T){
	if(T != NULL){
		T->Left = MakeEmpty(T->Left);
		T->Right = MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
static int Height(Position P){
	if(P == NULL)
		return -1;
	else
		return P->Height;
}
static Position SingleRotateWithLeft(Position k2){
	Position k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;

	k2->Height = (Height(k2->Left)>Height(k2->Right)?Height(k2->Left):Height(k2->Right))+1;
	k1->Height = (Height(k1->Left)>Height(k1->Right)?Height(k1->Left):Height(k1->Right))+1;

	return k1;
}
static Position SingleRotateWithRight(Position k2){
	Position k1 = k2->Right;
	k2->Right = k1->Left;
	k1->Left = k2;

	k2->Height = (Height(k2->Left)>Height(k2->Right)?Height(k2->Left):Height(k2->Right))+1;
	k1->Height = (Height(k1->Left)>Height(k1->Right)?Height(k1->Left):Height(k1->Right))+1;

	return k1;
}
static Position DoubleRotateWithLeft(Position k3){
	k3->Left = SingleRotateWithRight(k3->Left);
	return SingleRotateWithLeft(k3);
}
static Position DoubleRotateWithRight(Position k3){

	k3->Right = SingleRotateWithLeft(k3->Right);
	return SingleRotateWithRight(k3);

}
static void UpdateHeight(Position P){
	if(P != NULL){
		P->Height= (Height(P->Left)>Height(P->Right)?Height(P->Left):Height(P->Right))+1;
	}
}
AvlTree Insert(AvlElementType X, AvlTree T){
	if(T == NULL){
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if(T == NULL)
			printf("Out of Space!\n");
		else{
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}else{
		if(X < T->Element){
			T->Left = Insert(X,  T->Left);
			if(Height(T->Left) - Height(T->Right) == 2){
				if(X < T->Left->Element)
					T = SingleRotateWithLeft(T);
				else
					T = DoubleRotateWithLeft(T);
			}
		}
		else{
			if(X > T->Element){
				T->Right = Insert(X, T->Right);
				if(Height(T->Right) - Height(T->Left) == 2){
					if(X > T->Right->Element)
						T = SingleRotateWithRight(T);
					else
						T = DoubleRotateWithRight(T);
				}
			}else{
				printf("you input duplicate element, the system just dump it!\n");
			}
		}

	}
	T->Height = (Height(T->Left)>Height(T->Right)?Height(T->Left):Height(T->Right))+1;
	return T;


}
AvlTree Delete(AvlElementType X, AvlTree T){
	if(T == NULL)printf("not find element!\n");
	else{
		if(X < T->Element){
			T->Left = Delete(X, T->Left);
			if(Height(T->Right) - Height(T->Left) == 2){
				if(Height(T->Right->Right) > Height(T->Right->Left))
					T = SingleRotateWithRight(T);
				else
					T = DoubleRotateWithRight(T);
			}
		}else{
			if(X > T->Element){
				T->Right = Delete(X, T->Right);
				if(Height(T->Left) - Height(T->Right) == 2){
					if(Height(T->Left->Left) > Height(T->Left->Right))
						T = SingleRotateWithLeft(T);
					else
						T = DoubleRotateWithLeft(T);
				}
			}else{
				if(T->Left && T->Right){
					Position temp = FindMin(T->Right);
					T->Element = temp->Element;
					T->Right = Delete(T->Element, T->Right);
				}else{
					Position temp = T;
					if(T->Left != NULL)
						T = T->Left;
					else
						T = T->Right;
					printf("delete element : %d\n", temp->Element);
					free(temp);
				}
			}
		}
	}
	UpdateHeight(T);
	return T;
}
Position Find(AvlElementType X, AvlTree T){
	if(T == NULL)return NULL;
	if(X < T->Element)
		return Find(X, T->Left);
	else{
		if(X > T->Element)
			return Find(X, T->Right);
		else
			return T;
	}
}
Position FindMin(AvlTree T){
	if(T == NULL) return NULL;
	if(T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);

}
Position FindMax(AvlTree T){
	if(T == NULL) return NULL;
	if(T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}

void PreOrderTravel(AvlTree T){
	if(T == NULL)return;
	printf(" %d ", T->Element);
	PreOrderTravel(T->Left);
	PreOrderTravel(T->Right);
}
void InOrderTravel(AvlTree T){
	if(T == NULL)return;
	PreOrderTravel(T->Left);
	printf(" %d ", T->Element);
	PreOrderTravel(T->Right);
}
