/*
 ============================================================================
 Name        : learnC.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include <stdlib.h>
#include"myStack.h"
#include"AVLTree.h"
extern void quickSort(int a[], int left, int right);
extern void printArray(int v[], int n);
extern int bagPack(int w[], int v[], int n, int W);
int main ()
{
	AvlTree T = NULL;
	T = Insert(1, T);
	T = Insert(2, T);
	T = Insert(3, T);
	T = Insert(4, T);
	T = Insert(5, T);
	T = Insert(6, T);
	T = Insert(6, T);
	T = Insert(6, T);
	T = Insert(7, T);
	T = Insert(16, T);
	T = Insert(15, T);
	T = Insert(14, T);
	T = Insert(13, T);
	T = Insert(12, T);
	T = Insert(11, T);
	T = Insert(10, T);
	T = Insert(8, T);
	T = Insert(9, T);


	T = Delete(5,T);
	T = Delete(6,T);
	printf("\n前序遍历的结果为：\n");
	PreOrderTravel(T);
	printf("\n中序遍历的结果为：\n");
	InOrderTravel(T);
    return 0;
}
