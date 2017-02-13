/*
 * BinaryHeap.c
 *
 *  Created on: 2017年2月13日
 *      Author: lujuan
 */
#include"BinaryHeap.h"
#include<stdlib.h>
#include<stdio.h>

//初始化优先队列
PriorityQueue Initialize(int MaxElements){
	PriorityQueue H;
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if(H != NULL){
		H->Capacity = MaxElements;
		H->Size = 0;
		H->Elements = (ElementTypeHeapStruct *)malloc(MaxElements * sizeof(ElementTypeHeapStruct));
		if(H->Elements == NULL)printf("malloc error!\n");
	}
	return H;
}
int isFullPriorityQueue(PriorityQueue H){
	if(H->Size >= H->Capacity)
		return 1;
	else
		return 0;
}
int isEmptyPriorityQueue(PriorityQueue H){
	if(H->Size == 0)
		return 1;
	else
		return 0;
}
void InsertPriorityQueue(ElementTypeHeapStruct X, PriorityQueue H){
	if(isFullPriorityQueue(H)){
		printf("PriorityQUEUE is full!\n");
		return;
	}
	int i;
	for(i = (++H->Size)-1; i >0 && H->Elements[(i-1)/2] > X;){
		H->Elements[i] = H->Elements[(i-1)/2];
		i = (i-1)/2;
	}
	H->Elements[i] = X;
}
void DeleteMinPriorityQueue(PriorityQueue H){
	if(isEmptyPriorityQueue(H))return;
	ElementTypeHeapStruct last = H->Elements[H->Size-1];
	H->Size--;
	int i, child;
	for(i = 0; 2*i +1 < H->Size; ){
		child = 2*i +1;
		if(child+1 < H->Size && H->Elements[child+1] < H->Elements[child])
			child = child+1;
		if(H->Elements[child] < last){
			H->Elements[i] = H->Elements[child];
			i = child;
		}else break;
	}
	H->Elements[i] = last;
}


