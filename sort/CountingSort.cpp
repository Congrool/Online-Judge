#include<iostream>
using namespace std;
const int LENGTH = 8;
int a[LENGTH+1] = {-10000,2,5,3,0,2,3,0,3};
void Counting_sort(int a[],int b[],int n,int k)
{
	int c[k];
	for(int i = 0;i <= k; i++)
		c[i] = 0;
	for(int j = 1; j <= n; j++)
		c[a[j]]++;
	for(int i = 1; i <= k; i++)
		c[i] = c[i] + c[i-1];
	for(int i = n; i >= 1; i--)
	{
		b[c[a[i]]] = a[i];
		c[a[i]] = c[a[i]] - 1; 
	}
}
void show(int a[])
{
	for(int i = 1; i <= LENGTH ;i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int b[LENGTH];
	show(a);
	Counting_sort(a,b,8,5);
	show(b);
}
