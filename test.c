/*
 * test.c
 *
 *  Created on: 2017��2��12��
 *      Author: lujuan
 */
#include<stdlib.h>
#include<stdio.h>
extern void printArray(int v[], int n);
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int * result = NULL;
    if(numsSize >0){
        result = (int *)calloc(numsSize, sizeof(int));
        for(int i = 0; i < numsSize; i++){
            int count = 0;
            for(int j = i+1; j < numsSize; j++){
                if(nums[j] < nums[i])
                    count++;
            }
            result[i] = count;
        }
    }
    return result;

}
