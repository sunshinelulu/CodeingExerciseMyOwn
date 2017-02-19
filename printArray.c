/*
 * printArray.c
 *
 *  Created on: 2016年10月10日
 *      Author: lujuan
 */
#include<stdio.h>
//打印数组里面的元素，v为数组首地址，n为数组的长度
void printArray(int v[], int n)
{
	 int i;
	 for(i = 0; i < n;++i)
	 {
		 printf("  %d", v[i]);
	 }
	 printf("\n");
}
void printStrArray(char v[], int n)
{
	 int i;
	 for(i = 0; i < n;++i)
	 {
		 printf("  %c", v[i]);
	 }
	 printf("\n");
}

