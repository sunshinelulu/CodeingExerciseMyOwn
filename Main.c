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
extern void reverseString();
int main ()
{
	reverseString();
    return 0;
}
