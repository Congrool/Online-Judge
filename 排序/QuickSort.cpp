#include<iostream>
using namespace std;
const int LENGTH = 10;
int a[LENGTH];
void exchange(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
int partition(int a[], int lo, int hi)
{
	int x = a[hi];
	int i = lo - 1;
	for (int j = lo; j < hi; j++)
	{
		if (a[j] <= x)
		{
			i++;
			exchange(a[j], a[i]);
		}
	}
	exchange(a[hi], a[i + 1]);
	return i + 1;
}

void Quick_sort(int a[], int lo, int hi)
{
	if (lo < hi)
	{
		int mid = partition(a, lo, hi);
		Quick_sort(a, lo, mid-1);
		Quick_sort(a, mid + 1, hi);
	}
}
void show(int a[])
{
	for (int i = 0; i < LENGTH; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	for (int i = 0; i < LENGTH; i++)
		cin >> a[i];
	Quick_sort(a, 0, LENGTH - 1);
	show(a);
}
