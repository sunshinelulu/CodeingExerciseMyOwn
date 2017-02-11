#include"myStack.h"
#include<stdio.h>
#include<stdlib.h>
int isEmpty(stack * topStack){
    if(topStack == NULL)
        return 1;
    else
        return 0;
}
stack * Push(stack * topStack, struct TreeNode * element){
    stack * newTop = (stack * )malloc(sizeof(stack));
    if(newTop != NULL){
        newTop->element = element;
        newTop->next = topStack;
        newTop->isVisited = 0;
    }
    return newTop;
}
stack * Pop(stack * topStack){
    stack * newTop = NULL;
    if(topStack != NULL){
        newTop = topStack->next;
        free(topStack);
    }
    return newTop;
}
int * addArray(int *array, int *len, int val){
    int *newArray = (int *)malloc((*len+1)*sizeof(int));
    if(newArray != NULL){
    	int i;
        for(i = 0; i < *len; ++i)
            newArray[i] = array[i];
        newArray[*len] = val;
        *len = *len+1;
    }
    return newArray;
}
