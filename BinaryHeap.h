/*
 * BinaryHeap.h
 *
 *  Created on: 2017Äê2ÔÂ13ÈÕ
 *      Author: lujuan
 */

#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementTypeHeapStruct;

PriorityQueue Initialize(int MaxElements);
void DestoryPriorityQueue(PriorityQueue H);
void MakeEmptyPriorityQueue(PriorityQueue H);
void InsertPriorityQueue(ElementTypeHeapStruct X, PriorityQueue H);
ElementTypeHeapStruct FindMin(PriorityQueue H);
void DeleteMinPriorityQueue(PriorityQueue H);

int isEmptyPriorityQueue(PriorityQueue H);
int isFullPriorityQueue(PriorityQueue H);
struct HeapStruct{
	int Capacity;
	int Size;
	ElementTypeHeapStruct * Elements;
};
#endif /* BINARYHEAP_H_ */
