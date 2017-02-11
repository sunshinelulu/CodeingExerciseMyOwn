
void quickSort(int a[], int left, int right){
	if(left>=right)return;
	int low = left;
	int i;
	int key = a[left];
	for(i = left+1; i <= right; ++i){
		if(a[i] < key){
			int temp = a[i];
			a[i] = a[++low];
			a[low] = temp;
		}
	}
	a[left] = a[low];
	a[low] = key;
	quickSort(a, left, low-1);
	quickSort(a, low+1, right);
}
