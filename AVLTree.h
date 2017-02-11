/*
 * AVLTree.h
 * 自己实现的AVL平衡二叉树，其中包含了若干个函数。
 *  Created on: 2017年2月11日
 *      Author: lujuan
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

struct AvlNode;
typedef struct AvlNode * Position;
typedef struct AvlNode * AvlTree;
typedef  int  AvlElementType;

AvlTree MakeEmpty(AvlTree T);
Position Find(AvlElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(AvlElementType X, AvlTree T);
AvlTree Delete(AvlElementType X, AvlTree T);
void PreOrderTravel(AvlTree T);
void InOrderTravel(AvlTree T);


#endif /* AVLTREE_H_ */
