/*
 * printArray.c
 *
 *  Created on: 2016��10��10��
 *      Author: lujuan
 */
#include<stdio.h>
void printArray(int v[], int n)
{
	 int i;
	 for(i = 0; i < n;++i)
	 {
		 printf("  %d", v[i]);
	 }
	 printf("\n");
}

