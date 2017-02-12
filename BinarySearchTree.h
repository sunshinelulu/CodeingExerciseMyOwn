#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H
struct TreeNode;
typedef struct TreeNode * BinarySearchTree;
typedef struct TreeNode * PositionBinarySearchTree;
typedef int ElementType;
BinarySearchTree MakeEmpty(BinarySearchTree T);
BinarySearchTree Insert(ElementType X, BinarySearchTree T);
BinarySearchTree Delete(ElementType X, BinarySearchTree T);
PositionBinarySearchTree Find(ElementType X, BinarySearchTree T);
PositionBinarySearchTree FindMin(BinarySearchTree T);
PositionBinarySearchTree FindMax(BinarySearchTree T);

#endif

