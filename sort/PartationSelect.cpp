#include<iostream>
using namespace std;
const int LENGTH = 10;
int a[LENGTH] = { 18,22,6,7,3,2,0,7,20,16 };
void exchange(int &a, int &b)
{
	if (a == b) return;
	int t = a;
	a = b;
	b = t;
}
int partition(int a[], int p, int r)
{
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j] <= x)
		{
			i++;
			exchange(a[i], a[j]);
		}
	}
	exchange(a[r], a[i + 1]);
	return i + 1;
}
int Partition_select(int a[], int p, int r, int i)
{
	if (p == r)
		return a[p];
	int q = partition(a, p, r);
	int k = q - p + 1;
	if (i == k)
		return a[q];
	else if (i < k)
		return Partition_select(a, p, q - 1, i);  //注意这是  q-1 
	else
		return Partition_select(a, q + 1, r, i - k); //注意是 i-k
}
int main()
{
	cout << Partition_select(a, 0, LENGTH - 1, 8) << endl;

}
