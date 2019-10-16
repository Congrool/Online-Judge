#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
const int LENGTH = 10;
int heapsize = LENGTH;
int A[LENGTH + 1] = { INT_MAX,16,14,10,8,7,9,3,2,4,1 };
void exchange(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void ContainHeap(int a[], int i)
{
	int largest_s = i;
	int left = 2 * i;
	int right = 2 * i + 1;
	if (left <= heapsize && a[left] > a[i])
		largest_s = left;
	if (right <= heapsize && a[right] > a[largest_s])	
		largest_s = right;
	if (largest_s != i)
	{
		exchange(a[i], a[largest_s]);
		ContainHeap(a, largest_s);
	}

}
void BuildMaxHeap(int a[])
{
	for (int i = heapsize / 2; i >= 1; i--)
		ContainHeap(a, i);
}

void Heap_sort(int a[])
{
	BuildMaxHeap(a);
	for (int i = LENGTH; i >= 2; i--)
	{
		exchange(a[1], a[i]);
		heapsize--;
		ContainHeap(a, 1);
	}
}
void show(int a[])
{
	for (int i = 1; i < LENGTH + 1; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	show(A);
	Heap_sort(A);
	show(A);
}
