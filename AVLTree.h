/*
 * AVLTree.h
 * �Լ�ʵ�ֵ�AVLƽ������������а��������ɸ�������
 *  Created on: 2017��2��11��
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
