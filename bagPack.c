//0-1������������
#include<stdlib.h>
extern void printArray(int v[], int n);
//wΪ��Ʒ��������vΪ��Ʒ�ļ�ֵ��nΪ��Ʒ�ĸ�����WΪ���������ɵ�����
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
