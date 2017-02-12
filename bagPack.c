/*
 * bagPack.c
 * 0-1背包问题的求解
 *  Created on: 2016年9月1日
 *      Author: lujuan
 */
#include<stdlib.h>
extern void printArray(int v[], int n);
//w为物品的重量，v为物品的价值，n为物品的个数，W为背包能容纳的重量
int bagPack(int w[], int v[], int n, int W){
	int *f = (int *)calloc((W+1), sizeof(int));
	int i,j;
	for(i = 0; i < n; ++i){
		for(j = W; j>=w[i]; --j){
			int newValue = v[i] +f[j-w[i]];
			if(newValue > f[j])
				f[j] = newValue;
		}
		printArray(f, W+1);
	}
	return f[W];

}
