#include <stdio.h>

//线性查找  对数据没有要求 效率低
size_t line_find(int* arr, size_t size,int key)
{
	for(int i=0; i<size; i++)
	{
		if(key == arr[i]) return i;
	}
	return -1;
}

size_t repeat_find(int* arr,size_t left,size_t right,int key)
{
	if(left > right) return -1;
	int p = (left+right)/2;
	if(arr[p] > key) 
		repeat_find(arr,left,p-1,key);
	else if(arr[p] < key)
		repeat_find(arr,p+1,right,key);
	else
		return p;
}


//二分查找（折半查找）对数据有要求，必须有序，效率高
size_t half_find(int* arr,size_t size,int key)
{
	return repeat_find(arr,0,size-1,key);
/*	int left = 0;
	int right = size-1;
	while(left<=right)
	{
		int pv = (left+right)/2;
		if(arr[pv] > key)
			right = pv-1;
		else if(arr[pv] < key)
			left = pv+1;
		else
			return pv;
	}
	return -1;*/
}

int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
	int index = half_find(arr,11,9);
	if(-1 == index)
	{
		printf("查无此数！\n");
	}
	else
	{
		printf("key = %d\n",index);
	}

}
