#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int CAPACITY = 100000;
int text[CAPACITY];
//融合两个已排序的子数列 
void merge(int a[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *arr1 = new int[n1];
	int *arr2 = new int[n2];
	for (int i = 0; i < n1; i++)
		arr1[i] = a[p + i];				//这步很重要，注意是从p开始取而不是0 
	for (int i = 0; i < n2; i++)
		arr2[i] = a[q + i + 1];			//同理是从r-q+1开始 
	int j = 0, k = 0;
	for (int i = p; i <= r; i++)
	{
		if (j < n1 && k < n2)
		{
			if (arr1[j] <= arr2[k])
				a[i] = arr1[j++];
			else
				a[i] = arr2[k++];
		}
		else
		{
			if (j < n1)
				a[i] = arr1[j++];
			else
				a[i] = arr2[k++];
		}
	}
	delete arr1;
	delete arr2;
}
//merge的简化版本，使用INT_MAX
/*
void Merge(int a[], int lo, int mid, int hi)
{
	int n1 = mid - lo + 1;
	int n2 = hi - mid;
	int *arr1 = new int[n1 + 1];
	int *arr2 = new int[n2 + 1];
	arr1[n1] = INT_MAX;
	arr2[n2] = INT_MAX;
	int j = lo, k = 0;   
	for (int i = 0; i < n1; i++)
		arr1[i] = a[j++];
	for (int i = 0; i < n2; i++)
		arr2[i] = a[j++];
	j = 0;
	for (int i = lo; i <= hi ;i++)
	{
		if (arr1[j] < arr2[k])
			a[i] = arr1[j++];
		else
			a[i] = arr2[k++];
	}
	delete arr1;
	delete arr2;

}
*/ 
//归并排序
void merge_sort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;	
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}
//插入排序 
void insert_sort(int a[],int lo, int hi)
{
	for(int i = lo+1; i <= hi; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(a[j] <= a[j-1])
			{
				int t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;
			}
			else
				break;		
		}
	 } 
}
int main()
{
	time_t now;
	time(&now);
	srand((unsigned)time(NULL));
	for (int i = 0; i < CAPACITY; i++)
		text[i] = rand() % 10000;
	
	cout << "begin time : " << ctime(&now);
	insert_sort(text,0,CAPACITY-1);	
	time(&now);
	cout << "end time : " << ctime(&now) << endl;

	cout << "begin time : " << ctime(&now);
	merge_sort(text,0,CAPACITY-1);
	time(&now);
	cout << "end time : " << ctime(&now) << endl;

}
