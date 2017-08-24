#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 准备工作,计算数组长度
#define ARR_SIZE(a) (sizeof(a)/sizeof(a[0]))

// 变量交换
#define swap(a,b) {a^=b; b^=a; a^=b;}

/*void swapf(int* p1,int* p2)
{
	
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	
	*p1 ^= *p2;
	*p2 ^= *p1;
	*p1 ^= *p2;
}*/

// 冒泡排序(简单，稳定，安全)

void bubble_sort(int* arr,size_t size)
{
	for(int i=size-1; i>0; i--)
	{
		bool flag = true;
		for(int j=0; j<i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				flag = false;
			}
		}
		if(flag) break;//一轮排完如果没有交换，说明已经是递增序列，直接退出循环
	}
}

// 插入排序
void insert_sort(int* arr,size_t size)
{
	for(int i=1; i<size; i++)
	{
		int insert = arr[i];
		int j = i-1;
		for(; j>=0; j--)
		{
			if(arr[j]>insert)
			{
				arr[j+1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1] = insert;
	}

}
// 选择排序
void select_sort(int* arr,size_t size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(arr[i] >arr[j])
			{
				swap(arr[i],arr[j]);
			}
		}
	}
}

// 快速排序(所有数据环境下，表现都比较优秀)
void quick_sort(int* arr,size_t left,size_t right)
{
	//计算标杆的下标
	int p = (left+right)/2;
	int i = left;
	int j = right;
	//备份标杆的值
	int pv = arr[p];
	while(i < j)
	{
		//查找比标杆大的数，跟标杆进行交换
		for(; i<p&&pv>arr[i]; i++);
		if(i<p)
		{
			arr[p] = arr[i];
			p = i;
		}
		//查找比标杆小的数，跟标杆进行交换
		for(; j>p&&pv<arr[j]; j--);
		if(j>p)
		{
			arr[p] = arr[j];
			p = j;
		}
	}
	//重新放置标杆
	arr[p] = pv;
	//快速排序标杆左边的序列
	if(p - left > 1) quick_sort(arr,left,p-1);
	//快速排序标杆右边的序列
	if(right - p > 1) quick_sort(arr,p+1,right);
}

void quick(int* arr,size_t size)
{
	quick_sort(arr,0,size-1);
}
// 显示数组
void show_arr(int* arr,size_t size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

}


int main()
{
	int arr[] = {1,9,6,3,7,0,8,2,5,4};
	quick(arr,ARR_SIZE(arr));
	show_arr(arr,ARR_SIZE(arr));
	
}
